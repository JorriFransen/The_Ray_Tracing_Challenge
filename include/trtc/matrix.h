#pragma once

#include "tuple.h"
#include <cstddef>
namespace RayTracer {

union Matrix
{
    float m[4][4];
    struct
    {
        float m00;
        float m01;
        float m02;
        float m03;

        float m10;
        float m11;
        float m12;
        float m13;

        float m20;
        float m21;
        float m22;
        float m23;

        float m30;
        float m31;
        float m32;
        float m33;
    };

    // Overloading [] for single dimension, returns a reference to a row,
    //  on which we can use [] again.
    float (&operator[](size_t i)) [4]
    {
        return m[i];
    }
};

union Matrix3x3
{
    float m[3][3];
    struct
    {
        float m00;
        float m01;
        float m02;

        float m10;
        float m11;
        float m12;

        float m20;
        float m21;
        float m22;
    };

    // Overloading [] for single dimension, returns a reference to a row,
    //  on which we can use [] again.
    float (&operator[](size_t i)) [3]
    {
        return m[i];
    }
};

union Matrix2x2
{
    float m[2][2];
    struct
    {
        float m00;
        float m01;

        float m10;
        float m11;
    };

    // Overloading [] for single dimension, returns a reference to a row,
    //  on which we can use [] again.
    float (&operator[](size_t i)) [2]
    {
        return m[i];
    }
};

Matrix matrix(float m00, float m01, float m02, float m03,
              float m10, float m11, float m12, float m13,
              float m20, float m21, float m22, float m23,
              float m30, float m31, float m32, float m33);

Matrix3x3 matrix3x3(float m00, float m01, float m02,
                    float m10, float m11, float m12,
                    float m20, float m21, float m22);

Matrix2x2 matrix2x2(float m00, float m01,
                    float m10, float m11);

bool matrix_eq(const Matrix &a, const Matrix &b);
bool matrix_eq(const Matrix3x3 &a, const Matrix3x3 &b);
bool matrix_eq(const Matrix2x2 &a, const Matrix2x2 &b);

void matrix_mul_with(Matrix *a, const Matrix &b);
Matrix matrix_mul(const Matrix &a, const Matrix &b);
Tuple matrix_mul(const Matrix &m, const Tuple &t);
}

