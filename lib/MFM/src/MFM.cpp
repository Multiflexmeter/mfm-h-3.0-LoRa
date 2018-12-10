
#include "MFM.h"

MFMState MFM::state;

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

void MFM::LoadState(int address) {
    EEPROM.readBlock(address, MFM::state);
}
