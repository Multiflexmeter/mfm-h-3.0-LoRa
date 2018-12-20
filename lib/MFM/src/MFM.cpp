
#include "MFM.h"

MFMState MFM::state;

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

void MFM::LoadState(int address) {
    EEPROM.readBlock(address, MFM::state);
}

bool MFM::SendData(SensorResultContext<SENSOR_MAX_ENTRIES>& context) {
    communication->Activate();
    // TODO: Convert context to byte array
    uint8_t dataBytes[] = {0};
    communication->Send(dataBytes, 1);
}