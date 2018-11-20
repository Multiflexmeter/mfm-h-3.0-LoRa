#ifndef _SENSOR_HANDLER_BASE_H_
#define _SENSOR_HANDLER_BASE_H_

#include "Config.h"


class SensorHandlerBase {
public:
    virtual ~SensorHandlerBase() {}
    virtual void ReadSensor(byte (&buffer)[SENSOR_READ_BUFFER_SIZE]) = 0;
};

#endif /* end of include guard: _SENSOR_HANDLER_BASE_H_ */
