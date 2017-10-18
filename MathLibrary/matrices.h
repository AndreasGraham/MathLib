#pragma once
#include "vec3.h"
#include "vec2.h"
#define PI = 3.14159265359

union mat3 {
	vec3 c[3];
	float m[9];
	float mm[3][3];
	

	vec3 &operator[](size_t idx) { return c[idx]; };
	vec3 operator[](size_t idx) const { return c[idx]; };

	static mat3 identity() {
		return mat3{1,0,0,
					0,1,0,
					0,0,1};
	}

	static mat3 zero() {
		return mat3{0,0,0,
					0,0,0,
					0,0,0};
	}
};

mat3 operator+(const mat3 &a, const mat3 &b); // not really used
mat3 operator-(const mat3 &a, const mat3 &b); //not really used

bool operator==(const mat3 &a, const mat3 &b);

mat3 operator*(const mat3 &a, const mat3 &b); // combine transformations
vec3 operator*(const mat3 &a, const vec3 &v); // apply a transformation


mat3 transpose(const mat3 &a); //flip the rows and the columns

//unknowns!

float determinant(const mat3 &a);
mat3 inverse(const mat3 &a);

mat3 translate(const vec2 &t);
//translation:
//[1 0 x]
//[0 1 y]
//[0 0 1]



mat3 scale(const vec2 &s);
/* scale
[x 0 0]
[0 y 0]
[0 0 1]

*/
mat3 rotate(float deg);
/*rotation:
a[0] is the x - axis
a[1] is the y- axis

[cos(a) -sin(a) 0]
[sin(a)  cos(a) 0]
[    0       0   0]

*/