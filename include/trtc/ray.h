#pragma once

#include "point.h"
#include "vector.h"

#include <cassert>
#include <stdint.h>

namespace RayTracer {

struct Ray
{
    Point origin;
    Vector direction;
};

struct Sphere
{
    Point origin;
};

struct Ray_Sphere_Intersection
{
    int32_t count = 0;
    float distances[2];

    float operator[](int32_t i)
    {
        assert(i >= 0);
        assert(i < 2);

        return distances[i];
    }
};


Ray ray(Point origin, Vector direction);
Sphere sphere();

Point ray_position(const Ray &r, float t);

Ray_Sphere_Intersection ray_intersects(const Ray &r, const Sphere &s);
}
