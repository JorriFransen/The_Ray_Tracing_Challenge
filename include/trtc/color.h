#pragma once

#include "tuple.h"

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
            float ___a___;
        };
    };
};

void color_init(Color *color, float r, float g, float b);
Color color(float r, float g, float b);
