#ifndef AIDL_HAL_H
#define AIDL_HAL_H

#include "HDMICecHal.h"

class AidlHAL : public HDMICecHal {
public:
    bool HdmiCecOpen() override;
};

#endif // AIDL_HAL_H
