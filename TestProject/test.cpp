#include "Library.h"
#include <iostream>

using namespace std;

int main()
{
	Vector2D v1(1,2);
	Vector2D v2(4,5);
	Vector3D vector(2,5,0);

	float mat[3][3] = 
	{
		{1,0,0},
		{0,1,0},
		{2,1,1}
	};

	Matrix2D matrix(mat);
	vector = matrix.Translate(vector);

	cout << vector;

	//Matrix2D m = mat;
	//m.Print(); 
	//cout << endl;

	//m.Scale(1, 2);
	//m.Transpose();
	//m.Print();

	//cout << CrossProduct(v1, v2);

	//Vector3D v3 = v1 + v2;
	//v3.Scale(2);
	//Vector3D v4 = v3;
	//cout << v3;
	//cout << v4;

	//cout << Magnitude(Vector3D(3,2, 1));

	//cout << Normalize(Vector3D(10, 14, 18));

	system("pause");
	return 0;
}