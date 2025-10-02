#pragma once

#include <Arduino.h>

#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#include "PinBase.h"

namespace app {

// -------------------------------------------------------

class PinBMP280 {
public:
    PinBMP280(uint8_t sda, uint8_t scl);
    ~PinBMP280() = default;

    bool begin(uint8_t address = 0x76);
    void read();

    float readTemperature();
    float readPressure(void);

    bool available() const;

protected:
    uint8_t mSdaPin;
    uint8_t mSclPin;

    bool mAvailable;
    Adafruit_BMP280 mSensor;

public:
    float temperature;
    float pressure;
    float humidity;
};

} // namespace fm