#ifndef UNIT_TEST

#include <Arduino.h>

#include <lmic.h>
#include <hal/hal.h>

#include <MFM.h>
#include <LoRaWanCommunication.h>

/*
 * Define LMIC specific functions
 */

// lsb
static const u1_t PROGMEM APPEUI[8] = {0xFD, 0x7F, 0x00, 0xD0, 0x7E, 0xD5, 0xB3, 0x70};
void os_getArtEui (u1_t* buf) { memcpy_P(buf, APPEUI, 8); }
// lsb
static const u1_t PROGMEM DEVEUI[8] = {0x81, 0x12, 0x3A, 0x80, 0x1E, 0x91, 0x77, 0x00};
void os_getDevEui (u1_t* buf) { memcpy_P(buf, DEVEUI, 8); }
// as provided
static const u1_t PROGMEM APPKEY[16] = {0x48, 0x5A, 0x9B, 0xD3, 0x82, 0x38, 0x16, 0x86, 0x83, 0x0F, 0x68, 0xF6, 0xA0, 0xE3, 0x00, 0xEA};
void os_getDevKey (u1_t* buf) {  memcpy_P(buf, APPKEY, 16); }

const lmic_pinmap lmic_pins = {
    .nss = 10,
    .rxtx = LMIC_UNUSED_PIN,
    .rst = 9,
    .dio = {8, 7, 6},
};

LoRaWanCommunication communication;

osjob_t triggerJob;

void trigger(osjob_t * job) {
    MFM::StartCycle();
}

bool ScheduleTrigger(ReceiveContext_t & ctx) {
    os_setTimedCallback(&triggerJob, sec2osticks(MFM::GetInterval()), trigger);
    return true;
}

void SetupLora() {
    // LMIC init
    os_init();
    // Reset the MAC state. Session and pending data transfers will be discarded.
    LMIC_reset();
    LMIC_setClockError(MAX_CLOCK_ERROR * 1 / 100);

    // Disable link check validation
    LMIC_setLinkCheckMode(0);

    LMIC.dn2Dr = DR_SF9;

    // Set data rate and transmit power for uplink (note: txpow seems to be ignored by the library)
    LMIC_setDrTxpow(DR_SF10, 14);

    LMIC_startJoining();
}

void setup() {
    digitalWrite(2, HIGH);
    Serial.begin(9600);
    Serial.println("Starting system module");

    SetupLora();

    MFM::Setup(communication);
    communication.receiveChain.add(ScheduleTrigger);
    communication.receiveChain.add(MFM::EndCycle);
}

void setupMiddleware(MFMMiddleware& middleware) {
    // Setup your own middleware here, such as filters or modifiers.
}

void setupSettings() {

}

void loop() {
    MFM::Loop();
}

void onEvent(ev_t ev)
{
    if (ev == EV_TXCOMPLETE) {
        ReceiveContext_t ctx;
        communication.receiveChain.execute(ctx);
    }
}

#endif
