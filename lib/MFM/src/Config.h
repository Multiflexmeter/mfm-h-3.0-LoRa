#ifndef _MFM_CONFIG_H_
#define _MFM_CONFIG_H_

#include <Sensors.h>

#include "SensorResultContext.h"

#ifndef MFM_MIDDLEWARE_CTX_TYPE
#define MFM_MIDDLEWARE_CTX_TYPE SensorResultContext<SENSOR_MAX_ENTRIES>
#endif

#ifndef MFM_MIDDLEWARE_LENGTH
#define MFM_MIDDLEWARE_LENGTH 10
#endif

#endif