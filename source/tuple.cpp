
#include "tuple.h"

#include "util.h"

namespace RayTracer
{

Tuple tuple(float x, float y, float z, float w)
{
    return { x, y, z, w };
}

bool tuple_eq(Tuple *lhs, Tuple *rhs)
{
    if (lhs == rhs) return true;
    return tuple_eq(*lhs, *rhs);
}

bool tuple_eq(const Tuple lhs, const Tuple rhs)
{
    if (!float_eq(lhs.x, rhs.x)) return false;
    if (!float_eq(lhs.y, rhs.y)) return false;
    if (!float_eq(lhs.z, rhs.z)) return false;
    if (!float_eq(lhs.w, rhs.w)) return false;

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

Tuple tuple_div(const Tuple &t, float divisor)
{
    return tuple(t.x / divisor, t.y / divisor,
                 t.z / divisor, t.w / divisor);
}

bool tuple_is_point(Tuple *tuple)
{
    return tuple->w == 1.0f;
}

bool tuple_is_vector(Tuple *tuple)
{
    return tuple->w == 0.0f;
}

}
