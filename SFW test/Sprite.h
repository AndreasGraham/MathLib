#pragma once
#include "Vec2.h"
#include "transform.h"
#include "sfwdraw.h"

class Sprite {
public:
	int handle;
	vec2 dim; // dimensions
	vec2 offset;

	Sprite(int a_handle, int width, int height) : handle(a_handle),
												dim{ width, height },
												offset{ 0,0 }
	{

	}

	void draw(const Transform &t, const mat3 &cam = mat3::identity()) {
		mat3 M = cam *t.getGlobalTransform() * translate(offset) * scale(dim);
	//	M = scale({ 400,300 }) * scale({ 20,20 });
		sfw::drawTextureMatrix(handle, 0, WHITE, M.m);
	}
};