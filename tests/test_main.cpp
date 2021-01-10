
#include "common.h"
#include "CH01.cpp"

static const MunitSuite child_suites[] = {
    CH01_Suite,

    { nullptr, nullptr, nullptr, 0, MUNIT_SUITE_OPTION_NONE },
};

static const MunitSuite suite = {
    (char*)"/RT",
    nullptr,
    (MunitSuite*)child_suites,
    1,
    MUNIT_SUITE_OPTION_NONE,
};

int main(int argc, char** argv)
{
    return munit_suite_main(&suite, NULL, argc, argv);
}
