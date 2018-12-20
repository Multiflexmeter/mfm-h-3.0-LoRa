#ifndef _MFM_LORAWAN_H_
#define _MFM_LORAWAN_H_

#include <lmic.h>
#include <hal/hal.h>

#include <MFM.h>
#include <MiddlewareSystem.h>

// TODO: Configuration for other frequencies

class LoRaWan {
private:
    static osjob_t triggerJob;
    static MiddlewareSystem<void, 5> middleware;
public:
    static void Setup();
    static void Loop();
    static void Middleware(SensorResultContext<SENSOR_MAX_ENTRIES> &context);
    static void TriggerJob(osjob_t *job);
    static void AddListener(MiddlewareFunctionPtr<void> callback);
    static void OnReceive();
};

#endif