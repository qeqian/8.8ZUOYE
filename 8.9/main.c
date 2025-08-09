#include "matrix.h"
#include <stdio.h>

int main() {
    int row, column;  // 保持原有变量名
    
    printf("请输入矩阵的行数：");
    scanf("%d",&row);
    printf("请输入矩阵的列数：");
    scanf("%d",&column);
    
    Matrix mat = matrix_create(row,column);
    if (mat == NULL) {
        return 1;
    }
    
    matrix_input(mat);
    
    printf("\n原始矩阵：\n");
    matrix_print(mat);
    
    Matrix transMat = matrix_transpose(mat);
    if (transMat == NULL) {
        matrix_free(mat);
        return 1;
    }
    
    printf("\n转置矩阵：\n");
    matrix_print(transMat);
    
    Matrix result = matrix_multiply(mat, transMat);
    if (result != NULL) {
        printf("\n原始矩阵与转置矩阵的乘积：\n");
        matrix_print(result);
    }
    
    matrix_free(mat);
    matrix_free(transMat);
    matrix_free(result);
    
    return 0;
}
    
