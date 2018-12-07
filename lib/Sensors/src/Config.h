#ifndef _SENSORS_CONFIG_H_
#define _SENSORS_CONFIG_H_

typedef unsigned char byte;

#ifndef SENSOR_MAX_PINS
#define SENSOR_MAX_PINS 4
#endif

#ifndef SENSOR_MAX_TYPES
#define SENSOR_MAX_TYPES 10
#endif

#ifndef SENSOR_MAX_ENTRIES
#define SENSOR_MAX_ENTRIES 10
#endif

#ifndef SENSOR_READ_BUFFER_SIZE
#define SENSOR_READ_BUFFER_SIZE 32
#endif

#endif /* end of include guard: _SENSORS_CONFIG_H_ */
