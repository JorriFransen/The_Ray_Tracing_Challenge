

#define _USE_MATH_DEFINES
#include <math.h>

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

#define assert_custom_string_equal(a, b) \
  do { \
    if (MUNIT_UNLIKELY(string_eq(a, b) == false)) { \
      munit_errorf("assertion failed: string %s == %s (\"%.*s\" == \"%.*s\")", \
                   #a, #b, (int)a.length, a.data, (int)b.length, b.data); \
    } \
    MUNIT_PUSH_DISABLE_MSVC_C4127_ \
  } while (0) \
  MUNIT_POP_DISABLE_MSVC_C4127_

