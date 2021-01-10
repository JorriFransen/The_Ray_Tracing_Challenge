
#include "tuple.h"

#include "util.h"

void tuple_init(Tuple *tuple, float x, float y, float z, float w)
{
    tuple->x = x;
    tuple->y = y;
    tuple->z = z;
    tuple->w = w;

}

Tuple tuple(float x, float y, float z, float w)
{
    Tuple result;

    tuple_init(&result, x, y, z, w);

    return result;
}

bool tuple_eq(Tuple *lhs, Tuple *rhs)
{
    if (lhs == rhs) return true;
    return tuple_eq(*lhs, *rhs);
}

bool tuple_eq(const Tuple lhs, const Tuple rhs)
{
    if (!(abs_f(lhs.x - rhs.x) < EPSILON)) return false;
    if (!(abs_f(lhs.y - rhs.y) < EPSILON)) return false;
    if (!(abs_f(lhs.z - rhs.z) < EPSILON)) return false;
    if (!(abs_f(lhs.w - rhs.w) < EPSILON)) return false;

    return true;
}

Tuple tuple_add(const Tuple &lhs, const Tuple &rhs)
{
    return tuple(
        lhs.x + rhs.x,
        lhs.y + rhs.y,
        lhs.z + rhs.z,
        lhs.w + rhs.w
    );
}

Tuple tuple_sub(const Tuple &lhs, const Tuple &rhs)
{
    return tuple(
        lhs.x - rhs.x,
        lhs.y - rhs.y,
        lhs.z - rhs.z,
        lhs.w - rhs.w
    );
}

Tuple tuple_neg(const Tuple &t)
{
    return tuple(-t.x, -t.y, -t.z, -t.w);
}

Tuple tuple_scale(const Tuple &t, float scale)
{
    return tuple(t.x * scale, t.y * scale, t.z * scale, t.w * scale);
}

bool tuple_is_point(Tuple *tuple)
{
    return tuple->w == 1.0f;
}

bool tuple_is_vector(Tuple *tuple)
{
    return tuple->w == 0.0f;
}
