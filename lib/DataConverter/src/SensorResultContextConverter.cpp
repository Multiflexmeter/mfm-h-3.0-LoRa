#include "DataConverter.h"

#include <SensorResultContext.h>

// Easier reading
using SensoResultContext_ = SensorResultContext<SENSOR_MAX_ENTRIES>;

bool DataConverter<SensoResultContext_>::convert(SensoResultContext_ &data)
{
    // Unused thus far, initial idea was huffman compression
}