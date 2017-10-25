#pragma once
#include "Shapes.h"
#include "bullet.h"

class Triangle : public Heroes {
public:
	int ammo = 25;
	Bullet magazine[25];
	int health = 50;

	char up;
	char down;
	char left;
	char right;
	char shoot;


	Triangle();
	Triangle(vec2 pos, vec2 scale, float angle,char upK,char downK,char leftK,char rightK,char shotK);
	void drawTriangle(float ax, float ay, float bx, float by, float cx, float cy);
	void draw() override;
	void update() override;
	void ability1() override;
	void ability2() override;
	void ability3() override;
};