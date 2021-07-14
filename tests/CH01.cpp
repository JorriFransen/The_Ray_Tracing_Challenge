
#include "common.h"

#include "tuple.h"
#include "point.h"
#include "vector.h"
#include "util.h"

#include <cmath>

using namespace RayTracer;

MunitResult T01_Tuple_Point_Constr(const MunitParameter args[], void *user_data)
{
    Tuple a = tuple(4.3f, -4.2f, 3.1f, 1.0f);

    assert_float(a.x, ==, 4.3f);
    assert_float(a.y, ==, -4.2f);
    assert_float(a.z, ==, 3.1f);
    assert_float(a.w, ==, 1.0f);

    assert_true(tuple_is_point(&a));
    assert_false(tuple_is_vector(&a));

    return MUNIT_OK;
}

MunitResult T02_Tuple_Vector_Constr(const MunitParameter args[], void *user_data)
{
    Tuple a = tuple(4.3f, -4.2f, 3.1f, 0.0f);

    assert_float(a.x, ==, 4.3f);
    assert_float(a.y, ==, -4.2f);
    assert_float(a.z, ==, 3.1f);
    assert_float(a.w, ==, 0.0f);

    assert_false(tuple_is_point(&a));
    assert_true(tuple_is_vector(&a));

    return MUNIT_OK;
}

MunitResult T03_Point_Constr(const MunitParameter args[], void *user_data)
{
    Point a = point(4, -4, 3);

    assert_float(a.x, ==, 4);
    assert_float(a.y, ==, -4);
    assert_float(a.z, ==, 3);
    assert_float(a.w, ==, 1.0);

    assert_true(tuple_is_point(&a));
    assert_false(tuple_is_vector(&a));

    return MUNIT_OK;
}

MunitResult T04_Vector_Constr(const MunitParameter args[], void *user_data)
{
    Vector a = vector(4, -4, 3);

    assert_float(a.x, ==, 4);
    assert_float(a.y, ==, -4);
    assert_float(a.z, ==, 3);
    assert_float(a.w, ==, 0.0);

    assert_false(tuple_is_point(&a));
    assert_true(tuple_is_vector(&a));

    return MUNIT_OK;
}

MunitResult T05_Tuple_EQ(const MunitParameter args[], void *user_data)
{
    Tuple a = tuple(1, 2, 3, 4);
    Tuple b = tuple(1, 2, 3, 4);

    Tuple c = tuple(1.1f, 2.f, 3.f, 4.f);
    Tuple d = tuple(1.1f, 2.f, 3.f, 4.f);

    Tuple e = tuple(1.000009f, 2.f, 3.f, 4.f);
    Tuple f = tuple(0.999991f, 2.f, 3.f, 4.f);

    assert_true(tuple_eq(a, b));
    assert_false(tuple_eq(a, c));
    assert_true(tuple_eq(c, d));
    assert_true(tuple_eq(a, e));
    assert_true(tuple_eq(a, f));

    return MUNIT_OK;
}

MunitResult T06_Tuple_ADD(const MunitParameter args[], void *user_data)
{
    Tuple a1 = tuple(3, -2, 5, 1);
    Tuple a2 = tuple(-2, 3, 1, 0);
    Tuple expected_result = tuple(1, 1, 6, 1);

    Tuple result = tuple_add(a1, a2);

    assert_true(tuple_eq(result, expected_result));

    assert_float(result.x, ==, expected_result.x);
    assert_float(result.y, ==, expected_result.y);
    assert_float(result.z, ==, expected_result.z);
    assert_float(result.w, ==, expected_result.w);
    return MUNIT_OK;
}

MunitResult T07_Vector_ADD_Vector(const MunitParameter args[], void *user_data)
{
    Vector a1 = vector(3, -2, 5);
    Vector a2 = vector(-2, 3, 1);
    Vector expected_result = vector(1, 1, 6);

    Vector result = vector_add(a1, a2);

    assert_true(vector_eq(result, expected_result));

    assert_float(result.x, ==, expected_result.x);
    assert_float(result.y, ==, expected_result.y);
    assert_float(result.z, ==, expected_result.z);
    assert_float(result.w, ==, expected_result.w);

    return MUNIT_OK;
}

MunitResult T08_Point_ADD_Vector(const MunitParameter args[], void *user_data)
{
    Point a1 = point(3, -2, 5);
    Vector a2 = vector(-2, 3, 1);

    Point expected_result = point(1, 1, 6);
    Point result = point_add(a1, a2);

    assert_true(point_eq(result, expected_result));

    assert_float(result.x, ==, expected_result.x);
    assert_float(result.y, ==, expected_result.y);
    assert_float(result.z, ==, expected_result.z);
    assert_float(result.w, ==, expected_result.w);

    return MUNIT_OK;
}

MunitResult T09_Tuple_SUB(const MunitParameter args[], void *user_data)
{
    Tuple a1 = tuple(3, 2, 1, 0);
    Tuple a2 = tuple(5, 6, 7, 1);

    Tuple expected_result = tuple(-2, -4, -6, -1);
    Tuple result = tuple_sub(a1, a2);

    assert_true(tuple_eq(result, expected_result));

    assert_float(result.x, ==, expected_result.x);
    assert_float(result.y, ==, expected_result.y);
    assert_float(result.z, ==, expected_result.z);
    assert_float(result.w, ==, expected_result.w);

    return MUNIT_OK;
}

MunitResult T10_Point_SUB(const MunitParameter args[], void *user_data)
{
    Point a1 = point(3, 2, 1);
    Point a2 = point(5, 6, 7);

    Vector expected_result = vector(-2, -4, -6);
    Vector result = point_sub(a1, a2);

    assert_true(vector_eq(result, expected_result));

    assert_float(result.x, ==, expected_result.x);
    assert_float(result.y, ==, expected_result.y);
    assert_float(result.z, ==, expected_result.z);
    assert_float(result.w, ==, expected_result.w);

    return MUNIT_OK;
}

MunitResult T11_Point_SUB_vector(const MunitParameter args[], void *user_data)
{
    Point p = point(3, 2, 1);
    Vector v = vector(5, 6, 7);

    Point expected_result = point(-2, -4, -6);
    Point result = point_sub(p, v);

    assert_true(point_eq(result, expected_result));

    assert_float(result.x, ==, expected_result.x);
    assert_float(result.y, ==, expected_result.y);
    assert_float(result.z, ==, expected_result.z);
    assert_float(result.w, ==, expected_result.w);

    return MUNIT_OK;
}

MunitResult T12_Vector_SUB_vector(const MunitParameter args[], void *user_data)
{
    Vector v1 = vector(3, 2, 1);
    Vector v2 = vector(5, 6, 7);

    Vector expected_result = vector(-2, -4, -6);
    Vector result = vector_sub(v1, v2);

    assert_true(vector_eq(result, expected_result));

    assert_float(result.x, ==, expected_result.x);
    assert_float(result.y, ==, expected_result.y);
    assert_float(result.z, ==, expected_result.z);
    assert_float(result.w, ==, expected_result.w);

    return MUNIT_OK;

}

MunitResult T13_Vector_SUB_from_zero(const MunitParameter args[], void *user_data)
{
    Vector zero = vector(0, 0, 0);
    Vector v = vector(1, -2, 3);

    Vector expected_result = vector(-1, 2, -3);
    Vector result = vector_sub(zero, v);

    assert_true(vector_eq(result, expected_result));

    assert_float(result.x, ==, expected_result.x);
    assert_float(result.y, ==, expected_result.y);
    assert_float(result.z, ==, expected_result.z);
    assert_float(result.w, ==, expected_result.w);

    return MUNIT_OK;
}

MunitResult T14_Tuple_NEG(const MunitParameter args[], void *user_data)
{
    Tuple t = tuple(1, -2, 3, -4);

    Tuple expected_result = tuple(-1, 2, -3, 4);
    Tuple result = tuple_neg(t);

    assert_true(vector_eq(result, expected_result));

    assert_float(result.x, ==, expected_result.x);
    assert_float(result.y, ==, expected_result.y);
    assert_float(result.z, ==, expected_result.z);
    assert_float(result.w, ==, expected_result.w);

    return MUNIT_OK;
}

MunitResult T15_Point_NEG(const MunitParameter args[], void *user_data)
{
    Point p = point(1, -2, 3);

    Point expected_result = point(-1, 2, -3);
    expected_result.w = -1.0f;
    Point result = point_neg(p);

    assert_float(p.x, ==, 1.0f);
    assert_float(result.x, ==, -1.0f);

    assert_true(vector_eq(result, expected_result));

    assert_float(result.x, ==, expected_result.x);
    assert_float(result.y, ==, expected_result.y);
    assert_float(result.z, ==, expected_result.z);
    assert_float(result.w, ==, expected_result.w);

    return MUNIT_OK;
}

MunitResult T16_Vector_NEG(const MunitParameter args[], void *user_data)
{
    Vector v = vector(1, -2, 3);

    Vector expected_result = vector(-1, 2, -3);
    Vector result = vector_neg(v);;

    assert_true(vector_eq(result, expected_result));

    assert_float(result.x, ==, expected_result.x);
    assert_float(result.y, ==, expected_result.y);
    assert_float(result.z, ==, expected_result.z);
    assert_float(result.w, ==, expected_result.w);

    return MUNIT_OK;
}

MunitResult T17_Tuple_Scalar_MUL(const MunitParameter args[], void *user_data)
{
    Tuple a = tuple(1, -2, 3, -4);

    Tuple expected_result = tuple(3.5, -7, 10.5, -14);
    Tuple result = tuple_scale(a, 3.5);

    assert_true(tuple_eq(result, expected_result));

    assert_float(result.x, ==, expected_result.x);
    assert_float(result.y, ==, expected_result.y);
    assert_float(result.z, ==, expected_result.z);
    assert_float(result.w, ==, expected_result.w);

    return MUNIT_OK;
}

MunitResult T18_Tuple_Fraction_MUL(const MunitParameter args[], void *user_data)
{
    Tuple a = tuple(1, -2, 3, -4);

    Tuple expected_result = tuple(0.5, -1, 1.5, -2);
    Tuple result = tuple_scale(a, 0.5);

    assert_true(tuple_eq(result, expected_result));

    assert_float(result.x, ==, expected_result.x);
    assert_float(result.y, ==, expected_result.y);
    assert_float(result.z, ==, expected_result.z);
    assert_float(result.w, ==, expected_result.w);

    return MUNIT_OK;
}

MunitResult T19_Tuple_Fraction_DIV(const MunitParameter args[], void *user_data)
{
    Tuple a = tuple(1, -2, 3, -4);

    Tuple expected_result = tuple(0.5, -1, 1.5, -2);
    Tuple result = tuple_div(a, 2);

    assert_true(tuple_eq(result, expected_result));

    assert_float(result.x, ==, expected_result.x);
    assert_float(result.y, ==, expected_result.y);
    assert_float(result.z, ==, expected_result.z);
    assert_float(result.w, ==, expected_result.w);

    return MUNIT_OK;
}

MunitResult T20_Vector_Length_X1(const MunitParameter args[], void *user_data)
{
    Vector v = vector(1, 0, 0);

    float expected_result = 1;
    float result = vector_length(v);

    assert_float(result, ==, expected_result);

    return MUNIT_OK;
}

MunitResult T21_Vector_Length_Y1(const MunitParameter args[], void *user_data)
{
    Vector v = vector(0, 1, 0);

    float expected_result = 1;
    float result = vector_length(v);

    assert_float(result, ==, expected_result);

    return MUNIT_OK;
}

MunitResult T22_Vector_Length_Z1(const MunitParameter args[], void *user_data)
{
    Vector v = vector(0, 0, 1);

    float expected_result = 1;
    float result = vector_length(v);

    assert_float(result, ==, expected_result);

    return MUNIT_OK;
}

MunitResult T23_Vector_Length_1_2_3(const MunitParameter args[], void *user_data)
{

    Vector v = vector(1, 2, 3);

    float expected_result = (float)sqrt(14);
    float result = vector_length(v);

    assert_float(result, ==, expected_result);

    return MUNIT_OK;
}

MunitResult T24_Vector_Length_1_2_3_neg(const MunitParameter args[], void *user_data)
{

    Vector v = vector(-1, -2, -3);

    float expected_result = (float)sqrt(14);
    float result = vector_length(v);

    assert_float(result, ==, expected_result);

    return MUNIT_OK;
}

MunitResult T25_Vector_Normalize_X4(const MunitParameter args[], void *user_data)
{
    Vector v = vector(4, 0, 0);

    Vector expected_result = vector(1, 0, 0);
    Vector result = vector_normalized(v);

    assert_true(tuple_eq(result, expected_result));

    assert_float(result.x, ==, expected_result.x);
    assert_float(result.y, ==, expected_result.y);
    assert_float(result.z, ==, expected_result.z);
    assert_float(result.w, ==, expected_result.w);

    return MUNIT_OK;
}

MunitResult T26_Vector_Normalize_1_2_3(const MunitParameter args[], void *user_data)
{
    Vector v = vector(1, 2, 3);

    Vector expected_result = vector(0.26726f, 0.53452f, 0.80178f);
    float sqrt14 = (float)sqrt(14);
    Vector expected_result2 = vector(1 / sqrt14, 2 / sqrt14, 3 / sqrt14);
    Vector result = vector_normalized(v);

    // tuple_eq uses EPSILON so this will pass
    assert_true(tuple_eq(result, expected_result));

    assert_true(tuple_eq(result, expected_result2));

    // Here we need to specify precision
    munit_assert_double_equal(result.x, expected_result.x, 5);
    munit_assert_double_equal(result.y, expected_result.y, 5);
    munit_assert_double_equal(result.z, expected_result.z, 5);
    munit_assert_double_equal(result.w, expected_result.w, 5);

    assert_float(result.x, ==, expected_result2.x);
    assert_float(result.y, ==, expected_result2.y);
    assert_float(result.z, ==, expected_result2.z);
    assert_float(result.w, ==, expected_result2.w);

    return MUNIT_OK;

}

MunitResult T27_Vector_Normalize_Length_1(const MunitParameter args[], void *user_data)
{
    Vector v = vector(1, 2, 3);

    Vector norm = vector_normalized(v);

    float expected_result = 1;
    float result = vector_length(norm);


    assert_true(float_eq(result, expected_result));
    munit_assert_double_equal(result, expected_result, 5);

    return MUNIT_OK;
}

MunitResult T28_Vector_Dot(const MunitParameter args[], void *user_data)
{
    Vector a = vector(1, 2, 3);
    Vector b = vector(2, 3, 4);

    float expected_result = 20;
    float result = vector_dot(a, b);

    assert_double(result, ==, expected_result);

    return MUNIT_OK;
}

MunitResult T29_Vector_Cross(const MunitParameter args[], void *user_data)
{
    Vector a = vector(1, 2, 3);
    Vector b = vector(2, 3, 4);

    Vector expected_result_cross_ab = vector(-1, 2, -1);
    Vector expected_result_cross_ba = vector(1, -2, 1);

    Vector result_ab = vector_cross(a, b);
    Vector result_ba = vector_cross(b, a);

    assert_true(vector_eq(result_ab, expected_result_cross_ab));
    assert_true(vector_eq(result_ba, expected_result_cross_ba));

    assert_float(result_ab.x, ==, expected_result_cross_ab.x);
    assert_float(result_ab.y, ==, expected_result_cross_ab.y);
    assert_float(result_ab.z, ==, expected_result_cross_ab.z);
    assert_float(result_ab.w, ==, expected_result_cross_ab.w);

    assert_float(result_ba.x, ==, expected_result_cross_ba.x);
    assert_float(result_ba.y, ==, expected_result_cross_ba.y);
    assert_float(result_ba.z, ==, expected_result_cross_ba.z);
    assert_float(result_ba.w, ==, expected_result_cross_ba.w);

    return MUNIT_OK;
}

MunitTest ch01_tests[] = {

    REGISTER_TEST(T01_Tuple_Point_Constr)
    REGISTER_TEST(T02_Tuple_Vector_Constr)
    REGISTER_TEST(T03_Point_Constr)
    REGISTER_TEST(T04_Vector_Constr)
    REGISTER_TEST(T05_Tuple_EQ)
    REGISTER_TEST(T06_Tuple_ADD)
    REGISTER_TEST(T07_Vector_ADD_Vector)
    REGISTER_TEST(T08_Point_ADD_Vector)
    REGISTER_TEST(T09_Tuple_SUB)
    REGISTER_TEST(T10_Point_SUB)
    REGISTER_TEST(T11_Point_SUB_vector)
    REGISTER_TEST(T12_Vector_SUB_vector)
    REGISTER_TEST(T13_Vector_SUB_from_zero)
    REGISTER_TEST(T14_Tuple_NEG)
    REGISTER_TEST(T15_Point_NEG)
    REGISTER_TEST(T16_Vector_NEG)
    REGISTER_TEST(T17_Tuple_Scalar_MUL)
    REGISTER_TEST(T18_Tuple_Fraction_MUL)
    REGISTER_TEST(T19_Tuple_Fraction_DIV)
    REGISTER_TEST(T20_Vector_Length_X1)
    REGISTER_TEST(T21_Vector_Length_Y1)
    REGISTER_TEST(T22_Vector_Length_Z1)
    REGISTER_TEST(T23_Vector_Length_1_2_3)
    REGISTER_TEST(T24_Vector_Length_1_2_3_neg)
    REGISTER_TEST(T25_Vector_Normalize_X4)
    REGISTER_TEST(T26_Vector_Normalize_1_2_3)
    REGISTER_TEST_NAMED("T27_Vector_Normalize_Len", T27_Vector_Normalize_Length_1)
    REGISTER_TEST(T28_Vector_Dot)
    REGISTER_TEST(T29_Vector_Cross)

    REGISTER_EMPTY_TEST()
};

static const MunitSuite CH01_Suite = {
    (char*)"CH01",
    ch01_tests,
    nullptr,
    1,
    MUNIT_SUITE_OPTION_NONE,
};
