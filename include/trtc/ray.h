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

struct Intersection_Object
{
};

struct Sphere : public Intersection_Object
{
    Point origin;
};

struct Intersection
{
    float t;
    Intersection_Object *object;
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


Ray ray(Point origin, Vector direction);
Sphere sphere();
Intersection intersection(float t, Intersection_Object *object);

Point ray_position(const Ray &r, float t);

Intersection_Result ray_intersects(const Ray &r, Sphere *s);
}
