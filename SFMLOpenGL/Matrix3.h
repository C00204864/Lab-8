#pragma once
//#include <string>
//#include <sstream>
#include "Vector3.h"

/*
Liam Hickey
C00204864
Vector Class
*/

class Matrix3 {
public:
	//Constructor Functions
	Matrix3();
	Matrix3(MyVector3 vOne, MyVector3 vTwo, MyVector3 vThree);
	Matrix3(float a11, float a12, float a13, float a21, float a22, float a23, float a31, float a32, float a33);

	//Getter Functions
	float GetM11() const;
	float GetM12() const;
	float GetM13() const;
	float GetM21() const;
	float GetM22() const;
	float GetM23() const;
	float GetM31() const;
	float GetM32() const;
	float GetM33() const;

	//Row And Column Functions
	MyVector3 GetRow(int i) const;
	MyVector3 GetCol(int i) const;

	//Operator Overloads
	MyVector3 operator*(MyVector3 & vIn) const;
	Matrix3 operator+(Matrix3 & mIn) const;
	Matrix3 operator-(Matrix3 & mIn) const;
	Matrix3 operator*(Matrix3 & mIn) const;
	Matrix3 operator*(float valIn)const;

	//Matrix Operation Functions
	Matrix3 Transpose();
	float Determinant();
	Matrix3 Inverse();

	//Rotational Functions
	MyVector3 RotateAboutX(MyVector3 vectorToRotate, float angle);
	MyVector3 RotateAboutY(MyVector3 vectorToRotate, float angle);
	MyVector3 RotateAboutZ(MyVector3 vectorToRotate, float angle);

	//Translate Function
	void Translate(float xIn, float yIn, MyVector3 & vIn);

private:
	//Component Cells Of The Matrix
	float m_11;
	float m_12;
	float m_13;
	float m_21;
	float m_22;
	float m_23;
	float m_31;
	float m_32;
	float m_33;
};