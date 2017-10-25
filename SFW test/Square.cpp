#include "Square.h"
#include "sfwdraw.h"
#include <iostream>

Square::Square() {

}

Square::Square(vec2 pos, vec2 scale, float angle) {
	myT.position = pos;
	myT.dimension = scale;
	myT.angle = angle;
}

void Square::drawSquare(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy) {
	sfw::drawLine(ax, ay, bx, by, RED);
	sfw::drawLine(bx, by, cx, cy, RED);
	sfw::drawLine(cx, cy, dx, dy, RED);
	sfw::drawLine(dx, dy, ax, ay, RED);

}

void Square::drawSquareNew(int base, int height) {
	

}

void Square::draw() {
	drawSquare(myT.position.x, myT.position.y, myT.position.x - 25, myT.position.y, myT.position.x-25, myT.position.y - 25, myT.position.x , myT.position.y - 25);
	drawSquare(myT.position.x + 25, myT.position.y + 25, myT.position.x - 50, myT.position.y +25 , myT.position.x - 50, myT.position.y - 50, myT.position.x +25, myT.position.y - 50);
}

void Square::ability1() {
	if (sfw::getKey('F')) {
		drawSquare(myT.position.x, myT.position.y , myT.position.x - 50.00f, myT.position.y, myT.position.x - 50.00f, myT.position.y - 50.00f, myT.position.x, myT.position.y - 50.00f);
	}
}

void Square::update() {
	vec2 movement = { 0,0 };

	int momentum = 4;

	if (sfw::getKey('I')) {
		movement.y += momentum;
	}
	if (sfw::getKey('K')) {
		movement.y -= momentum;
	}
	if (sfw::getKey('J')) {
		movement.x -= momentum;
	}
	if (sfw::getKey('L')) {
		movement.x += momentum;
	}

	myT.position += movement;
	ability1();

	
}


void Square::ability2() {

}
void Square::ability3() {

}