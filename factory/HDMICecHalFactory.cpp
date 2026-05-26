#include "HDMICecHalFactory.h"

#include "AidlHAL.h"
#include "LegacyHAL.h"

std::unique_ptr<HDMICecHal> HDMICecHalFactory::Create(bool aidl_hal_available) {
    if (aidl_hal_available) {
        return std::make_unique<AidlHAL>();
    }

    return std::make_unique<LegacyHAL>();
}
