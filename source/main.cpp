
#include "c_allocator.h"
#include "gui_window.h"
#include "putting_it_together_ch06.h"

#include <stdio.h>

using namespace RayTracer;

int main(int argc, char** argv)
{
    float x = 6.78f;
    int y = (int)x;
    printf("y: %d\n", y);

    auto ca = c_allocator_get();

    // Canvas c = canvas(500, 500, ca);
    Canvas c = canvas(128, 128, ca);

    CH06::CH06_putting_it_together(c);

    guisystem_init();

    guiwindow_show(c);

    guisystem_deinit();

    canvas_free(&c);
    return 0;
}
