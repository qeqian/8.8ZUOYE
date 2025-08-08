#include <stdio.h>
#include <stdint.h>
//不会写，正在学。 

uint32_t endian_swap(uint32_t value) {
    // 分解原数据的四个字节
    uint8_t byte0 = (value & 0x000000FF);  // 低8位（0x47）
    uint8_t byte1 = (value & 0x0000FF00) >> 8;  // 次低8位（0x36）
    uint8_t byte2 = (value & 0x00FF0000) >> 16;  // 次高8位（0x25）
    uint8_t byte3 = (value & 0xFF000000) >> 24;  // 高8位（0x12）
    
    // 重新组合为相反字节序
    return (byte0 << 24) | (byte1 << 16) | (byte2 << 8) | byte3;
}

// 判断本机字节序：返回1表示小端，0表示大端
int is_little_endian() {
    uint32_t test = 0x00000001;
    // 将32位整数的地址转换为8位指针，指向第一个字节
    uint8_t *byte = (uint8_t *)&test;
    // 如果第一个字节是1，则为小端模式
    return (*byte == 1);
}

int main() {
    uint32_t num = 0x12253647;
    
    // 检测本机字节序
    int little_endian = is_little_endian();
    printf("本机字节序: %s\n", little_endian ? "小端模式" : "大端模式");
    
    // 输出原数字
    printf("原始数字: 0x%08X\n", num);
    
    // 输出本机字节序下的存储形式
    printf("本机字节序下的存储(从低地址到高地址): ");
    uint8_t *bytes = (uint8_t *)&num;
    int i; 
    for (i = 0; i < 4; i++) {
        printf("0x%02X ", bytes[i]);
    }
    printf("\n");
    
    // 计算并输出大端模式下的存储形式
    uint32_t big_endian_num = little_endian ? endian_swap(num) : num;
    printf("大端模式下的存储(从低地址到高地址): 0x12 0x25 0x36 0x47\n");
    printf("大端模式对应的数值: 0x%08X\n", big_endian_num);
    
    // 计算并输出小端模式下的存储形式
    uint32_t little_endian_num = little_endian ? num : endian_swap(num);
    printf("小端模式下的存储(从低地址到高地址): 0x47 0x36 0x25 0x12\n");
    printf("小端模式对应的数值: 0x%08X\n", little_endian_num);
    
    return 0;
}


