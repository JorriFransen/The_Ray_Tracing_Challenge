
#include "c_allocator.h"
#include "gui_window.h"
#include "putting_it_together_ch04.h"

using namespace RayTracer;

int main(int argc, char** argv)
{
    auto ca = c_allocator_get();
    Canvas c = CH04::CH04_putting_it_together(ca);

    guisystem_init();

    guiwindow_show(c);

    guisystem_deinit();

    canvas_free(&c);
    return 0;
}
