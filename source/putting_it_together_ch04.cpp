
#include "putting_it_together_ch04.h"
#include "c_allocator.h"
#include "matrix.h"
#include "point.h"

#include <cstdio>

#define _USE_MATH_DEFINES
#include <math.h>

namespace RayTracer {
namespace CH04 {

int rect_size = 20;
int canvas_size = 1000;
Canvas  c;

Matrix canvas_matrix;

void set_pixel(Point p, Color color)
{
    if (p.x >= 0 && p.x < canvas_size &&
        p.y >= 0 && p.y < canvas_size) {
        canvas_set_pixel(&c, (int)p.x, (int)p.y, color);
    }
}

void center_rect(Point center, Color color)
{
    float half_size = rect_size / 2.f;
    for (int y = (int)(center.y - half_size); y < center.y + half_size; y++) {
        for (int x = (int)(center.x - half_size); x < center.x + half_size; x++) {
            set_pixel(point(x, y, 0), color);
        }
    }
}

Canvas CH04_putting_it_together()
{
    auto ca = c_allocator_get();

    c = canvas(canvas_size, canvas_size, ca);

    Color white = color_create(1, 1, 1);
    Color red = color_create(1, 0, 0);
    Color green = color_create(0, 1, 0);
    Color blue = color_create(0, 0, 1);

    float scale_factor = canvas_size / 2.f * .85f;

    canvas_matrix = matrix_identity().scale(scale_factor, -scale_factor, 1);
    canvas_matrix.translate(canvas_size / 2.f, canvas_size / 2.f, 0);

    Matrix rot_mat = matrix_rotation_z((float)(-M_PI / 6));
    Point current_point = point(0, 1, 0);

    for (int i = 0; i < 12; i++) {

        Color color;
        if (i == 0) color = red;
        else if(i == 3) color = green;
        else if (i == 6) color = blue;
        else color = white;

        Point canvas_point = matrix_mul(canvas_matrix, current_point);
        center_rect(canvas_point, color);
        current_point = matrix_mul(rot_mat, current_point);
    }

    // String ppm_str = canvas_to_ppm(c, ca);
    // write_file("clock.ppm", ppm_str);

    // free(ca, ppm_str.data);
    // canvas_free(&c);
    return c;
}

} }
