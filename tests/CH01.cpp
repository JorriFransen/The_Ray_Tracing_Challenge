
#include "common.h"

#include "tuple.h"
#include "point.h"
#include "vector.h"

MunitResult T01_Tuple_Point_Constr(const MunitParameter args[], void *user_data)
{
    Tuple a = tuple(4.3, -4.2, 3.1, 1.0);

    assert_float(a.x, ==, 4.3);
    assert_float(a.y, ==, -4.2);
    assert_float(a.z, ==, 3.1);
    assert_float(a.w, ==, 1.0);

    assert_true(tuple_is_point(&a));
    assert_false(tuple_is_vector(&a));

    return MUNIT_OK;
}

MunitResult T02_Tuple_Vector_Constr(const MunitParameter args[], void *user_data)
{
    Tuple a = tuple(4.3, -4.2, 3.1, 0.0);

    assert_float(a.x, ==, 4.3);
    assert_float(a.y, ==, -4.2);
    assert_float(a.z, ==, 3.1);
    assert_float(a.w, ==, 0.0);

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

    Tuple c = tuple(1.1, 2, 3, 4);
    Tuple d = tuple(1.1, 2, 3, 4);

    Tuple e = tuple(1.000009, 2, 3, 4);
    Tuple f = tuple(0.999991, 2, 3, 4);

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

MunitResult T17_Tumple_Scalar_MUL(const MunitParameter args[], void *user_data)
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

MunitResult T18_Tumple_Fraction_MUL(const MunitParameter args[], void *user_data)
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
    REGISTER_TEST(T17_Tumple_Scalar_MUL)
    REGISTER_TEST(T18_Tumple_Fraction_MUL)
    REGISTER_EMPTY_TEST()
};

static const MunitSuite CH01_Suite = {
    (char*)"/CH01",
    ch01_tests,
    nullptr,
    1,
    MUNIT_SUITE_OPTION_NONE,
};