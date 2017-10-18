#include "vec3.h"
#include <cmath>
#include <cfloat>

vec3 operator+(const vec3 &lhs, const vec3 &rhs) {
	vec3 result;
	result.x = lhs.x + rhs.x;
	result.y = lhs.y + rhs.y;
	result.z = lhs.z + rhs.z;

	return result;
}

vec3 &operator+=(vec3 &lhs, const vec3 &rhs) {
	lhs = lhs + rhs;
	return lhs;
}

bool operator==(const vec3 &lhs, const vec3 &rhs) {
	if (abs(lhs.x - rhs.x) < EPSILON &&
		abs(lhs.y - rhs.y) < EPSILON &&
		abs(lhs.z - rhs.z < EPSILON))
	{
		return true;
	}

	return false;
}

vec3 operator-(const vec3 & lhs, const vec3 & rhs)
{
	vec3 result;
	result.x = lhs.x - rhs.x;
	result.y = lhs.y - rhs.y;
	result.z = lhs.z - rhs.z;

	return result;
}

vec3 operator*(const vec3 &lhs, const float rhs) {
	vec3 result;
	result.x = lhs.x * rhs;
	result.y = lhs.y * rhs;
	result.z = lhs.z * rhs;

	return result;
}

vec3 operator*(const float lhs, const vec3 & rhs)
{
	vec3 result;
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;
	result.z = lhs * rhs.z;

	return result;
}

bool operator!=(const vec3 & lhs, const vec3 & rhs)
{
	if (abs(lhs.x - rhs.x) < FLT_EPSILON &&
		abs(lhs.y - rhs.y) < FLT_EPSILON &&
		abs(lhs.z - rhs.z < FLT_EPSILON))
	{
		return false;
	}

	return true;
}

vec3 operator/(const vec3 &lhs, const vec3 &rhs) {
	vec3 result;
	result.x = lhs.x / rhs.x;
	result.y = lhs.y / rhs.x;
	result.z = lhs.z / rhs.z;
	return result;
}

//bool operator!=(const vec3 &lhs, const vec3 &rhs) {
//	if (lhs.x != rhs.x || lhs.y != rhs.y || lhs.z != rhs.z) {
//		return true;
//	}
//	return false;
//}

vec3 &operator-=(vec3 &lhs, const vec3 &rhs) {
	lhs = lhs - rhs;
	return lhs;
}

vec3 &operator*=(vec3 &lhs, const float rhs) {
	//vec3 result;
	lhs.x = lhs.x * rhs;
	lhs.y = lhs.y * rhs;
	lhs.z = lhs.z * rhs;

	return lhs;
}

vec3 &operator /=( vec3 &lhs, const float rhs) {
	//vec3 result;
	lhs.x = lhs.x / rhs;
	lhs.y = lhs.y / rhs;
	lhs.z = lhs.z / rhs;

	return lhs;
}


float magnitude(vec3 a)
{
	// solve for c in pythagorian theorem
	float one = powf(a.x, 2.0f) + powf(a.y, 2.0f) + powf(a.z, 2.0f); //c^2 = a^2 + b^2 + d^2
	return sqrtf(one); // return c
}

vec3 normalize(vec3 a) {
	vec3 result = a;
	float f = magnitude(a); //gives us magnitude
	result.x = result.x / f;
	result.y = result.y / f;
	result.z = result.z / f;

	return result;
}

void normalizeReference(vec3 &a)
{
	float f = magnitude(a);
	a.x = a.x / f;
	a.y = a.y / f;
	a.z = a.z / f;
}

void vec3::NormalizeMyThing()
{
	vec3 dummy;
	dummy.x = x;
	dummy.y = y;
	dummy.z = z;
	float f = magnitude(dummy);
	x = x / f;
	y = y / f;
	z = z / f;


}

float vec3::operator[](unsigned idx) const
{
	return v[idx];
}

float & vec3::operator[](unsigned idx)
{
	return v[idx];
}

float Dot(vec3 a, vec3 b) {
	float c = a.x*b.x + a.y*b.y + a.z*b.z;
	return c;
}

float Distance(vec3 a, vec3 b) {
	float X = b.x - a.x;
	float Y = b.y - a.y;
	float Z = b.z - a.z;
	float Z1 = powf(X, 2.0f);
	float Z2 = powf(Y, 2.0f);
	float Z3 = powf(Z, 2.0f);
	float Z4 = Z1 + Z2 + Z3;

	return sqrtf(Z4);
}

vec3 Lerp(vec3 start, vec3 end, float ratio) {
	vec3 result;
	//ratio is the percentage of distance traveled between start and end
	float xDist = end.x - start.x;
	float yDist = end.y - start.y;
	float zDist = end.z - start.z;

	result.x = xDist * ratio;
	result.y = yDist * ratio;
	result.z = zDist * ratio;
	return result;
}

vec3 min(vec3 a, vec3 b) {
	vec3 result;

	if (a.x > b.x) {
		result.x = b.x;
	}
	else {
		result.x = a.x;
	}

	if (a.y > b.y) {
		result.y = b.y;
	}
	else {
		result.y = a.y;
	}

	if (a.z > b.z) {
		result.z = b.z;
	}
	else {
		result.z = a.z;
	}

	return result;
}

vec3 max(vec3 a, vec3 b) {
	vec3 result;

	if (a.x > b.x) {
		result.x = a.x;
	}
	else {
		result.x = b.x;
	}

	if (a.y > b.y) {
		result.y = a.y;
	}
	else {
		result.y = b.y;
	}

	if (a.z > b.z) {
		result.z = a.z;
	}
	else {
		result.z = b.z;
	}
	return result;
}

vec3 cross(const vec3 &a, const vec3 &b) {
	return vec3 {a.y*b.z - a.z*b.y,
		a.z*b.x - a.x*b.z,
		a.x*b.y - a.y*b.x};
}

float dot(vec3 lhs, vec3 rhs) {
	return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
}