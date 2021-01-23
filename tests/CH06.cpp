#include "color.h"
#include "common.h"

#include "light.h"
#include "material.h"
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

MunitResult T07_Reflect_Vector_45D(const MunitParameter args[], void *user_data)
{
    Vector v = vector(1, -1, 0);
    Vector n = vector(0, 1, 0);

    Vector r = vector_reflect(v, n);

    assert_true(vector_eq(r, vector(1, 1, 0)));

    return MUNIT_OK;
}

MunitResult T08_Reflect_Vector_Slanted_N(const MunitParameter args[], void *user_data)
{
    Vector v = vector(0, -1, 0);
    float sqrt2_d2 = sqrt(2) / 2;
    Vector n = vector(sqrt2_d2, sqrt2_d2, 0);

    Vector r = vector_reflect(v, n);

    assert_true(vector_eq(r, vector(1, 0, 0)));

    return MUNIT_OK;
}

MunitResult T09_Point_Light_Creation(const MunitParameter args[], void *user_data)
{
    Color intensity = color_create(1, 1, 1);
    Point position = point(0, 0, 0);

    Point_Light light = point_light(position, intensity);

    assert_true(point_eq(light.position, position));
    assert_true(color_eq(light.intensity, intensity));

    return MUNIT_OK;
}

MunitResult T10_Material_Default(const MunitParameter args[], void *user_data)
{
    Material m = material_create();

    assert_true(color_eq(m.color, color_create(1, 1, 1)));
    assert_float(m.ambient, ==,  0.1f);
    assert_float(m.diffuse, ==,  0.9f);
    assert_float(m.specular, ==,  0.9f);
    assert_float(m.shininess, ==,  200.0f);

    return MUNIT_OK;
}

MunitResult T11_Material_EQ(const MunitParameter args[], void *user_data)
{
    Material m1 = material_create();
    Material m2 = material_create();
    Material m3 = material_create(color_create(0.5, 0.5, 0.5), 0.2, 0.8, 0.8, 100.0);

    assert_true(color_eq(m1.color, m2.color));
    assert_float(m1.ambient, ==, m2.ambient);
    assert_float(m1.diffuse, ==, m2.diffuse);
    assert_float(m1.specular, ==, m2.specular);
    assert_float(m1.shininess, ==, m2.shininess);

    assert_true(material_eq(m1, m2));

    assert_false(color_eq(m1.color, m3.color));
    assert_float(m1.ambient, !=, m3.ambient);
    assert_float(m1.diffuse, !=, m3.diffuse);
    assert_float(m1.specular, !=, m3.specular);
    assert_float(m1.shininess, !=, m3.shininess);

    assert_false(material_eq(m1, m3));

    return MUNIT_OK;
}

MunitResult T12_Sphere_Default_Material(const MunitParameter args[], void *user_data)
{
    Sphere s = sphere();

    assert_true(material_eq(s.material, material_create()));

    return MUNIT_OK;
}

MunitResult T13_Sphere_Assign_Material(const MunitParameter args[], void *user_data)
{
    Sphere s = sphere();
    Material m = material_create();
    m.ambient = 1;

    s.material = m;

    assert_true(material_eq(s.material, m));

    return MUNIT_OK;
}

MunitResult T14_Light_LES(const MunitParameter args[], void *user_data)
{
    Material m = material_create();
    Point position = point(0, 0, 0);

    Vector eye = vector(0, 0, -1);
    Vector normal = vector(0, 0, -1);
    Point_Light light = point_light(point(0, 0, -10), color_create(1, 1, 1));

    Color result = lighting(m, light, position, eye, normal);

    assert_true(color_eq(result, color_create(1.9, 1.9, 1.9, 1.9)));

    return MUNIT_OK;
}

MunitResult T15_Light_LE45S(const MunitParameter args[], void *user_data)
{
    Material m = material_create();
    Point position = point(0, 0, 0);

    float sqrt2_d2 = sqrt(2) / 2;
    Vector eye = vector(0, sqrt2_d2, -sqrt2_d2);
    Vector normal = vector(0, 0, -1);
    Point_Light light = point_light(point(0, 0, -10), color_create(1, 1, 1));

    Color result = lighting(m, light, position, eye, normal);

    assert_true(color_eq(result, color_create(1.0, 1.0, 1.0)));

    return MUNIT_OK;
}

MunitResult T16_Light_L45ES(const MunitParameter args[], void *user_data)
{
    Material m = material_create();
    Point position = point(0, 0, 0);

    Vector eye = vector(0, 0, -1);
    Vector normal = vector(0, 0, -1);
    Point_Light light = point_light(point(0, 10, -10), color_create(1, 1, 1));

    Color result = lighting(m, light, position, eye, normal);

    assert_true(color_eq(result, color_create(0.7364, 0.7364, 0.7364, 0.7364)));

    return MUNIT_OK;
}

MunitResult T17_Light_L45En45S(const MunitParameter args[], void *user_data)
{
    Material m = material_create();
    Point position = point(0, 0, 0);

    float sqrt2_d2 = sqrt(2) / 2;
    Vector eye = vector(0, -sqrt2_d2, -sqrt2_d2);
    Vector normal = vector(0, 0, -1);
    Point_Light light = point_light(point(0, 10, -10), color_create(1, 1, 1));

    Color result = lighting(m, light, position, eye, normal);

    assert_true(color_eq(result, color_create(1.63638, 1.63638, 1.63638, 1.63638)));

    return MUNIT_OK;
}

MunitResult T18_Light_ELS(const MunitParameter args[], void *user_data)
{
    Material m = material_create();
    Point position = point(0, 0, 0);

    Vector eye = vector(0, 0, -1);
    Vector normal = vector(0, 0, -1);
    Point_Light light = point_light(point(0, 0, 10), color_create(1, 1, 1));

    Color result = lighting(m, light, position, eye, normal);

    assert_true(color_eq(result, color_create(0.1, 0.1, 0.1, 2.099999)));

    return MUNIT_OK;
}
MunitTest ch06_tests[] = {

    REGISTER_TEST(T01_Sphere_Normal_X_Axis)
    REGISTER_TEST(T02_Sphere_Normal_Y_Axis)
    REGISTER_TEST(T03_Sphere_Normal_Z_Axis)
    REGISTER_TEST(T04_Sphere_Normal_Nonaxial)
    REGISTER_TEST(T05_Translated_Sphere_Normal)
    REGISTER_TEST(T06_Transformed_Sphere_Normal)
    REGISTER_TEST(T07_Reflect_Vector_45D)
    REGISTER_TEST(T08_Reflect_Vector_Slanted_N)
    REGISTER_TEST(T09_Point_Light_Creation)
    REGISTER_TEST(T10_Material_Default)
    REGISTER_TEST(T11_Material_EQ)
    REGISTER_TEST(T12_Sphere_Default_Material)
    REGISTER_TEST(T13_Sphere_Assign_Material)
    REGISTER_TEST(T14_Light_LES)
    REGISTER_TEST(T15_Light_LE45S)
    REGISTER_TEST(T16_Light_L45ES)
    REGISTER_TEST(T17_Light_L45En45S)
    REGISTER_TEST(T18_Light_ELS)

    REGISTER_EMPTY_TEST()
};

static const MunitSuite CH06_Suite = {
    (char*)"CH06",
    ch06_tests,
    nullptr,
    1,
    MUNIT_SUITE_OPTION_NONE,
};
