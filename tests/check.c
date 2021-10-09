#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

#include "../src/my_evalexpr.h"
#include "../src/stack.h"

Test(evalexpr, my_pow)
{
    int expected = 1;
    int actual = my_pow(1, 1);
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);

    expected = 27;
    actual = my_pow(3, 3);
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);

    expected = 1;
    actual = my_pow(0, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);

    expected = 1024;
    actual = my_pow(2, 10);
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);

    expected = 4096;
    actual = my_pow(16, 3);
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);

    expected = 1024;
    actual = my_pow(4, 5);
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
}

Test(evalexpr, easy, .init = redirect_all_stdout)
{
    const char *output = "2\n";
    int expected = 0;
    char exp[] = "1 1 +";
    int written = rpn(exp);
    fflush(stdout);
    cr_assert_stdout_eq_str(output);
    cr_assert_eq(written, expected, "Expected %d. Got %d.", expected, written);
}

Test(evalexpr, random, .init = redirect_all_stdout)
{
    const char *output = "35\n";
    int expected = 0;
    char exp[] = "5 2 2 ^ 3 + *";
    int written = rpn(exp);
    fflush(stdout);
    cr_assert_stdout_eq_str(output);
    cr_assert_eq(written, expected, "Expected %d. Got %d.", expected, written);
}

Test(evalexpr, negative, .init = redirect_all_stdout)
{
    const char *output = "-20\n";
    int expected = 0;
    char exp[] = "3 4 5 * 3 + -";
    int written = rpn(exp);
    fflush(stdout);
    cr_assert_stdout_eq_str(output);
    cr_assert_eq(written, expected, "Expected %d. Got %d.", expected, written);
}

Test(evalexpr, hard, .init = redirect_all_stdout)
{
    const char *output = "3\n";
    int expected = 0;
    char exp[] = "7 8 4 / 2 + -";
    int written = rpn(exp);
    fflush(stdout);
    cr_assert_stdout_eq_str(output);
    cr_assert_eq(written, expected, "Expected %d. Got %d.", expected, written);
}

Test(evalexpr, power, .init = redirect_all_stdout)
{
    const char *output = "80\n";
    int expected = 0;
    char exp[] = "2 4 ^ 5 1 ^ *";
    int written = rpn(exp);
    fflush(stdout);
    cr_assert_stdout_eq_str(output);
    cr_assert_eq(written, expected, "Expected %d. Got %d.", expected, written);
}

Test(evalexpr, module, .init = redirect_all_stdout)
{
    const char *output = "10\n";
    int expected = 0;
    char exp[] = "7 52 2 % 3 + +";
    int written = rpn(exp);
    fflush(stdout);
    cr_assert_stdout_eq_str(output);
    cr_assert_eq(written, expected, "Expected %d. Got %d.", expected, written);
}
