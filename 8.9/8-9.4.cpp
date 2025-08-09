#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 比较函数，用于qsort
int compare(const void *a, const void *b) {
    float float_a = *(const float *)a;
    float float_b = *(const float *)b;
    
    if (float_a < float_b) return -1;
    if (float_a > float_b) return 1;
    return 0;
}

// 输入函数：读取数据直到输入c结束
float* inputNumbers(int *count) {
    float *numbers = NULL;
    char input[100];
    *count = 0;

    printf("请输入float类型的数据（每行一个，输入c结束）：\n");

    while (1) {
        // 读取一行输入
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        // 移除换行符
        input[strcspn(input, "\n")] = '\0';
        
        // 检查是否输入c（不区分大小写）
if (strlen(input) == 1 && tolower(input[0]) == 'c') {
    break; 
}
        // 扩展数组
        float *temp = (float *)realloc(numbers, (*count + 1) * sizeof(float));
        if (temp == NULL) {
            printf("内存分配失败\n");
            free(numbers);
            return NULL;
        }
        numbers = temp;

        // 转换为float
        if (sscanf(input, "%f", &numbers[*count]) != 1) {
            printf("无效的输入: %s，请重新输入\n", input);
            continue; // 不退出，允许重新输入
        }

        (*count)++;
    }

    return numbers;
}

int main() {
    int count;
    float *numbers = inputNumbers(&count);

    if (numbers == NULL || count == 0) {
        printf("没有有效数据可排序。\n");
        return 1;
    }

    // 排序
    qsort(numbers, count, sizeof(float), compare);

    // 输出结果
    printf("排序后的结果（从小到大）：\n");
    for (int i = 0; i < count; i++) {
        printf("%.2f ", numbers[i]);
    }
    printf("\n");

    free(numbers);
    return 0;
}
    
