#include "common.h"

#include "ray.h"

using namespace RayTracer;

MunitResult T01_Ray_Creation(const MunitParameter args[], void *user_data)
{
    Point origin = point(1, 2, 3);
    Vector direction = vector(4, 5, 6);

    Ray r = ray(origin, direction);

    assert_float(r.origin.x, ==, origin.x);
    assert_float(r.origin.y, ==, origin.y);
    assert_float(r.origin.z, ==, origin.z);
    assert_float(r.origin.w, ==, origin.w);

    assert_true(point_eq(r.origin, origin));

    assert_float(r.direction.x, ==, direction.x);
    assert_float(r.direction.y, ==, direction.y);
    assert_float(r.direction.z, ==, direction.z);
    assert_float(r.direction.w, ==, direction.w);

    assert_true(vector_eq(r.direction, direction));

    return MUNIT_OK;
}

MunitResult T02_Point_On_Ray(const MunitParameter args[], void *user_data)
{
    Ray r = ray(point(2, 3, 4), vector(1, 0, 0));

    assert_true(point_eq(ray_position(r, 0), point(2, 3, 4)));
    assert_true(point_eq(ray_position(r, 1), point(3, 3, 4)));
    assert_true(point_eq(ray_position(r, -1), point(1, 3, 4)));
    assert_true(point_eq(ray_position(r, 2.5), point(4.5, 3, 4)));

    return MUNIT_OK;
}

MunitResult T03_Ray_Sphere_XS(const MunitParameter args[], void *user_data)
{
    Ray r = ray(point(0, 0, -5), vector(0, 0, 1));
    Sphere s = sphere();

    Intersection_Result xs = ray_intersects(r, &s);

    assert_int32(xs.count, ==, 2);
    assert_float(xs[0].t, ==, 4.0);
    assert_float(xs[1].t, ==, 6.0);

    assert_true(xs[0].object == &s);

    return MUNIT_OK;
}

MunitResult T04_Ray_Sphere_Tangent_XS(const MunitParameter args[], void *user_data)
{
    Ray r = ray(point(0, 1, -5), vector(0, 0, 1));
    Sphere s = sphere();

    Intersection_Result xs = ray_intersects(r, &s);

    assert_int32(xs.count, ==, 1);
    assert_float(xs[0].t, ==, 5.0);
    assert_float(xs[1].t, ==, 5.0);
    return MUNIT_OK;
}

MunitResult T05_Ray_Missing_Sphere(const MunitParameter args[], void *user_data)
{
    Ray r = ray(point(0, 2, -5), vector(0, 0, 1));
    Sphere s = sphere();

    Intersection_Result xs = ray_intersects(r, &s);

    assert_int32(xs.count, ==, 0);

    return MUNIT_OK;
}

MunitResult T06_Ray_Inside_Sphere_XS(const MunitParameter args[], void *user_data)
{
    Ray r = ray(point(0, 0, 0), vector(0, 0, 1));
    Sphere s = sphere();

    Intersection_Result xs = ray_intersects(r, &s);

    assert_int32(xs.count, ==, 2);
    assert_float(xs[0].t, ==, -1);
    assert_float(xs[1].t, ==, 1);

    assert_true(xs[0].object == &s);
    assert_true(xs[1].object == &s);

    return MUNIT_OK;
}

MunitResult T07_Ray_Behind_Sphere_XS(const MunitParameter args[], void *user_data)
{
    Ray r = ray(point(0, 0, 5), vector(0, 0, 1));
    Sphere s = sphere();

    Intersection_Result xs = ray_intersects(r, &s);

    assert_int32(xs.count, ==, 2);
    assert_float(xs[0].t, ==, -6);
    assert_float(xs[1].t, ==, -4);

    assert_true(xs[0].object == &s);
    assert_true(xs[1].object == &s);

    return MUNIT_OK;
}

MunitTest ch05_tests[] = {

    REGISTER_TEST(T01_Ray_Creation)
    REGISTER_TEST(T02_Point_On_Ray)
    REGISTER_TEST(T03_Ray_Sphere_XS)
    REGISTER_TEST(T04_Ray_Sphere_Tangent_XS)
    REGISTER_TEST(T05_Ray_Missing_Sphere)
    REGISTER_TEST(T06_Ray_Inside_Sphere_XS)
    REGISTER_TEST(T07_Ray_Behind_Sphere_XS)

    REGISTER_EMPTY_TEST()
};

static const MunitSuite CH05_Suite = {
    (char*)"CH05",
    ch05_tests,
    nullptr,
    1,
    MUNIT_SUITE_OPTION_NONE,
};
