#pragma once
#include "Vec2.h"
union vec3 {

	float v[3];
	struct { float x, y, z; };
	vec2 xy;

	float operator[](unsigned idx)const;
	float &operator[](unsigned idx);

	void NormalizeMyThing();
};
						//{1,2,4} + {3,2,1}
vec3 operator+(const vec3 &lhs, const vec3 &rhs);

bool operator==(const vec3 &lhs, const vec3 &rhs);
vec3 operator-(const vec3 &lhs, const vec3 &rhs);
vec3 operator*(const vec3 &lhs, const float rhs);
vec3 operator*(const float lhs, const vec3 &rhs);
bool operator!=(const vec3 &lhs, const vec3 &rhs);

vec3 &operator+=(vec3 &lhs, vec3 &rhs);
vec3 &operator-=( vec3 &lhs, const vec3 &rhs);
vec3 &operator*=( vec3 &lhs, const float rhs);
vec3 &operator /=(vec3 &lhs, const float rhs);

vec3 normalize(vec3 a);
void normalizeReference(vec3 &a);
float magnitude(vec3 a);
float Dot(vec3 a, vec3 b);
float Distance(vec3 a, vec3 b);
vec3 Lerp(vec3 a, vec3 b, float c);
vec3 min(vec3 a, vec3 b);
vec3 max(vec3 a, vec3 b);
vec3 cross(const vec3 &a, const vec3 &b);
float dot(vec3 lhs, vec3 rhs);