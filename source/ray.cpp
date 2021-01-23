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
    return {};
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

Intersection_Result ray_intersects(const Ray &r, Sphere *s)
{
    Vector sphere_to_ray = point_sub(r.origin, s->object.origin);

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
        .intersections = { intersection(t1, &s->object),
                           intersection(t2, &s->object), },
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

}
