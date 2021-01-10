
#define MUNIT_ENABLE_ASSERT_ALIASES
#include <munit/munit.h>

#define REGISTER_TEST(func_name) { \
        (char*)"/"#func_name, \
        func_name, \
        nullptr, \
        nullptr, \
        MUNIT_TEST_OPTION_NONE, \
        nullptr, \
    },

#define REGISTER_EMPTY_TEST() { \
        nullptr, \
        nullptr, \
        nullptr, \
        nullptr, \
        MUNIT_TEST_OPTION_NONE, \
        nullptr, \
    },
