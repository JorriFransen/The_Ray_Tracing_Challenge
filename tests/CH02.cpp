#include "common.h"

#include "color.h"

MunitResult T01_Color_Create(const MunitParameter args[], void *user_data)
{
    Color c = color(-0.5, 0.4, 1.7);

    assert_float(c.r, ==, -0.5);
    assert_float(c.g, ==, 0.4);
    assert_float(c.b, ==, 1.7);
    assert_float(c.tuple.w, ==, 1.0);

    return MUNIT_OK;
}

MunitTest ch02_tests[] = {

    REGISTER_TEST(T01_Color_Create)

    REGISTER_EMPTY_TEST()
};

static const MunitSuite CH02_Suite = {
    (char*)"CH02",
    ch02_tests,
    nullptr,
    1,
    MUNIT_SUITE_OPTION_NONE,
};
