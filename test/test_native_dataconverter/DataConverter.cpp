#ifdef UNIT_TEST

#include <unity.h>
#include <stdint.h>
#include <stdio.h>

#include <DataConverter.h>

// Implementation
class IntDataConverter : public DataConverter {
public:
    bool convert(int& data) {
        dataBytesLength = 4;
        dataBytes = new uint8_t[dataBytesLength];

        dataBytes[0] = 0x11;
        dataBytes[1] = 0x22;
        dataBytes[2] = 0x33;
        dataBytes[3] = 0x44;
    }
};

// Tests
void test_DataConverter_should_ReturnCorrectSize(void) {
    // Arrange
    IntDataConverter converter;
    int ctx = 15;
    uint8_t arrayLength = 0;
    // Act
    converter.convert(ctx);
    arrayLength = converter.getDataSize();
    // Assert
    TEST_ASSERT_EQUAL_INT(4, arrayLength);
}

void test_DataConverter_should_ReturnCorrectDataBytes(void)
{
    // Arrange
    IntDataConverter converter;
    int ctx = 15;
    converter.convert(ctx);
    // Act
    uint8_t resultBytes[converter.getDataSize()] = {0};

    // Assert
    TEST_ASSERT_EQUAL_HEX(0x11, converter.dataBytes[0]);
    TEST_ASSERT_EQUAL_HEX(0x22, converter.dataBytes[1]);
    TEST_ASSERT_EQUAL_HEX(0x33, converter.dataBytes[2]);
    TEST_ASSERT_EQUAL_HEX(0x44, converter.dataBytes[3]);
}

// Entry point
int main(int argc, char **argv)
{
    UNITY_BEGIN();
    RUN_TEST(test_DataConverter_should_ReturnCorrectSize);
    RUN_TEST(test_DataConverter_should_ReturnCorrectDataBytes);
    UNITY_END();
}

#endif