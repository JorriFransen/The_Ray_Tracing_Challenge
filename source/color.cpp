#include "color.h"

void color_init(Color *color, float r, float g, float b)
{
    tuple_init(&color->tuple, r, g, b, 1.0f);
}

Color color(float r, float g, float b)
{
    Color result;
    color_init(&result, r, g, b);
    return result;
}
