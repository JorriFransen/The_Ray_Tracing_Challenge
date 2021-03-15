#pragma once

#include "array.h"
#include "light.h"
#include "ray.h"

namespace RayTracer {

struct World
{
    Allocator *allocator = nullptr;

    Array<Point_Light> lights;
    Array<Sphere> spheres;

    int64_t object_count() {
        return spheres.count;
    }
};

World world_create(Allocator *allocator);
World world_create_default(Allocator *allocator);

void world_free(World *w);

}
