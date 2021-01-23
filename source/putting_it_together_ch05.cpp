
#include "putting_it_together_ch05.h"
#include "point.h"
#include "ray.h"

#include <cassert>

namespace RayTracer {
namespace CH05 {

void CH05_putting_it_together(Canvas &canvas)
{
    assert(canvas.width == canvas.height);
    auto canvas_size = canvas.width;

    Color red = color(1, 0, 0);
    Sphere shape = sphere();

    // shape.transform.scale(1, 0.5, 1);
    // shape.transform.scale(0.5, 1, 1);

    // Matrix r = matrix_rotation_z(M_PI / 4);
    // Matrix s = matrix_scale(0.5, 1, 1);
    // shape.transform = matrix_mul(r, s);

    // shape.transform.scale(0.5, 1, 1).rotate_z(M_PI / 4);

    // Matrix shear = matrix_shear(1, 0, 0, 0, 0, 0);
    // Matrix scale = matrix_scale(0.5, 1, 1);
    // shape.transform = matrix_mul(shear, scale);

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
            Intersection_Result ir = ray_intersects(r, &shape);

            bool hit;
            Intersection i = best_hit_count(ir.count, ir.intersections, &hit);
            if (hit) {
                canvas_set_pixel(&canvas, x, y, red);
            }
        }
    }
}

}}
