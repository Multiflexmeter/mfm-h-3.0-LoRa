#ifndef _SENSORS_H_
#define _SENSORS_H_

#include "Config.h"
#include "SensorHandlerBase.h"

/**
 * Struct for a sensor entry
 */
struct SensorEntry_t {
    byte id;
    bool active;
    unsigned short sensorType;
    byte (&pins)[SENSOR_MAX_PINS];
};

/**
 * This class manages and interfaces sensors
 */
class Sensors {
public:
    Sensors();
    unsigned short AddSensorType(SensorHandlerBase &handler);
    byte AddSensor(byte sensorTypeId, byte (&pins)[SENSOR_MAX_PINS]);
    void RemoveSensor(byte id);
    bool IsActive(byte id);
    void DisableSensor(byte id);
    void ActivateSensor(byte id);
    void ReadSensor(byte id, byte (&buffer)[SENSOR_READ_BUFFER_SIZE]);
    SensorHandlerBase &GetSensorType(unsigned short signature);
    SensorEntry_t &GetSensor(byte id);

  private:
    byte nextSensorTypeId = 0;
    byte nextSensorEntryId[SENSOR_MAX_ENTRIES];
    SensorEntry_t *sensors[SENSOR_MAX_ENTRIES] = {0};
    SensorHandlerBase *sensorTypes[SENSOR_MAX_TYPES] = {0};
    byte NewSensorId();
    void FreeSensorId(byte id);
};

#endif /* end of include guard: _SENSORS_H_ */