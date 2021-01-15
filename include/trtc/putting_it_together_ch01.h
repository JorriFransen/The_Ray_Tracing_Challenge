#pragma once

#include "vector.h"
#include "point.h"

using namespace RayTracer;

struct Projectile
{
    Point position;
    Vector velocity;
};

struct Environment
{
    Vector gravity;
    Vector wind;
};

void CH01_putting_it_together();

Projectile projectile(const Point &pos, const Vector &vel);
void projectile_print(const Projectile &p);

Environment environment(const Vector &gravity, const Vector &wind);

Projectile tick(const Environment &env, const Projectile &p);
