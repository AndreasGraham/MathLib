#pragma once
#include "Shapes.h"

class Square : public Heroes {
public:
	Square();
	Square(vec2 pos, vec2 scale, float angle);
	void drawSquare(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy);
	void draw() override;
	void update() override;
	void ability1() override;
	void ability2() override;
	void ability3() override;
	void drawSquareNew(int base, int height);
};