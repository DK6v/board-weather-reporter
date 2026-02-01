#pragma once

#include "Sensor.h"
#include "I2CManager.h"

namespace app
{

    class I2CSensor : public Sensor
    {
    public:
        I2CSensor(uint8_t sda, uint8_t scl, uint8_t address);
        virtual ~I2CSensor() = default;

        bool initializeI2C(uint32_t frequency = 100000);
        bool isI2CDeviceConnected() const;

        uint8_t getI2CAddress() const { return mAddress; }

    protected:
        uint8_t mSdaPin;
        uint8_t mSclPin;
        uint8_t mAddress;
        bool mI2CInitialized = false;
    };

} // namespace app