#include "sfwdraw.h"
#include "Player.h"
#include "transform.h"
#include <iostream>
#include "DrawShapes.h"
#include "Rigidbody.h"
#include "Collision.h"
#include <cassert>
#include "Collider.h"
#include "Controller.h"

int main() {
	sfw::initContext();
	Player link;
	link.transform.position = { 400, 300 };
	int handle = sfw::loadTextureMap("res/Link.png",14,6);
	link.sprite.handle = handle;
	link.sprite.dim = { 50,50 };
	link.sprite.animMaxRange = 10;
	link.sprite.animMinRange = 4;
	link.sprite.animTimer = .2f;
	link.sprite.startTimer = .2f;
	int down[2];
	down[0] = 1;
	down[1] = 15;
	int up[2];
	up[0] = 17;
	up[1] = 3;
	int left[2];
	left[0] = 2;
	left[1] = 16;
	int right[2];
	right[0] = 4;
	right[1] = 18;
	int idle[1];
	idle[0] = 29;

	int index = 0;
	while (sfw::stepContext()) {
		
		
		link.controller.poll(link.rigidbody, link.transform, up, down, left, right, link.sprite, index);
		link.rigidbody.integrate(link.transform, sfw::getDeltaTime());
		//link.sprite.draw(link.transform,sfw::getDeltaTime());
		//sfw::drawTexture(handle, link.transform.position.x, link.transform.position.y, 50, 50,link.transform.angle);
		//sfw::drawCircle(link.transform.position.x, link.transform.position.y, 5);
		//link.sprite.animeCycle(idle, link.transform, 1, sfw::getDeltaTime(), index);
		DrawMatrix(link.transform.getGlobalTransform(),40);
		//link.rigidbody.force = { 5,5 };
	}

	sfw::termContext();

}