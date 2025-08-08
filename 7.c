#include <stdio.h>
#include <stdint.h>
//����д������ѧ�� 

uint32_t endian_swap(uint32_t value) {
    // �ֽ�ԭ���ݵ��ĸ��ֽ�
    uint8_t byte0 = (value & 0x000000FF);  // ��8λ��0x47��
    uint8_t byte1 = (value & 0x0000FF00) >> 8;  // �ε�8λ��0x36��
    uint8_t byte2 = (value & 0x00FF0000) >> 16;  // �θ�8λ��0x25��
    uint8_t byte3 = (value & 0xFF000000) >> 24;  // ��8λ��0x12��
    
    // �������Ϊ�෴�ֽ���
    return (byte0 << 24) | (byte1 << 16) | (byte2 << 8) | byte3;
}

// �жϱ����ֽ��򣺷���1��ʾС�ˣ�0��ʾ���
int is_little_endian() {
    uint32_t test = 0x00000001;
    // ��32λ�����ĵ�ַת��Ϊ8λָ�룬ָ���һ���ֽ�
    uint8_t *byte = (uint8_t *)&test;
    // �����һ���ֽ���1����ΪС��ģʽ
    return (*byte == 1);
}

int main() {
    uint32_t num = 0x12253647;
    
    // ��Ȿ���ֽ���
    int little_endian = is_little_endian();
    printf("�����ֽ���: %s\n", little_endian ? "С��ģʽ" : "���ģʽ");
    
    // ���ԭ����
    printf("ԭʼ����: 0x%08X\n", num);
    
    // ��������ֽ����µĴ洢��ʽ
    printf("�����ֽ����µĴ洢(�ӵ͵�ַ���ߵ�ַ): ");
    uint8_t *bytes = (uint8_t *)&num;
    int i; 
    for (i = 0; i < 4; i++) {
        printf("0x%02X ", bytes[i]);
    }
    printf("\n");
    
    // ���㲢������ģʽ�µĴ洢��ʽ
    uint32_t big_endian_num = little_endian ? endian_swap(num) : num;
    printf("���ģʽ�µĴ洢(�ӵ͵�ַ���ߵ�ַ): 0x12 0x25 0x36 0x47\n");
    printf("���ģʽ��Ӧ����ֵ: 0x%08X\n", big_endian_num);
    
    // ���㲢���С��ģʽ�µĴ洢��ʽ
    uint32_t little_endian_num = little_endian ? num : endian_swap(num);
    printf("С��ģʽ�µĴ洢(�ӵ͵�ַ���ߵ�ַ): 0x47 0x36 0x25 0x12\n");
    printf("С��ģʽ��Ӧ����ֵ: 0x%08X\n", little_endian_num);
    
    return 0;
}


