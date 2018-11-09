#include <Arduino.h>
#include <MFM.h>

/*
 * Define LMIC specific functions
 */

// lsb
static const u1_t PROGMEM APPEUI[8]={ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
void os_getArtEui (u1_t* buf) { memcpy_P(buf, APPEUI, 8); }
// lsb
static const u1_t PROGMEM DEVEUI[8]={ 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
void os_getDevEui (u1_t* buf) { memcpy_P(buf, DEVEUI, 8); }
// as provided
static const u1_t PROGMEM APPKEY[16] = { ***REMOVED*** };
void os_getDevKey (u1_t* buf) {  memcpy_P(buf, APPKEY, 16); }

const lmic_pinmap lmic_pins = {
    .nss = 6,
    .rxtx = LMIC_UNUSED_PIN,
    .rst = 5,
    .dio = {2, 3, 4},
};

void setup() {
    Serial.begin(9600);
    Serial.println("Starting system module");

    MFM::Setup(15);
}

void loop() {
    MFM::Loop();
}
