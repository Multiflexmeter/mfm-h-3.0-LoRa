#ifndef _MFM_H_
#define _MFM_H_

#include <lmic.h>
#include <hal/hal.h>
#include <LowPower.h>

#include <Sensors.h>

#include "Config.h"

class MFM {
public:
    static unsigned long interval_time;
    static void Setup(unsigned long interval);
    static void Loop();
private:
    static osjob_t init_job;
    static osjob_t interval_job;
    static void Init(osjob_t* job);
    static void IntervalTrigger(osjob_t* job);
    static void EnterSleep();
};

#endif /* end of include guard: _MFM_H_ */
