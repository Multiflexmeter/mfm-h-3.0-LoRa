#ifndef _SENSORS_H_
#define _SENSORS_H_

#ifdef ARDUINO
#include <Arduino.h>
#else
#include <cstring>
using namespace std;
#endif

#include <stdint.h>

#include "Config.h"
#include "SensorHandlerBase.h"
#include "SensorEntry.h"

/**
 * This class manages and interfaces sensors
 */
class Sensors {
public:
    // Sensors();
    // ~Sensors();
    unsigned short AddSensorType(SensorHandlerBase &handler);
    uint8_t AddSensor(unsigned short sensorTypeSignature, uint8_t * pinArrayStart, uint8_t pinArrayLength);
    void RemoveSensor(uint8_t id);
    bool IsActive(uint8_t id);
    void DisableSensor(uint8_t id);
    void ActivateSensor(uint8_t id);
    void ReadSensor(uint8_t id, uint8_t (&buffer)[SENSOR_READ_BUFFER_SIZE]);
    SensorHandlerBase *GetSensorType(unsigned short signature);

private:
    uint8_t nextSensorTypeId = 0;
    bool usedSensorIds[SENSOR_MAX_ENTRIES] = {false};
    SensorEntry sensors[SENSOR_MAX_ENTRIES] = {};
    SensorHandlerBase *sensorTypes[SENSOR_MAX_TYPES] = {nullptr};
    uint8_t NewSensorId();
    void FreeSensorId(uint8_t id);
    SensorEntry &GetSensor(uint8_t id);
};

#endif /* end of include guard: _SENSORS_H_ */
