//5.x��y��z����floatԪ�ص���ά�����ṹ�壬�ṹ������Ϊvector3f
//Χ����дһ������⣨ÿ��������Ҫдע��Ŷ��
//ʵ����ά�����ļӡ�������ˡ���λ������ģ���ˣ���������������ܣ�
#ifndef VECTOR3F_H
#define VECTOR3F_H
typedef struct {
    float x;
    float y;  
    float z;  
} vector3f;
vector3f add(vector3f* a,vector3f* b);//�����ӷ�
vector3f sub(vector3f* a,vector3f* b);//��������
float dotpro(vector3f* a,vector3f* b);//���
vector3f unit(vector3f* a);//��λ��
float modulo(vector3f* a);//��ģ
vector3f multi(vector3f* a,vector3f* b);//��� 
#endif
 
