#include "DataConverter.h"

template<class T>
uint16_t DataConverter<T>::getDataSize() {
    return this->dataBytesLength;
}

template<class T>
void DataConverter<T>::getDataBytes(uint8_t * array) {
    memcpy(array, dataBytes, dataBytesLength);
}