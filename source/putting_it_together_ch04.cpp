
#include "putting_it_together_ch04.h"
#include "c_allocator.h"
#include "matrix.h"
#include "point.h"
#include <cstdio>

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
        canvas_set_pixel(&c, p.x, p.y, color);
    }
}

void center_rect(Point center, Color color)
{
    float half_size = rect_size / 2.;
    for (int y = center.y - half_size; y < center.y + half_size; y++) {
        for (int x = center.x - half_size; x < center.x + half_size; x++) {
            set_pixel(point(x, y, 0), color);
        }
    }
}

Canvas CH04_putting_it_together(Allocator *allocator)
{
    auto ca = c_allocator_get();

    c = canvas(canvas_size, canvas_size, ca);

    Color white = color(1, 1, 1);
    Color red = color(1, 0, 0);
    Color green = color(0, 1, 0);
    Color blue = color(0, 0, 1);

    float scale_factor = canvas_size / 2. * .85;

    canvas_matrix = matrix_identity().scale(scale_factor, -scale_factor, 1);
    canvas_matrix.translate(canvas_size / 2., canvas_size / 2., 0);

    Matrix rot_mat = matrix_rotation_z(-M_PI / 6);
    Point current_point = point(0, 1, 0);

    for (int i = 0; i < 12; i++) {

        Color c;
        if (i == 0) c = red;
        else if(i == 3) c = green;
        else if (i == 6) c = blue;
        else c = white;

        Point canvas_point = matrix_mul(canvas_matrix, current_point);
        center_rect(canvas_point, c);
        current_point = matrix_mul(rot_mat, current_point);
    }

    // String ppm_str = canvas_to_ppm(c, ca);
    // write_file("clock.ppm", ppm_str);

    // free(ca, ppm_str.data);
    // canvas_free(&c);
    return c;
}

} }
