
#include "common.h"

MunitResult example(const MunitParameter args[], void *user_data)
{
    assert_int(41, ==, 41);
    return MUNIT_OK;
}

MunitTest ch01_tests[] = {

    REGISTER_TEST(example)
    REGISTER_EMPTY_TEST()
};

static const MunitSuite CH01_Suite = {
    (char*)"/CH01",
    ch01_tests,
    nullptr,
    1,
    MUNIT_SUITE_OPTION_NONE,
};
