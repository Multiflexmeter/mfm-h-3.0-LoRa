#ifndef _MFM_DATA_CONVERTER_H_
#define _MFM_DATA_CONVERTER_H_

#include <stdint.h>
#include <string.h>

template<class T>
class DataConverter {
private:
    uint16_t dataBytesLength = 0;
    uint8_t dataBytes[] = {};
public:
    DataConverter();
    uint16_t getDataSize();
    void getDataBytes(uint8_t * array);
    bool convert(T& data);
};

#endif