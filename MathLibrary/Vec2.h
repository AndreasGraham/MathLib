#pragma once
#define EPSILON 0.00001
// functions with a special name
union vec2 {
	//access by array
	float v[2];

	float operator[](unsigned idx)const; //here constant means the return value has not been changed
	float &operator[](unsigned idx); //allows us to access a vec2 array using a vec2 reference instead of the constant
	
	void NormalizeMyThing();
	//access by individual component
	struct { float x, y; };

	//overlapping space in memory that we can acess two different ways
	// accessing one gets you ino from the other
	//need need a function for get x or get y, we can just access that data and fuck with it
};

vec2 operator-(const vec2 &v);
vec2 operator/(const vec2 &lhs, float rhs);

vec2 operator+(const vec2 &lhs,const vec2 &rhs);
vec2 &operator+=(vec2 &lhs, const vec2 &rhs);
bool operator==(const vec2 &lhs, const vec2 &rhs);
vec2 operator-(const vec2 &lhs, const vec2 &rhs);
vec2 operator*( float a, const vec2 &rhs);
vec2 operator*(const vec2 &lhs,  float a);
vec2 operator/(const vec2 &lhs, const vec2 &rhs);
//vec2 operator-(const vec2 &lhs, const vec2 &rhs);
bool operator!=(const vec2 &lhs, const vec2 &rhs);
vec2 &operator-=(vec2 &lhs, const vec2 &rhs);
vec2 operator*=(const vec2 &lhs, const vec2 &rhs);
vec2 operator/=(const vec2 &lhs, const vec2 &rhs);

vec2 normalize(vec2 a);
void normalizeReference(vec2 &a);
float magnitude(vec2 a);
float Dot(vec2 a, vec2 b);
float Distance(vec2 a, vec2 b);
vec2 Perpendicular(vec2 a);
vec2 Lerp(vec2 a, vec2 b, float c);
vec2 min(vec2 a, vec2 b);
vec2 max(vec2 a, vec2 b);