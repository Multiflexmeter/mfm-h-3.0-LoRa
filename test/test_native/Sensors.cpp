#ifdef UNIT_TEST

#define SENSORS_MAX_PINS 4

#include <unity.h>
#include <Sensors.h>
#include <SensorHandlerBase.h>

void test_Sensors_should_IncrementSensorTypeIdFromZero(void) {
    // Arrange
    Sensors sensors;
    byte id1, id2, id3, id4;
    // Act
    id1 = sensors.AddSensor(0, new byte[4]{0, 0, 0, 0});
    id2 = sensors.AddSensor(0, new byte[4]{0, 0, 0, 0});
    id3 = sensors.AddSensor(0, new byte[4]{0, 0, 0, 0});
    id4 = sensors.AddSensor(0, new byte[4]{0, 0, 0, 0});
    // Assert
    TEST_ASSERT_EQUAL_INT(0, id1);
    TEST_ASSERT_EQUAL_INT(1, id2);
    TEST_ASSERT_EQUAL_INT(2, id3);
    TEST_ASSERT_EQUAL_INT(3, id4);
}

void test_Sensors_should_IncrementSensorIdFromZero(void) {
    // Arrange
    Sensors sensors;
    byte id1, id2, id3, id4;
    // Act
    id1 = sensors.AddSensorType((SensorHandlerBase*)0);
    id2 = sensors.AddSensorType((SensorHandlerBase*)0);
    id3 = sensors.AddSensorType((SensorHandlerBase*)0);
    id4 = sensors.AddSensorType((SensorHandlerBase*)0);
    // Assert
    TEST_ASSERT_EQUAL_INT(0, id1);
    TEST_ASSERT_EQUAL_INT(1, id2);
    TEST_ASSERT_EQUAL_INT(2, id3);
    TEST_ASSERT_EQUAL_INT(3, id4);
}

/**
 * Used as sensor handler for testing
 */
class TestSensorHandler : public SensorHandlerBase {
public:
    bool IsCalled = false;
    virtual void ReadSensor(byte (&buffer)[SENSOR_READ_BUFFER_SIZE]) {
        this->IsCalled = true;
        buffer[0] = 0x01;
        buffer[1] = 0x02;
    }
};

void test_Sensors_should_ExecuteSensorHandlerOnReading(void) {
    // Arrange
    Sensors sensors;
    TestSensorHandler handler;
    byte sensorTypeId = sensors.AddSensorType(&handler);
    byte sensorId = sensors.AddSensor(sensorTypeId, new byte[4]);
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
    Sensors sensors;
    TestSensorHandler handler;
    byte sensorTypeId = sensors.AddSensorType(&handler);
    byte sensorId = sensors.AddSensor(sensorTypeId, new byte[4]);
    // Act & Assert
    TEST_ASSERT_EQUAL_HEX(true, sensors.IsActive(sensorId));
    sensors.DisableSensor(sensorId);
    TEST_ASSERT_EQUAL_HEX(false, sensors.IsActive(sensorId));
    sensors.ActivateSensor(sensorId);
    TEST_ASSERT_EQUAL_HEX(true, sensors.IsActive(sensorId));
}

int main( int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_Sensors_should_IncrementSensorTypeIdFromZero);
    RUN_TEST(test_Sensors_should_IncrementSensorIdFromZero);
    RUN_TEST(test_Sensors_should_ExecuteSensorHandlerOnReading);
    RUN_TEST(test_Sensors_should_DisableAndActivate);
    UNITY_END();
}

#endif
