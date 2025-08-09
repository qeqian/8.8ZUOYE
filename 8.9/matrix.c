#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

// ��������
Matrix matrix_create(int row, int column) {
    int i;  // ѭ�������Ƶ��ⲿ����
    
    if (row==0||column==0) 
	{
        printf("���������������������0\n");
        return NULL;
    }
    
    Matrix mat = (Matrix)malloc(sizeof(struct MParam));
    if (mat == NULL) {
       perror("�ڴ����ʧ��");
       return NULL;
    }
    
    mat->row = row;
    mat->column = column;
    mat->data = (float **)malloc(row * sizeof(float *));
    if (mat->data == NULL) {
        perror("�ڴ����ʧ��");
        free(mat);
        return NULL;
    }
    
    // ѭ������i���ⲿ����
    for (i = 0; i < row; i++) {
        mat->data[i] = (float *)malloc(column * sizeof(float));
        if (mat->data[i] == NULL) {
            perror("�ڴ����ʧ��");
            // �ع��ѷ����ڴ�
            int j;  // �ڲ�ѭ������Ҳ�Ƶ��ⲿ
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

// �������Ԫ��
void matrix_input(Matrix mat) {
    if (mat == NULL) return;
    
    int i, j;  // ѭ�������Ƶ��ⲿ
    printf("���������Ԫ�أ�%d��%d�У���\n",mat->row,mat->column);
    
    for (i = 0; i < mat->row; i++) {
        for (j = 0; j < mat->column; j++) {
            scanf("%f", &mat->data[i][j]);
        }
    }
}

// ����ת�þ���
Matrix matrix_transpose(Matrix mat) {
    if (mat == NULL) return NULL;
    
    Matrix trans = matrix_create(mat->column, mat->row);
    if (trans == NULL) return NULL;
    
    int i, j;  // ѭ�������Ƶ��ⲿ
    for (i = 0; i < mat->row; i++) {
        for (j = 0; j < mat->column; j++) {
            trans->data[j][i] = mat->data[i][j];
        }
    }
    
    return trans;
}

// ����˷�
Matrix matrix_multiply(Matrix a, Matrix b) {
    if (a == NULL || b == NULL || a->column != b->row) {
        printf("���󣺾���ά�Ȳ�ƥ�䣬�޷����\n");
        return NULL;
    }
    
    Matrix res = matrix_create(a->row, b->column);
    if (res == NULL) return NULL;
    
    int i, j, k;  // ѭ�������Ƶ��ⲿ
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

// ��ӡ����
void matrix_print(Matrix mat) {
    if (mat == NULL) return;
    
    int i, j;  // ѭ�������Ƶ��ⲿ
    for (i = 0; i < mat->row; i++) {
        for (j = 0; j < mat->column; j++) {
            printf("%.2f\t", mat->data[i][j]);
        }
        printf("\n");
    }
}

// �ͷž����ڴ�
void matrix_free(Matrix mat) {
    if (mat == NULL) return;
    
    int i;  // ѭ�������Ƶ��ⲿ
    for (i = 0; i < mat->row; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
    free(mat);
}
    
