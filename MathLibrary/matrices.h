#pragma once
#include "vec3.h"

union mat3 {
	float m[9];
	float mm[3][3];
	vec3 c[3];
};

mat3 operator+(const mat3 &a, const mat3 &b); // not really used
mat3 operator-(const mat3 &a, const mat3 &b); //not really used

mat3 operator*(const mat3 &a, const mat3 &b); // combine transformations
mat3 operator*(const mat3 &a, const vec3 &v); // apply a transformation

mat3 transpose(const mat3 &a); //flip the rows and the columns

//unknowns!

float determinant(const mat3 &a);
mat3 inverse(const mat3 &a);