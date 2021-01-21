
#include <munit/munit.h>

#include "matrix.h"

using namespace RayTracer;

MunitResult T01(const MunitParameter args[], void *user_data)
{
    return MUNIT_OK;
}

MunitTest ch04_tests[] = {
    REGISTER_TEST(T01)

    REGISTER_EMPTY_TEST()
};

static const MunitSuite CH04_Suite = {
    (char*)"CH04",
    ch04_tests,
    nullptr,
    1,
    MUNIT_SUITE_OPTION_NONE,
};
