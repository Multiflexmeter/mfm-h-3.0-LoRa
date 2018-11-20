#ifndef _SENSORS_H_
#define _SENSORS_H_

#include "Config.h"
#include "SensorHandlerBase.h"

/*
 *
 */
struct SensorType_t {
    byte id;
    SensorHandlerBase* handler;
};

/**
 * Struct for a sensor entry
 */
struct SensorEntry_t {
    byte id;
    bool disabled;
    SensorType_t sensorType;
    byte pins[SENSOR_MAX_PINS];
};

/**
 * This class manages and interfaces sensors
 */
class Sensors {
public:
    byte AddSensorType(SensorHandlerBase* handler);
    byte AddSensor(byte sensorTypeId, byte pins[SENSOR_MAX_PINS]);
    void RemoveSensor(byte Id);
    void DisableSensor(byte Id);
    void ReadSensor(byte Id, byte buffer[]);
private:
    byte nextSensorTypeId = 0;
    SensorType_t sensorTypes[];
    byte nextSensorEntryId = 0;
    SensorEntry_t sensors[];
};

#endif /* end of include guard: _SENSORS_H_ */
