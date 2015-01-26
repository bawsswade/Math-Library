#include "Library.h"
#include <iostream>


using namespace std;

int main()
{
	Vector2D v1(1,1);
	Vector2D v2(2,2);
	Vector3D v3(1,1,1);
	Vector3D v4(2,2,2);
	Vector4D vector(2,5,1,1);
	Vector4D hex(0xffffffff);

	float ID1[3][3] = 
	{
		{1,0,0},
		{0,1,0},
		{0,0,1}
	};
	
	float ID2[4][4] =
	{
		{1,0,0,0},
		{0,1,0,0},
		{0,0,1,0},
		{0,0,0,1}
	};

	float m1[3][3] =
	{
		{ 1, 2, 3 },
		{ 3, 2, 1 },
		{ 2, 1, 3 }
	};

	float m2[3][3] =
	{
		{ 4, 5, 6 },
		{ 6, 5, 4 },
		{ 4, 6, 5 }
	};

	float m3[4][4] =
	{
		{ 1, 2, 3, 4 },
		{ 5, 6, 7, 8 },
		{ 9, 10, 11, 12 },
		{ 13, 14, 15, 16}
	};

	float m4[4][4] =
	{
		{ 4, 3, 2, 1 },
		{ 8, 7, 6, 5 },
		{ 12, 11, 10, 9 },
		{ 16, 15, 14, 13  }
	};
	
	cout << "Testing Dot product..." << endl;
	cout << "v1 . v2 : " << DotProduct(v1, v2) << endl;
	cout << "v3 . v4 : " << DotProduct(v3, v4) << endl << endl;

	cout << "Testing Cross Product..." << endl;
	cout << "v1 x v2 : " << CrossProduct(v1, v2) << endl;
	cout << "v3 x v4 : " << CrossProduct(v3, v4) << endl << endl;

	cout << "Testing Magnititude..." << endl;
	cout << "mag of v1 : " << Magnitude(v1) << endl;
	cout << "mag of v3 : " << Magnitude(v3) << endl << endl;

	cout << "testing overloading operators..." << endl;
	cout << "v1 + v2 = ";
	cout << v1 + v2;

	cout << "v2 - v1 = ";
	cout << v2 - v1;

	v2 += v1;
	cout << v2;

	v2 -= v1;
	cout << v2;

	cout << "v2 = v1: ";
	v2 = v1;
	cout << v2;

	cout << "scale v1 by 2: ";
	v1.Scale(2);
	cout << v1 << endl;

	cout << "Testing linear interpolation..." << endl;
	cout << "interp v1 and v2 by 25% : " << Interpolate(v1, v2, .25);
	cout << "interp v3 and v4 by 25% : " << Interpolate(v3, v4, .25) << endl << endl;

	cout << "Testing Orthographic Projection Creation..." << endl;
	Matrix3D mat(m3);
	SetOMat(0,1,2, 0, 1,2, mat);

	cout << "Testing Matrix Scale..." << endl;
	Matrix2D mat3(m1);
	mat3.Scale(2,2);
	mat3.Print();

	Matrix3D mat4(m3);
	mat4.Scale(2, 2, 2);
	mat4.Print();
	cout << endl;

	cout << "Testing Matrix Transform..." << endl;
	mat3.Translate(1, 1);
	mat3.Print();

	mat4.Translate(1, 1, 1);
	mat4.Print();

	cout << "Testing Matrix Rotation..." << endl;
	mat3.Rotate(90);
	mat3.Print();

	mat4.Rotate(90);
	mat4.Print();
	cout << endl;

	cout << "Testing Matrix Multiplication..." << endl;
	Matrix2D mat1(m1);
	cout << Multiply(mat1, v3);
	cout << endl;

	cout << "Testing Vector 4 Normalization..." << endl;
	Normalize(vector);

	Vector4D color(hex);
	cout << hex << endl;

	cout << "Testing Interpolation for scalars..." << endl;
	cout << Interpolate(1, 10, .5) << endl;

	cout << "Testing conversion between radians and degrees..." << endl;
	cout << DegreesToRadians(180) << endl;
	cout << RadiansToAgrees(3.15) << endl << endl;

	cout << "Testing finding power of 2..." << endl;
	cout << "power for 20 is " << FindPowerof2(20) << endl << endl;
	
	system("pause");
	return 0;
}