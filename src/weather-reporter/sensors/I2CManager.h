#pragma once

#include <Arduino.h>
#include <Wire.h>

namespace app
{

    class I2CManager
    {
    public:
        static I2CManager &getInstance();

        bool initialize(uint8_t sda, uint8_t scl, uint32_t frequency = 100000);
        bool isDeviceConnected(uint8_t address);
        bool checkI2C() const { return mInitialized; }

    private:
        I2CManager() = default;
        ~I2CManager() = default;

        bool mInitialized = false;
        uint8_t mSdaPin = 0;
        uint8_t mSclPin = 0;
    };

} // namespace app