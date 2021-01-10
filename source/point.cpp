
#include "point.h"

#include <assert.h>


void point_init(Point *point, float x, float y, float z)
{
    tuple_init(point, x, y, z, 1.0f);
}

Point point(float x, float y, float z)
{
    Point result;
    point_init(&result, x, y, z);
    return result;
}

Point point_add(const Point &lhs, const Vector &rhs)
{
    Tuple result = tuple_add(lhs, rhs);
    assert(result.w == 1.0f);
    return *(Point*)&result;
}

Vector point_sub(const Point &lhs, const Point &rhs)
{
    Tuple result = tuple_sub(lhs, rhs);
    assert(result.w == 0.0f);
    return *(Vector*)&result;
}

Point point_sub(const Point &lhs, const Vector &rhs)
{
    Tuple result = tuple_sub(lhs, rhs);
    assert(result.w == 1.0f);
    return *(Point*)&result;
}

Point point_neg(const Point &p)
{
    Tuple result = tuple_neg(p);
    assert(result.w == 1.0f || result.w == -1);
    return *(Point*)&result;
}
