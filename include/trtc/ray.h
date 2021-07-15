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
Intersections<count> intersections_variadic(int n, ...)
{
    Intersections<count> result;

    va_list args;
    va_start(args, n);

    for (int i = 0; i < n; i++) {
        Intersection intersection = va_arg(args, Intersection);
        result.intersections[i] = intersection;
    }

    va_end(args);

    return result;
}

#ifdef _MSC_VER

#define INTERNAL_ARGS_AUGMENTER(...) unused, __VA_ARGS__
#define EXPAND(x) x
#define EXPAND_(...) EXPAND(NUMARGS_(__VA_ARGS__, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0))
#define NUMARGS_(_1_, _2_, _3_, _4_, _5_, _6_, _7_, _8_, _9_, _10_, count, ...) count
#define NUMARGS(...)  EXPAND_(INTERNAL_ARGS_AUGMENTER(__VA_ARGS__))

#else

#define NUMARGS(...) NUMARGS_(0, ## __VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define NUMARGS_(_0, _1_, _2_, _3_, _4_, _5_, _6_, _7_, _8_, _9_, _10_, count, ...) count

#endif // _MSC_VER

static_assert(NUMARGS() == 0, "NUMARGS() failed");
static_assert(NUMARGS(1) == 1, "NUMARGS(1) failed");
static_assert(NUMARGS(1, 2) == 2, "NUMARGS(1, 2) failed");
static_assert(NUMARGS(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) == 10, "NUMARGS() failed with 10 args");

#define intersections_count(c, ...) (intersections_variadic<c>(c, __VA_ARGS__))
#define intersections(...) (intersections_count(NUMARGS(__VA_ARGS__), __VA_ARGS__))

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
