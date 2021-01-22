
#include "matrix.h"
#include <cassert>
#include <stdio.h>

#include "gui_window.h"

#include "c_allocator.h"
#include "putting_it_together_ch04.h"

using namespace RayTracer;

bool toggle_wireframe = false;
bool wireframe = false;
float screen_ratio;

Matrix model_matrix;
GLint model_matrix_location;


int main(int argc, char** argv)
{
    auto ca = c_allocator_get();
    Canvas c = CH04::CH04_putting_it_together(ca);

    guisystem_init();

    guiwindow_show(c);
    guiwindow_show(c);

    guisystem_deinit();

    return 0;
}
