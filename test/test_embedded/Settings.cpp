#include <Arduino.h>
#include "unity.h"

#if defined(ARDUINO) && defined(UNIT_TEST)

#include <Settings.h>

void test_SettingsReservation_should_StartAt0(void)
{
    // Arrange
    Settings::Reset();
    // Act
    int spaceAddr = Settings::ReserveSpace(sizeof(int));
    // Assert
    TEST_ASSERT_EQUAL_INT(0, spaceAddr);
}

void test_SettingsReservation_should_IncreaseWithSize(void)
{
    // Arrange
    Settings::Reset();
    // Act
    int spaceAddr1 = Settings::ReserveSpace(sizeof(int));
    int spaceAddr2 = Settings::ReserveSpace(sizeof(int));
    int spaceAddr3 = Settings::ReserveSpace(sizeof(int));
    // Assert
    TEST_ASSERT_EQUAL_INT(0 * sizeof(int), spaceAddr1);
    TEST_ASSERT_EQUAL_INT(1 * sizeof(int), spaceAddr2);
    TEST_ASSERT_EQUAL_INT(2 * sizeof(int), spaceAddr3);
}

void setup()
{
    delay(2000);

    UNITY_BEGIN();
    RUN_TEST(test_SettingsReservation_should_StartAt0);
    RUN_TEST(test_SettingsReservation_should_IncreaseWithSize);
    UNITY_END();
}

void loop()
{
    // nothing to be done here.
}

#endif