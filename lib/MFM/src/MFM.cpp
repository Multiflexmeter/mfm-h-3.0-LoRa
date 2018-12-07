
#include "MFM.h"

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
    EEPROMVar<MFMState> stateVar(MFM::state);
    stateVar.restore();
}
