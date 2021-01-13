#include "common.h"

#include "util.h"
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

MunitResult T02_Color_Add(const MunitParameter args[], void *user_data)
{
    Color c1 = color(0.9, 0.6, 0.75);
    Color c2 = color(0.7, 0.1, 0.25);

    Color expected_result = color(1.6, 0.7, 1.0, 2.0);
    Color result = color_add(c1, c2);

    assert_true(color_eq(result, expected_result));

    munit_assert_double_equal(result.r, expected_result.r, 5);
    munit_assert_double_equal(result.g, expected_result.g, 5);
    munit_assert_double_equal(result.b, expected_result.b, 5);
    munit_assert_double_equal(result.a, expected_result.a, 5);

    assert_true(float_eq(result.r, expected_result.r));
    assert_true(float_eq(result.g, expected_result.g));
    assert_true(float_eq(result.b, expected_result.b));
    assert_true(float_eq(result.a, expected_result.a));

    return MUNIT_OK;
}

MunitResult T03_Color_Sub(const MunitParameter args[], void *user_data)
{
    Color c1 = color(0.9, 0.6, 0.75);
    Color c2 = color(0.7, 0.1, 0.25);

    Color expected_result = color(0.2, 0.5, 0.5, 0.0f);
    Color result = color_sub(c1, c2);

    assert_true(color_eq(result, expected_result));

    munit_assert_double_equal(result.r, expected_result.r, 5);
    munit_assert_double_equal(result.g, expected_result.g, 5);
    munit_assert_double_equal(result.b, expected_result.b, 5);
    munit_assert_double_equal(result.a, expected_result.a, 5);

    assert_true(float_eq(result.r, expected_result.r));
    assert_true(float_eq(result.g, expected_result.g));
    assert_true(float_eq(result.b, expected_result.b));
    assert_true(float_eq(result.a, expected_result.a));

    return MUNIT_OK;
}

MunitResult T04_Color_Mul_Scalar(const MunitParameter args[], void *user_data)
{
    Color c = color(0.2, 0.3, 0.4);

    Color expected_result = color(0.4, 0.6, 0.8, 2.0f);
    Color result = color_mul(c, 2.0);

    assert_true(color_eq(result, expected_result));

    munit_assert_double_equal(result.r, expected_result.r, 5);
    munit_assert_double_equal(result.g, expected_result.g, 5);
    munit_assert_double_equal(result.b, expected_result.b, 5);
    munit_assert_double_equal(result.a, expected_result.a, 5);

    assert_true(float_eq(result.r, expected_result.r));
    assert_true(float_eq(result.g, expected_result.g));
    assert_true(float_eq(result.b, expected_result.b));
    assert_true(float_eq(result.a, expected_result.a));

    return MUNIT_OK;
}

MunitResult T05_Color_Hadamard(const MunitParameter args[], void *user_data)
{
    Color c1 = color(1, 0.2, 0.4);
    Color c2 = color(0.9, 1, 0.1);

    Color expected_result = color(0.9, 0.2, 0.04);
    Color result = color_hadamard(c1, c2);

    assert_true(color_eq(result, expected_result));

    munit_assert_double_equal(result.r, expected_result.r, 5);
    munit_assert_double_equal(result.g, expected_result.g, 5);
    munit_assert_double_equal(result.b, expected_result.b, 5);
    munit_assert_double_equal(result.a, expected_result.a, 5);

    assert_true(float_eq(result.r, expected_result.r));
    assert_true(float_eq(result.g, expected_result.g));
    assert_true(float_eq(result.b, expected_result.b));
    assert_true(float_eq(result.a, expected_result.a));

    return MUNIT_OK;
}

MunitTest ch02_tests[] = {

    REGISTER_TEST(T01_Color_Create)
    REGISTER_TEST(T02_Color_Add)
    REGISTER_TEST(T03_Color_Sub)
    REGISTER_TEST(T04_Color_Mul_Scalar)
    REGISTER_TEST(T05_Color_Hadamard)

    REGISTER_EMPTY_TEST()
};

static const MunitSuite CH02_Suite = {
    (char*)"CH02",
    ch02_tests,
    nullptr,
    1,
    MUNIT_SUITE_OPTION_NONE,
};
