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
	int block_handle = sfw::loadTextureMap("res/block.png");
	moveableBlock block;
	block.sprite.animTimer = .2f;
	block.sprite.startTimer = .2f;
	block.transform.position = { 500, 400 };
	block.sprite.handle = block_handle;
	block.sprite.dim = { 50,50 };
	link.sprite.handle = handle;
	link.sprite.dim = { 50,50 };
	link.sprite.animMaxRange = 10;
	link.sprite.animMinRange = 4;
	link.sprite.animTimer = .2f;
	link.sprite.startTimer = .2f;
	wall wall;
	int wall_handle = sfw::loadTextureMap("res/tiles.png");
	wall.transform.position = { 400,400 };
	wall.sprite.handle = wall_handle;
	wall.sprite.dim = { 50,50 };

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
	int bk[1];
	bk[0] = 0;
	int index = 0;
	int i = 1;
	
	link.collider.box.extents = { 15, 15 };
	block.collider.box.extents = { 30, 30 };

	block.rigidbody.drag = 5;


	while (sfw::stepContext()) {
		
		
		link.controller.poll(link.rigidbody, link.transform, up, down, left, right, idle, link.sprite, index);
		link.rigidbody.integrate(link.transform, sfw::getDeltaTime());
		block.rigidbody.integrate(block.transform, sfw::getDeltaTime());
		//link.sprite.draw(link.transform,sfw::getDeltaTime());
		//sfw::drawTexture(handle, link.transform.position.x, link.transform.position.y, 50, 50,link.transform.angle);
		//sfw::drawCircle(link.transform.position.x, link.transform.position.y, 5);
		//link.sprite.animeCycle(idle, link.transform, 1, sfw::getDeltaTime(), index);
		//block.sprite.animeCycle(bk, block.transform, 1, sfw::getDeltaTime(), i);
		


		sfw::drawTextureMatrix3(block.sprite.handle, 0, WHITE, (mat3::identity() * block.transform.getGlobalTransform() * translate(block.sprite.offset) * scale(block.sprite.dim)).m);
		sfw::drawTextureMatrix3(wall.sprite.handle, 0, WHITE, (mat3::identity() * wall.transform.getGlobalTransform() * translate(wall.sprite.offset) * scale(wall.sprite.dim)).m);
		//sfw::drawTextureMatrix3(block_handle, bk[0], WHITE, m.m);
		DrawMatrix(link.transform.getGlobalTransform(),40);
		drawAABB(block.collider.getGlobalBox(block.transform),MAGENTA);
		drawAABB(link.collider.getGlobalBox(link.transform), MAGENTA);
		//DrawMatrix(block.transform.getGlobalTransform(), 40);
		//link.rigidbody.force = { 5,5 };
		doCollision(block, link);
	}

	sfw::termContext();

}