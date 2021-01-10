
#pragma once

#include "tuple.h"

struct Vector : public Tuple
{
};

void vector_init(Vector *vector, float x, float y, float z);
Vector vector(float x, float y, float z);

#define vector_eq(a, b) (tuple_eq((a), (b)))

Vector vector_add(const Vector &lhs, const Vector &rhs);
Vector vector_sub(const Vector &lhs, const Vector &rhs);
Vector vector_neg(const Vector &v);
