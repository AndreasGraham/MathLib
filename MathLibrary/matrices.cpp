#include <cmath>
#include <cfloat>
#include "matrices.h"


mat3 operator*(const mat3 &a, const mat3 &b) {
	mat3 result;
	//3x3 * 3x3 for combine transformations

	result.c[0].x = (b.c[0].x*a.c[0].x) + (b.c[0].y*a.c[1].x) + (b.c[0].z*a.c[2].x);
	result.c[0].y = (b.c[0].x*a.c[0].y) + (b.c[0].y*a.c[1].y) + (b.c[0].z*a.c[2].y);
	result.c[0].z = (b.c[0].x*a.c[0].z) + (b.c[0].y*a.c[1].z) + (b.c[0].z*a.c[2].z);

	result.c[1].x = (b.c[1].x*a.c[0].x) + (b.c[1].y*a.c[1].x) + (b.c[1].z*a.c[2].x);
	result.c[1].y = (b.c[1].x*a.c[0].y) + (b.c[1].y*a.c[1].y) + (b.c[1].z*a.c[2].y);
	result.c[1].z = (b.c[1].x*a.c[0].z) + (b.c[1].y*a.c[1].z) + (b.c[1].z*a.c[2].z);

	result.c[2].x = (b.c[2].x*a.c[0].x) + (b.c[2].y*a.c[1].x) + (b.c[2].z*a.c[2].x);
	result.c[2].y = (b.c[2].x*a.c[0].y) + (b.c[2].y*a.c[1].y) + (b.c[2].z*a.c[2].y);
	result.c[2].z = (b.c[2].x*a.c[0].z) + (b.c[2].y*a.c[1].z) + (b.c[2].z*a.c[2].z);

	return result;
}

vec3 operator*(const mat3 &at, const vec3 &v) {
	// 3x3 * 3x1 to apply transformation
	vec3 result;

	mat3 a = transpose(at);

	result.x = (a.c[0].x*v.x) + (a.c[0].y*v.y) + (a.c[0].z*v.z);
	result.y = (a.c[1].x*v.x) + (a.c[1].y*v.y) + (a.c[1].z*v.z);
	result.z = (a.c[2].x*v.x) + (a.c[2].y*v.y) + (a.c[2].z*v.z);
	
	return result;
}

mat3 operator+(const mat3 &a, const mat3 &b){
	mat3 retval;

	for (int i = 0; i < 9; i++)
		retval.m[i] = a.m[i] + b.m[i];

	return retval;



}

mat3 operator-(const mat3 &a, const mat3 &b) {
	mat3 retval;

	for (int i = 0; i < 9; i++)
		retval.m[i] = a.m[i] - b.m[i];

	return retval;
}

bool operator==(const mat3 &a, const mat3 &b) {
	return (a[0] == b[0] &&
		   a[1] == b[1] &&
		   a[2] == b[2]);
}

mat3 transpose(const mat3 &a) {
	/*mat3 retval;
	for (int x = 0; x < 3; ++x)
		for (int y = 0; y < 3; ++y)
			retval[x][y] = a[y][x];

	return retval;*/

	return mat3{ a[0][0], a[1][0], a[2][0],
				a[0][1], a[1][1], a[2][1],
				a[0][2], a[1][2], a[2][2] };

	}
float determinant(const mat3 &a) {
	return dot(a[0], cross(a[1], a[2]));
}

mat3 inverse(const mat3 &a) {
	float di = 1 / determinant(a);
	
	return transpose(mat3{
		cross(a[1], a[2]) * di,
		cross(a[2], a[0]) * di,
		cross(a[0], a[1]) * di });
}

mat3 translate(const vec2 &t) {
	/*mat3 retval = mat3::identity();
	retval[2].xy = t;
	return retval;*/
	return mat3{ 1, 0, 0,
				 0, 1, 0,
				 t.x, t.y, 1 };

}

mat3 scale(const vec2 &s) {
	return mat3{ s.x, 0, 0,
				0, s.y, 0,
				0, 0, 1 };
}

mat3 rotate(float deg) {
	float radicalGnar = deg * (3.14159265359f / 180);

	return mat3 { cos(radicalGnar), sin(radicalGnar), 0, // x- axis
				-sin(radicalGnar),  cos(radicalGnar),   0, // y-axis
					           0,		          0,   1};
}