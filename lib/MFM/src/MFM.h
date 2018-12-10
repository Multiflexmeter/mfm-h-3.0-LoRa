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

#include "Config.h"
#include "MFMState.h"

typedef MiddlewareSystem<MFM_MIDDLEWARE_CTX_TYPE, MFM_MIDDLEWARE_LENGTH> MFMMiddleware;

extern void setupMiddleware(MFMMiddleware& middleware);
extern void setupSettings();

class MFM {
public:
    static void Setup();
    static void Loop();
private:
    static MFMState state;
    static MFMMiddleware middleware;
    static void LoadState(int address);
};

#endif /* end of include guard: _MFM_H_ */
