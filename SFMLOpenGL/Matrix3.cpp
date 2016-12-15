#include "Matrix3.h"

//Default Constructor
Matrix3::Matrix3()
{
	m_11 = 0;
	m_12 = 0;
	m_13 = 0;
	m_21 = 0;
	m_22 = 0;
	m_23 = 0;
	m_31 = 0;
	m_32 = 0;
	m_33 = 0;
}

//Constructor Takes In Three Vectors As Parameters
Matrix3::Matrix3(MyVector3 vOne, MyVector3 vTwo, MyVector3 vThree)
{
	m_11 = vOne.GetX();
	m_12 = vOne.GetY();
	m_13 = vOne.GetZ();
	m_21 = vTwo.GetX();
	m_22 = vTwo.GetY();
	m_23 = vTwo.GetZ();
	m_31 = vThree.GetX();
	m_32 = vThree.GetY();
	m_33 = vThree.GetZ();
}

//Constructoir Function Takes In Nine Floats As Arguments
Matrix3::Matrix3(float a11, float a12, float a13, float a21, float a22, float a23, float a31, float a32, float a33)
{
	m_11 = a11;
	m_12 = a12;
	m_13 = a13;
	m_21 = a21;
	m_22 = a22;
	m_23 = a23;
	m_31 = a31;
	m_32 = a32;
	m_33 = a33;
}

//Getter Functions
float Matrix3::GetM11() const
{
	return m_11;
}
float Matrix3::GetM12() const
{
	return m_12;
}
float Matrix3::GetM13() const
{
	return m_13;
}
float Matrix3::GetM21() const
{
	return m_21;
}
float Matrix3::GetM22() const
{
	return m_22;
}
float Matrix3::GetM23() const
{
	return m_23;
}
float Matrix3::GetM31() const
{
	return m_31;
}
float Matrix3::GetM32() const
{
	return m_32;
}
float Matrix3::GetM33() const
{
	return m_33;
}

//Row Getter Function
MyVector3 Matrix3::GetRow(int i) const
{
	switch (i)
	{
	case 0:
		return MyVector3(m_11, m_12, m_13);
		break;
	case 1:
		return MyVector3(m_21, m_22, m_23);
		break;
	default:
		return MyVector3(m_31, m_32, m_33);
		break;
	}
}

//Row Getter Function
MyVector3 Matrix3::GetCol(int i) const
{
	switch (i)
	{
	case 0:
		return MyVector3(m_11, m_21, m_31);
		break;
	case 1:
		return MyVector3(m_12, m_22, m_32);
		break;
	default:
		return MyVector3(m_13, m_23, m_33);
		break;
	}
}

//'*' Operator Overload
MyVector3 Matrix3::operator*(MyVector3 &vIn) const
{
	float x = (m_11 * vIn.GetX()) + (m_12 * vIn.GetY()) + (m_13 * vIn.GetZ());
	float y = (m_21 * vIn.GetX()) + (m_22 * vIn.GetY()) + (m_23 * vIn.GetZ());
	float z = (m_31 * vIn.GetX()) + (m_32 * vIn.GetY()) + (m_33 * vIn.GetZ());
	return MyVector3(x, y, z);
}

//'+' Operator Overload
Matrix3 Matrix3::operator+(Matrix3 &mIn) const
{
	MyVector3 rowOne(m_11, m_21, m_31);
	MyVector3 rowTwo(m_11, m_21, m_31);
	MyVector3 rowThree(m_13, m_23, m_33);
	return Matrix3((mIn.GetRow(0) + rowOne), (mIn.GetRow(1) + rowTwo), (mIn.GetRow(2) + rowThree));
}

//'-' Operator Overload
Matrix3 Matrix3::operator-(Matrix3 &mIn) const
{
	MyVector3 rowOne(m_11, m_21, m_31);
	MyVector3 rowTwo(m_11, m_21, m_31);
	MyVector3 rowThree(m_13, m_23, m_33);
	return Matrix3((mIn.GetRow(0) - rowOne), (mIn.GetRow(1) - rowTwo), (mIn.GetRow(2) - rowThree));
}

//'*' Operator Overload
Matrix3 Matrix3::operator*(Matrix3 &mIn) const
{
	MyVector3 rowOne(m_11, m_21, m_31);
	MyVector3 rowTwo(m_11, m_21, m_31);
	MyVector3 rowThree(m_13, m_23, m_33);
	float l_11 = (float)(rowOne.DotProduct(mIn.GetRow(0)));
	float l_12 = (float)(rowOne.DotProduct(mIn.GetRow(1)));
	float l_13 = (float)(rowOne.DotProduct(mIn.GetRow(2)));
	float l_21 = (float)(rowTwo.DotProduct(mIn.GetRow(0)));
	float l_22 = (float)(rowTwo.DotProduct(mIn.GetRow(1)));
	float l_23 = (float)(rowTwo.DotProduct(mIn.GetRow(2)));
	float l_31 = (float)(rowThree.DotProduct(mIn.GetRow(0)));
	float l_32 = (float)(rowThree.DotProduct(mIn.GetRow(1)));
	float l_33 = (float)(rowThree.DotProduct(mIn.GetRow(2)));
	Matrix3 returnMatrix(l_11, l_12, l_13, l_21, l_22, l_23, l_31, l_32, l_33);
	return returnMatrix;
}

//'*' Operator Overload
Matrix3 Matrix3::operator*(float valIn) const
{
	MyVector3 rowOne(m_11, m_21, m_31);
	MyVector3 rowTwo(m_11, m_21, m_31);
	MyVector3 rowThree(m_13, m_23, m_33);
	return Matrix3(rowOne.Scale(valIn), rowTwo.Scale(valIn), rowThree.Scale(valIn));
}

//Function Calculates the Transpose of a matrix
Matrix3 Matrix3::Transpose()
{
	MyVector3 rowOne(m_11, m_21, m_31);
	MyVector3 rowTwo(m_11, m_21, m_31);
	MyVector3 rowThree(m_13, m_23, m_33);
	Matrix3 returnMatrix(rowOne, rowTwo, rowThree);
	returnMatrix = Matrix3(returnMatrix.GetCol(0), returnMatrix.GetCol(1), returnMatrix.GetCol(2));
	return returnMatrix;
}

//Function Calculates The Determinant Of A Matrix
float Matrix3::Determinant()
{
	float returnValue = (m_11 * ((m_22 * m_33) - (m_32 * m_23))) - (m_21 * ((m_33 * m_12) - (m_32 * m_13))) + (m_31 * ((m_23 * m_12) - (m_22 * m_13)));
	return returnValue;
}

//Function Calculates And Returns The Inverse Of A Matrix
Matrix3 Matrix3::Inverse()
{
	MyVector3 rowOne(m_11, m_21, m_31);
	MyVector3 rowTwo(m_11, m_21, m_31);
	MyVector3 rowThree(m_13, m_23, m_33);
	Matrix3 tempMatrix(rowOne, rowTwo, rowThree);
	float determinant = tempMatrix.Determinant();
	if (determinant == 0)
	{
		return Matrix3();
	}
	else
	{
		return (Matrix3(
			(m_33 * m_22) - (m_32 * m_23),
			(m_32 * m_13) - (m_33 * m_12),
			(m_23 * m_12) - (m_22 * m_13),
			(m_31 * m_23) - (m_33 * m_21),
			(m_33 * m_11) - (m_31 * m_13),
			(m_21 * m_13) - (m_23 * m_11),
			(m_32 * m_21) - (m_31 * m_22),
			(m_31 * m_12) - (m_32 * m_11),
			(m_22 * m_11) - (m_21 * m_12)
		) * (1.0 / determinant));
	}
}

//Function Rotates A Vector About The X Axis
MyVector3 Matrix3::RotateAboutX(MyVector3 vectorToRotate, float angle)
{
	double angleInRadians = (angle / 180.0) * acos(-1);
	Matrix3 rotationalMatrixX(
		1.f,
		0.f,
		0.f,
		0.f,
		(float)(cos(angleInRadians)),
		(float)(-sin(angleInRadians)),
		0.f,
		(float)(sin(angleInRadians)),
		(float)(cos(angleInRadians))
	);
	MyVector3 answer = rotationalMatrixX * vectorToRotate;
	return answer;
}

//Function Rotates A Vector About The Y Axis
MyVector3 Matrix3::RotateAboutY(MyVector3 vectorToRotate, float angle)
{
	double angleInRadians = (angle / 180.0) * acos(-1);
	Matrix3 rotationalMatrixY(
		(float)(cos(angleInRadians)),
		0.f,
		(float)(sin(angleInRadians)),
		0.f,
		1.f,
		0.f,
		(float)(-sin(angleInRadians)),
		0.f,
		(float)(cos(angleInRadians))
	);
	MyVector3 answer = rotationalMatrixY * vectorToRotate;
	return answer;
}

//Function Rotates A Vector About The Z Axis
MyVector3 Matrix3::RotateAboutZ(MyVector3 vectorToRotate, float angle)
{
	double angleInRadians = (angle / 180.0) * acos(-1);
	Matrix3 rotationalMatrixZ(
		(float)(cos(angleInRadians)),
		(float)(-sin(angleInRadians)),
		0.f,
		(float)(sin(angleInRadians)),
		(float)(cos(angleInRadians)),
		0.f,
		0.f,
		0.f,
		1.f
	);
	MyVector3 answer = rotationalMatrixZ * vectorToRotate;
	return answer;
}

//Function Translates a Vector using Matrices
void Matrix3::Translate(float xIn, float yIn, MyVector3  & vIn)
{
	float zVal = vIn.GetZ();
	Matrix3 translationMatrix(
		1, 0, xIn,
		0, 1, yIn,
		0, 0, 1
	);
	vIn = MyVector3(vIn.GetX(), vIn.GetY(), 1);
	vIn = translationMatrix * vIn;
	vIn = MyVector3(vIn.GetX(), vIn.GetY(), zVal);
}