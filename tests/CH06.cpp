#include "common.h"

#include "ray.h"

using namespace RayTracer;

MunitResult T01_Sphere_Normal_X_Axis(const MunitParameter args[], void *user_data)
{
    Sphere s = sphere();
    Vector n = sphere_normal(s, point(1, 0, 0));

    assert_true(vector_eq(n, vector(1, 0, 0)));

    return MUNIT_OK;
}

MunitResult T02_Sphere_Normal_Y_Axis(const MunitParameter args[], void *user_data)
{
    Sphere s = sphere();
    Vector n = sphere_normal(s, point(0, 1, 0));

    assert_true(vector_eq(n, vector(0, 1, 0)));

    return MUNIT_OK;
}

MunitResult T03_Sphere_Normal_Z_Axis(const MunitParameter args[], void *user_data)
{
    Sphere s = sphere();
    Vector n = sphere_normal(s, point(0, 0, 1));

    assert_true(vector_eq(n, vector(0, 0, 1)));

    return MUNIT_OK;
}

MunitResult T04_Sphere_Normal_Nonaxial(const MunitParameter args[], void *user_data)
{
    Sphere s = sphere();
    float sqrt3_d3 = sqrt(3) / 3;

    Vector n = sphere_normal(s, point(sqrt3_d3, sqrt3_d3, sqrt3_d3));

    assert_true(vector_eq(n, vector(sqrt3_d3, sqrt3_d3, sqrt3_d3)));

    return MUNIT_OK;
}

MunitResult T04_Sphere_Normal_Normalized(const MunitParameter args[], void *user_data)
{
    Sphere s = sphere();
    float sqrt3_d3 = sqrt(3) / 3;

    Vector n = sphere_normal(s, point(sqrt3_d3, sqrt3_d3, sqrt3_d3));

    assert_true(vector_eq(n, vector_normalized(n)));

    return MUNIT_OK;
}

MunitResult T05_Translated_Sphere_Normal(const MunitParameter args[], void *user_data)
{
    auto s = sphere();
    s.transform.translate(0, 1, 0);

    auto n = sphere_normal(s, point(0, 1.70711, -0.70711));

    auto expected_n = vector(0, 0.70711, -0.70711);

    assert_double_equal(n.x, expected_n.x, 5);
    assert_double_equal(n.y, expected_n.y, 5);
    assert_double_equal(n.z, expected_n.z, 5);
    assert_double_equal(n.w, expected_n.w, 5);

    assert_true(vector_eq(n, expected_n));

    return MUNIT_OK;
}

MunitResult T06_Transformed_Sphere_Normal(const MunitParameter args[], void *user_data)
{
    auto s = sphere();
    s.transform.rotate_z(M_PI / 5).scale(1, 0.5, 1);

    float sqrt2_d2 = sqrt(2) / 2;
    auto n = sphere_normal(s, point(0, sqrt2_d2, -sqrt2_d2));

    auto expected_n = vector(0, 0.97014, -0.24254);

    assert_double_equal(n.x, expected_n.x, 5);
    assert_double_equal(n.y, expected_n.y, 5);
    assert_double_equal(n.z, expected_n.z, 5);
    assert_double_equal(n.w, expected_n.w, 5);

    assert_true(vector_eq(n, expected_n));
    return MUNIT_OK;
}

MunitTest ch06_tests[] = {

    REGISTER_TEST(T01_Sphere_Normal_X_Axis)
    REGISTER_TEST(T02_Sphere_Normal_Y_Axis)
    REGISTER_TEST(T03_Sphere_Normal_Z_Axis)
    REGISTER_TEST(T04_Sphere_Normal_Nonaxial)
    REGISTER_TEST(T05_Translated_Sphere_Normal)
    REGISTER_TEST(T06_Transformed_Sphere_Normal)

    REGISTER_EMPTY_TEST()
};

static const MunitSuite CH06_Suite = {
    (char*)"CH06",
    ch06_tests,
    nullptr,
    1,
    MUNIT_SUITE_OPTION_NONE,
};
