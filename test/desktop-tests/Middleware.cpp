#ifdef UNIT_TEST

#include <unity.h>
#include <MiddlewareSystem.h>

void test_Middleware_should_ShiftRight(void) {
    // DUMMY TEST
    TEST_ASSERT_EQUAL_HEX8(0xff, 0xff);
}

int main( int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_Middleware_should_ShiftRight);
    UNITY_END();
}

#endif
