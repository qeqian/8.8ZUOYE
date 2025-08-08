# 无标题

# 第四题说明文件：

## 1. 使用函数：

- way1:通过强制将浮点型数据的地址字符化，然后通过字符型指针循环在依次存入char数组中。

```c
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
```

- way2:利用函数memcpy,将数据存入数组中。

```c
void way2(float a,float b,char *p)
{
	memcpy(p,&a,4);
	memcpy(p+4,&b,4);
}
```

- way3:将指针和结构体结合起来，存入时利用结构体变量的指针，但仍然需要强制类型转换，与第一种方法差不多。

```c
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
```

- chazhi:算出存入前和提取后的数据之差。

```c
float chazhi(float m,float m1)
{
	float diff=fabsf(m-m1);
	return diff;
}
```

## 2. 主函数：

- 关键是定义了一个函数数组，通过函数指针，实现在不同循环中使用不同的函数。
- a和b的变化用来检测循环的执行。

```c
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
```