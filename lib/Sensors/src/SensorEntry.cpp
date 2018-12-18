#include "SensorEntry.h"

#include <string.h>

SensorEntry::SensorEntry(uint8_t id, bool active, uint16_t sensorType,
        uint8_t * pinArrayStart, uint8_t pinArrayLength) {
    this->id = id;
    this->active = active;
    this->sensorType = sensorType;
    memcpy(this->pins, pinArrayStart, pinArrayLength);
}

SensorEntry::SensorEntry(): pins{} {
    id = 0xFF;
    active = false;
    sensorType = 0xFFFF;
}