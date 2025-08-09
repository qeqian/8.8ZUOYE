#include "matrix.h"
#include <stdio.h>

int main() {
    int row, column;  // ����ԭ�б�����
    
    printf("����������������");
    scanf("%d",&row);
    printf("����������������");
    scanf("%d",&column);
    
    Matrix mat = matrix_create(row,column);
    if (mat == NULL) {
        return 1;
    }
    
    matrix_input(mat);
    
    printf("\nԭʼ����\n");
    matrix_print(mat);
    
    Matrix transMat = matrix_transpose(mat);
    if (transMat == NULL) {
        matrix_free(mat);
        return 1;
    }
    
    printf("\nת�þ���\n");
    matrix_print(transMat);
    
    Matrix result = matrix_multiply(mat, transMat);
    if (result != NULL) {
        printf("\nԭʼ������ת�þ���ĳ˻���\n");
        matrix_print(result);
    }
    
    matrix_free(mat);
    matrix_free(transMat);
    matrix_free(result);
    
    return 0;
}
    
