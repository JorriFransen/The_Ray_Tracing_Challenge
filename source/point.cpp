
#include "point.h"

#include <assert.h>

namespace RayTracer
{

Point point(float x, float y, float z)
{
    Tuple result = tuple(x, y, z, 1.0f);
    return *static_cast<Point *>(&result);
}

Point point_add(const Point &lhs, const Vector &rhs)
{
    Tuple result = tuple_add(lhs, rhs);
    assert(result.w == 1.0f);
    return *static_cast<Point *>(&result);
}

Vector point_sub(const Point &lhs, const Point &rhs)
{
    Tuple result = tuple_sub(lhs, rhs);
    return vector(result);
}

Point point_sub(const Point &lhs, const Vector &rhs)
{
    Tuple result = tuple_sub(lhs, rhs);
    assert(result.w == 1.0f);
    return *static_cast<Point *>(&result);
}

Point point_neg(const Point &p)
{
    Tuple result = tuple_neg(p);
    assert(result.w == 1.0f || result.w == -1);
    return *static_cast<Point *>(&result);
}

}
