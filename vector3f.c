#include "vector3f.h"
#include <math.h> 
vector3f add(vector3f* a,vector3f* b)//.......加法 
{
	vector3f c;
	c.x=a->x+b->x;
	c.y=a->y+b->y;
	c.z=a->z+b->z;
	return c; 
}
vector3f sub(vector3f* a,vector3f* b)//.......减法 
{
	vector3f c;
	c.x=a->x-b->x;
	c.y=a->y-b->y;
	c.z=a->z-b->z;
	return c; 
}
float dotpro(vector3f* a,vector3f* b)//.......点乘 
{
	float num;
	num=(a->x*b->x+a->y*b->y+a->z*b->z);
	return num;
}
vector3f unit(vector3f* a)//.......单位化 
{
	vector3f c={0,0,0};
	float modul=modulo(a);
	if(modul==0)
	return c;
	else 
	{
		c.x=a->x/modul;
		c.y=a->y/modul;
		c.z=a->z/modul;
		return c;
	}
}
float modulo(vector3f* a)//.......取模 
{
	float result,x1,y1,z1;
	x1=pow(a->x,2);
	y1=pow(a->y,2);
	z1=pow(a->z,2);
	result=sqrt(x1+y1+z1);
	return result;
}
vector3f multi(vector3f* a,vector3f* b)//.......叉乘 
{
	vector3f result;
	result.x = a->y * b->z - a->z * b->y;
    result.y = a->z * b->x - a->x * b->z;
    result.z = a->x * b->y - a->y * b->x;
    return result;
}
