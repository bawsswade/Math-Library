#include <math.h>
#include <iostream>
using namespace std;

#ifndef _MATH_LIBRARY_H_
#define _MATH_LIBRARY_H_

const int XSIZE = 3;
const int YSIZE = 3;
const int ZSIZE = 3;

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

	float x, y;
	// returns perp vector
	Vector2D Perp(Vector2D v);
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

	float x, y, z;
};

class Matrix2D
{
public:
	float Matrix[XSIZE][YSIZE];

	Matrix2D();

	//converts from column major to row major (math to memory way)
	Matrix2D(float array[XSIZE][YSIZE]);

	void Scale(float x, float y);

	//inverts matrix
	void Transpose();

	Vector3D Translate(Vector3D v);

	//prints column major (looks like a math matrix) 
	void Print();

	~Matrix2D();

	
};

//*********FUNCTIONS*************

// aka gets hypotonuese
float Magnitude(Vector2D v);
float Magnitude(Vector3D v);

// return scalar of vector b projected onto vector a
float DotProduct(Vector2D a, Vector2D b);
float DotProduct(Vector3D a, Vector3D b);

// normalize vector (get hypotnuse to 1)
Vector2D Normalize(Vector2D v);
Vector3D Normalize(Vector3D v);

float CrossProduct(Vector2D a, Vector2D b);
// get perp
Vector3D CrossProduct(Vector3D v1, Vector3D v2);

float GetAngle(Vector2D a, Vector2D b);

#endif