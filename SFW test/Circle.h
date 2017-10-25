#pragma once
#include "Shapes.h"

class Circle : public Heroes {
public:
	Circle();
	Circle(vec2 pos, vec2 scale, float angle);
	void draw() override;
	void update() override;

};