#ifndef HDMI_CEC_HAL_FACTORY_H
#define HDMI_CEC_HAL_FACTORY_H

#include "HDMICecHal.h"

#include <memory>

class HDMICecHalFactory {
public:
    static std::unique_ptr<HDMICecHal> Create(bool aidl_hal_available);
};

#endif // HDMI_CEC_HAL_FACTORY_H
