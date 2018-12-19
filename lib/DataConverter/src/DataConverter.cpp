#include "DataConverter.h"

DataConverter::DataConverter():dataBytesLength(0) {
    dataBytes = new uint8_t[0];
};

DataConverter::~DataConverter() {
    delete[] dataBytes;
}

uint16_t DataConverter::getDataSize() {
    return this->dataBytesLength;
}

void DataConverter::getDataBytes(uint8_t * array) {
    memcpy(array, &dataBytes, dataBytesLength);
}