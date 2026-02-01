#include "I2CManager.h"

namespace app
{
    I2CManager &I2CManager::getInstance()
    {
        static I2CManager instance;
        return instance;
    }

    bool I2CManager::initialize(uint8_t sda, uint8_t scl, uint32_t frequency)
    {
        if (mInitialized)
        {
            return true;
        }

        mSdaPin = sda;
        mSclPin = scl;

        Wire.begin(mSdaPin, mSclPin);
        Wire.setClock(frequency);

        mInitialized = true;

        Wire.beginTransmission(0x00);
        uint8_t error = Wire.endTransmission();
        return (error == 0);
    }

    bool I2CManager::isDeviceConnected(uint8_t address)
    {
        if (!mInitialized)
        {
            return false;
        }

        Wire.beginTransmission(address);
        uint8_t error = Wire.endTransmission();
        return (error == 0);
    }

} // namespace app