#ifndef UNIT_TEST

#include <Arduino.h>
#include <lmic.h>
#include <hal/hal.h>

#include <MFM.h>
#include <LoRaWan.h>
#include <LoRaWanCommunication.h>



/*
 * Define LMIC specific functions
 */

// lsb
static const u1_t PROGMEM APPEUI[8]={ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
void os_getArtEui (u1_t* buf) { memcpy_P(buf, APPEUI, 8); }
// lsb
static const u1_t PROGMEM DEVEUI[8]={ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
void os_getDevEui (u1_t* buf) { memcpy_P(buf, DEVEUI, 8); }
// as provided
static const u1_t PROGMEM APPKEY[16] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
void os_getDevKey (u1_t* buf) {  memcpy_P(buf, APPKEY, 16); }

const lmic_pinmap lmic_pins = {
    .nss = 10,
    .rxtx = LMIC_UNUSED_PIN,
    .rst = 9,
    .dio = {11, 12, 13},
};


LoRaWanCommunication communication;
MFM_t MFMContext;

bool FinishCycle(uint8_t & context)
{
    MFM::LowPowerSleep(MFMContext);
    MFMContext.ready = true;
    return true;
}

void setup() {
    Serial.begin(9600);
    Serial.println("Starting system module");

    LoRaWan::Setup(MFMContext);
    LoRaWan::AddListener(FinishCycle);

    MFMContext = MFM::Setup(&communication);
}

void setupMiddleware(MiddlewareSystem<SensorResultContext<SENSOR_MAX_ENTRIES>, 10> &middleware)
{
    // Setup your own middleware here, such as filters or modifiers.
}

void setupSettings() {
    // Reserve your own EEPROM space here
}

void loop() {
    MFM::Loop(MFMContext);
}

#endif
