
#include "LoRaWanCommunication.h"

bool LoRaWanCommunication::Activate()
{
    return true;
}

bool LoRaWanCommunication::Deactivate()
{
    return true;
}

void LoRaWanCommunication::Send(uint8_t * data, uint16_t length) {
    if (!(LMIC.opmode & OP_TXRXPEND)) {
        LMIC_setTxData2(1, data, length, 0);
    }
}