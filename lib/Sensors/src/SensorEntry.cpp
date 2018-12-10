#include "SensorEntry.h"

#include <string.h>

SensorEntry::SensorEntry(uint8_t id, bool active, uint16_t sensorType, uint8_t pins[SENSOR_MAX_PINS]) {
    this->id = id;
    this->active = active;
    this->sensorType = sensorType;
    memcpy(this->pins, pins, SENSOR_MAX_PINS);
}

SensorEntry::SensorEntry() {
    id = 0xFF;
    active = false;
    sensorType = 0xFFFF;
    pins = {};
}