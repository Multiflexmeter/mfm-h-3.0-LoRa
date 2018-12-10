#ifndef _SENSORS_H_
#define _SENSORS_H_

#ifdef __COMPILE_NATIVE_
#include <cstring>
using namespace std;
#else
#include <Arduino.h>
#endif

#include <stdint.h>

#include "Config.h"
#include "SensorHandlerBase.h"

/**
 * Struct for a sensor entry
 */
struct SensorEntry_t {
    uint8_t id;
    bool active;
    unsigned short sensorType;
    uint8_t pins[SENSOR_MAX_PINS];
};

/**
 * This class manages and interfaces sensors
 */
class Sensors {
public:
    // Sensors();
    unsigned short AddSensorType(SensorHandlerBase &handler);
    uint8_t AddSensor(unsigned short sensorTypeSignature, uint8_t *pinArray, int pinArraySize);
    void RemoveSensor(uint8_t id);
    bool IsActive(uint8_t id);
    void DisableSensor(uint8_t id);
    void ActivateSensor(uint8_t id);
    void ReadSensor(uint8_t id, uint8_t (&buffer)[SENSOR_READ_BUFFER_SIZE]);
    bool GetSensorType(unsigned short signature, SensorHandlerBase & returnHandler);

  private:
    uint8_t nextSensorTypeId = 0;
    bool usedSensorIds[SENSOR_MAX_ENTRIES] = {false};
    SensorEntry_t sensors[SENSOR_MAX_ENTRIES];
    SensorHandlerBase *sensorTypes[SENSOR_MAX_TYPES] = {0};
    uint8_t NewSensorId();
    void FreeSensorId(uint8_t id);
    SensorEntry_t &GetSensor(uint8_t id);
};

#endif /* end of include guard: _SENSORS_H_ */
