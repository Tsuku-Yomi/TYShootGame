#pragma once
#include <math.h>
class T_Vector3
{
public:
	T_Vector3(void) :x(0), y(0), z(0) {};
	T_Vector3(float x1, float y1, float z1) :x(x1), y(y1), z(z1) {};
	T_Vector3(const T_Vector3& v);

	T_Vector3 operator =(const T_Vector3& v); //��ֵ���������

	// +-*/��ͬ�����ط�ʽ
	T_Vector3 operator +(const T_Vector3& v);
	T_Vector3 operator -(const T_Vector3& v);
	T_Vector3 operator *(const T_Vector3& v);
	T_Vector3 operator /(const T_Vector3& v);

	T_Vector3 operator +(float a);
	T_Vector3 operator -(float a);
	T_Vector3 operator *(float a);
	T_Vector3 operator /(float a);

	float dot(const T_Vector3& v1, const T_Vector3& v2);      //2��������������
	T_Vector3 Cross(const T_Vector3& v1, const T_Vector3& v2); //2��������������
	float length();     //�������ĳ���
	T_Vector3 Normalize();//��λ������
	T_Vector3 Scale(float n);//�������������� 
	virtual ~T_Vector3(void);

private:
	float x;
	float y;
	float z;
};
