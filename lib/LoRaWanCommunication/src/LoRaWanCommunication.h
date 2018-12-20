#ifndef _MFM_LORAWAN_COMMUNICATION_H_
#define _MFM_LORAWAN_COMMUNICATION_H_

#include <lmic.h>
#include <hal/hal.h>

#include "Communication.h"

class LoRaWanCommunication : public CommunicationSAL
{
public:
    virtual bool Activate();
    virtual bool Deactivate();
    virtual bool Send(uint8_t *data, uint16_t size);
};

#endif