
#pragma once

const float EPSILON = 0.00001f;

float abs_f(float x)
{
    if (x < 0.0f)
        x *= -1;

    return x;
}
