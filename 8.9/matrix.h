#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h>

// ����ṹ�嶨�壨MatrixΪָ�����ͣ�
typedef struct MParam {
    int row;
    int column;
    float **data;
} *Matrix;

// ��������
Matrix matrix_create(int row, int column);
void matrix_input(Matrix mat);
Matrix matrix_transpose(Matrix mat);
Matrix matrix_multiply(Matrix a, Matrix b);
void matrix_print(Matrix mat);
void matrix_free(Matrix mat);

#endif // MATRIX_H
    
 
