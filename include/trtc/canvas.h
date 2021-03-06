#pragma once

#include "allocator.h"
#include "color.h"
#include "util.h"

#include <assert.h>

namespace RayTracer
{

struct Canvas_Pixel;
struct Canvas
{
    int width = -1;
    int height = -1;

    Canvas_Pixel *buffer = nullptr;

    Allocator *allocator = nullptr;
};

void canvas_init(Canvas *c, int width, int height, Allocator *allocator);
Canvas canvas(int width, int height, Allocator *allocator);
void canvas_free(Canvas *c);

Canvas_Pixel canvas_pixel(float r, float g, float b);

Color canvas_get_pixel(const Canvas &c, int x, int y);
Color canvas_get_pixel(const Canvas *c, int x, int y);

void canvas_set_pixel(Canvas *c, int x, int y, const Color &color);

void canvas_clear(Canvas *c, const Color &color);

String canvas_to_ppm(const Canvas &c, Allocator *allocator);

}
