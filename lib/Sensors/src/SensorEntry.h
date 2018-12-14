#ifndef _SENSORY_ENTRY_H_
#define _SENSORY_ENTRY_H_

#include <stdint.h>

#include "Config.h"

class SensorEntry
{
private:
public:
  uint8_t id;
  bool active;
  uint16_t sensorType;
  uint8_t pins[SENSOR_MAX_PINS];

  SensorEntry(uint8_t id, bool active, uint16_t sensorType, uint8_t * pinArrayStart, uint8_t pinArrayLength);
  SensorEntry();
//   ~SensorEntry(){}
};

#endif