#ifndef _MFM_DATA_CONVERTER_H_
#define _MFM_DATA_CONVERTER_H_

#include <stdint.h>

class DataConverter {
protected:
    uint16_t dataBytesLength = 0;

public:
    // variables
    uint8_t *dataBytes;
    // methods
    DataConverter();
    ~DataConverter();
    uint16_t getDataSize();
    template <class T>
    bool convert(T &data);
};

#endif