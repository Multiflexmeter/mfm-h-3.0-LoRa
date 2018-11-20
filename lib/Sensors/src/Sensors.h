#ifndef _SENSORS_H_
#define _SENSORS_H_

<<<<<<< HEAD
#include "Config.h"
#include "SensorHandlerBase.h"

/*
 *
 */
struct SensorType_t {
    byte id;
    SensorHandlerBase* handler;
};
=======
#ifndef SENSORS_PIN_AMOUNT
#define SENSORS_PIN_AMOUNT 4
#endif

typedef unsigned char byte;

/**
 * Signature of a sensor read function
 */
typedef int(*SensorReadFunction)(byte[SENSORS_PIN_AMOUNT]);

/**
 * Available sensor types
 */
enum SensorType { ULTRASONE, DS18B20 };
>>>>>>> 88f175dd0a0097879f88293e7e97c82b70fd0d98

/**
 * Struct for a sensor entry
 */
struct SensorEntry_t {
<<<<<<< HEAD
    byte id;
    bool disabled;
    SensorType_t sensorType;
    byte pins[SENSOR_MAX_PINS];
=======
    byte Id;
    bool Disabled;
    SensorType Type;
    byte Pins[SENSORS_PIN_AMOUNT];
>>>>>>> 88f175dd0a0097879f88293e7e97c82b70fd0d98
};

/**
 * This class manages and interfaces sensors
 */
class Sensors {
public:
<<<<<<< HEAD
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
=======
    void AddSensorType(SensorType type, SensorReadFunction readFunction);
    void AddSensor(SensorType type, byte pins[SENSORS_PIN_AMOUNT]);
    void RemoveSensor(byte Id);
    void DisableSensor(byte Id);
    int ReadSensor(byte Id);

private:
>>>>>>> 88f175dd0a0097879f88293e7e97c82b70fd0d98
};

#endif /* end of include guard: _SENSORS_H_ */
