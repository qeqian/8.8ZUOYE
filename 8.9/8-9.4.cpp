#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// �ȽϺ���������qsort
int compare(const void *a, const void *b) {
    float float_a = *(const float *)a;
    float float_b = *(const float *)b;
    
    if (float_a < float_b) return -1;
    if (float_a > float_b) return 1;
    return 0;
}

// ���뺯������ȡ����ֱ������c����
float* inputNumbers(int *count) {
    float *numbers = NULL;
    char input[100];
    *count = 0;

    printf("������float���͵����ݣ�ÿ��һ��������c��������\n");

    while (1) {
        // ��ȡһ������
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        // �Ƴ����з�
        input[strcspn(input, "\n")] = '\0';
        
        // ����Ƿ�����c�������ִ�Сд��
if (strlen(input) == 1 && tolower(input[0]) == 'c') {
    break; 
}
        // ��չ����
        float *temp = (float *)realloc(numbers, (*count + 1) * sizeof(float));
        if (temp == NULL) {
            printf("�ڴ����ʧ��\n");
            free(numbers);
            return NULL;
        }
        numbers = temp;

        // ת��Ϊfloat
        if (sscanf(input, "%f", &numbers[*count]) != 1) {
            printf("��Ч������: %s������������\n", input);
            continue; // ���˳���������������
        }

        (*count)++;
    }

    return numbers;
}

int main() {
    int count;
    float *numbers = inputNumbers(&count);

    if (numbers == NULL || count == 0) {
        printf("û����Ч���ݿ�����\n");
        return 1;
    }

    // ����
    qsort(numbers, count, sizeof(float), compare);

    // ������
    printf("�����Ľ������С���󣩣�\n");
    for (int i = 0; i < count; i++) {
        printf("%.2f ", numbers[i]);
    }
    printf("\n");

    free(numbers);
    return 0;
}
    
