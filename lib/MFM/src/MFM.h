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

#include "MFMContext.h"
#include "MFMState.h"
#include "SensorResultContext.h"
#include "SensorResultContextConverter.cpp"

extern void setupMiddleware(MiddlewareSystem<SensorResultContext<SENSOR_MAX_ENTRIES>, 10> &middleware);
extern void setupSettings();

class MFM
{
  private:
    static void LoadState(int address, MFM_t & ctx);
    static bool SendData(SensorResultContext<SENSOR_MAX_ENTRIES> &data, MFM_t & ctx);

  public:
    static MFM_t Setup(CommunicationSAL *communication);
    static void TriggerChain(SensorResultContext<SENSOR_MAX_ENTRIES> &context, MFM_t & ctx);
    static bool LowPowerSleep(MFM_t & ctx);
    static void Loop(MFM_t & ctx);
};

#endif /* end of include guard: _MFM_H_ */
