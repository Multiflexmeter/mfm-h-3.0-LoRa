#include "LoRaWanCommunication.h"

bool LoRaWanCommunication::Activate()
{

}

bool LoRaWanCommunication::Deactivate()
{
    // Use to save frame count.
}

bool LoRaWanCommunication::Send(uint8_t * array, uint16_t size)
{
    if (!(LMIC.opmode & OP_TXRXPEND)) {
        LMIC_setTxData2(1, array, size, 0);
    }
}