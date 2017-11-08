#pragma once
#include "Vec2.h"
#include "transform.h"
#include "sfwdraw.h"
#include <iostream>

class Sprite {
public:
	int handle;
	vec2 dim; // dimensions
	vec2 offset;

	//this is which sprite we draw
	int animIDX;
	int animMinRange;
	int animMaxRange;
	float animTimer;
	float startTimer;
	int animations[12];
	int animationsIndexCap;
	Sprite();
	Sprite(int a_handle, float width, float height) : handle(a_handle),
												dim{ width, height },
												offset{ 0,0 }
	{
		animIDX = 0;
		animMinRange = 0;
		animMaxRange = 4;
		animTimer = .2f;
		startTimer = .2f;
	}

	void draw(const Transform &t,float dt, const mat3 &cam = mat3::identity()) {
		UpdateAnim(dt);
		mat3 L = cam;
		mat3 C = L * t.getGlobalTransform();
		mat3 G = C * scale(dim);
		mat3 F =  G * translate(offset);
		mat3 M = cam *t.getGlobalTransform() * translate(offset) * scale(dim);
	//	M = scale({ 400,300 }) * scale({ 20,20 });
		sfw::drawTextureMatrix3(handle, animIDX, WHITE, M.m);
		//sfw::drawTextureMatrix(handle, 0, WHITE, M.m);
	}

	void UpdateAnim(float dt)
	{
		animTimer -= dt;
		if (animTimer < 0)
		{
			animIDX++;
			animTimer = startTimer;
		}
		if (animIDX > animMaxRange)
		{
			animIDX = animMinRange;
		}


	}
	void animeCycle(int a[], const Transform &t, int arsize, float dt, int &i, const mat3 &cam = mat3::identity()) {		
		animTimer -= dt;
		if (animTimer < 0)
		{
			i++;
			animTimer = startTimer;
		}
		if (i == arsize) {
			i = 0;
		}
		mat3 M = cam *t.getGlobalTransform() * translate(offset) * scale(dim);
		sfw::drawTextureMatrix3(handle, a[i], WHITE, M.m);
		std::cout << a[i] << std::endl;
		
	}
		
};