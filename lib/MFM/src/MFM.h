#ifndef _MFM_H_
#define _MFM_H_

#include <LowPower.h>
#include <EEPROMex.h>
#include <EEPROMVar.h>

#include <Settings.h>
#include <Sensors.h>
#include <MiddlewareSystem.h>
#include <Communication.h>
#include <DataConverter.h>

#include "Config.h"
#include "MFMState.h"
#include "SensorResultContext.h"
#include "SensorResultContextConverter.cpp"

typedef MiddlewareSystem<MFM_MIDDLEWARE_CTX_TYPE, MFM_MIDDLEWARE_LENGTH> MFMMiddleware;

extern void setupMiddleware(MFMMiddleware& middleware);
extern void setupSettings();

class MFM
{
  private:
    static bool automaticTrigger;
    static CommunicationSAL *communication;
    static MFMState state;
    static MFMMiddleware middleware;
    static void LoadState(int address);
    static bool SendData(SensorResultContext<SENSOR_MAX_ENTRIES> &context);
    static void Loop();

  public:
    static void Setup(CommunicationSAL *communication, bool automaticTrigger);
    static void TriggerChain(SensorResultContext<SENSOR_MAX_ENTRIES> &context);
    static bool LowPowerSleep();
    static int GetTriggerInterval();
};

#endif /* end of include guard: _MFM_H_ */
