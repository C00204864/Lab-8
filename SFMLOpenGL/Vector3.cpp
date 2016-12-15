#include "Vector3.h"

//Constructor Function
MyVector3::MyVector3(float xIn, float yIn, float zIn)
{
	m_x = xIn;
	m_y = yIn;
	m_z = zIn;
}

MyVector3::MyVector3(MyVector3 &vIn)
{
	m_x = vIn.GetX();
	m_y = vIn.GetY();
	m_z = vIn.GetZ();
}

//Function To Read The Value Of The Private Member X
float MyVector3::GetX() const
{
	return m_x;
}

//Function To Read The Value Of The Private Member Y
float MyVector3::GetY() const
{
	return m_y;
}

//Function To Read The Value Of The Private Member Z
float MyVector3::GetZ() const
{
	return m_z;
}

//Function Converts To String
std::string MyVector3::ToString() const
{
	std::ostringstream ss;
	ss << m_x << ", " << m_y << ", " << m_z;
	return std::string(ss.str());
}

//Function Returns The Length Of The Vector
double MyVector3::Length() const
{
	return (sqrt((m_x * m_x) + (m_y * m_y) + (m_z * m_z)));
}

//Function Returns The Length Of The Vector Squared
double MyVector3::LengthSquared() const
{
	return ((m_x * m_x) + (m_y * m_y) + (m_z * m_z));
}

//Function To Tell if Two Vectors Are Equal
bool MyVector3::Equals(MyVector3 &vIn) const
{
	if (m_x == vIn.GetX() && m_y == vIn.GetY() && m_z == vIn.GetZ())
	{
		return true;
	}
	return false;
}

//'==' Operator Overload
bool MyVector3::operator==(MyVector3 &vIn) const
{
	if (m_x == vIn.GetX() && m_y == vIn.GetY() && m_z == vIn.GetZ())
	{
		return true;
	}
	return false;
}

//'!=' Operator Overload
bool MyVector3::operator!=(MyVector3 &vIn) const
{
	if (m_x != vIn.GetX() || m_y != vIn.GetY() || m_z != vIn.GetZ())
	{
		return true;
	}
	return false;
}

//'+' Operator Overload
MyVector3 MyVector3::operator+(MyVector3 &vIn) const
{
	return MyVector3((m_x + vIn.GetX()), (m_y + vIn.GetY()), (m_z + vIn.GetZ()));
}

//'-' Operator Overload
MyVector3 MyVector3::operator-(MyVector3 &vIn) const
{
	return MyVector3((m_x - vIn.GetX()), (m_y - vIn.GetY()), (m_z - vIn.GetZ()));
}

//Function Calculates And Returns The Dot Product Of Two Vectors
double MyVector3::DotProduct(MyVector3 &vIn) const
{
	return double((m_x * vIn.GetX()) + (m_y * vIn.GetY()) + (m_z * vIn.GetZ()));
}

//Function Calculates And Returns The Cross Product OF Two Vectors
MyVector3 MyVector3::CrossProduct(MyVector3 &vIn) const
{
	return MyVector3(((m_y * vIn.GetZ()) - (m_z * vIn.GetY())), ((m_x * vIn.GetZ()) - (m_z * vIn.GetX())), ((m_x * vIn.GetY()) - (m_y * vIn.GetX()))); //Done Using The Determinant Method
}

//Function Calculates the Angle Between Two Vectors (slightly off due to the inaccuracy of acos)
double MyVector3::AngleBetween(MyVector3 &vIn) const
{
	MyVector3 v(m_x, m_y, m_z);
	return (180 / std::acos(-1)) * (std::acos(v.DotProduct(vIn) / (v.Length() * vIn.Length())));
}

//Function That Returns A Unit Vector
MyVector3 MyVector3::Unit()
{
	MyVector3 tempVector(m_x, m_y, m_z);
	double length = tempVector.Length();
	return MyVector3(m_x / length, m_y / length, m_z / length);
}

//Function Calculates The Parallel Component Of A Vector (Parallel To Parameter)
MyVector3 MyVector3::ParallelComponent(MyVector3 &vIn)
{
	MyVector3 v1(vIn);
	MyVector3 v2(m_x, m_y, m_z);
	double lengthSqrd = v1.LengthSquared();
	double dotProduct = v1.DotProduct(v2);
	double multiplier = dotProduct / lengthSqrd;
	return MyVector3(m_x * multiplier, m_y * multiplier, m_z * multiplier);
}

//Function Calculates The Perpendicular Component Of A Vector (Perpendicularl To Parameter)
MyVector3 MyVector3::PerpendicularComponent(MyVector3 &vIn)
{
	MyVector3 v1(vIn);
	MyVector3 v2(m_x, m_y, m_z);
	return (v2 - v1.ParallelComponent(v2));
}

//Returns A Scaled Vectoir (By Parameter)
MyVector3 MyVector3::Scale(float fIn)
{
	return MyVector3(m_x * fIn, m_y * fIn, m_z * fIn);
}

//Overloaded - Returns A Scaled Vectoir (By Parameter)
MyVector3 MyVector3::Scale(double dIn)
{
	return Scale((float)(dIn));
}
