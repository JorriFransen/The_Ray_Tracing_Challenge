#include "ray.h"
#include "util.h"

#include <math.h>

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
    return {};
}

Point ray_position(const Ray &r, float t)
{
    Vector n_direction = vector_normalized(r.direction);
    Vector distance_along_ray = vector_scale(n_direction, t);

    return point_add(r.origin, distance_along_ray);
}

Ray_Sphere_Intersection ray_intersects(const Ray &r, const Sphere &s)
{
    Vector sphere_to_ray = point_sub(r.origin, s.origin);

    float a = vector_dot(r.direction, r.direction);
    float b = 2 * vector_dot(r.direction, sphere_to_ray);
    float c = vector_dot(sphere_to_ray, sphere_to_ray) - 1;

    float discriminant = (b * b) - 4 * a * c;

    if (discriminant < 0.0) {
        return { .count = 0 };
    }

    float sqrt_discriminant = sqrt(discriminant);

    float _t1 = (-b - sqrt_discriminant) / (2 * a);
    float _t2 = (-b + sqrt_discriminant) / (2 * a);

    if (float_eq(_t1, _t2)) return { .count = 1, .distances = { _t1, _t2 }};

    float t1 = fmin(_t1, _t2);
    float t2 = fmax(_t1, _t2);

    return { .count = 2, .distances = { t1, t2 }};
}

}
