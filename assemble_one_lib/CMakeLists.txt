cmake_minimum_required(VERSION 3.14)

project(single_lib_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(HDMICecHal_legacy SHARED
    LegacyHAL/HDMICecHal.cpp
)

target_include_directories(HDMICecHal_legacy
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(HDMICecHal_legacy PROPERTIES
    OUTPUT_NAME HDMICecHal
    PREFIX "lib"
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/LegacyHAL
)

add_library(HDMICecHal_aidl SHARED
    AidlHAL/HDMICecHal.cpp
)

target_include_directories(HDMICecHal_aidl
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(HDMICecHal_aidl PROPERTIES
    OUTPUT_NAME HDMICecHal
    PREFIX "lib"
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/AidlHAL
)

add_library(main_obj OBJECT
    main.cpp
)

target_include_directories(main_obj
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(single_lib_demo
    $<TARGET_OBJECTS:main_obj>
)

add_library(HDMICecHal_from_legacy_dir SHARED IMPORTED GLOBAL)
set_target_properties(HDMICecHal_from_legacy_dir PROPERTIES
    IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/LegacyHAL/libHDMICecHal.so
)

add_dependencies(single_lib_demo HDMICecHal_legacy)

target_link_libraries(single_lib_demo
    PRIVATE
        HDMICecHal_from_legacy_dir
)

# Ensure the default executable resolves the legacy shared library at runtime.
set_target_properties(single_lib_demo PROPERTIES
    BUILD_RPATH "${CMAKE_BINARY_DIR}/LegacyHAL"
)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(HDMICecHal_legacy PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(HDMICecHal_aidl PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(main_obj PRIVATE -Wall -Wextra -pedantic)
endif()
