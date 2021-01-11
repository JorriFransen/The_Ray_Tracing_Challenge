
#include "vector.h"

#include <assert.h>
#include <cmath>

void vector_init(Vector *vector, float x, float y, float z)
{
    tuple_init(vector, x, y, z, 0.0f);
}

Vector vector(float x, float y, float z)
{
    Vector result;
    vector_init(&result, x, y, z);
    return result;
}

Vector vector(const Vector &v)
{
    Vector result;
    vector_init(&result, v.x, v.y, v.z);
    return result;
}

Vector vector_add(const Vector &lhs, const Vector &rhs)
{
    Tuple result = tuple_add(lhs, rhs);
    assert(result.w == 0.0f);
    return *(Vector*)&result;
}

Vector vector_sub(const Vector &lhs, const Vector &rhs)
{
    Tuple result = tuple_sub(lhs, rhs);
    assert(result.w == 0.0f);
    return *(Vector*)&result;
}

Vector vector_neg(const Vector &v)
{
    Tuple result = tuple_neg(v);
    assert(result.w == 0.0f);
    return *(Vector*)&result;
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
