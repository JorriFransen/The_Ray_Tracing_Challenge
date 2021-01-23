#include "ray.h"
#include "util.h"

#include <math.h>
#include <float.h>

namespace RayTracer {

Ray ray(Point origin, Vector direction)
{
    return {
        origin,
        direction,
    };
}

Sphere sphere()
{
    Sphere result;
    result.transform = matrix_identity();
    return result;
}

Vector sphere_normal(const Sphere &s, const Point &world_point)
{
    Matrix inverse_transform = matrix_inverse(s.transform);

    Point object_point = matrix_mul(inverse_transform, world_point);
    Vector object_normal = point_sub(object_point, point(0, 0, 0));
    Vector world_normal = matrix_mul(matrix_transpose(inverse_transform), object_normal);
    world_normal.w = 0;
    return vector_normalized(world_normal);
}

Intersection intersection(float t, Intersection_Object *object)
{
    return { t, object };
}

bool intersection_eq(const Intersection &a, const Intersection &b)
{
    if (a.object != b.object) return false;
    return float_eq(a.t, b.t);
}

Point ray_position(const Ray &r, float t)
{
    Vector n_direction = vector_normalized(r.direction);
    Vector distance_along_ray = vector_scale(n_direction, t);

    return point_add(r.origin, distance_along_ray);
}

Intersection_Result ray_intersects(const Ray &_r, Sphere *s)
{
    Ray r = ray_transform(_r, matrix_inverse(s->transform));

    Vector sphere_to_ray = point_sub(r.origin, point(0, 0, 0));

    float a = vector_dot(r.direction, r.direction);
    float b = 2 * vector_dot(r.direction, sphere_to_ray);
    float c = vector_dot(sphere_to_ray, sphere_to_ray) - 1;

    float discriminant = (b * b) - 4 * a * c;

    if (discriminant < 0.0) {
        return { .count = 0 };
    }

    float sqrt_discriminant = sqrt(discriminant);

    float t1 = (-b - sqrt_discriminant) / (2 * a);
    float t2 = (-b + sqrt_discriminant) / (2 * a);

    int count = 2;

    if (float_eq(t1, t2)) {
        count = 1;
    } else {
        float _t1 = fmin(t1, t2);
        float _t2 = fmax(t1, t2);
        t1 = _t1;
        t2 = _t2;
    }

    return{
        .count = count,
        .intersections = { intersection(t1, s),
                           intersection(t2, s), },
    };
}

Intersection best_hit_count(int count, Intersection *intersections, bool *hit)
{
    assert(hit);

    *hit = false;

    if (count == 0) return {};

    float lowest = FLT_MAX;
    uint64_t lowest_index = -1;

    for (int i = 0; i < count; i++) {
        if (intersections[i].t < lowest &&
            intersections[i].t >= EPSILON) {
            lowest = intersections[i].t;
            lowest_index = i;
        }
    }

    if (lowest_index == -1) return {};

    *hit = true;

    return intersections[lowest_index];
}

Ray ray_transform(const Ray &r, const Matrix &m)
{
    return {
        .origin = matrix_mul(m, r.origin),
        .direction = matrix_mul(m, r.direction),
    };
}

}
