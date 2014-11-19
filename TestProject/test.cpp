#include "Library.h"
#include <iostream>

using namespace std;

int main()
{

	Vector3D v1(1,2,3);
	Vector3D v2(4,5,6);

	Vector3D v3 = v1 + v2;
	v3.Scale(2);
	Vector3D v4 = v3;
	//cout << v3;
	//cout << v4;

	//cout << Magnitude(Vector3D(3,2, 1));

	cout << Normalize(Vector3D(10, 14, 18));

	system("pause");
	return 0;
}