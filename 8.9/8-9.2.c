#include<stdio.h>
#include<stdint.h> 
#include<string.h>
int main()
 {
    float f1 = 59.622f,f2 = 92.6327f;//原始数据 
    char arr[4];
    float scale1=1000,scale2=10000;//将浮点型变成整形的放大倍数 
    
    uint16_t num1 = (uint16_t)(f1 * scale1); 
    uint16_t num2 = (uint16_t)(f2 * scale2);//将浮点型变为uint16_t类型，每个变量两个字节，缩小字节。
	 
    memcpy(arr,&num1,2);
    memcpy(arr+2, &num2,2);//将整形数据放入数组中
	 
    uint16_t exnum1, exnum2;
    memcpy(&exnum1, arr, 2);
    memcpy(&exnum2, arr + 2, 2);//将数据取出 
    
    float result1 = exnum1 / scale1;
    float result2 = exnum2/ scale2;// 转换回float
    
    printf("原始值1: %.3f\n", f1);
    printf("提取值1: %.3f\n", result1);
    printf("误差:     %.3f\n\n", f1 - result1);
    printf("原始值2: %.4f\n", f2);
    printf("提取值2: %.4f\n", result2);
    printf("误差:     %.4f\n", f2-result2);// 显示结果
    
    //改进：
	printf("\n\n改进：\n");//因为f2在转化到整数时超过了uint16_t的最大值65535，所以数据被截断，应确保扩大为整数时在范围内。

	scale2 = 65535.0f / 100.0f;  // 655.35 ，新的扩大倍数 
	
    num2 = (uint16_t)(f2 * scale2);
    memcpy(arr+2, &num2,2);
    memcpy(&exnum2, arr + 2, 2);
    result2 = exnum2/ scale2;//重复上面的操作

    printf("原始值2: %.4f\n", f2);
    printf("提取值2: %.4f\n", result2);
    printf("误差:     %.4f\n", f2-result2);// 显示结果
    
    return 0;
}


