
#include "common.h"
#include "CH01.cpp"
#include "CH02.cpp"
#include "CH03.cpp"
#include "CH04.cpp"
#include "CH05.cpp"
#include "CH06.cpp"
#include "CH07.cpp"

static const MunitSuite child_suites[] = {
    CH01_Suite,
    CH02_Suite,
    CH03_Suite,
    CH04_Suite,
    CH05_Suite,
    CH06_Suite,
    CH07_Suite,

    { nullptr, nullptr, nullptr, 0, MUNIT_SUITE_OPTION_NONE },
};

static const MunitSuite suite = {
    (char*)"",
    nullptr,
    (MunitSuite*)child_suites,
    1,
    MUNIT_SUITE_OPTION_NONE,
};

int main(int argc, char** argv)
{
    return munit_suite_main(&suite, NULL, argc, argv);
}
