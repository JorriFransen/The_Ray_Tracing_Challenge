#pragma once

#include "tuple.h"

namespace RayTracer
{

struct Color
{
    union
    {
        Tuple tuple;

        struct
        {
            float r;
            float g;
            float b;
            float a;
        };
    };
};

Color color(float r, float g, float b);
Color color(float r, float g, float b, float a);

#define color_eq(c1, c2) (tuple_eq((c1.tuple), (c2.tuple)))

Color color_add(const Color &c1, const Color &c2);
Color color_sub(const Color &c1, const Color &c2);
Color color_mul(const Color &c1, float s);

Color color_hadamard(const Color &c1, const Color &c2);

}
