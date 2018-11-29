#ifdef UNIT_TEST

#define SENSORS_MAX_PINS 4

#include <unity.h>
#include <Sensors.h>
#include <SensorHandlerBase.h>

/**
 * Used as sensor handler for testing
 */
class TestSensorHandler : public SensorHandlerBase {
public:
    bool IsCalled = false;
    virtual unsigned short GetSignature() {
        return 0xFF01;
    }
    virtual void ReadSensor(byte (&pins)[SENSOR_MAX_PINS], byte (&buffer)[SENSOR_READ_BUFFER_SIZE]) {
        this->IsCalled = true;
        buffer[0] = 0x01;
        buffer[1] = 0x02;
    }
};

void test_SensorHandlerBase_should_ReturnCorrectSensorTypeSignature(void) {
    // Arrange
    TestSensorHandler handler;
    unsigned short signature;
    // Act
    signature = handler.GetSignature();
    // Assert
    TEST_ASSERT_EQUAL_HEX((unsigned short)0xFF01, signature);
}

void test_Sensors_should_ReturnCorrectSensorTypeSignatureOnAdd(void) {
    // Arrange
    Sensors sensors;
    TestSensorHandler handler;
    unsigned short signature;
    // Act
    signature = sensors.AddSensorType(handler);
    // Assert
    TEST_ASSERT_EQUAL_HEX((unsigned short)0xFF01, signature);
}

void test_Sensors_should_ExecuteSensorHandlerOnReading(void) {
    // Arrange
    byte pins[SENSOR_MAX_PINS];
    Sensors sensors;
    TestSensorHandler handler;
    unsigned short sensorSignature = sensors.AddSensorType(handler);
    byte sensorId = sensors.AddSensor(sensorSignature, pins);
    // Act
    byte buffer[SENSOR_READ_BUFFER_SIZE];
    sensors.ReadSensor(sensorId, buffer);
    // Assert
    TEST_ASSERT_EQUAL_HEX(true, handler.IsCalled);
    TEST_ASSERT_EQUAL_HEX(0x01, buffer[0]);
    TEST_ASSERT_EQUAL_HEX(0x02, buffer[1]);
}

void test_Sensors_should_DisableAndActivate(void) {
    // Arrange
    byte pins[SENSOR_MAX_PINS];
    Sensors sensors;
    TestSensorHandler handler;
    unsigned short sensorSignature = sensors.AddSensorType(handler);
    byte sensorId = sensors.AddSensor(sensorSignature, pins);
    // Act & Assert
    TEST_ASSERT_EQUAL_HEX(true, sensors.IsActive(sensorId));
    sensors.DisableSensor(sensorId);
    TEST_ASSERT_EQUAL_HEX(false, sensors.IsActive(sensorId));
    sensors.ActivateSensor(sensorId);
    TEST_ASSERT_EQUAL_HEX(true, sensors.IsActive(sensorId));
}

int main( int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_SensorHandlerBase_should_ReturnCorrectSensorTypeSignature);
    RUN_TEST(test_Sensors_should_ReturnCorrectSensorTypeSignatureOnAdd);
    RUN_TEST(test_Sensors_should_ExecuteSensorHandlerOnReading);
    RUN_TEST(test_Sensors_should_DisableAndActivate);
    UNITY_END();
}

#endif
