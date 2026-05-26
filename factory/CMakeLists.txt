cmake_minimum_required(VERSION 3.14)

project(factory_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(factory_demo
    main.cpp
    LegacyHAL.cpp
    AidlHAL.cpp
    HDMICecHalFactory.cpp
)

target_include_directories(factory_demo
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(factory_demo PRIVATE -Wall -Wextra -pedantic)
endif()
