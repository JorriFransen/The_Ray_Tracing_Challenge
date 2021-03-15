#pragma once

#include "material.h"
#include "matrix.h"
#include "point.h"
#include "vector.h"

#include <cassert>
#include <cstdio>
#include <stdint.h>
#include <stdarg.h>

namespace RayTracer {

struct Ray
{
    Point origin;
    Vector direction;
};

struct Sphere
{
    Matrix transform;
    Material material;
};

struct Intersection
{
    float t;
    Sphere *object;
};

struct Intersection_Result
{
    int32_t count = 0;
    Intersection intersections[2];

    Intersection operator[](int32_t i)
    {
        assert(i >= 0);
        assert(i < 2);

        return intersections[i];
    }
};

template <std::size_t count>
struct Intersections
{
    Intersection intersections[count];
};

Ray ray(Point origin, Vector direction);
Sphere sphere_create();
Vector sphere_normal(const Sphere &s, const Point &p);

Intersection intersection(float t, Sphere *object);

bool intersection_eq(const Intersection &a, const Intersection &b);

template <std::size_t count>
Intersections<count> intersections_variadic(int num, ...)
{
    Intersections<count> result;

    va_list args;
    va_start(args, num);

    for (int i = 0; i < num; i++) {
        Intersection intersection = va_arg(args, Intersection);
        result.intersections[i] = intersection;
    }

    va_end(args);

    return result;
}

#define ELEVENTH_ARGUMENT(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, ...) a11
#define COUNT_ARGUMENTS(...) ELEVENTH_ARGUMENT(dummy, ## __VA_ARGS__, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

#define intersections_count(count, args...) (intersections_variadic<count>(count, args))
#define intersections(args...) (intersections_count(COUNT_ARGUMENTS(args), args))

Point ray_position(const Ray &r, float t);

Intersection_Result ray_intersects(const Ray &r, Sphere *s);

Intersection best_hit_count(int count, Intersection *intersections, bool *hit);

template <size_t count>
Intersection best_hit(Intersections<count> &intersections, bool *hit)
{
    return best_hit_count(count, intersections.intersections, hit);
}

Ray ray_transform(const Ray &r, const Matrix &m);

}
