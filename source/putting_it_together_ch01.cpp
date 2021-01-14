#include "putting_it_together_ch01.h"

#include <stdio.h>

void CH01_putting_it_together()
{
    Projectile p =
        projectile(point(0, 1, 0), vector_normalized(vector(1, 1, 0))); 

    Environment e = environment(vector(0, -0.1, 0), vector(-0.01, 0, 0));

    while (p.position.y > 0) {
        projectile_print(p);
        p = tick(e, p);    
    } 
    projectile_print(p);
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
