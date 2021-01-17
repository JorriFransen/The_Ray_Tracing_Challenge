#pragma once

#include "tuple.h"
#include <cstddef>
namespace RayTracer {

union Matrix
{
    float m[4][4];
    float flat[16];
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

static const Matrix identity_matrix = { 1, 0, 0, 0,
                                        0, 1, 0, 0,
                                        0, 0, 1, 0,
                                        0, 0, 0, 1 };

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
Matrix matrix_transpose(const Matrix &m);

float matrix_determinant(const Matrix2x2 &m);
float matrix_determinant(const Matrix3x3 &m);
float matrix_determinant(const Matrix &m);
float matrix_minor(const Matrix3x3 &m, int r, int c);
float matrix_minor(const Matrix &m, int r, int c);
float matrix_cofactor(const Matrix3x3 &m, int r, int c);
float matrix_cofactor(const Matrix &m, int r, int c);
Matrix matrix_cofactor_matrix(const Matrix& m);
Matrix2x2 matrix_submatrix(const Matrix3x3 &m, int remove_row, int remove_column);
Matrix3x3 matrix_submatrix(const Matrix &m, int remove_row, int remove_column);

Matrix matrix_inverse(const Matrix &m);


void matrix_print(const Matrix& m);
void matrix_print(const Matrix2x2& m);
}

