#include "Circle.h"
#include "sfwdraw.h"
Circle::Circle(vec2 pos, vec2 scale, float angle) {
	myT.position = pos;
	myT.dimension = scale;
	myT.angle = angle;
}
Circle::Circle() {

}
void Circle::draw() {
	sfw::drawCircle(myT.position.x, myT.position.y, 10, 100, GREEN);
}

void Circle::update() {
	vec2 movement = { 0,0 };
	int momentum = 4;

	if (sfw::getKey('W')) {
		movement.y += momentum;
	}
	if (sfw::getKey('S')) {
		movement.y -= momentum;
	}
	if (sfw::getKey('A')) {
		movement.x -= momentum;
	}
	if (sfw::getKey('D')) {
		movement.x += momentum;
	}

	myT.position += movement;
}