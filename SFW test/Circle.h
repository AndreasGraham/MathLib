#pragma once
#include "Shapes.h"

class Circle : public Heroes {
public:
	float health = 50.0f;
	char up;
	char down;
	char left;
	char right;
	int color;
	Circle();
	Circle(vec2 pos, vec2 scale, float angle, int c, char upk, char downk, char leftk, char rightk);
	void draw() override;
	void update() override;

};