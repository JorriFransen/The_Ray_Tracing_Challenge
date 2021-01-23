
#include "c_allocator.h"
#include "gui_window.h"
#include "putting_it_together_ch05.h"

using namespace RayTracer;

int main(int argc, char** argv)
{
    auto ca = c_allocator_get();

    Canvas c = canvas(200, 200, ca);

    CH05::CH05_putting_it_together(c);

    guisystem_init();

    guiwindow_show(c);

    guisystem_deinit();

    canvas_free(&c);
    return 0;
}
