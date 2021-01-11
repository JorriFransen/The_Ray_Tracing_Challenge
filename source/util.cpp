
#include "util.h"

float abs_f(float x)
{
    if (x < 0.0f)
        x *= -1;

    return x;
}

bool float_eq(float lhs, float rhs)
{
    return abs_f(lhs - rhs) < EPSILON;
}
