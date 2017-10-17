#include <cmath>
#include <cfloat>
#include "matrices.h"

mat3 operator*(const mat3 &a, const mat3 &b) {
	mat3 result;
	//3x3 * 3x3 for combine transformations

	result.c[0].x = (a.c[0].x*b.c[0].x) + (a.c[0].y*b.c[1].x) + (a.c[0].z*b.c[2].x);
	result.c[0].y = (a.c[0].x*b.c[0].y) + (a.c[0].y*b.c[1].y) + (a.c[0].z*b.c[2].y);
	result.c[0].z = (a.c[0].x*b.c[0].z) + (a.c[0].y*b.c[1].z) + (a.c[0].z*b.c[2].z);

	result.c[1].x = (a.c[1].x*b.c[0].x) + (a.c[1].y*b.c[1].x) + (a.c[1].z*b.c[2].x);
	result.c[1].y = (a.c[1].x*b.c[0].y) + (a.c[1].y*b.c[1].y) + (a.c[1].z*b.c[2].y);
	result.c[1].z = (a.c[1].x*b.c[0].z) + (a.c[1].y*b.c[1].z) + (a.c[1].z*b.c[2].z);

	result.c[2].x = (a.c[2].x*b.c[0].x) + (a.c[2].y*b.c[1].x) + (a.c[2].z*b.c[2].x);
	result.c[2].y = (a.c[2].x*b.c[0].y) + (a.c[2].y*b.c[1].y) + (a.c[2].z*b.c[2].y);
	result.c[2].z = (a.c[2].x*b.c[0].z) + (a.c[2].y*b.c[1].z) + (a.c[2].z*b.c[2].z);

	return result;
}

mat3 operator*(const mat3 &a, const vec3 &v) {
	// 3x3 * 3x1 to apply transformation
	vec3 result;

	result.x = (a.c[0].x*v.x) + (a.c[0].y*v.y) + (a.c[0].z*v.z);
	result.y = ;
	result.z ;

}