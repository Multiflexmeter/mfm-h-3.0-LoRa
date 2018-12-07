#include "Sensors.h"
#include <stdio.h>

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
    this->GetSensor(id).active = false;
}

void Sensors::ActivateSensor(byte id) {
    if (this->usedSensorIds[id] == true) {
        this->GetSensor(id).active = true;
    }
}

void Sensors::ReadSensor(byte id, byte (&buffer)[SENSOR_READ_BUFFER_SIZE]) {
    SensorEntry_t &sensor = this->GetSensor(id);
    if (!sensor.active) return;

    SensorHandlerBase &handler = this->GetSensorType(sensor.sensorType);
    handler.ReadSensor(sensor.pins, buffer);
}

byte Sensors::NewSensorId() {
    byte i = 0;
    do {
        if (this->usedSensorIds[i] == false) {
            this->usedSensorIds[i] = true;
            return i;
        }
    } while (++i < SENSOR_MAX_ENTRIES);
    return 0xFF;
}

void Sensors::FreeSensorId(byte id) {
    this->usedSensorIds[id] = false;
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
