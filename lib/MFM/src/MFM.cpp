
#include "MFM.h"

MFMState MFM::state;
MFMMiddleware MFM::middleware;
CommunicationSAL * MFM::communication = NULL;

/*
 * Define static functions
 */
void MFM::Setup(CommunicationSAL & communication) {
    // Variables
    MFM::communication = &communication;

    // Space reservation
    Settings::Reset();

    // Register required EEPROM space
    MFM::LoadState(Settings::ReserveSpace(sizeof(MFMState)));
    setupSettings();
    
    // Register required middleware
    setupMiddleware(MFM::middleware);
    middleware.add(&(MFM::SendData));
}

bool MFM::ReadSensors(SensorResultContext<SENSOR_MAX_ENTRIES> &context) {

    return true;
}

void MFM::Loop() {
    
}

void MFM::StartCycle()
{
    SensorResultContext<SENSOR_MAX_ENTRIES> ctx;
    middleware.execute(ctx);
}

void MFM::LoadState(int address)
{
    EEPROM.readBlock(address, MFM::state);
}

bool MFM::SendData(SensorResultContext<SENSOR_MAX_ENTRIES>& context) {
    communication->Activate();
    // TODO: Convert context to byte array
    uint8_t dataBytes[] = {0};
    communication->Send(dataBytes, 1);
    return true;
}

void MFM::DisableHardwarePower()
{

}

void MFM::EnableHardwarePower()
{

}

bool MFM::EndCycle(ReceiveContext_t &data)
{
    DisableHardwarePower();
    return true;
}

int MFM::GetInterval() {
    return state.triggerInterval;
}