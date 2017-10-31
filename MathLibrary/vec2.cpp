#include "Vec2.h"
#include <cmath>
#include <cfloat>

vec2 operator-(const vec2 & v)
{
	v * -1;
}

vec2 operator/(const vec2 & lhs, float rhs)
{
	lhs * (1 / rhs);
}

vec2 operator+(const vec2 &lhs, const vec2 &rhs) {
	vec2 result;
	result.x = lhs.x + rhs.x;
	result.y = lhs.y + rhs.y;

	return result;
}

vec2 &operator+=(vec2 &lhs, const vec2 &rhs) {
	lhs = lhs + rhs;
	return lhs;
}

bool operator==(const vec2 &lhs, const vec2 &rhs) {
	if (abs(lhs.x - rhs.x) < EPSILON &&
		abs(lhs.y - rhs.y < EPSILON))
	{
		return true;
	}

	return false;
}

vec2 operator-(const vec2 &lhs, const vec2 &rhs) {
	vec2 result;
	result.x = lhs.x - rhs.x;
	result.y = lhs.y - rhs.y;
	return result;
}

vec2 operator*( float a, const vec2 &rhs) {
	vec2 result;
	result.x = a * rhs.x;
	result.y = a * rhs.y;

	return result;
}

vec2 operator*(const vec2 &lhs, float a){
	return{ lhs.x*a, lhs.y*a };
}

vec2 operator/(const vec2 &lhs, const vec2 &rhs) {
	vec2 result;
	result.x = lhs.x / rhs.x;
	result.y = lhs.y / rhs.x;
	return result;
}



bool operator!=(const vec2 &lhs, const vec2 &rhs) {
	if (lhs.x != rhs.x || lhs.y != rhs.y) {
		return true;
	}
	return false;
}

vec2 &operator-=(vec2 &lhs, const vec2 &rhs) {
	lhs = lhs - rhs;
	return lhs;
}

vec2 operator*=(const vec2 &lhs, const vec2 &rhs) {
	vec2 result;
	result.x = lhs.x * rhs.x;
	result.y = lhs.y * rhs.x;

	return result;
}

vec2 operator /=(const vec2 &lhs, const vec2 &rhs) {
	vec2 result;
	result.x = lhs.x / rhs.x;
	result.y = lhs.y / rhs.x;

	return result;
}

vec2 normalize(vec2 a)
{
	vec2 result = a;
	float f = magnitude(a); //gives us magnitude
	result.x = result.x / f;
	result.y = result.y / f;
	
	return result;
}


void normalizeReference(vec2 &a)
{
	float f = magnitude(a);
		a.x = a.x / f;
		a.y = a.y / f;
}

float magnitude(vec2 a)
{
		// solve for c in pythagorian theorem
		float one = powf(a.x, 2.0f) + powf(a.y, 2.0f); // a^2 + b^2
		return sqrtf(one); // return c
}



float vec2::operator[](unsigned idx) const
{
	return v[idx];
}

float & vec2::operator[](unsigned idx)
{
	return v[idx];
}


void vec2::NormalizeMyThing()
{
	vec2 dummy;
	dummy.x = x;
	dummy.y = y;
	float f = magnitude(dummy);
	x = x / f;
	y = y / f;

	
}

float Dot(vec2 a, vec2 b) {
	float c = a.x*b.x + a.y*b.y;
	return c;
}

float Distance(vec2 a, vec2 b) {
	float X = b.x - a.x;
	float Y = b.y - a.y;
	float Z1 = powf(X, 2.0f);
	float Z2 = powf(Y, 2.0f);
	float Z3 = Z1 + Z2;

	return sqrtf(Z3);
}

vec2 Perpendicular(vec2 a) {
	vec2 result;
	result.x = -a.y;
	result.y = a.x;
	return result;
}

vec2 Lerp(vec2 start, vec2 end, float ratio) {
	vec2 result;
	//ratio is the percentage of distance traveled between start and end
	float xDist = end.x - start.x;
	float yDist = end.y - start.y;

	result.x = xDist * ratio;
	result.y = yDist * ratio;

	return result;
}

vec2 min(vec2 a, vec2 b) {
	vec2 result;

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
	return result;
}

vec2 max(vec2 a, vec2 b) {
	vec2 result;

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
	return result;
}


