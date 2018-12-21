#ifndef _MFM_VECTOR_CONTEXT_H_
#define _MFM_VECTOR_CONTEXT_H_

#include <stdint.h>

#include "Sensors.h"

class SensorResult {
public:
    uint16_t sensorType = 0xFFFF;
    uint8_t sensorId = 0xFF;
    uint8_t result[SENSOR_READ_BUFFER_SIZE] = {0};
};

// T is the amount of active sensors
template<uint8_t T>
class SensorResultContext {
public:
    uint8_t index = 0;
    SensorResult results[T];
};

#endif