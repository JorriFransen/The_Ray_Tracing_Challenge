
#include "common.h"

#include "matrix.h"
#include "point.h"

using namespace RayTracer;

MunitResult T01_Point_Mul_Translation(const MunitParameter args[], void *user_data)
{
    Matrix transform = matrix_translation(5, -3, 2);
    Point p = point(-3, 4, 5);

    Point expected_result = point(2, 1, 7);
    Point result = matrix_mul(transform, p);

    assert_float(result.x, ==, expected_result.x);
    assert_float(result.y, ==, expected_result.y);
    assert_float(result.z, ==, expected_result.z);
    assert_float(result.w, ==, expected_result.w);

    assert_true(point_eq(result, expected_result));

    return MUNIT_OK;
}

MunitResult T02_Point_Mul_Translation_Inv(const MunitParameter args[], void *user_data)
{
    Matrix transform = matrix_translation(5, -3, 2);
    Matrix inv = matrix_inverse(transform);
    Point p = point(-3, 4, 5);

    Point expected_result = point(-8, 7, 3);
    Point result = matrix_mul(inv, p);

    assert_float(result.x, ==, expected_result.x);
    assert_float(result.y, ==, expected_result.y);
    assert_float(result.z, ==, expected_result.z);
    assert_float(result.w, ==, expected_result.w);

    assert_true(point_eq(result, expected_result));

    return MUNIT_OK;
}

MunitResult T03_Vector_Mul_Translation(const MunitParameter args[], void *user_data)
{
    Matrix transform = matrix_translation(5, -3, 2);
    Vector v = vector(-3, 4, 5);

    Vector expected_result = vector(-3, 4, 5);
    Vector result = matrix_mul(transform, v);

    assert_float(result.x, ==, expected_result.x);
    assert_float(result.y, ==, expected_result.y);
    assert_float(result.z, ==, expected_result.z);
    assert_float(result.w, ==, expected_result.w);

    assert_true(point_eq(result, expected_result));

    return MUNIT_OK;
}

MunitResult T04_Point_Mul_Scale(const MunitParameter args[], void *user_data)
{
    Matrix transform = matrix_scale(2, 3, 4);
    Point p = point(-4, 6, 8);

    Point expected_result = point(-8, 18, 32);
    Point result = matrix_mul(transform, p);

    assert_float(result.x, ==, expected_result.x);
    assert_float(result.y, ==, expected_result.y);
    assert_float(result.z, ==, expected_result.z);
    assert_float(result.w, ==, expected_result.w);

    assert_true(point_eq(result, expected_result));

    return MUNIT_OK;
}

MunitResult T05_Vector_Mul_Scale(const MunitParameter args[], void *user_data)
{
    Matrix transform = matrix_scale(2, 3, 4);
    Vector v = vector(-4, 6, 8);

    Vector expected_result = vector(-8, 18, 32);
    Vector result = matrix_mul(transform, v);

    assert_float(result.x, ==, expected_result.x);
    assert_float(result.y, ==, expected_result.y);
    assert_float(result.z, ==, expected_result.z);
    assert_float(result.w, ==, expected_result.w);

    assert_true(vector_eq(result, expected_result));

    return MUNIT_OK;
}

MunitResult T06_Vector_Mul_Scale_Inv(const MunitParameter args[], void *user_data)
{
    Matrix transform = matrix_scale(2, 3, 4);
    Matrix inv = matrix_inverse(transform);
    Vector v = vector(-4, 6, 8);

    Vector expected_result = vector(-2, 2, 2);
    Vector result = matrix_mul(inv, v);

    assert_float(result.x, ==, expected_result.x);
    assert_float(result.y, ==, expected_result.y);
    assert_float(result.z, ==, expected_result.z);
    assert_float(result.w, ==, expected_result.w);

    assert_true(vector_eq(result, expected_result));

    return MUNIT_OK;
}

MunitResult T07_Negative_Scale_Is_Reflection(const MunitParameter args[], void *user_data)
{
    Matrix transform = matrix_scale(-1, 1, 1);
    Point p = point(2, 3, 4);

    Point expected_result = point(-2, 3, 4);
    Point result = matrix_mul(transform, p);

    assert_float(result.x, ==, expected_result.x);
    assert_float(result.y, ==, expected_result.y);
    assert_float(result.z, ==, expected_result.z);
    assert_float(result.w, ==, expected_result.w);

    assert_true(vector_eq(result, expected_result));

    return MUNIT_OK;
}

MunitResult T08_X_Rotation(const MunitParameter args[], void *user_data)
{
    Point p = point(0, 1, 0);
    Matrix half_quarter = matrix_rotation_x(M_PI / 4);
    Matrix full_quarter = matrix_rotation_x(M_PI / 2);

    Point expected_result_half = point(0, sqrt(2)/2, sqrt(2)/2);
    Point expected_result_full = point(0, 0, 1);

    Point result_half = matrix_mul(half_quarter, p);
    Point result_full = matrix_mul(full_quarter, p);

    assert_float(result_half.x, ==, expected_result_half.x);
    assert_float(result_half.y, ==, expected_result_half.y);
    assert_float(result_half.z, ==, expected_result_half.z);
    assert_float(result_half.w, ==, expected_result_half.w);

    assert_true(point_eq(result_half, expected_result_half));

    assert_double_equal(result_full.x, expected_result_full.x, 5);
    assert_double_equal(result_full.y, expected_result_full.y, 5);
    assert_double_equal(result_full.z, expected_result_full.z, 5);
    assert_double_equal(result_full.w, expected_result_full.w, 5);

    assert_true(point_eq(result_full, expected_result_full));

    return MUNIT_OK;
}

MunitResult T09_X_Rotation_Inv(const MunitParameter args[], void *user_data)
{
    Point p = point(0, 1, 0);
    Matrix half_quarter = matrix_rotation_x(M_PI / 4);
    Matrix inv = matrix_inverse(half_quarter);

    Point expected_result = point(0, sqrt(2)/2, -(sqrt(2)/2));

    Point result_half = matrix_mul(inv, p);

    assert_double_equal(result_half.x, expected_result.x, 5);
    assert_double_equal(result_half.y, expected_result.y, 5);
    assert_double_equal(result_half.z, expected_result.z, 5);
    assert_double_equal(result_half.w, expected_result.w, 5);

    assert_true(point_eq(result_half, expected_result));

    return MUNIT_OK;
}

MunitResult T10_Y_Rotation(const MunitParameter args[], void *user_data)
{
    Point p = point(0, 0, 1);
    Matrix half_quarter = matrix_rotation_y(M_PI / 4);
    Matrix full_quarter = matrix_rotation_y(M_PI / 2);

    Point expected_result_half = point(sqrt(2)/2, 0, sqrt(2)/2);
    Point expected_result_full = point(1, 0, 0);

    Point result_half = matrix_mul(half_quarter, p);
    Point result_full = matrix_mul(full_quarter, p);

    assert_float(result_half.x, ==, expected_result_half.x);
    assert_float(result_half.y, ==, expected_result_half.y);
    assert_float(result_half.z, ==, expected_result_half.z);
    assert_float(result_half.w, ==, expected_result_half.w);

    assert_true(point_eq(result_half, expected_result_half));

    assert_double_equal(result_full.x, expected_result_full.x, 5);
    assert_double_equal(result_full.y, expected_result_full.y, 5);
    assert_double_equal(result_full.z, expected_result_full.z, 5);
    assert_double_equal(result_full.w, expected_result_full.w, 5);

    assert_true(point_eq(result_full, expected_result_full));

    return MUNIT_OK;
}

MunitResult T11_Z_Rotation(const MunitParameter args[], void *user_data)
{
    Point p = point(0, 1, 0);
    Matrix half_quarter = matrix_rotation_z(M_PI / 4);
    Matrix full_quarter = matrix_rotation_z(M_PI / 2);

    Point expected_result_half = point(-(sqrt(2)/2), sqrt(2)/2, 0);
    Point expected_result_full = point(-1, 0, 0);

    Point result_half = matrix_mul(half_quarter, p);
    Point result_full = matrix_mul(full_quarter, p);

    assert_float(result_half.x, ==, expected_result_half.x);
    assert_float(result_half.y, ==, expected_result_half.y);
    assert_float(result_half.z, ==, expected_result_half.z);
    assert_float(result_half.w, ==, expected_result_half.w);

    assert_true(point_eq(result_half, expected_result_half));

    assert_double_equal(result_full.x, expected_result_full.x, 5);
    assert_double_equal(result_full.y, expected_result_full.y, 5);
    assert_double_equal(result_full.z, expected_result_full.z, 5);
    assert_double_equal(result_full.w, expected_result_full.w, 5);

    assert_true(point_eq(result_full, expected_result_full));

    return MUNIT_OK;
}

MunitTest ch04_tests[] = {
    REGISTER_TEST(T01_Point_Mul_Translation)
    REGISTER_TEST(T02_Point_Mul_Translation_Inv)
    REGISTER_TEST(T03_Vector_Mul_Translation)
    REGISTER_TEST(T04_Point_Mul_Scale)
    REGISTER_TEST(T05_Vector_Mul_Scale)
    REGISTER_TEST(T06_Vector_Mul_Scale_Inv)
    REGISTER_TEST(T07_Negative_Scale_Is_Reflection)
    REGISTER_TEST(T08_X_Rotation)
    REGISTER_TEST(T09_X_Rotation_Inv)
    REGISTER_TEST(T10_Y_Rotation)
    REGISTER_TEST(T11_Z_Rotation)

    REGISTER_EMPTY_TEST()
};

static const MunitSuite CH04_Suite = {
    (char*)"CH04",
    ch04_tests,
    nullptr,
    1,
    MUNIT_SUITE_OPTION_NONE,
};
