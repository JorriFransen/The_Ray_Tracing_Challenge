#include "putting_it_together_ch02.h"
#include "c_allocator.h"
#include "canvas.h"

#include <stdio.h>

namespace RayTracer
{
namespace CH02
{

void CH02_putting_it_together()
{
    Point start = point(0, 1, 0);
    Vector velocity = vector_scale(vector_normalized(vector(1, 1.8, 0)), 11.25);
    Projectile p = projectile(start, velocity);

    Vector gravity = vector(0, -0.1, 0);
    Vector wind = vector(-0.01, 0, 0);
    Environment e = environment(gravity, wind);

    Canvas c = canvas(900, 550);

    Color p_color = color(1, 0, 0);

    while (p.position.y > 0) {

        Point pixel_pos = point(p.position.x, c.height - p.position.y, p.position.z);
        pixel_pos.x = clamp(0, c.width - 1, pixel_pos.x);
        pixel_pos.y = clamp(0, c.height - 1, pixel_pos.y);
        canvas_set_pixel(&c, pixel_pos.x, pixel_pos.y, p_color);
        p = tick(e, p);
    }
    Point pixel_pos = point(p.position.x, c.height - p.position.y, p.position.z);
        pixel_pos.x = clamp(0, c.width - 1, pixel_pos.x);
        pixel_pos.y = clamp(0, c.height - 1, pixel_pos.y);
    canvas_set_pixel(&c, pixel_pos.x, pixel_pos.y, p_color);

    auto ca = c_allocator_get();

    String ppm_str = canvas_to_ppm(c, ca);
    // printf("%s\n", ppm_str.data);

    free(ca, ppm_str.data);
    canvas_free(&c);
}

Projectile projectile(const Point &pos, const Vector &vel)
{
    Projectile result;
    result.position = pos;
    result.velocity = vel;
    return result;
}

void projectile_print(const Projectile &p)
{
    printf("p: %f, %f, %f --- v: %f, %f, %f\n",
            p.position.x, p.position.y, p.position.z,
            p.velocity.x, p.velocity.y, p.velocity.z);
}

Environment environment(const Vector &gravity, const Vector &wind)
{
    Environment result;
    result.gravity = gravity;
    result.wind = wind;
    return result;
}

Projectile tick(const Environment &env, const Projectile &p)
{
    Point new_position = point_add(p.position, p.velocity);
    Vector new_velocity = vector_add(vector_add(p.velocity, env.gravity), env.wind);

    return projectile(new_position, new_velocity);
}

}
}
