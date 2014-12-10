#include <math.h>
#include <cstdlib>
#include <iostream>
using namespace std;

#ifndef _MATH_LIBRARY_H_
#define _MATH_LIBRARY_H_

const int XSIZE = 3;
const int YSIZE = 3;
const int SIZE = 4;

class Vector2D
{
public:
	Vector2D();
	Vector2D(float a_x, float a_y);
	~Vector2D();

	//OVERLOAD OPERATORS 
	friend ostream& operator<<(ostream& os, const Vector2D& v);

	Vector2D operator+(Vector2D &other);
	Vector2D operator-(Vector2D &other);

	void operator+=(Vector2D &other);
	void operator-=(Vector2D &other);
	void operator=(Vector2D &other);
	bool operator==(Vector2D &other);

	//Maths
	void Scale(float num);	//changes vector values

	// returns perp vector
	Vector2D Perp(Vector2D v);

	// parameters: vector end point, percent to interpolate by 
	Vector2D Interpolate(Vector2D v, float perc);

	float x, y;
};

class Vector3D
{
public:
	Vector3D();
	Vector3D(float a_x, float a_y, float a_z);
	~Vector3D();

	//OVERLOAD OPERATORS
	friend ostream& operator<<(ostream& os, const Vector3D& v);

	Vector3D operator+(Vector3D &other);
	Vector3D operator-(Vector3D &other);

	void operator+=(Vector3D &other);
	void operator-=(Vector3D &other);
	void operator=(Vector3D &other);
	bool operator==(Vector3D &other);

	//Maths
	void Scale(float num);	//changes vector values

	void SetValues(float x, float y, float z);
	/*used to put matrix points into vector*/

	// parameters: vector end point, percent to interpolate by 
	Vector3D Interpolate(Vector3D v, float perc);

	float x, y, z;
};

class Vector4D
{
public:
	Vector4D();
	friend ostream& operator<<(ostream& os, const Vector4D& v);
	void operator=(Vector4D &other);
	void operator+=(Vector4D &other);

	Vector4D(float a_x, float a_y, float a_z, float a_w);
	Vector4D(char a_x[], char a_y[], char a_z[], char a_w[]);

	void SetValues(float x, float y, float z, float w);
	/*used to put matrix points into vector*/

	~Vector4D();
	float x, y, z, w;
};

class Matrix2D
{
public:
	float Matrix[XSIZE][YSIZE];

	Matrix2D();
	Matrix2D(float array[XSIZE][YSIZE]);

	//void Scale(float x, float y);

	//inverts matrix
	void Transpose();
	
	void Translate(float a_x, float a_y);
	/*parameters: (shift x value by float a_x, shift y value by float b_x)*/

	void Rotate(float angle);
	/*parameters: (angle in degrees)*/

	void Scale(float a_x, float a_y);
	/*parameters: (scale x value by float a_x, scale y value by float b_x)*/

	//prints column major (looks like a math matrix) 
	void Print();

	~Matrix2D();	
};

class Matrix3D
{
public:
	Matrix3D();
	Matrix3D(float array[SIZE][SIZE]);

	float Matrix[SIZE][SIZE];

	void Translate(float a_x, float a_y, float a_z);
	/*parameters: (shift x value by float a_x, shift y value by float b_x)*/

	void Rotate(float angle);
	/*parameters: (rotate by float angle)*/

	void Scale(float a_x, float a_y, float a_z);
	/*parameters: (scale x value by float a_x, scale y value by float b_x)*/

	void Print();

	~Matrix3D();
};

//*********FUNCTIONS*************

//conversion
float DegreesToRadians(float degrees);
float RadiansToAgrees(float radians);

// aka gets hypotonuese
float Magnitude(Vector2D v);
float Magnitude(Vector3D v);
float Magnitude(Vector4D v);

// returns scalar of vector b projected onto vector a
float DotProduct(Vector2D a, Vector2D b);
//float DotProduct(float[], float[]);
float DotProduct(Vector3D a, Vector3D b);
float DotProduct(Vector4D a, Vector4D b);

// normalize vector (get hypotnuse to 1)
Vector2D Normalize(Vector2D v);
Vector3D Normalize(Vector3D v);
Vector4D Normalize(Vector4D v);

float CrossProduct(Vector2D a, Vector2D b);
// get perp
Vector3D CrossProduct(Vector3D v1, Vector3D v2);

float GetAngle(Vector2D a, Vector2D b);

Vector3D Multiply(Matrix2D m, Vector3D v);
Vector4D Multiply(Matrix3D m, Vector4D v);
Matrix2D Multiply(Matrix2D m1, Matrix2D m2);

void SetOMat(float l, float r, float t, float b, float n, float f, Matrix3D mat);

Vector2D Interpolate(Vector2D v1, Vector2D v2, float perc);
Vector3D Interpolate(Vector3D v1, Vector3D v2, float perc);
/*takes in 2 vectors and percent to interpolate it by. returns temp interpolated vector*/
float Interpolate(float a, float b, float perc);
/*interpolates between 2 floats by percent*/

int FindPowerof2(int num);
//finds power of two or nearest

#endif