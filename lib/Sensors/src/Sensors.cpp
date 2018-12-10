#include "Sensors.h"
#include <stdio.h>

unsigned short Sensors::AddSensorType(SensorHandlerBase &handler) {
    uint8_t index = this->nextSensorTypeId++;
    Sensors::sensorTypes[index] = &handler;
    return handler.GetSignature();
}

uint8_t Sensors::AddSensor(unsigned short sensorTypeSignature, uint8_t *pinArray, int pinArraySize)
{
    // Index is also the ID
    uint8_t index = this->NewSensorId();

    // If there is no space return 
    if (index == 0xFF) return 0xFF;

    SensorEntry_t newSensorEntry = {
        index,
        true,
        sensorTypeSignature,
        {}
    };
    memcpy(newSensorEntry.pins, pinArray, pinArraySize);
    this->sensors[index] = newSensorEntry;
    return index;
}

void Sensors::RemoveSensor(uint8_t id) {
    this->DisableSensor(id);
    this->FreeSensorId(id);
}

bool Sensors::IsActive(uint8_t id) {
    return this->GetSensor(id).active;
}

void Sensors::DisableSensor(uint8_t id) {
    this->GetSensor(id).active = false;
}

void Sensors::ActivateSensor(uint8_t id) {
    if (this->usedSensorIds[id] == true) {
        this->GetSensor(id).active = true;
    }
}

void Sensors::ReadSensor(uint8_t id, uint8_t (&buffer)[SENSOR_READ_BUFFER_SIZE]) {
    SensorEntry_t &sensor = this->GetSensor(id);
    if (!sensor.active) return;

    SensorHandlerBase * handler = this->GetSensorType(sensor.sensorType);
    if (handler == NULL){
        return;
    }
    handler->ReadSensor(sensor.pins, buffer);
}

uint8_t Sensors::NewSensorId() {
    uint8_t i = 0;
    do {
        if (this->usedSensorIds[i] == false) {
            this->usedSensorIds[i] = true;
            return i;
        }
    } while (++i < SENSOR_MAX_ENTRIES);
    return 0xFF;
}

void Sensors::FreeSensorId(uint8_t id) {
    this->usedSensorIds[id] = false;
}

SensorHandlerBase * Sensors::GetSensorType(unsigned short signature){
    for (uint8_t i = 0; i < SENSOR_MAX_TYPES; i++) {
        // Skip null references
        if (this->sensorTypes[i] == 0x00) continue;
        // De-reference pointer
        SensorHandlerBase *type = this->sensorTypes[i];
        if (type->GetSignature() == signature) {
            printf("found!");
            return type;
        }
    }
    return nullptr;
}

SensorEntry_t &Sensors::GetSensor(uint8_t id) {
    return this->sensors[id];
}
