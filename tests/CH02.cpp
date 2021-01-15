#include "common.h"

#include "array.h"
#include "canvas.h"
#include "color.h"
#include "temp_allocator.h"
#include "util.h"
#include <cstdio>

using namespace RayTracer;

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

MunitResult T06_Canvas_Creation(const MunitParameter args[], void *user_data)
{
    Canvas c = canvas(10, 20);

    Color expected_color = color(0, 0, 0);

    munit_assert_int(c.width, ==, 10);
    munit_assert_int(c.height, ==, 20);

    for (int y = 0; y < c.width; y++)
    {
        for (int x = 0; x < c.width; x++)
        {
            Color pixel_c = canvas_get_pixel(c, x, y);

            assert_float(pixel_c.r, ==, expected_color.r);
            assert_float(pixel_c.g, ==, expected_color.g);
            assert_float(pixel_c.b, ==, expected_color.b);
            assert_float(pixel_c.a, ==, expected_color.a);

            assert_true(color_eq(pixel_c, expected_color));

        }
    }

    canvas_free(&c);

    return MUNIT_OK;
}

MunitResult T07_Canvas_Write_Pixel(const MunitParameter args[], void *user_data)
{
    Canvas c = canvas(10, 20);
    Color red = color(1, 0, 0);

    canvas_set_pixel(&c, 2, 3, red);

    Color result = canvas_get_pixel(&c, 2, 3);

    assert_true(color_eq(result, red));

    assert_float(result.r, ==, red.r);
    assert_float(result.g, ==, red.g);
    assert_float(result.b, ==, red.b);
    assert_float(result.a, ==, red.a);

    canvas_free(&c);

    return MUNIT_OK;
}

MunitResult T08_PPM_Header(const MunitParameter args[], void *user_data)
{
    auto ta = temp_allocator_get();
    temp_allocator_reset(ta);

    Canvas c = canvas(5, 3);
    String ppm_str = canvas_to_ppm(c, ta);

    auto lines = string_split_ref(ta, ppm_str, '\n');

    assert_int64(lines.count, >=, 3);
    assert_custom_string_equal(lines[0], string_ref("P3"));
    assert_custom_string_equal(lines[1], string_ref("5 3"));
    assert_custom_string_equal(lines[2], string_ref("255"));

    canvas_free(&c);

    return MUNIT_OK;
}

MunitResult T09_PPM_Pixel_Data(const MunitParameter args[], void *user_data)
{
    auto ta = temp_allocator_get();
    temp_allocator_reset(ta);

    Canvas c = canvas(5, 3);
    Color c1 = color(1.5, 0, 0);
    Color c2 = color(0, 0.5, 0);
    Color c3 = color(-0.5, 0, 1);

    canvas_set_pixel(&c, 0, 0, c1);
    canvas_set_pixel(&c, 2, 1, c2);
    canvas_set_pixel(&c, 4, 2, c3);

    String ppm_str = canvas_to_ppm(c, ta);

    Array<String> lines = string_split_ref(ta, ppm_str, '\n');

    assert_int64(lines.count, ==, 6);
    assert_custom_string_equal(lines[3], string_ref("255 0 0 0 0 0 0 0 0 0 0 0 0 0 0"));
    assert_custom_string_equal(lines[4], string_ref("0 0 0 0 0 0 0 128 0 0 0 0 0 0 0"));
    assert_custom_string_equal(lines[5], string_ref("0 0 0 0 0 0 0 0 0 0 0 0 0 0 255"));

    canvas_free(&c);

    return MUNIT_OK;
}

MunitResult T10_PPM_Line_Limit(const MunitParameter args[], void *user_data)
{
    auto ta = temp_allocator_get();
    temp_allocator_reset(ta);

    Canvas c = canvas(10, 2);

    canvas_clear(&c, color(1, 0.8, 0.6));

    String ppm_str = canvas_to_ppm(c, ta);
    Array<String> lines = string_split_ref(ta, ppm_str, '\n');

    assert_int64(lines.count, ==, 7);

    String l4 = string_ref("255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204");
    assert_custom_string_equal(lines[3], l4);

    String l5 = string_ref("153 255 204 153 255 204 153 255 204 153 255 204 153");
    assert_custom_string_equal(lines[4], l5);

    assert_custom_string_equal(lines[5], l4);
    assert_custom_string_equal(lines[6], l5);

    canvas_free(&c);
    return MUNIT_OK;
}

MunitResult T11_PPM_Ends_With_Newline(const MunitParameter args[], void *user_data)
{
    auto ta = temp_allocator_get();
    temp_allocator_reset(ta);

    Canvas c = canvas(5, 3);

    String ppm_str = canvas_to_ppm(c, ta);

    assert_char(ppm_str[ppm_str.length - 1], ==, '\n');

    canvas_free(&c);
    return MUNIT_OK;
}

MunitTest ch02_tests[] = {

    REGISTER_TEST(T01_Color_Create)
    REGISTER_TEST(T02_Color_Add)
    REGISTER_TEST(T03_Color_Sub)
    REGISTER_TEST(T04_Color_Mul_Scalar)
    REGISTER_TEST(T05_Color_Hadamard)
    REGISTER_TEST(T06_Canvas_Creation)
    REGISTER_TEST(T07_Canvas_Write_Pixel)
    REGISTER_TEST(T08_PPM_Header)
    REGISTER_TEST(T09_PPM_Pixel_Data)
    REGISTER_TEST(T10_PPM_Line_Limit)
    REGISTER_TEST(T11_PPM_Ends_With_Newline)

    REGISTER_EMPTY_TEST()
};

static const MunitSuite CH02_Suite = {
    (char*)"CH02",
    ch02_tests,
    nullptr,
    1,
    MUNIT_SUITE_OPTION_NONE,
    // char *cstr = alloc_array<char>(allocator, required_cap + 1);
};
