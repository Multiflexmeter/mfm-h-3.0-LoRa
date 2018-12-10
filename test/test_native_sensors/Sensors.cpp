#define SENSORS_MAX_PINS 4

#include "unity.h"
#include "unity_internals.h"
#include <Sensors.h>
#include <SensorHandlerBase.h>
#include <stdio.h>

#ifdef UNIT_TEST

uint8_t pins[SENSOR_MAX_PINS] = {0};

/**
 * Used as sensor handler for testing
 */
class TestSensorHandler : public SensorHandlerBase
{
  public:
    bool IsCalled = false;
    virtual unsigned short GetSignature()
    {
        return 0xFF01;
    }
    virtual void ReadSensor(uint8_t(pins)[SENSOR_MAX_PINS], uint8_t (&buffer)[SENSOR_READ_BUFFER_SIZE])
    {
        this->IsCalled = true;
        buffer[0] = 0x01;
        buffer[1] = 0x02;
    }
};

void test_SensorHandlerBase_should_ReturnCorrectSensorTypeSignature(void)
{
    // Arrange
    TestSensorHandler handler;
    unsigned short signature;
    // Act
    signature = handler.GetSignature();
    // Assert
    TEST_ASSERT_EQUAL_HEX((unsigned short)0xFF01, signature);
}

void test_Sensors_GetSensorType_should_ReturnCorrectSensorType(void)
{
    // Arrange
    Sensors sensors;
    TestSensorHandler handler;
    sensors.AddSensorType(handler);
    // Act
    SensorHandlerBase* handlerPtr = sensors.GetSensorType(0xFF01);
    // Assert
    TEST_ASSERT_EQUAL(handlerPtr, &handler);
}

void test_Sensors_AddSensorType_should_ReturnCorrectSignature(void)
{
    // Arrange
    Sensors sensors;
    TestSensorHandler handler;
    unsigned short signature;
    // Act
    signature = sensors.AddSensorType(handler);
    // Assert
    TEST_ASSERT_EQUAL_HEX((unsigned short)0xFF01, signature);
}

void test_Sensors_ReadSensor_should_ExecuteSensorHandler(void)
{
    // Arrange
    Sensors sensors;
    TestSensorHandler handler;
    unsigned short sensorSignature = sensors.AddSensorType(handler);
    uint8_t sensorId = sensors.AddSensor(sensorSignature, pins, SENSOR_MAX_PINS);
    // Act
    uint8_t buffer[SENSOR_READ_BUFFER_SIZE];
    sensors.ReadSensor(sensorId, buffer);

    // Assert
    TEST_ASSERT_EQUAL_HEX(true, handler.IsCalled);
    TEST_ASSERT_EQUAL_HEX(0x01, buffer[0]);
    TEST_ASSERT_EQUAL_HEX(0x02, buffer[1]);
}

void test_Sensors_AddSensor_should_IncreaseId(void)
{
    TEST_IGNORE();
    // Arrange Act
    Sensors sensors;
    uint8_t sensorId1 = sensors.AddSensor(0, pins, 0);
    uint8_t sensorId2 = sensors.AddSensor(0, pins, 0);
    uint8_t sensorId3 = sensors.AddSensor(0, pins, 0);

    // Assert
    TEST_ASSERT_EQUAL_HEX(0, sensorId1);
    TEST_ASSERT_EQUAL_HEX(1, sensorId2);
    TEST_ASSERT_EQUAL_HEX(2, sensorId3);
}

void test_Sensors_AddSensor_should_ComplyToEntryLimit(void)
{
    TEST_IGNORE();
    // Arrange
    Sensors sensors;
    for (uint8_t i = 0; i < SENSOR_MAX_ENTRIES; i++)
    {
        sensors.AddSensor(0, pins, 0);
    }
    
    // Act
    uint8_t sensorId = sensors.AddSensor(0, pins, 0);

    // Assert
    TEST_ASSERT_EQUAL_HEX(0xFF, sensorId);
}

void test_Sensors_AddSensor_should_ReuseRemovedId(void)
{
    TEST_IGNORE();
    // Arrange
    Sensors sensors;
    uint8_t sensorId1 = sensors.AddSensor(0, pins, 0);
    uint8_t sensorId2 = sensors.AddSensor(0, pins, 0);

    // Act
    sensors.RemoveSensor(sensorId2);
    uint8_t sensorId3 = sensors.AddSensor(0, pins, 0);

    // Assert
    TEST_ASSERT_EQUAL_HEX(sensorId2, sensorId3);
}

void test_Sensors_should_DisableAndActivate(void)
{
    TEST_IGNORE();
    // Arrange
    uint8_t pins[SENSOR_MAX_PINS];
    Sensors sensors;
    TestSensorHandler handler;
    unsigned short sensorSignature = sensors.AddSensorType(handler);
    uint8_t sensorId = sensors.AddSensor(sensorSignature, pins, SENSOR_MAX_ENTRIES);
    // Act & Assert
    TEST_ASSERT_EQUAL_HEX(true, sensors.IsActive(sensorId));
    sensors.DisableSensor(sensorId);
    TEST_ASSERT_EQUAL_HEX(false, sensors.IsActive(sensorId));
    sensors.ActivateSensor(sensorId);
    TEST_ASSERT_EQUAL_HEX(true, sensors.IsActive(sensorId));
}

void test_Sensors_should_NotActivateUninitializedId(void)
{
    TEST_IGNORE();
    // Arrange
    Sensors sensors;

    // Act
    sensors.ActivateSensor(0);

    // Assert
    TEST_ASSERT_EQUAL_HEX(false, sensors.IsActive(0));
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();
    RUN_TEST(test_SensorHandlerBase_should_ReturnCorrectSensorTypeSignature);
    RUN_TEST(test_Sensors_GetSensorType_should_ReturnCorrectSensorType);
    RUN_TEST(test_Sensors_AddSensorType_should_ReturnCorrectSignature);
    RUN_TEST(test_Sensors_ReadSensor_should_ExecuteSensorHandler);
    RUN_TEST(test_Sensors_AddSensor_should_IncreaseId);
    RUN_TEST(test_Sensors_AddSensor_should_ComplyToEntryLimit);
    RUN_TEST(test_Sensors_AddSensor_should_ReuseRemovedId);
    RUN_TEST(test_Sensors_should_DisableAndActivate);
    RUN_TEST(test_Sensors_should_NotActivateUninitializedId);
    return UNITY_END();
}

#endif
