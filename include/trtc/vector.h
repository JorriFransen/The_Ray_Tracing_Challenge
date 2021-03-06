
#pragma once

#include "tuple.h"

namespace RayTracer
{

struct Vector : public Tuple
{
    Vector &operator-=(const Vector &rhs);
    Vector &operator*=(const float rhs);
};

Vector operator-(Vector lhs, const Vector &rhs);
Vector operator*(Vector lhs, const float rhs);

Vector vector(float x, float y, float z);
Vector vector(const Vector &v);
Vector vector(const Tuple &t);

#define vector_eq(a, b) (tuple_eq((a), (b)))

Vector vector_scale(const Vector &v, float scale);
Vector vector_add(const Vector &lhs, const Vector &rhs);
Vector vector_sub(const Vector &lhs, const Vector &rhs);
Vector vector_neg(const Vector &v);

float vector_length(const Vector &v);

Vector vector_normalized(const Vector &v);
void vector_normalize(Vector *v);

float vector_dot(const Vector &a, const Vector &b);

Vector vector_cross(const Vector &a, const Vector &b);

Vector vector_reflect(const Vector &v, const Vector &n);

}
