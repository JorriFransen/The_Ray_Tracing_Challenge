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

    assert_ptr_equal(xs[0].object, &s.object);

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

    assert_ptr_equal(xs[0].object, &s.object);
    assert_ptr_equal(xs[1].object, &s.object);

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

    assert_ptr_equal(xs[0].object, &s.object);
    assert_ptr_equal(xs[1].object, &s.object);

    return MUNIT_OK;
}

MunitResult T08_Intersection_Creation(const MunitParameter args[], void *user_data)
{
    Sphere s = sphere();
    Intersection i = intersection(3.5, &s.object);

    assert_float(i.t, ==, 3.5);
    assert_ptr_equal(i.object, &s.object);

    return MUNIT_OK;
}

MunitResult T09_Hit_All_Positive_T(const MunitParameter args[], void *user_data)
{
    auto s = sphere();
    auto i1 = intersection(1, &s.object);
    auto i2 = intersection(2, &s.object);

    auto xs = intersections(i2, i1);

    assert_int(sizeof(xs.intersections) / sizeof(xs.intersections[0]), ==, 2);

    bool hit;
    auto i = best_hit(xs, &hit);

    assert_true(hit);

    assert_true(intersection_eq(i, i1));

    return MUNIT_OK;
}

MunitResult T10_Hit_Mixed_T(const MunitParameter args[], void *user_data)
{
    auto s = sphere();
    auto i1 = intersection(-1, &s.object);
    auto i2 = intersection(1, &s.object);

    auto xs = intersections(i2, i1);

    assert_int(sizeof(xs.intersections) / sizeof(xs.intersections[0]), ==, 2);

    bool hit;
    auto i = best_hit(xs, &hit);

    assert_true(hit);

    assert_true(intersection_eq(i, i2));

    return MUNIT_OK;
}

MunitResult T11_Hit_All_Negative_T(const MunitParameter args[], void *user_data)
{
    auto s = sphere();
    auto i1 = intersection(-2, &s.object);
    auto i2 = intersection(-1, &s.object);

    auto xs = intersections(i2, i1);

    assert_int(sizeof(xs.intersections) / sizeof(xs.intersections[0]), ==, 2);

    bool hit;
    auto i = best_hit(xs, &hit);

    assert_false(hit);

    return MUNIT_OK;
}

MunitResult T12_Hit_Lowest_Positive_T(const MunitParameter args[], void *user_data)
{
    auto s = sphere();
    auto i1 = intersection(5, &s.object);
    auto i2 = intersection(7, &s.object);
    auto i3 = intersection(-3, &s.object);
    auto i4 = intersection(2, &s.object);

    auto xs = intersections(i1, i2, i3, i4);

    assert_int(sizeof(xs.intersections) / sizeof(xs.intersections[0]), ==, 4);

    bool hit;
    auto i = best_hit(xs, &hit);

    assert_true(hit);

    assert_true(intersection_eq(i, i4));

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
    REGISTER_TEST(T08_Intersection_Creation)
    REGISTER_TEST(T09_Hit_All_Positive_T)
    REGISTER_TEST(T10_Hit_Mixed_T)
    REGISTER_TEST(T11_Hit_All_Negative_T)
    REGISTER_TEST(T12_Hit_Lowest_Positive_T)

    REGISTER_EMPTY_TEST()
};

static const MunitSuite CH05_Suite = {
    (char*)"CH05",
    ch05_tests,
    nullptr,
    1,
    MUNIT_SUITE_OPTION_NONE,
};
