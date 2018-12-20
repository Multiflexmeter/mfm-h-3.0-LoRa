#ifndef UNIT_TEST

#include <Arduino.h>
#include <hal/hal.h>
#include <lmic.h>
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

bool FinishCycle(uint8_t & context)
{
    MFM::LowPowerSleep();
    MFM::Ready();
    return true;
}

void setup() {
    Serial.begin(9600);
    Serial.println("Starting system module");

    LoRaWan::Setup();
    LoRaWan::AddListener(FinishCycle);

    MFM::Setup(&communication);
}

void setupMiddleware(MFMMiddleware& middleware) {
    // Setup your own middleware here, such as filters or modifiers.
}

void setupSettings() {
    // Reserve your own EEPROM space here
}

void loop() {
    MFM::Loop();
}

#endif
