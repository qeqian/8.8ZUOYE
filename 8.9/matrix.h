#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h>

// 矩阵结构体定义（Matrix为指针类型）
typedef struct MParam {
    int row;
    int column;
    float **data;
} *Matrix;

// 函数声明
Matrix matrix_create(int row, int column);
void matrix_input(Matrix mat);
Matrix matrix_transpose(Matrix mat);
Matrix matrix_multiply(Matrix a, Matrix b);
void matrix_print(Matrix mat);
void matrix_free(Matrix mat);

#endif // MATRIX_H
    
 
