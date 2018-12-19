#ifndef _MFM_DATA_CONVERTER_H_
#define _MFM_DATA_CONVERTER_H_

#include <stdint.h>
#include <string.h>

class DataConverter {
protected:
    uint16_t dataBytesLength = 0;
    uint8_t * dataBytes;
public:
    DataConverter();
    ~DataConverter();
    uint16_t getDataSize();
    void getDataBytes(uint8_t *array);
    template <class T>
    bool convert(T &data);
};

#endif