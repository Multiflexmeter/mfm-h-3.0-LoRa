#include "LoRaWan.h"

void LoRaWan::Setup() {
    os_init();
    LMIC_reset();

    // TTN Receive frequency
    LMIC.dn2Freq = DR_SF9;

    // Setup frequency
    LMIC_setupChannel(0, 868100000, DR_RANGE_MAP(DR_SF12, DR_SF7), BAND_CENTI);  // g-band
    LMIC_setupChannel(1, 868300000, DR_RANGE_MAP(DR_SF12, DR_SF7B), BAND_CENTI); // g-band
    LMIC_setupChannel(2, 868500000, DR_RANGE_MAP(DR_SF12, DR_SF7), BAND_CENTI);  // g-band
    LMIC_setupChannel(3, 867100000, DR_RANGE_MAP(DR_SF12, DR_SF7), BAND_CENTI);  // g-band
    LMIC_setupChannel(4, 867300000, DR_RANGE_MAP(DR_SF12, DR_SF7), BAND_CENTI);  // g-band
    LMIC_setupChannel(5, 867500000, DR_RANGE_MAP(DR_SF12, DR_SF7), BAND_CENTI);  // g-band
    LMIC_setupChannel(6, 867700000, DR_RANGE_MAP(DR_SF12, DR_SF7), BAND_CENTI);  // g-band
    LMIC_setupChannel(7, 867900000, DR_RANGE_MAP(DR_SF12, DR_SF7), BAND_CENTI);  // g-band
    LMIC_setupChannel(8, 868800000, DR_RANGE_MAP(DR_FSK, DR_FSK), BAND_MILLI);   // g2-band
}

void LoRaWan::Loop() {
    os_runloop_once();
}

void LoRaWan::Middleware(SensorResultContext<SENSOR_MAX_ENTRIES> &context) {
    // WARN:    Possible fail, because we will stay be in LowPower when this triggers.
    //          It should be scheduled forward by default.
    os_setTimedCallback(&triggerJob, sec2osticks(MFM::GetTriggerInterval()), TriggerJob);
}

void LoRaWan::TriggerJob(osjob_t *job)
{
    SensorResultContext<SENSOR_MAX_ENTRIES> context;
    MFM::TriggerChain(context);
}

// LMIC events
void onEvent(ev_t ev)
{
    switch(ev) {
        case EV_TXCOMPLETE:
            // Fire receive chain
            break;
    }
}
