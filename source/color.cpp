#include "color.h"

#include <cassert>

namespace RayTracer
{

Color color_create(float r, float g, float b)
{
    return color_create(r, g, b, 1.0f);
}

Color color_create(float r, float g, float b, float a)
{
    return {  tuple(r, g, b, a) };
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
    return color_create(c1.r * c2.r, c1.g * c2.g, c1.b * c2.b, c1.a * c2.a);
}

}
