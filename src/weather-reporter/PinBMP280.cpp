#include <Arduino.h>

#include "PinBMP280.h"

namespace app {

// -------------------------------------------------------

PinBMP280::PinBMP280(uint8_t sda, uint8_t scl)
    : mSdaPin(sda),
      mSclPin(scl),
      mAvailable(false),
      temperature(NAN),
      pressure(NAN) {
}

bool PinBMP280::begin(uint8_t address) {

    Wire.begin(mSdaPin, mSclPin);
    mAvailable = mSensor.begin(address);

    return mAvailable;
}

void PinBMP280::read() {

    readTemperature();
    readPressure();
}

float PinBMP280::readTemperature() {
    temperature = mSensor.readTemperature();
    return temperature;
}

float PinBMP280::readPressure() {
    pressure = mSensor.readPressure();
    return pressure;
}

bool PinBMP280::available() const {
    return mAvailable;
}

} // namespace fm