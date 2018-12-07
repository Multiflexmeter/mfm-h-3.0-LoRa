#include "Sensors.h"
#include <stdio.h>

Sensors::Sensors() {
    // // Populate available entry and type ids
    for (byte i = 0; i < SENSOR_MAX_ENTRIES; i++) {
        this->nextSensorEntryId[i] = i;
    }
}

unsigned short Sensors::AddSensorType(SensorHandlerBase &handler) {
    byte index = this->nextSensorTypeId++;
    Sensors::sensorTypes[index] = &handler;
    return handler.GetSignature();
}

byte Sensors::AddSensor(unsigned short sensorTypeSignature, byte *pinArray, int pinArraySize)
{
    // Index is also the ID
    byte index = this->NewSensorId();

    // If there is no space return 
    if (index == 0xFF) return 0xFF;

    SensorEntry_t newSensorEntry{
        index,
        true,
        sensorTypeSignature,
        {}
    };
    memcpy(newSensorEntry.pins, pinArray, pinArraySize);
    this->sensors[index] = newSensorEntry;
    return index;
}

void Sensors::RemoveSensor(byte id) {
    this->DisableSensor(id);
    this->FreeSensorId(id);
}

bool Sensors::IsActive(byte id) {
    return this->GetSensor(id).active;
}

void Sensors::DisableSensor(byte id) {
    (this->GetSensor(id).active) = false;
}

void Sensors::ActivateSensor(byte id) {
    (this->GetSensor(id).active) = true;
}

void Sensors::ReadSensor(byte id, byte (&buffer)[SENSOR_READ_BUFFER_SIZE]) {
    SensorEntry_t &sensor = this->GetSensor(id);
    if (!sensor.active) return;

    SensorHandlerBase &handler = this->GetSensorType(sensor.sensorType);
    handler.ReadSensor(sensor.pins, buffer);
}

byte Sensors::NewSensorId() {
    for (byte i = 0; i < SENSOR_MAX_ENTRIES; i++) {
        byte id = this->nextSensorEntryId[i];
        if (id >= 0) {
            // Remove from array
            this->nextSensorEntryId[i] = 0xFF;
            // Return
            return id;
        }
    }
    return 0xFF;
}

void Sensors::FreeSensorId(byte id) {
    this->nextSensorEntryId[id] = id;
}

SensorHandlerBase &Sensors::GetSensorType(unsigned short signature) {
    for (byte i = 0; i < SENSOR_MAX_TYPES; i++) {
        // Skip null references
        if (this->sensorTypes[i] == 0x00) continue;
        // De-reference pointer
        SensorHandlerBase *type = this->sensorTypes[i];
        if (type->GetSignature() == signature) {
            return *type;
        }
    }
}

SensorEntry_t &Sensors::GetSensor(byte id) {
    return this->sensors[id];
}
