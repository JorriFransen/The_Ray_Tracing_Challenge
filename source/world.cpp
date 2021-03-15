#include "world.h"

namespace RayTracer {

World world_create(Allocator *allocator)
{
    World result;

    result.allocator = allocator;
    result.lights = array_create<Point_Light>(allocator, 4);
    result.spheres = array_create<Sphere>(allocator, 4);

    return result;
}

World world_create_default(Allocator *allocator)
{
    World result = world_create(allocator);

    Point_Light light = point_light(point(-10, 10, -10), color_create(1, 1, 1));;
    array_append(&result.lights, light);

    return result;
}

void world_free(World *w)
{
    array_free(&w->lights);
    array_free(&w->spheres);
}

}

