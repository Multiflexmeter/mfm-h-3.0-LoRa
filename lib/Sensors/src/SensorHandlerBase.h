#ifndef _SENSOR_HANDLER_BASE_H_
#define _SENSOR_HANDLER_BASE_H_

#include <stdint.h>

#include "Config.h"

class SensorHandlerBase {
public:
    virtual ~SensorHandlerBase() {}
    virtual unsigned short GetSignature() = 0;
    virtual void ReadSensor(uint8_t pins[SENSOR_MAX_PINS], uint8_t (&buffer)[SENSOR_READ_BUFFER_SIZE]) = 0;
};

#endif /* end of include guard: _SENSOR_HANDLER_BASE_H_ */
