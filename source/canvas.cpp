#include "canvas.h"

#include "string_builder.h"
#include "temp_allocator.h"

#include <cstdlib>
#include <cstring>

struct Canvas_Pixel
{
    float r, g, b;
};

void canvas_init(Canvas *c, int width, int height)
{
    c->width = width;
    c->height = height;

    auto pixel_count = width * height;
    auto byte_size = pixel_count * sizeof(Canvas_Pixel);
    c->buffer = (Canvas_Pixel *)malloc(byte_size);
    memset(c->buffer, 0, byte_size);
}

void canvas_free(Canvas *c)
{
    assert(c->buffer);

    free(c->buffer);

    c->buffer = nullptr;
    c->width = -1;
    c->height = -1;
}

Canvas canvas(int width, int height)
{
    Canvas result;
    canvas_init(&result, width, height);
    return result;
}

Canvas_Pixel canvas_pixel(float r, float g, float b)
{
    Canvas_Pixel result;
    result.r = r;
    result.g = g;
    result.b = b;
    return result;
}

Color canvas_get_pixel(const Canvas &c, int x, int y)
{
    return canvas_get_pixel(&c, x, y);
}

Color canvas_get_pixel(const Canvas *c, int x, int y)
{
    assert(x >= 0 && x < c->width);
    assert(y >= 0 && y < c->height);

    auto cv = c->buffer[x + y * c->width];
    return color(cv.r, cv.g, cv.b, 1.0f);
}

void canvas_set_pixel(Canvas *c, int x, int y, const Color &color)
{
    assert(x >= 0 && x < c->width);
    assert(y >= 0 && y < c->height);

    Canvas_Pixel cv = canvas_pixel(color.r, color.g, color.b);
    c->buffer[x + y * c->width] = cv;
}

String canvas_to_ppm(const Canvas &c, Allocator *allocator)
{
    auto ta = temp_allocator_get();

    String_Builder sb;
    string_builder_init(ta, &sb, 2048);

    string_builder_append(&sb, "P3\n");
    string_builder_appendf(&sb, "%d %d\n", c.width, c.height);
    string_builder_append(&sb, "255\n") ;

    String result = string_builder_to_string(allocator, &sb);
    string_builder_free(&sb);

    return result;
}
