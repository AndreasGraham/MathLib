#pragma once
#include "Vec2.h"
#include "matrices.h"


struct circle {
	float radius;
	vec2 position;
};

// asix aligned abouding box
struct AABB {
	vec2 position;
	vec2 extents;// extent of something, how far reaching something is
	// define a box using a position width and height
	vec2 min() const { return position - extents; }
	vec2 max() const { return position + extents; }
};

circle operator*(const mat3 &M, const circle &C); // allows it to follow a position perfectly, wether its a player or offset from a player
AABB operator*(const mat3 &M, const AABB &B);
 