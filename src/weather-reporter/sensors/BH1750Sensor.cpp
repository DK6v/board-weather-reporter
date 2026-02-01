#include <cmath>

#include "BH1750Sensor.h"

namespace app {

BH1750Sensor::BH1750Sensor(uint8_t sda, uint8_t scl, uint8_t address)
    : I2CSensor(sda, scl, address),
      mSensorInitialized(false),
      lightLevel(NAN) {}

bool BH1750Sensor::initialize() {

    if (mSensorInitialized) {
        return true;
    }

    if (!initializeI2C()) {
        return false;
    }

    if (!isI2CDeviceConnected()) {
        return false;
    }

    mSensorInitialized = mSensor.begin(BH1750::CONTINUOUS_HIGH_RES_MODE, getI2CAddress());
    return mSensorInitialized;
}

bool BH1750Sensor::isAvailable() {
    return mSensorInitialized && mSensor.measurementReady();
}

MeasurementResult BH1750Sensor::read() {

    MeasurementResult result;
    result.timestamp = millis();

    if (!mSensorInitialized && !initialize()) {
        result.errorCode = 1;
        result.errorMessage = "Sensor not initialized";
        return result;
    }

    for (uint8_t wait = 20; wait != 0; --wait, delay(50)) {
        if (isAvailable()) {
            float rawValue = mSensor.readLightLevel();

            if (rawValue >= 0.0f) {
                lightLevel = rawValue;
                result.success = true;
                result.value = lightLevel;
                return result;
            } else {
                result.errorCode = 3;
                break;
            }
        }
    }

    result.errorCode = 2;
    lightLevel = NAN;
    return result;
}

} // namespace app