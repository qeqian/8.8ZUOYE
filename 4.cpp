//4.���ַ�����
//������float���͵�С������һ������Ϊ8��char�����С�
//�ٴӸ���������ȡ��������float���͵�С�����Ƚ�ʹ�ò�ͬ������ȡ����С����ԭ������֮��Ĳ�࣬
//дһ��˵���ļ�����markdown��ʽд���ļ�����ΪREADME.md����
#include<stdio.h>
#include<string.h>
#include<math.h>
void way1(float a,float b,char *p) 
{
	char *p1=(char*)&a;
	char *p2=(char*)&b;
	for(int i=0;i<4;i++)
	{
		*(p+i)=p1[i];
		*(p+i+4)=p2[i];
	}
}
void way2(float a,float b,char *p)
{
	memcpy(p,&a,4);
	memcpy(p+4,&b,4);
}
void way3(float a,float b,char *p)
{
	struct numpair{
		float x;
		float y; 
	};
	struct numpair u={a,b};
	char *q=(char*)&u;
	for(int i=0;i<8;i++)
	{
		*(p+i)=*(q+i);
	}
}
float chazhi(float m,float m1)
{
	float diff=fabsf(m-m1);
	return diff;
}
int main()
{
	int i;
	float a,b;
	a=1.234f;
	b=5.6789f;
	char arr[8]={0};
	typedef void (*Function)(float,float,char*);
	Function funs[]={way1,way2,way3};
	for(i=0;i<3;i++)
	{
		a=a+1;
		b=b-1;
		memset(arr,0,8);//������� 
		funs[i](a,b,arr);//ÿ��ѭ�����ò�ͬ�ĺ��� 
	    float a1,b1;//��ȡ���� 
	    memcpy(&a1,arr,4);
	    memcpy(&b1,arr+4,4);
	    printf("����%d:\n",i+1);
        printf("ԭʼ��ֵ: a = %.6f, b = %.6f\n", a, b);
        printf("��ȡ��ֵ: a = %.6f, b = %.6f\n", a1, b1);
        printf("��ֵ:     a_diff = %f, b_diff = %f\n", chazhi(a,a1), chazhi(b,b1));
	}
	return 0;
}
