#ifndef LEGACY_HAL_H
#define LEGACY_HAL_H

#include "HDMICecHal.h"

class LegacyHAL : public HDMICecHal {
public:
    bool HdmiCecOpen() override;
};

#endif // LEGACY_HAL_H
