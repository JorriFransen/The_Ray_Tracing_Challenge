
#include "c_allocator.h"
#include "gui_window.h"
#include "putting_it_together_ch06.h"

using namespace RayTracer;

int main(int argc, char** argv)
{
    auto ca = c_allocator_get();

    // Canvas c = canvas(500, 500, ca);
    Canvas c = canvas(512, 512, ca);

    CH06::CH06_putting_it_together(c);

    guisystem_init();

    guiwindow_show(c);

    guisystem_deinit();

    canvas_free(&c);
    return 0;
}
