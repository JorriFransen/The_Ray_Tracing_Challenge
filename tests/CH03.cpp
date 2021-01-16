#include "common.h"

#include "matrix.h"
#include "tuple.h"

using namespace RayTracer;

MunitResult T01_M4x4_Layout(const MunitParameter args[], void *user_data)
{
    {
        Matrix m = matrix(1,  2,  3,  4,
                          5,  6,  7,  8,
                          9,  10, 11, 12,
                          13, 14, 15, 16);

        assert_float(m.m00, ==, 1);
        assert_float(m.m01, ==, 2);
        assert_float(m.m02, ==, 3);
        assert_float(m.m03, ==, 4);

        assert_float(m.m10, ==, 5);
        assert_float(m.m11, ==, 6);
        assert_float(m.m12, ==, 7);
        assert_float(m.m13, ==, 8);

        assert_float(m.m20, ==, 9);
        assert_float(m.m21, ==, 10);
        assert_float(m.m22, ==, 11);
        assert_float(m.m23, ==, 12);

        assert_float(m.m30, ==, 13);
        assert_float(m.m31, ==, 14);
        assert_float(m.m32, ==, 15);
        assert_float(m.m33, ==, 16);

        assert_float(m.m[0][0], ==, 1);
        assert_float(m.m[0][1], ==, 2);
        assert_float(m.m[0][2], ==, 3);
        assert_float(m.m[0][3], ==, 4);

        assert_float(m.m[1][0], ==, 5);
        assert_float(m.m[1][1], ==, 6);
        assert_float(m.m[1][2], ==, 7);
        assert_float(m.m[1][3], ==, 8);

        assert_float(m.m[2][0], ==, 9);
        assert_float(m.m[2][1], ==, 10);
        assert_float(m.m[2][2], ==, 11);
        assert_float(m.m[2][3], ==, 12);

        assert_float(m.m[3][0], ==, 13);
        assert_float(m.m[3][1], ==, 14);
        assert_float(m.m[3][2], ==, 15);
        assert_float(m.m[3][3], ==, 16);

        assert_float(m[0][0], ==, 1);
        assert_float(m[0][1], ==, 2);
        assert_float(m[0][2], ==, 3);
        assert_float(m[0][3], ==, 4);

        assert_float(m[1][0], ==, 5);
        assert_float(m[1][1], ==, 6);
        assert_float(m[1][2], ==, 7);
        assert_float(m[1][3], ==, 8);

        assert_float(m[2][0], ==, 9);
        assert_float(m[2][1], ==, 10);
        assert_float(m[2][2], ==, 11);
        assert_float(m[2][3], ==, 12);

        assert_float(m[3][0], ==, 13);
        assert_float(m[3][1], ==, 14);
        assert_float(m[3][2], ==, 15);
        assert_float(m[3][3], ==, 16);
    }
    {
        Matrix m = { 1,  2,  3,  4,
                     5,  6,  7,  8,
                     9,  10, 11, 12,
                     13, 14, 15, 16 };

        assert_float(m.m00, ==, 1);
        assert_float(m.m01, ==, 2);
        assert_float(m.m02, ==, 3);
        assert_float(m.m03, ==, 4);

        assert_float(m.m10, ==, 5);
        assert_float(m.m11, ==, 6);
        assert_float(m.m12, ==, 7);
        assert_float(m.m13, ==, 8);

        assert_float(m.m20, ==, 9);
        assert_float(m.m21, ==, 10);
        assert_float(m.m22, ==, 11);
        assert_float(m.m23, ==, 12);

        assert_float(m.m30, ==, 13);
        assert_float(m.m31, ==, 14);
        assert_float(m.m32, ==, 15);
        assert_float(m.m33, ==, 16);

        assert_float(m.m[0][0], ==, 1);
        assert_float(m.m[0][1], ==, 2);
        assert_float(m.m[0][2], ==, 3);
        assert_float(m.m[0][3], ==, 4);

        assert_float(m.m[1][0], ==, 5);
        assert_float(m.m[1][1], ==, 6);
        assert_float(m.m[1][2], ==, 7);
        assert_float(m.m[1][3], ==, 8);

        assert_float(m.m[2][0], ==, 9);
        assert_float(m.m[2][1], ==, 10);
        assert_float(m.m[2][2], ==, 11);
        assert_float(m.m[2][3], ==, 12);

        assert_float(m.m[3][0], ==, 13);
        assert_float(m.m[3][1], ==, 14);
        assert_float(m.m[3][2], ==, 15);
        assert_float(m.m[3][3], ==, 16);

        assert_float(m[0][0], ==, 1);
        assert_float(m[0][1], ==, 2);
        assert_float(m[0][2], ==, 3);
        assert_float(m[0][3], ==, 4);

        assert_float(m[1][0], ==, 5);
        assert_float(m[1][1], ==, 6);
        assert_float(m[1][2], ==, 7);
        assert_float(m[1][3], ==, 8);

        assert_float(m[2][0], ==, 9);
        assert_float(m[2][1], ==, 10);
        assert_float(m[2][2], ==, 11);
        assert_float(m[2][3], ==, 12);

        assert_float(m[3][0], ==, 13);
        assert_float(m[3][1], ==, 14);
        assert_float(m[3][2], ==, 15);
        assert_float(m[3][3], ==, 16);
    }
    return MUNIT_OK;
}

MunitResult T02_M4x4_Construction(const MunitParameter args[], void *user_data)
{
    Matrix m = { 1,    2,    3,    4,
                 5.5,  6.5,  7.5,  8.5,
                 9,    10,   11,   12,
                 13.5, 14.5, 15.5, 16.5} ;

    assert_float(m[0][0], ==, 1);
    assert_float(m[0][3], ==, 4);
    assert_float(m[1][0], ==, 5.5);
    assert_float(m[1][2], ==, 7.5);
    assert_float(m[2][2], ==, 11);
    assert_float(m[3][0], ==, 13.5);
    assert_float(m[3][2], ==, 15.5);
return MUNIT_OK;
}

MunitResult T03_M2x2_Layout(const MunitParameter args[], void *user_data)
{
    {
        Matrix2x2 m = matrix2x2(1, 2,
                                3, 4);

        assert_float(m.m00, ==, 1);
        assert_float(m.m01, ==, 2);

        assert_float(m.m10, ==, 3);
        assert_float(m.m11, ==, 4);

        assert_float(m.m[0][0], ==, 1);
        assert_float(m.m[0][1], ==, 2);

        assert_float(m.m[1][0], ==, 3);
        assert_float(m.m[1][1], ==, 4);

        assert_float(m[0][0], ==, 1);
        assert_float(m[0][1], ==, 2);

        assert_float(m[1][0], ==, 3);
        assert_float(m[1][1], ==, 4);
    }
    {
        Matrix2x2 m = { 1, 2,
                        3, 4 };

        assert_float(m.m00, ==, 1);
        assert_float(m.m01, ==, 2);

        assert_float(m.m10, ==, 3);
        assert_float(m.m11, ==, 4);

        assert_float(m.m[0][0], ==, 1);
        assert_float(m.m[0][1], ==, 2);

        assert_float(m.m[1][0], ==, 3);
        assert_float(m.m[1][1], ==, 4);

        assert_float(m[0][0], ==, 1);
        assert_float(m[0][1], ==, 2);

        assert_float(m[1][0], ==, 3);
        assert_float(m[1][1], ==, 4);
    }
    return MUNIT_OK;
}

MunitResult T04_M2x2_Construction(const MunitParameter args[], void *user_data)
{
    Matrix2x2 m = { -3,  5,
                     1, -2 };

    assert_float(m[0][0], ==, -3);
    assert_float(m[0][1], ==, 5);
    assert_float(m[1][0], ==, 1);
    assert_float(m[1][1], ==, -2);

    return MUNIT_OK;
}

MunitResult T05_M3x3_Layout(const MunitParameter args[], void *user_data)
{
    {
        Matrix3x3 m = matrix3x3(1, 2, 3,
                                4, 5, 6,
                                7, 8, 9);

        assert_float(m.m00, ==, 1);
        assert_float(m.m01, ==, 2);
        assert_float(m.m02, ==, 3);

        assert_float(m.m10, ==, 4);
        assert_float(m.m11, ==, 5);
        assert_float(m.m12, ==, 6);

        assert_float(m.m20, ==, 7);
        assert_float(m.m21, ==, 8);
        assert_float(m.m22, ==, 9);

        assert_float(m.m[0][0], ==, 1);
        assert_float(m.m[0][1], ==, 2);
        assert_float(m.m[0][2], ==, 3);

        assert_float(m.m[1][0], ==, 4);
        assert_float(m.m[1][1], ==, 5);
        assert_float(m.m[1][2], ==, 6);

        assert_float(m.m[2][0], ==, 7);
        assert_float(m.m[2][1], ==, 8);
        assert_float(m.m[2][2], ==, 9);

        assert_float(m[0][0], ==, 1);
        assert_float(m[0][1], ==, 2);
        assert_float(m[0][2], ==, 3);

        assert_float(m[1][0], ==, 4);
        assert_float(m[1][1], ==, 5);
        assert_float(m[1][2], ==, 6);

        assert_float(m[2][0], ==, 7);
        assert_float(m[2][1], ==, 8);
        assert_float(m[2][2], ==, 9);
    }
    {
        Matrix3x3 m = { 1, 2, 3,
                        4, 5, 6,
                        7, 8, 9 };

        assert_float(m.m00, ==, 1);
        assert_float(m.m01, ==, 2);
        assert_float(m.m02, ==, 3);

        assert_float(m.m10, ==, 4);
        assert_float(m.m11, ==, 5);
        assert_float(m.m12, ==, 6);

        assert_float(m.m20, ==, 7);
        assert_float(m.m21, ==, 8);
        assert_float(m.m22, ==, 9);

        assert_float(m.m[0][0], ==, 1);
        assert_float(m.m[0][1], ==, 2);
        assert_float(m.m[0][2], ==, 3);

        assert_float(m.m[1][0], ==, 4);
        assert_float(m.m[1][1], ==, 5);
        assert_float(m.m[1][2], ==, 6);

        assert_float(m.m[2][0], ==, 7);
        assert_float(m.m[2][1], ==, 8);
        assert_float(m.m[2][2], ==, 9);

        assert_float(m[0][0], ==, 1);
        assert_float(m[0][1], ==, 2);
        assert_float(m[0][2], ==, 3);

        assert_float(m[1][0], ==, 4);
        assert_float(m[1][1], ==, 5);
        assert_float(m[1][2], ==, 6);

        assert_float(m[2][0], ==, 7);
        assert_float(m[2][1], ==, 8);
        assert_float(m[2][2], ==, 9);
    }
    return MUNIT_OK;
}

MunitResult T06_M3x3_Construction(const MunitParameter args[], void *user_data)
{
    Matrix3x3 m = { -3,  5,  0,
                     1, -2, -7,
                     0,  1,  1 };

    assert_float(m[0][0], ==, -3);
    assert_float(m[0][1], ==, 5);
    assert_float(m[0][2], ==, 0);

    assert_float(m[1][0], ==, 1);
    assert_float(m[1][1], ==, -2);
    assert_float(m[1][2], ==, -7);

    assert_float(m[2][0], ==, 0);
    assert_float(m[2][1], ==, 1);
    assert_float(m[2][2], ==, 1);

    return MUNIT_OK;
}

MunitResult T07_M4x4_CMP_Identical(const MunitParameter args[], void *user_data)
{
    Matrix a = { 1, 2, 3, 4.00001,
                 5, 6, 7, 8,
                 9, 8, 7, 6,
                 5, 4, 3, 2 };

    Matrix b = { 1, 2, 3, 4.000018888,
                 5, 6, 7, 8,
                 9, 8, 7, 6,
                 5, 4, 3, 2 };

    munit_assert_double_equal(a[0][0], b[0][0], 5);
    munit_assert_double_equal(a[0][1], b[0][1], 5);
    munit_assert_double_equal(a[0][2], b[0][2], 5);
    munit_assert_double_equal(a[0][3], b[0][3], 5);

    munit_assert_double_equal(a[1][0], b[1][0], 5);
    munit_assert_double_equal(a[1][1], b[1][1], 5);
    munit_assert_double_equal(a[1][2], b[1][2], 5);
    munit_assert_double_equal(a[1][3], b[1][3], 5);

    munit_assert_double_equal(a[2][0], b[2][0], 5);
    munit_assert_double_equal(a[2][1], b[2][1], 5);
    munit_assert_double_equal(a[2][2], b[2][2], 5);
    munit_assert_double_equal(a[2][3], b[2][3], 5);

    munit_assert_double_equal(a[3][0], b[3][0], 5);
    munit_assert_double_equal(a[3][1], b[3][1], 5);
    munit_assert_double_equal(a[3][2], b[3][2], 5);
    munit_assert_double_equal(a[3][3], b[3][3], 5);

    assert_true(matrix_eq(a, b));

    return MUNIT_OK;
}

MunitResult T08_M4x4_CMP_Different(const MunitParameter args[], void *user_data)
{
    Matrix a = { 1, 2, 3, 4.00002,
                 5, 6, 7, 8,
                 9, 8, 7, 6,
                 5, 4, 3, 2 };

    Matrix b = { 1.0001, 2.00005, 3.001, 4.000018,
                 6, 7, 8, 9,
                 8, 7, 6, 5,
                 4, 3, 2, 1 };

    assert_float(a[0][0], !=, b[0][0]);
    assert_float(a[0][1], !=, b[0][1]);
    assert_float(a[0][2], !=, b[0][2]);
    assert_float(a[0][3], !=, b[0][3]);

    assert_float(a[1][0], !=, b[1][0]);
    assert_float(a[1][1], !=, b[1][1]);
    assert_float(a[1][2], !=, b[1][2]);
    assert_float(a[1][3], !=, b[1][3]);

    assert_float(a[2][0], !=, b[2][0]);
    assert_float(a[2][1], !=, b[2][1]);
    assert_float(a[2][2], !=, b[2][2]);
    assert_float(a[2][3], !=, b[2][3]);

    assert_float(a[3][0], !=, b[3][0]);
    assert_float(a[3][1], !=, b[3][1]);
    assert_float(a[3][2], !=, b[3][2]);
    assert_float(a[3][3], !=, b[3][3]);

    assert_false(matrix_eq(a, b));


    return MUNIT_OK;
}

MunitResult T09_M3x3_CMP_Identical(const MunitParameter args[], void *user_data)
{
    Matrix3x3 a = { 1, 2, 3.00002,
                    4, 5, 6,
                    7, 8, 9 };

    Matrix3x3 b = { 1, 2, 3.00001999,
                    4, 5, 6,
                    7, 8, 9 };


    munit_assert_double_equal(a[0][0], b[0][0], 5);
    munit_assert_double_equal(a[0][1], b[0][1], 5);
    munit_assert_double_equal(a[0][2], b[0][2], 5);

    munit_assert_double_equal(a[1][0], b[1][0], 5);
    munit_assert_double_equal(a[1][1], b[1][1], 5);
    munit_assert_double_equal(a[1][2], b[1][2], 5);

    munit_assert_double_equal(a[2][0], b[2][0], 5);
    munit_assert_double_equal(a[2][1], b[2][1], 5);
    munit_assert_double_equal(a[2][2], b[2][2], 5);

    assert_true(matrix_eq(a, b));

    return MUNIT_OK;
}

MunitResult T10_M3x3_CMP_Different(const MunitParameter args[], void *user_data)
{
    Matrix3x3 a = { 1, 2, 3.00002,
                    4, 5, 6,
                    7, 8, 9 };

    Matrix3x3 b = { 1.0001, 2.000005, 3.00001888,
                    5, 4, 3,
                    9, 7, 8 };

    assert_float(a[0][0], !=, b[0][0]);
    assert_float(a[0][1], !=, b[0][1]);
    assert_float(a[0][2], !=, b[0][2]);

    assert_float(a[1][0], !=, b[1][0]);
    assert_float(a[1][1], !=, b[1][1]);
    assert_float(a[1][2], !=, b[1][2]);

    assert_float(a[2][0], !=, b[2][0]);
    assert_float(a[2][1], !=, b[2][1]);
    assert_float(a[2][2], !=, b[2][2]);

    assert_false(matrix_eq(a, b));

    return MUNIT_OK;
}

MunitResult T11_M2x2_CMP_Identical(const MunitParameter args[], void *user_data)
{
    Matrix2x2 a = { 1, 2.00002,
                    4, 5 };

    Matrix2x2 b = { 1, 2.00001999,
                    4, 5 };

    munit_assert_double_equal(a[0][0], b[0][0], 5);
    munit_assert_double_equal(a[0][1], b[0][1], 5);

    munit_assert_double_equal(a[1][0], b[1][0], 5);
    munit_assert_double_equal(a[1][1], b[1][1], 5);

    assert_true(matrix_eq(a, b));

    return MUNIT_OK;
}

MunitResult T12_M2x2_CMP_Different(const MunitParameter args[], void *user_data)
{
    Matrix2x2 a = { 1, 2.00002,
                    4, 5 };

    Matrix2x2 b = { 1.0001, 2.00001888,
                    5, 4 };

    assert_float(a[0][0], !=, b[0][0]);
    assert_float(a[0][1], !=, b[0][1]);

    assert_float(a[1][0], !=, b[1][0]);
    assert_float(a[1][1], !=, b[1][1]);

    assert_false(matrix_eq(a, b));

    return MUNIT_OK;
}

MunitResult T13_M4x4_Mul(const MunitParameter args[], void *user_data)
{
    Matrix a = { 1, 2, 3, 4,
                 5, 6, 7, 8,
                 9, 8, 7, 6,
                 5, 4, 3, 2 };

    Matrix b = { -2, 1, 2,  3,
                  3, 2, 1, -1,
                  4, 3, 6,  5,
                  1, 2, 7,  8 };

    Matrix expected_result = { 20, 22,  50,  48,
                               44, 54, 114, 108,
                               40, 58, 110, 102,
                               16, 26,  46,  42 };

    Matrix result = matrix_mul(a, b);

    assert_float(result.m00, ==, expected_result.m00);
    assert_float(result.m01, ==, expected_result.m01);
    assert_float(result.m02, ==, expected_result.m02);
    assert_float(result.m03, ==, expected_result.m03);

    assert_float(result.m10, ==, expected_result.m10);
    assert_float(result.m11, ==, expected_result.m11);
    assert_float(result.m12, ==, expected_result.m12);
    assert_float(result.m13, ==, expected_result.m13);

    assert_float(result.m20, ==, expected_result.m20);
    assert_float(result.m21, ==, expected_result.m21);
    assert_float(result.m22, ==, expected_result.m22);
    assert_float(result.m23, ==, expected_result.m23);

    assert_float(result.m30, ==, expected_result.m30);
    assert_float(result.m31, ==, expected_result.m31);
    assert_float(result.m32, ==, expected_result.m32);
    assert_float(result.m33, ==, expected_result.m33);

    assert_true(matrix_eq(result, expected_result));

    return MUNIT_OK;
}

MunitResult T14_M4x4_Mul_Tuple(const MunitParameter args[], void *user_data)
{
    Matrix a = { 1, 2, 3, 4,
                 2, 4, 4, 2,
                 8, 6, 4, 1,
                 0, 0, 0, 1 };

    Tuple b = tuple(1, 2, 3, 1);

    Tuple expected_result = tuple(18, 24, 33, 1);
    Tuple result = matrix_mul(a, b);

    assert_float(result.x, ==, expected_result.x);
    assert_float(result.y, ==, expected_result.y);
    assert_float(result.z, ==, expected_result.z);
    assert_float(result.w, ==, expected_result.w);

    assert_true(tuple_eq(result, expected_result));

    return MUNIT_OK;
}

MunitTest ch03_tests[] = {

    REGISTER_TEST(T01_M4x4_Layout)
    REGISTER_TEST(T02_M4x4_Construction)
    REGISTER_TEST(T03_M2x2_Layout)
    REGISTER_TEST(T04_M2x2_Construction)
    REGISTER_TEST(T05_M3x3_Layout)
    REGISTER_TEST(T06_M3x3_Construction)
    REGISTER_TEST(T07_M4x4_CMP_Identical)
    REGISTER_TEST(T08_M4x4_CMP_Different)
    REGISTER_TEST(T09_M3x3_CMP_Identical)
    REGISTER_TEST(T10_M3x3_CMP_Different)
    REGISTER_TEST(T11_M2x2_CMP_Identical)
    REGISTER_TEST(T12_M2x2_CMP_Different)
    REGISTER_TEST(T13_M4x4_Mul)
    REGISTER_TEST(T14_M4x4_Mul_Tuple)

    REGISTER_EMPTY_TEST()
};

static const MunitSuite CH03_Suite = {
    (char*)"CH03",
    ch03_tests,
    nullptr,
    1,
    MUNIT_SUITE_OPTION_NONE,
};
