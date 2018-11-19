#ifndef _SENSORS_H_
#define _SENSORS_H_

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

/**
 * Struct for a sensor entry
 */
struct SensorEntry_t {
    byte Id;
    bool Disabled;
    SensorType Type;
    byte Pins[SENSORS_PIN_AMOUNT];
};

/**
 * This class manages and interfaces sensors
 */
class Sensors {
public:
    void AddSensorType(SensorType type, SensorReadFunction readFunction);
    void AddSensor(SensorType type, byte pins[SENSORS_PIN_AMOUNT]);
    void RemoveSensor(byte Id);
    void DisableSensor(byte Id);
    int ReadSensor(byte Id);

private:
};

#endif /* end of include guard: _SENSORS_H_ */
