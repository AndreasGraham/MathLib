#include "Circle.h"
#include "sfwdraw.h"
Circle::Circle(vec2 pos, vec2 scale, float angle, int c, char upk, char downk, char leftk, char rightk) {
	myT.position = pos;
	myT.dimension = scale;
	myT.angle = angle;
	color = c;
	up = upk;
	down = downk;
	left = leftk;
	right = rightk;
}
Circle::Circle() {

}
void Circle::draw() {
	if (health > 0) {
		if (color == 0) {
			sfw::drawCircle(myT.position.x, myT.position.y, 10, 100, RED);
		}
		else if (color == 1) {
			sfw::drawCircle(myT.position.x, myT.position.y, 10, 100, GREEN);
		}
	}
}

void Circle::update() {
	vec2 movement = { 0,0 };
	int momentum = 2;

	if (up == '0')
	{
		if (sfw::getKey(KEY_UP)) {
			movement.y += momentum;
		}
		if (sfw::getKey(KEY_DOWN)) {
			movement.y -= momentum;
		}
		if (sfw::getKey(KEY_LEFT)) {
			movement.x -= momentum;
		}
		if (sfw::getKey(KEY_RIGHT)) {
			movement.x += momentum;
		}
	}

	if (sfw::getKey(up)) {
		movement.y += momentum;
	}
	if (sfw::getKey(down)) {
		movement.y -= momentum;
	}
	if (sfw::getKey(left)) {
		movement.x -= momentum;
	}
	if (sfw::getKey(right)) {
		movement.x += momentum;
	}

	myT.position += movement;
}