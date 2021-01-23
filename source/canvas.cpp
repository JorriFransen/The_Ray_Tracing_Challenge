#include "canvas.h"

#include "string_builder.h"
#include "temp_allocator.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace RayTracer
{

struct Canvas_Pixel
{
    float r, g, b;
};

void canvas_init(Canvas *c, int width, int height, Allocator *allocator)
{
    c->width = width;
    c->height = height;

    auto pixel_count = width * height;
    // auto byte_size = pixel_count * sizeof(Canvas_Pixel);
    // c->buffer = (Canvas_Pixel *)malloc(byte_size);
    c->buffer = alloc_array<Canvas_Pixel>(allocator, pixel_count);
    // memset(c->buffer, 0, byte_size);
    c->allocator = allocator;
}

void canvas_free(Canvas *c)
{
    assert(c->buffer);

    free(c->allocator, c->buffer);

    c->buffer = nullptr;
    c->width = -1;
    c->height = -1;
}

Canvas canvas(int width, int height, Allocator *allocator)
{
    Canvas result;
    canvas_init(&result, width, height, allocator);
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

void canvas_clear(Canvas *c, const Color &color)
{
    Canvas_Pixel cv = canvas_pixel(color.r, color.g, color.b);

    for (int y = 0; y < c->height; y++) {
        for (int x = 0; x < c->width; x++) {
            c->buffer[x + y * c->width] = cv;
        }
    }
}

String canvas_to_ppm(const Canvas &c, Allocator *allocator)
{
    auto ta = temp_allocator_get();

    String_Builder sb;
    int predicted_size = (c.width * c.height * 12) + 32;
    string_builder_init(allocator, &sb, predicted_size);

    char line[70];
    int current_line_length = 0;

#define append_to_line(str) { \
    assert((str.length) <= 70); \
    if (current_line_length + (str.length) + 1 > 70) { \
        string_builder_appendf(&sb, "%.*s\n", current_line_length, line); \
        current_line_length = 0; \
        temp_allocator_reset(ta); \
    } \
    if (current_line_length != 0) { \
        line[current_line_length] = ' '; \
        current_line_length += 1; \
    } \
    memcpy(&line[current_line_length], (str.data), (str.length)); \
    current_line_length += (str.length); \
}

    string_builder_append(&sb, "P3\n");
    string_builder_appendf(&sb, "%d %d\n", c.width, c.height);
    string_builder_append(&sb, "255\n") ;

    for (int y = 0; y < c.height; y++) {

        current_line_length = 0;

        for (int x = 0; x < c.width; x++) {
            Canvas_Pixel pixel = c.buffer[x + y * c.width];

            float _r = ceil(pixel.r * 255.0f);
            float _g = ceil(pixel.g * 255.0f);
            float _b = ceil(pixel.b * 255.0f);

            uint8_t r = clamp(0, 255, _r);
            uint8_t g = clamp(0, 255, _g);
            uint8_t b = clamp(0, 255, _b);

            String r_str = uint_to_string(ta, r);
            String g_str = uint_to_string(ta, g);
            String b_str = uint_to_string(ta, b);

            append_to_line(r_str);
            append_to_line(g_str);
            append_to_line(b_str);

        }

        if (current_line_length) {
            string_builder_appendf(&sb, "%.*s\n", current_line_length, line);
           current_line_length = 0;
           temp_allocator_reset(ta);
        }
    }

    if (current_line_length) {
        string_builder_appendf(&sb, "%.*s\n", current_line_length, line);
        current_line_length = 0;
    }

#undef append_to_line

    String result = string_builder_to_string(allocator, &sb);
    string_builder_free(&sb);

    assert(result[result.length - 1] == '\n');

    return result;
}

}
