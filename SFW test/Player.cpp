#include "Player.h"
#include "sfwdraw.h"
#include <iostream>

void Player::update() {
	vec2 movement = {0,0};

	int momentum = 1;
	float time = 0;

	if (sfw::getKey('E')) {
		
		
		time = sfw::getDeltaTime() + time;
		std::cout << time << std::endl;
		momentum = 10;

	}

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

	pos += movement;
}

void Player::draw() {
	sfw::drawCircle(pos.x, pos.y, 30.f);
}

// what do i need, on a key press, increase the movement per call in the direction
// next, while key is pressed, track time, if that time is greater than 3, set momentum back to 1

