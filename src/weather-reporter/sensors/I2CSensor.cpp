#include "I2CSensor.h"

namespace app
{
    I2CSensor::I2CSensor(uint8_t sda, uint8_t scl, uint8_t address)
        : mSdaPin(sda), mSclPin(scl), mAddress(address) {}

    bool I2CSensor::initializeI2C(uint32_t frequency)
    {
        if (mI2CInitialized)
        {
            return true;
        }

        mI2CInitialized = I2CManager::getInstance().initialize(mSdaPin, mSclPin, frequency);
        return mI2CInitialized;
    }

    bool I2CSensor::isI2CDeviceConnected() const
    {
        return I2CManager::getInstance().isDeviceConnected(mAddress);
    }

} // namespace app