//5.x、y、z三个float元素的三维向量结构体，结构体命名为vector3f
//围绕它写一个运算库（每个函数都要写注释哦）
//实现三维向量的加、减、点乘、单位化、求模与叉乘（可以添加其他功能）
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
 
