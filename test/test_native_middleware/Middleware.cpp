#ifdef UNIT_TEST

#include <unity.h>
#include <MiddlewareSystem.h>

bool middlewareFunction1(int& context) {
    context *= 2;
    return true;
}
bool middlewareFunction2(int& context) {
    context -= 5;
    return false;
}
bool middlewareFunction3(int& context) {
    context = 0;
    return true;
}

/**
 * Tests whether the middleware is added, executed in order, changing the context
 * and continuing based on the return boolean.
 * TODO: more specific tests
 */
void test_Middleware_should_ChangeContext(void) {
    // Arrange
    MiddlewareSystem<int, 3> system;
    int context = 10;

    // Act
    system.add(&middlewareFunction1);
    system.add(&middlewareFunction2);
    system.add(&middlewareFunction3);
    system.execute(context);

    // Assert
    TEST_ASSERT_EQUAL_INT(15, context);
}

int main( int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_Middleware_should_ChangeContext);
    return UNITY_END();
}

#endif
