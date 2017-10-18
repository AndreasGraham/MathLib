#pragma once

#include "matrices.h"
class Transform {
public:
	vec2 position;
	vec2 dimension;
	float angle;

	Transform();
	mat3 getLocalTransofrm() const;
};

void DrawMatrix(const mat3 &t, float drawing_scale);