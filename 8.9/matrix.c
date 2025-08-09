#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

// 创建矩阵
Matrix matrix_create(int row, int column) {
    int i;  // 循环变量移到外部定义
    
    if (row==0||column==0) 
	{
        printf("错误：行数和列数必须大于0\n");
        return NULL;
    }
    
    Matrix mat = (Matrix)malloc(sizeof(struct MParam));
    if (mat == NULL) {
       perror("内存分配失败");
       return NULL;
    }
    
    mat->row = row;
    mat->column = column;
    mat->data = (float **)malloc(row * sizeof(float *));
    if (mat->data == NULL) {
        perror("内存分配失败");
        free(mat);
        return NULL;
    }
    
    // 循环变量i在外部声明
    for (i = 0; i < row; i++) {
        mat->data[i] = (float *)malloc(column * sizeof(float));
        if (mat->data[i] == NULL) {
            perror("内存分配失败");
            // 回滚已分配内存
            int j;  // 内部循环变量也移到外部
            for (j = 0; j < i; j++) {
                free(mat->data[j]);
            }
            free(mat->data);
            free(mat);
            return NULL;
        }
    }
    
    return mat;
}

// 输入矩阵元素
void matrix_input(Matrix mat) {
    if (mat == NULL) return;
    
    int i, j;  // 循环变量移到外部
    printf("请输入矩阵元素（%d行%d列）：\n",mat->row,mat->column);
    
    for (i = 0; i < mat->row; i++) {
        for (j = 0; j < mat->column; j++) {
            scanf("%f", &mat->data[i][j]);
        }
    }
}

// 计算转置矩阵
Matrix matrix_transpose(Matrix mat) {
    if (mat == NULL) return NULL;
    
    Matrix trans = matrix_create(mat->column, mat->row);
    if (trans == NULL) return NULL;
    
    int i, j;  // 循环变量移到外部
    for (i = 0; i < mat->row; i++) {
        for (j = 0; j < mat->column; j++) {
            trans->data[j][i] = mat->data[i][j];
        }
    }
    
    return trans;
}

// 矩阵乘法
Matrix matrix_multiply(Matrix a, Matrix b) {
    if (a == NULL || b == NULL || a->column != b->row) {
        printf("错误：矩阵维度不匹配，无法相乘\n");
        return NULL;
    }
    
    Matrix res = matrix_create(a->row, b->column);
    if (res == NULL) return NULL;
    
    int i, j, k;  // 循环变量移到外部
    for (i = 0; i < res->row; i++) {
        for (j = 0; j < res->column; j++) {
            res->data[i][j] = 0;
            for (k = 0; k < a->column; k++) {
                res->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
    
    return res;
}

// 打印矩阵
void matrix_print(Matrix mat) {
    if (mat == NULL) return;
    
    int i, j;  // 循环变量移到外部
    for (i = 0; i < mat->row; i++) {
        for (j = 0; j < mat->column; j++) {
            printf("%.2f\t", mat->data[i][j]);
        }
        printf("\n");
    }
}

// 释放矩阵内存
void matrix_free(Matrix mat) {
    if (mat == NULL) return;
    
    int i;  // 循环变量移到外部
    for (i = 0; i < mat->row; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
    free(mat);
}
    
