
#include "c_allocator.h"
#include "common.h"

#include "world.h"

using namespace RayTracer;

MunitResult T01_World_Creation(const MunitParameter args[], void *user_data)
{
    auto ca = c_allocator_get();

    World w = world_create(ca);

    assert_int64(w.object_count(), ==, 0);
    assert_int64(w.lights.count, ==, 0);

    world_free(&w);

    return MUNIT_OK;
}

MunitTest ch07_tests[] = {

    REGISTER_TEST(T01_World_Creation)

    REGISTER_EMPTY_TEST()
};

static const MunitSuite CH07_Suite = {
    (char*)"CH07",
    ch07_tests,
    nullptr,
    1,
    MUNIT_SUITE_OPTION_NONE,
};
