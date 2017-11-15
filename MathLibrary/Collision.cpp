#include "Collision.h"
#include <cmath>

Collision intersect_ID(float Amin, float Amax, float Bmin, float Bmax) {
	Collision ret;
	float lPD = Bmax - Amin;
	float rPD = Amax - Bmin;

	ret.penetrationDepth = fminf(lPD, rPD);
	ret.handedness = copysign(1, rPD - lPD);

	return ret;
}

Collision intersect_AABB(const AABB &A, const AABB &B) {
	Collision xres = intersect_ID(A.min().x, A.max().x, B.min().x, B.max().x);
	Collision yres = intersect_ID(A.min().y, A.max().y, B.min().y, B.max().y);

	xres.axis = vec2{ 1,0 };
	yres.axis = vec2{ 0,1 };
	return xres.penetrationDepth < yres.penetrationDepth ? xres : yres;
	//if x PD is less than YP return xres, else return yres
}

Collision intersect_circle(const circle & A, const circle & B) {
	Collision ret;
	ret.axis = normalize(B.position - A.position);
	ret.handedness = -1;
	float Ap = Dot(ret.axis, A.position);
	float Bp = Dot(ret.axis, B.position);

	float Amin = Ap - A.radius;
	float Amax = Ap + A.radius;

	float Bmin = Bp - B.radius;
	float Bmax = Bp + B.radius;
	// how do we calculate penetration depth - need min and max of circles (pretend they are on a 1 dimension line)
	ret.penetrationDepth = intersect_ID(Amin, Amax, Bmin, Bmax).penetrationDepth;

	return ret;
}


//static resoltuon

//Dynamic Resolution