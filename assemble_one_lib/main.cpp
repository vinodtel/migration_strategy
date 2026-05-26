#include "HDMICecHal.h"

#include <cstdlib>
#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<HDMICecHal> hal = std::make_unique<HDMICecHal>();

    if (!hal->HdmiCecOpen()) {
        std::cerr << "Failed to open HDMI CEC HAL" << std::endl;
        return 1;
    }

    return 0;
}
