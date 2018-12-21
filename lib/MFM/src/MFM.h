#ifndef _MFM_H_
#define _MFM_H_

#include <lmic.h>
#include <hal/hal.h>
#include <LowPower.h>
#include <EEPROMex.h>
#include <EEPROMVar.h>

#include <Settings.h>
#include <Sensors.h>
#include <MiddlewareSystem.h>
#include <CommunicationSAL.h>

#include "Config.h"
#include "MFMState.h"
#include "SensorResultContext.h"

typedef MiddlewareSystem<MFM_MIDDLEWARE_CTX_TYPE, MFM_MIDDLEWARE_LENGTH> MFMMiddleware;

extern void setupMiddleware(MFMMiddleware& middleware);
extern void setupSettings();

class MFM {
public:
    static void Setup(CommunicationSAL & communication);
    static void StartCycle();
    static void Loop();
    static void DisableHardwarePower();
    static void EnableHardwarePower();
    static bool EndCycle(ReceiveContext_t & data);
    static int GetInterval();
private: 
    static CommunicationSAL * communication;
    static MFMState state;
    static MFMMiddleware middleware;
    static void LoadState(int address);
    static bool SendData(SensorResultContext<SENSOR_MAX_ENTRIES>& context);
    static bool ReadSensors(SensorResultContext<SENSOR_MAX_ENTRIES> &context);
};

#endif /* end of include guard: _MFM_H_ */
