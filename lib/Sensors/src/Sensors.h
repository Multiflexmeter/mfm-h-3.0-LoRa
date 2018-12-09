#ifndef _SENSORS_H_
#define _SENSORS_H_

#ifdef __COMPILE_NATIVE_
#include <cstring>
using namespace std;
#else
#include <Arduino.h>
#endif

#include "Config.h"
#include "SensorHandlerBase.h"

typedef unsigned char byte;

/**
 * Struct for a sensor entry
 */
struct SensorEntry_t {
    byte id;
    bool active;
    unsigned short sensorType;
    byte pins[SENSOR_MAX_PINS];
};

/**
 * This class manages and interfaces sensors
 */
class Sensors {
public:
    // Sensors();
    unsigned short AddSensorType(SensorHandlerBase &handler);
    byte AddSensor(unsigned short sensorTypeSignature, byte *pinArray, int pinArraySize);
    void RemoveSensor(byte id);
    bool IsActive(byte id);
    void DisableSensor(byte id);
    void ActivateSensor(byte id);
    void ReadSensor(byte id, byte (&buffer)[SENSOR_READ_BUFFER_SIZE]);
    bool GetSensorType(unsigned short signature, SensorHandlerBase & returnHandler);

  private:
    byte nextSensorTypeId = 0;
    bool usedSensorIds[SENSOR_MAX_ENTRIES] = {false};
    SensorEntry_t sensors[SENSOR_MAX_ENTRIES];
    SensorHandlerBase *sensorTypes[SENSOR_MAX_TYPES] = {0};
    byte NewSensorId();
    void FreeSensorId(byte id);
    SensorEntry_t &GetSensor(byte id);
};

#endif /* end of include guard: _SENSORS_H_ */
