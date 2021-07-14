#include "common.h"

#include "matrix.h"
#include "tuple.h"
#include <cstdio>

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
    return MUNIT_OK;
}

MunitResult T02_M4x4_Construction(const MunitParameter args[], void *user_data)
{
    Matrix m = matrix(1,    2,    3,    4,
                      5.5,  6.5,  7.5,  8.5,
                      9,    10,   11,   12,
                      13.5, 14.5, 15.5, 16.5);

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
        Matrix2x2 m = matrix2x2(1, 2,
                                3, 4 );

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
    Matrix2x2 m = matrix2x2(-3,  5,
                             1, -2 );

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
    return MUNIT_OK;
}

MunitResult T06_M3x3_Construction(const MunitParameter args[], void *user_data)
{
    Matrix3x3 m = matrix3x3(-3,  5,  0,
                             1, -2, -7,
                             0,  1,  1);

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
    Matrix a = matrix(1.f, 2.f, 3.f, 4.00001f,
                      5.f, 6.f, 7.f, 8.f,
                      9.f, 8.f, 7.f, 6.f,
                      5.f, 4.f, 3.f, 2.f );

    Matrix b = matrix(1.f, 2.f, 3.f, 4.000018888f,
                      5.f, 6.f, 7.f, 8.f,
                      9.f, 8.f, 7.f, 6.f,
                      5.f, 4.f, 3.f, 2.f );

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
    Matrix a = matrix(1.f, 2.f, 3.f, 4.00002f,
                      5.f, 6.f, 7.f, 8.f,
                      9.f, 8.f, 7.f, 6.f,
                      5.f, 4.f, 3.f, 2.f );

    Matrix b = matrix(1.0001f, 2.00005f, 3.001f, 4.000018f,
                      6.f,     7.f,      8.f,    9.f,
                      8.f,     7.f,      6.f,    5.f,
                      4.f,     3.f,      2.f,    1.f );

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
    Matrix3x3 a = matrix3x3(1.f, 2.f, 3.00002f,
                            4.f, 5.f, 6.f,
                            7.f, 8.f, 9.f);

    Matrix3x3 b = matrix3x3(1.f, 2.f, 3.00001999f,
                            4.f, 5.f, 6.f,
                            7.f, 8.f, 9.f);


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
    Matrix3x3 a = matrix3x3(1.f, 2.f, 3.00002f,
                            4.f, 5.f, 6.f,
                            7.f, 8.f, 9.f);

    Matrix3x3 b = matrix3x3(1.0001f, 2.000005f, 3.00001888f,
                            5.f,     4.f,       3.f,
                            9.f,     7.f,       8.f);

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
    Matrix2x2 a = matrix2x2(1.f, 2.00002f,
                            4.f, 5.f );

    Matrix2x2 b = matrix2x2(1.f, 2.00001999f,
                            4.f, 5.f );

    munit_assert_double_equal(a[0][0], b[0][0], 5);
    munit_assert_double_equal(a[0][1], b[0][1], 5);

    munit_assert_double_equal(a[1][0], b[1][0], 5);
    munit_assert_double_equal(a[1][1], b[1][1], 5);

    assert_true(matrix_eq(a, b));

    return MUNIT_OK;
}

MunitResult T12_M2x2_CMP_Different(const MunitParameter args[], void *user_data)
{
    Matrix2x2 a = matrix2x2(1.f, 2.00002f,
                            4.f, 5.f );

    Matrix2x2 b = matrix2x2(1.0001f, 2.00001888f,
                            5.f,     4.f );

    assert_float(a[0][0], !=, b[0][0]);
    assert_float(a[0][1], !=, b[0][1]);

    assert_float(a[1][0], !=, b[1][0]);
    assert_float(a[1][1], !=, b[1][1]);

    assert_false(matrix_eq(a, b));

    return MUNIT_OK;
}

MunitResult T13_M4x4_Mul(const MunitParameter args[], void *user_data)
{
    Matrix a = matrix(1, 2, 3, 4,
                      5, 6, 7, 8,
                      9, 8, 7, 6,
                      5, 4, 3, 2 );

    Matrix b = matrix(-2, 1, 2,  3,
                       3, 2, 1, -1,
                       4, 3, 6,  5,
                       1, 2, 7,  8 );

    Matrix expected_result = matrix(20, 22,  50,  48,
                                    44, 54, 114, 108,
                                    40, 58, 110, 102,
                                    16, 26,  46,  42 );

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
    Matrix a = matrix(1, 2, 3, 4,
                      2, 4, 4, 2,
                      8, 6, 4, 1,
                      0, 0, 0, 1 );

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

MunitResult T15_M4x4_Mul_Identity(const MunitParameter args[], void *user_data)
{
    Matrix a = matrix(0, 1,  2,  4,
                      1, 2,  4,  8,
                      2, 4,  8, 16,
                      4, 8, 16, 32 );

    Matrix result = matrix_mul(a, identity_matrix);

    assert_float(result.m00, ==, a.m00);
    assert_float(result.m01, ==, a.m01);
    assert_float(result.m02, ==, a.m02);
    assert_float(result.m03, ==, a.m03);

    assert_float(result.m10, ==, a.m10);
    assert_float(result.m11, ==, a.m11);
    assert_float(result.m12, ==, a.m12);
    assert_float(result.m13, ==, a.m13);

    assert_float(result.m20, ==, a.m20);
    assert_float(result.m21, ==, a.m21);
    assert_float(result.m22, ==, a.m22);
    assert_float(result.m23, ==, a.m23);

    assert_float(result.m30, ==, a.m30);
    assert_float(result.m31, ==, a.m31);
    assert_float(result.m32, ==, a.m32);
    assert_float(result.m33, ==, a.m33);

    assert_true(matrix_eq(result, a));

    return MUNIT_OK;
}

MunitResult T16_M4x4_Mul_Identity_Tuple(const MunitParameter args[], void *user_data)
{
    Tuple t = { 1, 2, 3, 4 };

    Tuple result = matrix_mul(identity_matrix, t);

    assert_float(result.x, ==, t.x);
    assert_float(result.y, ==, t.y);
    assert_float(result.z, ==, t.z);
    assert_float(result.w, ==, t.w);

    assert_true(tuple_eq(result, t));

    return MUNIT_OK;
}

MunitResult T17_M4x4_Transpose(const MunitParameter args[], void *user_data)
{
    Matrix a = matrix(0, 9, 3, 0,
                      9, 8, 0, 8,
                      1, 8, 5, 3,
                      0, 0, 5, 8 );

    Matrix expected_result = matrix(0, 9, 1, 0,
                                    9, 8, 8, 0,
                                    3, 0, 5, 5,
                                    0, 8, 3, 8 );

    Matrix result = matrix_transpose(a);

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

MunitResult T18_M4x4_Transpose_Identity(const MunitParameter args[], void *user_data)
{
    Matrix a = matrix_transpose(identity_matrix);

    assert_float(a.m00, ==, identity_matrix.m00);
    assert_float(a.m01, ==, identity_matrix.m01);
    assert_float(a.m02, ==, identity_matrix.m02);
    assert_float(a.m03, ==, identity_matrix.m03);

    assert_float(a.m10, ==, identity_matrix.m10);
    assert_float(a.m11, ==, identity_matrix.m11);
    assert_float(a.m12, ==, identity_matrix.m12);
    assert_float(a.m13, ==, identity_matrix.m13);

    assert_float(a.m20, ==, identity_matrix.m20);
    assert_float(a.m21, ==, identity_matrix.m21);
    assert_float(a.m22, ==, identity_matrix.m22);
    assert_float(a.m23, ==, identity_matrix.m23);

    assert_float(a.m30, ==, identity_matrix.m30);
    assert_float(a.m31, ==, identity_matrix.m31);
    assert_float(a.m32, ==, identity_matrix.m32);
    assert_float(a.m33, ==, identity_matrix.m33);

    assert_true(matrix_eq(a, identity_matrix));

    return MUNIT_OK;
}

MunitResult T19_M2x2_Determinant(const MunitParameter args[], void *user_data)
{
    Matrix2x2 a = matrix2x2( 1, 5,
                            -3, 2);

    float expected_result = 17;
    float result = matrix_determinant(a);

    assert_float(result, ==, expected_result);

    return MUNIT_OK;
}

MunitResult T20_M3x3_Submatrix_2x2(const MunitParameter args[], void *user_data)
{
    Matrix3x3 a = matrix3x3( 1, 5, 0,
                            -3, 2, 7,
                             0, 6, 3);

    Matrix2x2 expected_result = matrix2x2(-3, 2,
                                           0, 6);

    Matrix2x2 result = matrix_submatrix(a, 0, 2);

    assert_float(result.m00, ==, expected_result.m00);
    assert_float(result.m01, ==, expected_result.m01);

    assert_float(result.m10, ==, expected_result.m10);
    assert_float(result.m11, ==, expected_result.m11);

    assert_true(matrix_eq(result, expected_result));

    return MUNIT_OK;
}

MunitResult T21_M4x4_Submatrix_3x3(const MunitParameter args[], void *user_data)
{
    Matrix a = matrix(-6, 1,  1, 6,
                      -8, 5,  8, 6,
                      -1, 0,  8, 2,
                      -7, 1, -1, 1 );

    Matrix3x3 expected_result = matrix3x3(-6,  1, 6,
                                          -8,  8, 6,
                                          -7, -1, 1);

    Matrix3x3 result = matrix_submatrix(a, 2, 1);

    assert_float(result.m00, ==, expected_result.m00);
    assert_float(result.m01, ==, expected_result.m01);
    assert_float(result.m02, ==, expected_result.m02);

    assert_float(result.m10, ==, expected_result.m10);
    assert_float(result.m11, ==, expected_result.m11);
    assert_float(result.m12, ==, expected_result.m12);

    assert_float(result.m20, ==, expected_result.m20);
    assert_float(result.m21, ==, expected_result.m21);
    assert_float(result.m22, ==, expected_result.m22);

    assert_true(matrix_eq(result, expected_result));

    return MUNIT_OK;
}

MunitResult T22_M3x3_Minor(const MunitParameter args[], void *user_data)
{
    Matrix3x3 a = matrix3x3(3,  5,  0,
                            2, -1, -7,
                            6, -1,  5);

    Matrix2x2 b = matrix_submatrix(a, 1, 0);

    assert_float(matrix_determinant(b), ==, 25);
    assert_float(matrix_minor(a, 1, 0), ==, 25);

    assert_float(matrix_minor(a, 0, 0), ==, -12);
    assert_float(matrix_minor(a, 0, 1), ==, 52);
    assert_float(matrix_minor(a, 0, 2), ==, 4);

    assert_float(matrix_minor(a, 1, 1), ==, 15);
    assert_float(matrix_minor(a, 1, 2), ==, -33);

    assert_float(matrix_minor(a, 2, 0), ==, -35);
    assert_float(matrix_minor(a, 2, 1), ==, -21);
    assert_float(matrix_minor(a, 2, 2), ==, -13);
    return MUNIT_OK;
}

MunitResult T23_M3x3_Cofactor(const MunitParameter args[], void *user_data)
{
    Matrix3x3 a = matrix3x3(3,  5,  0,
                            2, -1, -7,
                            6, -1,  5);

    assert_float(matrix_cofactor(a, 0, 0), ==, -12);
    assert_float(matrix_cofactor(a, 0, 1), ==, -52);
    assert_float(matrix_cofactor(a, 0, 2), ==, 4);

    assert_float(matrix_cofactor(a, 1, 0), ==, -25);
    assert_float(matrix_cofactor(a, 1, 1), ==, 15);
    assert_float(matrix_cofactor(a, 1, 2), ==, 33);

    assert_float(matrix_cofactor(a, 2, 0), ==, -35);
    assert_float(matrix_cofactor(a, 2, 1), ==, 21);
    assert_float(matrix_cofactor(a, 2, 2), ==, -13);

    return MUNIT_OK;
}

MunitResult T24_M3x3_Determinant(const MunitParameter args[], void *user_data)
{
    Matrix3x3 a = matrix3x3( 1, 2,  6,
                            -5, 8, -4,
                             2, 6,  4);

    assert_float(matrix_determinant(a), ==, -196);

    return MUNIT_OK;
}

MunitResult T25_M4x4_Determinant(const MunitParameter args[], void *user_data)
{
    Matrix a = matrix(-2, -8,  3,  5,
                      -3,  1,  7,  3,
                       1,  2, -9,  6,
                      -6,  7,  7, -9 );

    assert_float(matrix_cofactor(a, 0, 0), ==, 690);
    assert_float(matrix_cofactor(a, 0, 1), ==, 447);
    assert_float(matrix_cofactor(a, 0, 2), ==, 210);
    assert_float(matrix_cofactor(a, 0, 3), ==, 51);
    assert_float(matrix_determinant(a), ==, -4071);

    return MUNIT_OK;
}

MunitResult T26_M4x4_Invertibility(const MunitParameter args[], void *user_data)
{
    Matrix a = matrix(6,  4, 4,  4,
                      5,  5, 7,  6,
                      4, -9, 3, -7,
                      9,  1, 7, -6 );

    // Non zero determinant means this matrix can be inverted
    assert_float(matrix_determinant(a), ==, -2120);

    return MUNIT_OK;
}

MunitResult T27_M4x4_Non_Invertibility(const MunitParameter args[], void *user_data)
{
    Matrix a = matrix(-4,  2, -2, -3,
                       9,  6,  2,  6,
                       0, -5,  1, -5,
                       0,  0,  0,  0 );

    // Zero determinant means this matrix can not be inverted
    assert_float(matrix_determinant(a), ==, 0);
    return MUNIT_OK;
}

MunitResult T28_M4x4_Inverse(const MunitParameter args[], void *user_data)
{
    Matrix a = matrix(-5,  2,  6, -8,
                       1, -5,  1,  8,
                       7,  7, -6, -7,
                       1, -3,  7,  4 );

    Matrix expected_result = matrix( 0.21805f,  0.45113f,  0.24060f, -0.04511f,
                                    -0.80827f, -1.45677f, -0.44361f,  0.52068f,
                                    -0.07895f, -0.22368f, -0.05263f,  0.19737f,
                                    -0.52256f, -0.81391f, -0.30075f,  0.30639f);

    Matrix b = matrix_inverse(a);

    assert_float(matrix_determinant(a), ==, 532);
    assert_float(matrix_cofactor(a, 2, 3), ==, -160);
    assert_float(b.m32, ==, (-160.f/532.f));
    assert_float(matrix_cofactor(a, 3, 2), ==, 105);
    assert_float(b.m23, ==, (105.f/532.f));

    assert_true(matrix_eq(b, expected_result));

    return MUNIT_OK;
}

MunitResult T29_M4x4_Inverse2(const MunitParameter args[], void *user_data)
{
    Matrix a = matrix( 8, -5,  9,  2,
                       7,  5,  6,  1,
                      -6,  0,  9,  6,
                      -3,  0, -9, -4);

    Matrix expected_result = matrix(-0.15385f, -0.15385f, -0.28205f, -0.53846f,
                                    -0.07692f,  0.12308f,  0.02564f,  0.03077f,
                                     0.35897f,  0.35897f,  0.43590f,  0.92308f,
                                    -0.69231f, -0.69231f, -0.76923f, -1.92308f );

    Matrix b = matrix_inverse(a);

    assert_true(matrix_eq(b, expected_result));

    return MUNIT_OK;
}

MunitResult T30_M4x4_Inverse3(const MunitParameter args[], void *user_data)
{
    Matrix a = matrix( 9,  3,  0,  9,
                      -5, -2, -6, -3,
                      -4,  9,  6,  4,
                      -7,  6,  6,  2);

    Matrix expected_result = matrix(-0.04074f, -0.07778f,  0.14444f, -0.22222f,
                                    -0.07778f,  0.03333f,  0.36667f, -0.33333f,
                                    -0.02901f, -0.14630f, -0.10926f,  0.12963f,
                                     0.17778f,  0.06667f, -0.26667f,  0.33333f);

    Matrix b = matrix_inverse(a);

    assert_true(matrix_eq(b, expected_result));

    return MUNIT_OK;

}

MunitResult T31_M4x4_Mul_Inverse(const MunitParameter args[], void *user_data)
{
    Matrix a = matrix( 3, -9,  7,  3,
                       3, -8,  2, -9,
                      -4,  4,  4,  1,
                      -6,  5, -1,  1);

    Matrix b = matrix(8,  2,  2,  2,
                      3, -1,  7,  0,
                      7,  0,  5,  4,
                      6, -2,  0,  5);

    Matrix c = matrix_mul(a, b);

    assert_true(matrix_eq(matrix_mul(c, matrix_inverse(b)), a));

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
    REGISTER_TEST(T15_M4x4_Mul_Identity)
    REGISTER_TEST(T16_M4x4_Mul_Identity_Tuple)
    REGISTER_TEST(T17_M4x4_Transpose)
    REGISTER_TEST(T18_M4x4_Transpose_Identity)
    REGISTER_TEST(T19_M2x2_Determinant)
    REGISTER_TEST(T20_M3x3_Submatrix_2x2)
    REGISTER_TEST(T21_M4x4_Submatrix_3x3)
    REGISTER_TEST(T22_M3x3_Minor)
    REGISTER_TEST(T23_M3x3_Cofactor)
    REGISTER_TEST(T24_M3x3_Determinant)
    REGISTER_TEST(T25_M4x4_Determinant)
    REGISTER_TEST(T26_M4x4_Invertibility)
    REGISTER_TEST(T27_M4x4_Non_Invertibility)
    REGISTER_TEST(T28_M4x4_Inverse)
    REGISTER_TEST(T29_M4x4_Inverse2)
    REGISTER_TEST(T30_M4x4_Inverse3)
    REGISTER_TEST(T31_M4x4_Mul_Inverse)

    REGISTER_EMPTY_TEST()
};

static const MunitSuite CH03_Suite = {
    (char*)"CH03",
    ch03_tests,
    nullptr,
    1,
    MUNIT_SUITE_OPTION_NONE,
};
