#ifndef _MFM_COMMUNICATION_H_
#define _MFM_COMMUNICATION_H_

#include <stdint.h>

class CommunicationSAL {
    public:
    virtual bool Activate() = 0;
    virtual bool Deactivate() = 0;
    virtual void Send(uint8_t * data, uint16_t size) = 0;
    // Will perhaps need a 'addReceiveListener' function?
};

#endif