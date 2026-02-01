#pragma once

#include <Arduino.h>

#include <cstdint>
#include <limits>

namespace app
{

    struct MeasurementResult
    {
        bool success;
        float value;
        uint8_t errorCode;
        const char *errorMessage;
        uint32_t timestamp;

        MeasurementResult() : success(false), value(NAN), errorCode(0),
                              errorMessage(""), timestamp(millis()) {}
    };

    class Sensor
    {
    public:
        virtual ~Sensor() = default;

        virtual bool initialize() = 0;
        virtual bool isAvailable() = 0;

        virtual MeasurementResult read() = 0;

    protected:
        uint32_t lastReadTime = 0;
    };

} // namespace app