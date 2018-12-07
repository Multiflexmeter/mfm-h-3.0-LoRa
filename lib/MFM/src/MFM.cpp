
#include "MFM.h"

/*
 * Define static variables
 */
unsigned long MFM::interval_time = 10;
osjob_t MFM::init_job;
osjob_t MFM::interval_job;

/*
 * Define static functions
 */
void MFM::Setup() {
    Settings::Reset();

    // Register required EEPROM space
    MFM::LoadState(Settings::ReserveSpace(sizeof(MFMState)));
    setupSettings();

    // Register required middleware
    setupMiddleware(MFM::middleware);
}

void MFM::IntervalTrigger(osjob_t *job) {
    // Interval
    os_setTimedCallback(&interval_job, os_getTime() + sec2osticks(interval_time), &IntervalTrigger);
    // Enter lowpower
    EnterSleep();
}

void MFM::EnterSleep() {
    // This can be neater, but does the job for now.
    uint64_t remaining_time = interval_time;
    while (remaining_time >= 8) {
        LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
        remaining_time -= 8;
    }
    while (remaining_time >= 4) {
        LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);
        remaining_time -= 4;
    }
    while (remaining_time >= 2) {
        LowPower.powerDown(SLEEP_2S, ADC_OFF, BOD_OFF);
        remaining_time -= 2;
    }
    while (remaining_time >= 1) {
        LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);
        remaining_time -= 1;
    }
}

void MFM::Loop() {
    os_runloop_once();
}