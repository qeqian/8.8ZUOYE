# 无标题

# 第五题说明

## 1. 头文件：

```c
#ifndef VECTOR3F_H
#define VECTOR3F_H
typedef struct {
    float x;
    float y;  
    float z;  
} vector3f;
vector3f add(vector3f* a,vector3f* b);//向量加法
vector3f sub(vector3f* a,vector3f* b);//向量减法
float dotpro(vector3f* a,vector3f* b);//点乘
vector3f unit(vector3f* a);//单位化
float modulo(vector3f* a);//求模
vector3f multi(vector3f* a,vector3f* b);//叉乘 
#endif
 
```

- **#define用于防止头文件被重复编译。**
- 定义结构体 **vector3f。**
- 声明各种函数。

## 2. 头文件：

- 包含了在头文件声明的函数定义。如：叉乘和取模

```c
vector3f multi(vector3f* a,vector3f* b)//.......叉乘 
{
	vector3f result;
	result.x = a->y * b->z - a->z * b->y;
    result.y = a->z * b->x - a->x * b->z;
    result.z = a->x * b->y - a->y * b->x;
    return result;
}
```

```c
float modulo(vector3f* a)//.......取模 
{
	float result,x1,y1,z1;
	x1=pow(a->x,2);
	y1=pow(a->y,2);
	z1=pow(a->z,2);
	result=sqrt(x1+y1+z1);
	return result;
}
```

## 3. 执行文件

```c
int main()
{
	//第一问
	vector3f AB={0.0f, 1.0f, 0.0f};
    vector3f AC1={-1.0f, 1.0f, -1.0f}; 
    vector3f d=multi(&AB,&AC1);
	float result1=modulo(&d)/modulo(&AC1);
	printf("点B到直线AC1的距离为%f\n",result1);
	//第二问
	vector3f n={1.0f,2.0f,1.0f};
	vector3f FC={0.0f,0.5f,0.0f};
	float result2;
	result2= dotpro(&FC,&n)/modulo(&n);
	printf("直线FC到平面AEC1的距离为%f",result2); 
	return 0;
}
```

- 人为的计算所需的向量坐标初始化，然后调用函数进行计算，输出结果。