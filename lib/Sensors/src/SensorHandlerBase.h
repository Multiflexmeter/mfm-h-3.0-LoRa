#ifndef _SENSOR_HANDLER_BASE_H_
#define _SENSOR_HANDLER_BASE_H_

#include "Config.h"


class SensorHandlerBase {
public:
    virtual ~SensorHandlerBase() {}
    virtual int GetBufferSize() = 0;
    virtual void ReadSensor(byte buffer[]) = 0;
};

#endif /* end of include guard: _SENSOR_HANDLER_BASE_H_ */
