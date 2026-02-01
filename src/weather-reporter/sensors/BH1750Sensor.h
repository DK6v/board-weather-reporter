#pragma once

#include <Arduino.h>
#include <BH1750.h>

#include "I2CSensor.h"

namespace app {

class BH1750Sensor : public I2CSensor
{
public:
    BH1750Sensor(uint8_t sda, uint8_t scl, uint8_t address = 0x23);
    ~BH1750Sensor() = default;

    bool initialize() override;
    bool isAvailable() override;

    MeasurementResult read() override;

    float getLightLevel() const { return lightLevel; }

private:
    bool mSensorInitialized;
    BH1750 mSensor;
    float lightLevel;
};

} // namespace app