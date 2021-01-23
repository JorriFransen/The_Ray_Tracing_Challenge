#pragma once

#include "color.h"
#include "material.h"
#include "point.h"

namespace RayTracer {

struct Point_Light
{
    Point position;
    Color intensity;
};

Point_Light point_light(Point position, Color intensity);

Color lighting(const Material &material, const Point_Light &light, const Point &position,
               const Vector &eye, const Vector &normal);

}
