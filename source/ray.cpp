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

static int64_t next_sphere_id = 0;

Sphere sphere()
{
    return {};
}

Intersection intersection(float t, Intersection_Object *object)
{
    return { t, object };
}

Point ray_position(const Ray &r, float t)
{
    Vector n_direction = vector_normalized(r.direction);
    Vector distance_along_ray = vector_scale(n_direction, t);

    return point_add(r.origin, distance_along_ray);
}

Intersection_Result ray_intersects(const Ray &r, Sphere *s)
{
    Vector sphere_to_ray = point_sub(r.origin, s->origin);

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

}
