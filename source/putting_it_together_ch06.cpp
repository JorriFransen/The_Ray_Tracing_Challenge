
#include "putting_it_together_ch06.h"
#include "light.h"
#include "point.h"
#include "ray.h"

#include <cassert>

#define _USE_MATH_DEFINES
#include <math.h>

namespace RayTracer {
namespace CH06 {

void CH06_putting_it_together(Canvas &canvas)
{
    assert(canvas.width == canvas.height);
    auto canvas_size = canvas.width;

    Point_Light light = point_light(point(-10, 10, -10), color_create(1, 1, 1));

    Sphere sphere = sphere_create();
    sphere.material.color = color_create(1.f, 0.2f, 1.f);
    // sphere.material.specular = 0.5;

    // sphere.transform.scale(1, 0.5, 1).rotate_z(M_PI / 3).scale(1, 0.5, 1);;

    Point ray_origin = point(0, 0, -5);

    float wall_z = 10;
    float wall_size = 7;

    float pixel_world_size = wall_size / canvas_size;
    float half_wall_size = wall_size / 2;

    for (int y = 0; y < canvas_size; y++) {
        float world_y = half_wall_size - pixel_world_size * y;

        for (int x = 0; x < canvas_size; x++) {
            float world_x = -half_wall_size + pixel_world_size * x;

            Point position = point(world_x, world_y, wall_z);

            Ray r = ray(ray_origin, vector_normalized(point_sub(position, ray_origin)));
            Intersection_Result ir = ray_intersects(r, &sphere);

            bool hit;
            Intersection i = best_hit_count(ir.count, ir.intersections, &hit);
            if (hit) {
                Point point = ray_position(r, i.t);
                Vector normal = sphere_normal(*i.object, point);

                Vector eye = vector_neg(r.direction);
                // Vector eye = -r.direction;
                Color color = lighting(i.object->material, light, point, eye, normal);
                canvas_set_pixel(&canvas, x, y, color);
            }
        }
    }
}

}}
