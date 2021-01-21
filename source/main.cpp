
#include <stdio.h>

// #include "putting_it_together_ch02.h"

#include "matrix.h"

using namespace RayTracer;

int main(int argc, char** argv)
{
    // CH02_putting_it_together();

    // Matrix identity = identity_matrix;
    // matrix_print(identity);
    // matrix_print(matrix_inverse(identity));

    Matrix a = { -5,  2,  6, -8,
                  1, -5,  1,  8,
                  7,  7, -6, -7,
                  1, -3,  7,  4 };

    printf("\nA:\n");
    matrix_print(a);

    Matrix a_inverse = matrix_inverse(a);

    printf("\nA inverse:\n");
    matrix_print(a_inverse);

    Matrix b = matrix_mul(a, a_inverse);
    printf("\nB:\n");
    matrix_print(b);

    return 0;
}

