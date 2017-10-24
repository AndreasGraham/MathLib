#pragma once
#include "Vec2.h"

class Bullet {
public:
	vec2 pos;
	vec2 end;
	vec2 Dir;
	float speed;
	bool enabled = true;
	float lifetime;
	void update();
	void draw();
};