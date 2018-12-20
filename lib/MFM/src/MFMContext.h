#ifndef _MFM_CONTEXT_H_
#define _MFM_CONTEXT_H_

#include <Communication.h>
#include <MiddlewareSystem.h>

#include "MFMState.h"
#include "SensorResultContext.h"

struct MFM_t
{
    bool ready;
    CommunicationSAL *communication;
    MFMState state;
    MiddlewareSystem<SensorResultContext<SENSOR_MAX_ENTRIES>, 10> middleware;
};

#endif