#ifdef UNIT_TEST

#include <unity.h>
#include <stdint.h>

#include <DataConverter.h>

// Implementation
class IntDataConverter : public DataConverter {
public:
    bool convert(int& data) {
        dataBytesLength = 4;
        dataBytes = new uint8_t[dataBytesLength];
        // Copy int to array
        memcpy(dataBytes, &data, 4);
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

// Entry point
int main(int argc, char **argv)
{
    UNITY_BEGIN();
    RUN_TEST(test_DataConverter_should_ReturnCorrectSize);
    UNITY_END();
}

#endif