
#pragma once

#include "tuple.h"
#include "vector.h"

struct Point : public Tuple
{
};

void point_init(Point *point, float x, float y, float z);
Point point(float x, float y, float z);

#define point_eq(a, b) (tuple_eq((a), (b)))

Point point_add(const Point &lhs, const Vector &rhs);

Vector point_sub(const Point &lhs, const Point &rhs);
Point point_sub(const Point &lhs, const Vector &rhs);
Point point_neg(const Point &p);
