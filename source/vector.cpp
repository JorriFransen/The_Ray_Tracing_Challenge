
#include "vector.h"

#include <assert.h>
#include <cmath>

namespace RayTracer
{

Vector vector(float x, float y, float z)
{
    Tuple result = tuple(x, y, z, 0.0);
    return *static_cast<Vector *>(&result);
}

Vector vector(const Vector &v)
{
    return vector(v.x, v.y, v.z);
}

Vector vector(const Tuple &t)
{
    return vector(t.x, t.y, t.z);
}

Vector vector_scale(const Vector &v, float scale)
{
    Tuple result = tuple_scale(v, scale);
    assert(result.w == 0.0f);
    return *static_cast<Vector *>(&result);
}

Vector vector_add(const Vector &lhs, const Vector &rhs)
{
    Tuple result = tuple_add(lhs, rhs);
    assert(result.w == 0.0f);
    return *static_cast<Vector *>(&result);
}

Vector vector_sub(const Vector &lhs, const Vector &rhs)
{
    Tuple result = tuple_sub(lhs, rhs);
    assert(result.w == 0.0f);
    return *static_cast<Vector *>(&result);
}

Vector vector_neg(const Vector &v)
{
    Tuple result = tuple_neg(v);
    assert(result.w == 0.0f);
    return *static_cast<Vector *>(&result);
}

float vector_length(const Vector &v)
{
    assert(v.w == 0.0f);

    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

Vector vector_normalized(const Vector &v)
{
    Vector result = vector(v);
    vector_normalize(&result);
    return result;
}

void vector_normalize(Vector *v)
{
    assert(v->w == 0);

    float length = vector_length(*v);
    v->x /= length;
    v->y /= length;
    v->z /= length;
}

float vector_dot(const Vector &a, const Vector &b)
{
    assert(a.w == 0);
    assert(b.w == 0);

    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector vector_cross(const Vector& a, const Vector &b)
{
    return vector(a.y * b.z - a.z * b.y,
                  a.z * b.x - a.x * b.z,
                  a.x * b.y - a.y * b.x);
}

}
