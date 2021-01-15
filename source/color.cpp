#include "color.h"

#include <cassert>

namespace RayTracer
{

void color_init(Color *color, float r, float g, float b, float a)
{
    tuple_init(&color->tuple, r, g, b, a);
}

Color color(float r, float g, float b)
{
    Color result;
    color_init(&result, r, g, b, 1.0f);
    return result;
}

Color color(float r, float g, float b, float a)
{
    Color result;
    color_init(&result, r, g, b, a);
    return result;
}

Color color_add(const Color &c1, const Color &c2)
{
    Color result;
    result.tuple = tuple_add(c1.tuple, c2.tuple);
    return result;
}

Color color_sub(const Color &c1, const Color &c2)
{
    Color result;
    result.tuple = tuple_sub(c1.tuple, c2.tuple);
    return result;
}

Color color_mul(const Color &c1, float s)
{
    Color result;
    result.tuple = tuple_scale(c1.tuple, s);
    return result;
}

Color color_hadamard(const Color &c1, const Color &c2)
{
    return color(c1.r * c2.r, c1.g * c2.g, c1.b * c2.b, c1.a * c2.a);
}

}
