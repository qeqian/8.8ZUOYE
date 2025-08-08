#include"vector3f.h"
#include<stdio.h>
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
