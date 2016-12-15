#pragma once
#include <string>
#include <sstream>

/*
Liam Hickey
C00204864
Vector Class
*/

class MyVector3 {
public:
	//Constructor Functions
	MyVector3(float xIn = 0.f, float yIn = 0.f, float zIn = 0.f);
	MyVector3(MyVector3 &vIn);

	//Getter Functions
	float GetX() const;
	float GetY() const;
	float GetZ() const;

	//To String Function
	std::string ToString() const;

	//Vector Length(Magnitude) Function
	double Length() const;
	double LengthSquared() const;

	//Determine If Two Vectors Are Equal Function
	bool Equals(MyVector3 &vIn) const;

	//Vector Product Functions
	double DotProduct(MyVector3 &vIn) const;
	MyVector3 CrossProduct(MyVector3 & vIn) const;

	//Operator Overloads
	bool operator==(MyVector3 &vIn) const;
	bool operator!=(MyVector3 &vIn) const;
	MyVector3 operator+(MyVector3 &vIn) const;
	MyVector3 operator-(MyVector3 &vIn) const;

	//Angle Between Two Vectors Function
	double AngleBetween(MyVector3 & vIn) const;

	//Unit Vector Function
	MyVector3 Unit();

	//Component Functions
	MyVector3 ParallelComponent(MyVector3 &vIn);
	MyVector3 PerpendicularComponent(MyVector3 &vIn);

	//Scale Functions
	MyVector3 Scale(float fIn);
	MyVector3 Scale(double dIn);

private:
	float m_x;
	float m_y;
	float m_z;

};