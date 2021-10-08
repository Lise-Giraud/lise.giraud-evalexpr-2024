#include <criterion/criterion.h>
#include "../src/my_evalexpr.h"

Test(evalexpr, rpn_basic)
{
    int expected = 2;
    int actual = main();
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected actual);
}
