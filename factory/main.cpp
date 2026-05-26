#include "HDMICecHalFactory.h"

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>

bool parseBoolFlag(const std::string &value) {
    if (value == "1" || value == "true" || value == "TRUE" || value == "yes" || value == "YES") {
        return true;
    }
    if (value == "0" || value == "false" || value == "FALSE" || value == "no" || value == "NO") {
        return false;
    }
    throw std::invalid_argument("Invalid value for aidl_hal_available: " + value);
}

int main(int argc, char *argv[]) {
    // Priority: command-line flag, then environment variable, then default false.
    bool aidl_hal_available = false;

    if (argc > 1) {
        aidl_hal_available = parseBoolFlag(argv[1]);
    } else {
        const char *env = std::getenv("aidl_hal_available");
        if (env != nullptr) {
            aidl_hal_available = parseBoolFlag(env);
        }
    }

    std::unique_ptr<HDMICecHal> hal = HDMICecHalFactory::Create(aidl_hal_available);

    if (!hal->HdmiCecOpen()) {
        std::cerr << "Failed to open HDMI CEC HAL" << std::endl;
        return 1;
    }

    return 0;
}
