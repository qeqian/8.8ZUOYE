//4.三种方法，
//将两个float类型的小数存入一个长度为8的char数组中。
//再从该数组中提取出这两个float类型的小数，比较使用不同方法提取出的小数和原来数字之间的差距，
//写一个说明文件（用markdown格式写，文件命名为README.md）。
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
		memset(arr,0,8);//清空数组 
		funs[i](a,b,arr);//每次循环调用不同的函数 
	    float a1,b1;//提取数字 
	    memcpy(&a1,arr,4);
	    memcpy(&b1,arr+4,4);
	    printf("方法%d:\n",i+1);
        printf("原始数值: a = %.6f, b = %.6f\n", a, b);
        printf("提取数值: a = %.6f, b = %.6f\n", a1, b1);
        printf("差值:     a_diff = %f, b_diff = %f\n", chazhi(a,a1), chazhi(b,b1));
	}
	return 0;
}
