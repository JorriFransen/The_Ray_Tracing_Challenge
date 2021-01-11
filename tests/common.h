
#define MUNIT_ENABLE_ASSERT_ALIASES
#include <munit/munit.h>

#define REGISTER_TEST_NAMED(name, func) { \
        (char*)"/" name, \
        func, \
        nullptr, \
        nullptr, \
        MUNIT_TEST_OPTION_NONE, \
        nullptr, \
    },

#define REGISTER_TEST(func_name) REGISTER_TEST_NAMED(#func_name, func_name)

#define REGISTER_EMPTY_TEST() { \
        nullptr, \
        nullptr, \
        nullptr, \
        nullptr, \
        MUNIT_TEST_OPTION_NONE, \
        nullptr, \
    },
