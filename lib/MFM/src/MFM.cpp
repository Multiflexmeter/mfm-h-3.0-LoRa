
#include "MFM.h"

/*
 * Define static functions
 */
MFM_t MFM::Setup(CommunicationSAL *communication)
{
    // Initialize context
    MFM_t ctx;
    // Variables
    ctx.communication = communication;
    ctx.ready = true;

    // Space reservation
    Settings::Reset();

    // Register required EEPROM space
    MFM::LoadState(Settings::ReserveSpace(sizeof(MFMState)), ctx);
    setupSettings();
    
    // Register required middleware
    setupMiddleware(ctx.middleware);
}

void MFM::LoadState(int address, MFM_t & ctx) {
    EEPROM.readBlock(address, ctx.state);
}

bool MFM::SendData(SensorResultContext<SENSOR_MAX_ENTRIES>& data, MFM_t & ctx) {
    ctx.communication->Activate();
    // INFO: For other context objects, make sure you convert them with the correct converter
    // SensorResultContextConverter converter;
    uint8_t dataBytes[] = {0};
    ctx.communication->Send(dataBytes, 1);
    return true;
}

bool MFM::LowPowerSleep(MFM_t & ctx) {
    // Enter LowPower mode (Multiple of 8)
    for (int r = ctx.state.triggerInterval; r > 0; r -= 8) {
        LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
    }
    return true;
}

void MFM::TriggerChain(SensorResultContext<SENSOR_MAX_ENTRIES> &context, MFM_t & ctx) {
    ctx.middleware.execute(context);
    SendData(context, ctx);
}

void MFM::Loop(MFM_t & ctx) {
    if (ctx.ready) {
        SensorResultContext<SENSOR_MAX_ENTRIES> context;
        TriggerChain(context, ctx);
    }
}