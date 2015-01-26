#include "gtest\gtest.h"
#include "Library.h"
#include <math.h>

TEST(testingMaths, MagnitudeOfV2){
	Vector2D v(1, 1);
	EXPECT_FLOAT_EQ(1.4142135, Magnitude(v));
}

TEST(testingMaths, MagnitudeOfV3){
	Vector3D v(1, 1, 1);
	EXPECT_FLOAT_EQ(1.7320508, Magnitude(v));
}

TEST(testingMaths, MagnitudeOfV4){
	Vector4D v(1, 1, 1, 1);
	EXPECT_FLOAT_EQ(2, Magnitude(v));
}

TEST(testingMaths, DotProductVector2D){
	Vector2D v1(1, 2);
	Vector2D v2(3, 4);
	EXPECT_FLOAT_EQ(11, DotProduct(v1, v2));
}

TEST(testingMaths, DotProductVector3D){
	Vector3D v1(1, 2, 3);
	Vector3D v2(3, 4, 5);
	EXPECT_FLOAT_EQ(26, DotProduct(v1,v2));
}

TEST(testingMaths, DotProductVector4D){
	Vector4D v1(1, 2, 3, 4);
	Vector4D v2(3, 4, 5, 6);
	EXPECT_FLOAT_EQ(50, DotProduct(v1, v2));
}

/*TEST(testingMaths, Interpolate2D){
	Vector2D v1(1, 1);
	Vector2D v2(3,3);
	Vector2D midpoint(2,2);
	EXPECT_EQ(midpoint, Interpolate(v1, v2, .5));
}*/

TEST(testingMaths, InterpolateLinear){
	EXPECT_FLOAT_EQ(5, Interpolate(4, 6, .5));
}

TEST(testingMaths, DegreesToRadians){
	EXPECT_FLOAT_EQ(3.1415927, DegreesToRadians(180));
}

TEST(testingMaths, RadiansToDegrees){
	EXPECT_FLOAT_EQ(180, RadiansToAgrees(3.1415927));
}

TEST(testingMaths, findPower2){
	EXPECT_EQ(4, FindPowerof2(20));
}

