#include<stdio.h>
#include<stdint.h> 
#include<string.h>
int main()
 {
    float f1 = 59.622f,f2 = 92.6327f;//ԭʼ���� 
    char arr[4];
    float scale1=1000,scale2=10000;//�������ͱ�����εķŴ��� 
    
    uint16_t num1 = (uint16_t)(f1 * scale1); 
    uint16_t num2 = (uint16_t)(f2 * scale2);//�������ͱ�Ϊuint16_t���ͣ�ÿ�����������ֽڣ���С�ֽڡ�
	 
    memcpy(arr,&num1,2);
    memcpy(arr+2, &num2,2);//���������ݷ���������
	 
    uint16_t exnum1, exnum2;
    memcpy(&exnum1, arr, 2);
    memcpy(&exnum2, arr + 2, 2);//������ȡ�� 
    
    float result1 = exnum1 / scale1;
    float result2 = exnum2/ scale2;// ת����float
    
    printf("ԭʼֵ1: %.3f\n", f1);
    printf("��ȡֵ1: %.3f\n", result1);
    printf("���:     %.3f\n\n", f1 - result1);
    printf("ԭʼֵ2: %.4f\n", f2);
    printf("��ȡֵ2: %.4f\n", result2);
    printf("���:     %.4f\n", f2-result2);// ��ʾ���
    
    //�Ľ���
	printf("\n\n�Ľ���\n");//��Ϊf2��ת��������ʱ������uint16_t�����ֵ65535���������ݱ��ضϣ�Ӧȷ������Ϊ����ʱ�ڷ�Χ�ڡ�

	scale2 = 65535.0f / 100.0f;  // 655.35 ���µ������� 
	
    num2 = (uint16_t)(f2 * scale2);
    memcpy(arr+2, &num2,2);
    memcpy(&exnum2, arr + 2, 2);
    result2 = exnum2/ scale2;//�ظ�����Ĳ���

    printf("ԭʼֵ2: %.4f\n", f2);
    printf("��ȡֵ2: %.4f\n", result2);
    printf("���:     %.4f\n", f2-result2);// ��ʾ���
    
    return 0;
}


