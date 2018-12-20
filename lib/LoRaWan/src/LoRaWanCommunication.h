#ifndef _MFM_LORAWAN_COMMUNICATION_H_
#define _MFM_LORAWAN_COMMUNICATION_H_

#include <lmic.h>
#include <hal/hal.h>

#include <CommunicationSAL.h>

class LoRaWanCommunication : public CommunicationSAL {
private:
public:
    virtual bool Activate();
    virtual bool Deactivate();
    virtual void Send(uint8_t *data, uint16_t size);
}

#endif