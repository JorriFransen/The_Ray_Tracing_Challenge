
#include "matrix.h"
#include "util.h"

#include <cstdio>

namespace RayTracer {

Matrix &Matrix::translate(float x, float y, float z)
{
    Matrix translation = matrix_translation(x, y, z);
    *this = matrix_mul(translation, *this);
    return *this;
}

Matrix &Matrix::scale(float x, float y, float z)
{
    Matrix scale = matrix_scale(x, y, z);
    *this = matrix_mul(scale, *this);
    return *this;
}

Matrix &Matrix::rotate_x(float radians)
{
    Matrix rot_x = matrix_rotation_x(radians);
    *this = matrix_mul(rot_x, *this);
    return *this;
}

Matrix &Matrix::rotate_y(float radians)
{
    Matrix rot_y = matrix_rotation_y(radians);
    *this = matrix_mul(rot_y, *this);
    return *this;
}

Matrix &Matrix::rotate_z(float radians)
{
    Matrix rot_y = matrix_rotation_z(radians);
    *this = matrix_mul(rot_y, *this);
    return *this;
}


Matrix matrix(float m00, float m01, float m02, float m03,
              float m10, float m11, float m12, float m13,
              float m20, float m21, float m22, float m23,
              float m30, float m31, float m32, float m33)
{
    return {
        m00, m01, m02, m03,
        m10, m11, m12, m13,
        m20, m21, m22, m23,
        m30, m31, m32, m33,
    };
}

Matrix3x3 matrix3x3(float m00, float m01, float m02,
                    float m10, float m11, float m12,
                    float m20, float m21, float m22)
{
    return {
        m00, m01, m02,
        m10, m11, m12,
        m20, m21, m22,
    };
}

Matrix2x2 matrix2x2(float m00, float m01,
                    float m10, float m11)
{
    return {
        m00, m01,
        m10, m11,
    };
}

bool matrix_eq(const Matrix &a, const Matrix &b)
{
    return
        float_eq(a.m00, b.m00) && float_eq(a.m01, b.m01) &&
        float_eq(a.m02, b.m02) && float_eq(a.m03, b.m03) &&

        float_eq(a.m10, b.m10) && float_eq(a.m11, b.m11) &&
        float_eq(a.m12, b.m12) && float_eq(a.m13, b.m13) &&

        float_eq(a.m20, b.m20) && float_eq(a.m21, b.m21) &&
        float_eq(a.m22, b.m22) && float_eq(a.m23, b.m23) &&

        float_eq(a.m30, b.m30) && float_eq(a.m31, b.m31) &&
        float_eq(a.m32, b.m32) && float_eq(a.m33, b.m33);
}

bool matrix_eq(const Matrix3x3 &a, const Matrix3x3 &b)
{
    return
        float_eq(a.m00, b.m00) && float_eq(a.m01, b.m01) &&
        float_eq(a.m02, b.m02) &&

        float_eq(a.m10, b.m10) && float_eq(a.m11, b.m11) &&
        float_eq(a.m12, b.m12) &&

        float_eq(a.m20, b.m20) && float_eq(a.m21, b.m21) &&
        float_eq(a.m22, b.m22);
}

bool matrix_eq(const Matrix2x2 &a, const Matrix2x2 &b)
{
    return
        float_eq(a.m00, b.m00) && float_eq(a.m01, b.m01) &&
        float_eq(a.m10, b.m10) && float_eq(a.m11, b.m11);
}

Matrix matrix_identity()
{
    return identity_matrix;
}

Matrix matrix_mul(const Matrix &a, const Matrix &b)
{
    return {
        //r c
        //0 0
        a.m00 * b.m00 + a.m01 * b.m10 + a.m02 * b.m20 + a.m03 * b.m30,
        //0 1
        a.m00 * b.m01 + a.m01 * b.m11 + a.m02 * b.m21 + a.m03 * b.m31,
        //0 2
        a.m00 * b.m02 + a.m01 * b.m12 + a.m02 * b.m22 + a.m03 * b.m32,
        //0 3
        a.m00 * b.m03 + a.m01 * b.m13 + a.m02 * b.m23 + a.m03 * b.m33,

        //1 0
        a.m10 * b.m00 + a.m11 * b.m10 + a.m12 * b.m20 + a.m13 * b.m30,
        //1 1
        a.m10 * b.m01 + a.m11 * b.m11 + a.m12 * b.m21 + a.m13 * b.m31,
        //1 2
        a.m10 * b.m02 + a.m11 * b.m12 + a.m12 * b.m22 + a.m13 * b.m32,
        //1 3
        a.m10 * b.m03 + a.m11 * b.m13 + a.m12 * b.m23 + a.m13 * b.m33,

        //2 0
        a.m20 * b.m00 + a.m21 * b.m10 + a.m22 * b.m20 + a.m23 * b.m30,
        //2 1
        a.m20 * b.m01 + a.m21 * b.m11 + a.m22 * b.m21 + a.m23 * b.m31,
        //2 2
        a.m20 * b.m02 + a.m21 * b.m12 + a.m22 * b.m22 + a.m23 * b.m32,
        //2 3
        a.m20 * b.m03 + a.m21 * b.m13 + a.m22 * b.m23 + a.m23 * b.m33,

        //3 0
        a.m30 * b.m00 + a.m31 * b.m10 + a.m32 * b.m20 + a.m33 * b.m30,
        //3 1
        a.m30 * b.m01 + a.m31 * b.m11 + a.m32 * b.m21 + a.m33 * b.m31,
        //3 2
        a.m30 * b.m02 + a.m31 * b.m12 + a.m32 * b.m22 + a.m33 * b.m32,
        //3 3
        a.m30 * b.m03 + a.m31 * b.m13 + a.m32 * b.m23 + a.m33 * b.m33,
    };
}

Tuple matrix_mul(const Matrix &m, const Tuple &t)
{
    return {
        // x
        m.m00 * t.x + m.m01 * t.y + m.m02 * t.z + m.m03 * t.w,
        // y
        m.m10 * t.x + m.m11 * t.y + m.m12 * t.z + m.m13 * t.w,
        // z
        m.m20 * t.x + m.m21 * t.y + m.m22 * t.z + m.m23 * t.w,
        // w
        m.m30 * t.x + m.m31 * t.y + m.m32 * t.z + m.m33 * t.w,
    };
}

Point matrix_mul(const Matrix &m, const Point &p)
{
    Tuple result = matrix_mul(m, static_cast<Tuple>(p));
    return *(Point *)&result;
}

Vector matrix_mul(const Matrix &m, const Vector &v)
{
    Tuple result = matrix_mul(m, static_cast<Tuple>(v));
    return *(Vector *)&result;
}

Matrix matrix_transpose(const Matrix &m)
{
    return {
        m.m00, m.m10, m.m20, m.m30,
        m.m01, m.m11, m.m21, m.m31,
        m.m02, m.m12, m.m22, m.m32,
        m.m03, m.m13, m.m23, m.m33
    };
}

float matrix_determinant(const Matrix2x2 &m)
{
    return m.m00 * m.m11 - m.m01 * m.m10;
}

float matrix_determinant(const Matrix3x3 &m)
{
    return m.m00 * matrix_cofactor(m, 0, 0) +
           m.m01 * matrix_cofactor(m, 0, 1) +
           m.m02 * matrix_cofactor(m, 0, 2);
}

float matrix_determinant(const Matrix &m)
{
    return m.m00 * matrix_cofactor(m, 0, 0) +
           m.m01 * matrix_cofactor(m, 0, 1) +
           m.m02 * matrix_cofactor(m, 0, 2) +
           m.m03 * matrix_cofactor(m, 0, 3);
}

float matrix_minor(const Matrix3x3 &m, int r, int c)
{
    return matrix_determinant(matrix_submatrix(m, r, c));
}

float matrix_minor(const Matrix &m, int r, int c)
{
    return matrix_determinant(matrix_submatrix(m, r, c));
}

float matrix_cofactor(const Matrix3x3 &m, int r, int c)
{
    float result = matrix_minor(m, r, c);
    if ((r + c) % 2 != 0) result *= -1;
    return result;
}

float matrix_cofactor(const Matrix &m, int r, int c)
{
    float result = matrix_minor(m, r, c);
    if ((r + c) % 2 != 0) result *= -1;
    return result;
}

Matrix matrix_cofactor_matrix(const Matrix& m)
{
    return {
        matrix_cofactor(m, 0, 0),
        matrix_cofactor(m, 0, 1),
        matrix_cofactor(m, 0, 2),
        matrix_cofactor(m, 0, 3),

        matrix_cofactor(m, 1, 0),
        matrix_cofactor(m, 1, 1),
        matrix_cofactor(m, 1, 2),
        matrix_cofactor(m, 1, 3),

        matrix_cofactor(m, 2, 0),
        matrix_cofactor(m, 2, 1),
        matrix_cofactor(m, 2, 2),
        matrix_cofactor(m, 2, 3),

        matrix_cofactor(m, 3, 0),
        matrix_cofactor(m, 3, 1),
        matrix_cofactor(m, 3, 2),
        matrix_cofactor(m, 3, 3),
    };
}

Matrix2x2 matrix_submatrix(const Matrix3x3 &m, int remove_row, int remove_column)
{
    assert(remove_row >= 0);
    assert(remove_row <= 2);
    assert(remove_column >= 0);
    assert(remove_column <= 2);

    Matrix2x2 result = {};

    int dr = 0;
    int dc = 0;

    for (int r = 0; r < 3; r++) {

        if (r == remove_row) continue;

        for (int c = 0; c < 3; c++) {

            if (c == remove_column) continue;

            assert(dr <= 2);
            assert(dc <= 2);
            result.m[dr][dc] = m.m[r][c];

            dc += 1;
        }

        dc = 0;
        dr += 1;
    }

    return result;
}

Matrix3x3 matrix_submatrix(const Matrix &m, int remove_row, int remove_column)
{
    assert(remove_row >= 0);
    assert(remove_row <= 3);
    assert(remove_column >= 0);
    assert(remove_column <= 3);

    Matrix3x3 result = {};

    int dr = 0;
    int dc = 0;

    for (int r = 0; r < 4; r++) {

        if (r == remove_row) continue;

        for (int c = 0; c < 4; c++) {

            if (c == remove_column) continue;

            assert(dr <= 3);
            assert(dc <= 3);
            result.m[dr][dc] = m.m[r][c];

            dc += 1;
        }

        dc = 0;
        dr += 1;
    }

    return result;

}

Matrix matrix_inverse(const Matrix &m)
{
    float determinant = matrix_determinant(m);
    assert(determinant != 0.0f);

    // Matrix result = matrix_cofactor_matrix(m);

    // result = matrix_transpose(result);
    // for (int i = 0; i < 16; i++) {
    //     result.flat[i] /= determinant;
    // }

    // return result;

    Matrix result;
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            float cofactor = matrix_cofactor(m, r, c);

            // Transpose in place
            result[c][r] = cofactor / determinant;
        }
    }

    return result;
}

Matrix matrix_translation(float x, float y, float z)
{
    Matrix result = identity_matrix;

    result.m03 = x;
    result.m13 = y;
    result.m23 = z;

    return result;
}

Matrix matrix_scale(float x, float y, float z)
{
    return {
        x, 0, 0, 0,
        0, y, 0, 0,
        0, 0, z, 0,
        0, 0, 0, 1
    };
}

Matrix matrix_rotation_x(float radians)
{
    float cr = cos(radians);
    float sr = sin(radians);

    return {
        1,  0,   0, 0,
        0, cr, -sr, 0,
        0, sr,  cr, 0,
        0,  0,   0, 1,
    };
}

Matrix matrix_rotation_y(float radians)
{
    float cr = cos(radians);
    float sr = sin(radians);

    return {
         cr, 0, sr, 0,
          0, 1,  0, 0,
        -sr, 0, cr, 0,
          0, 0,  0, 1
    };
}

Matrix matrix_rotation_z(float radians)
{
    float cr = cos(radians);
    float sr = sin(radians);

    return {
        cr, -sr, 0, 0,
        sr,  cr, 0, 0,
         0,   0, 1, 0,
         0,   0, 0, 1
    };
}

Matrix matrix_shear(float xy, float xz, float yx, float yz, float zx, float zy)
{
    return {
         1, xy, xz, 0,
        yx,  1, yz, 0,
        zx, zy,  1, 0,
         0,  0,  0, 1,
    };
}

Matrix matrix_ortho(float l, float r, float b, float t, float n, float f)
{
    return {
        2 / (r - l), 0,           0,            -(r + l) / (r - l),
        0,           2 / (t - b), 0,            -(t + b) / (t - b),
        0,           0,           -2 / (f - n), -(f + n) / (f - n),
        0,           0,           0,            1,
    };
}

void matrix_print(const Matrix& m)
{
    printf("{ %f, %f, %f, %f\n",   m.m00, m.m01, m.m02, m.m03);
    printf("  %f, %f, %f, %f\n",   m.m10, m.m11, m.m12, m.m13);
    printf("  %f, %f, %f, %f\n",   m.m20, m.m21, m.m22, m.m23);
    printf("  %f, %f, %f, %f }\n", m.m30, m.m31, m.m32, m.m33);
}

void matrix_print(const Matrix2x2& m)
{
    printf("{ %f, %f\n", m.m00, m.m01);
    printf("  %f, %f }\n", m.m10, m.m11);
}

}
