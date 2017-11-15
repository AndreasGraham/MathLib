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
	link.transform.position = { 100, 300 };
	int handle = sfw::loadTextureMap("res/Link.png",14,6);
	int block_handle = sfw::loadTextureMap("res/block.png");
	moveableBlock block;
	block.sprite.animTimer = .2f;
	block.sprite.startTimer = .2f;
	block.transform.position = { 100, 350 };
	block.sprite.handle = block_handle;
	block.sprite.dim = { 50,50 };
	link.sprite.handle = handle;
	link.sprite.dim = { 50,50 };
	link.sprite.animMaxRange = 10;
	link.sprite.animMinRange = 4;
	link.sprite.animTimer = .2f;
	link.sprite.startTimer = .2f;
	
	int present_handle = sfw::loadTextureMap("res/presents.png");
	moveableBlock presents;
	presents.transform.position = { 600, 400 };
	presents.sprite.handle = present_handle;
	presents.sprite.dim = { 50,50 };

	int blue_handle = sfw::loadTextureMap("res/blue present.png");
	moveableBlock bluePresent;
	bluePresent.sprite.handle = blue_handle;
	bluePresent.sprite.dim = { 30,30 };
	bluePresent.transform.position = { 450, 450 };

	int green_handle = sfw::loadTextureMap("res/green.png");
	moveableBlock greenPresent;
	greenPresent.sprite.handle = green_handle;
	greenPresent.sprite.dim = { 30,30 };
	greenPresent.transform.position = { 400, 400 };

	int santa_handle = sfw::loadTextureMap("res/santa.jpg");
	moveableBlock santa;
	santa.sprite.handle = santa_handle;
	santa.sprite.dim = { 100, 100 };
	santa.transform.position = { 600, 200 };



	wall wall0;
	int wall_handle = sfw::loadTextureMap("res/xmass.png");
	wall0.transform.position = {0,200 };
	wall0.sprite.handle = wall_handle;
	wall0.sprite.dim = { 25,800 };
	wall0.sprite.animTimer = .2f;
	wall0.sprite.startTimer = .2f;

	wall wall1;
	wall1.transform.position = { 800, 300 };
	wall1.sprite.handle = wall_handle;
	wall1.sprite.dim = { 25,800 };

	wall wall2;
	wall2.transform.position = { 400, 600 };
	wall2.sprite.handle = wall_handle;
	wall2.sprite.dim = { 25,800 };
	wall2.transform.angle = 90.0f;

	wall wall3;
	wall3.transform.position = { 400, 0 };
	wall3.sprite.handle = wall_handle;
	wall3.sprite.dim = { 25,800 };
	wall3.transform.angle = 90.0f;

	wall wall4;
	wall4.transform.position = { 300,300 };
	wall4.sprite.handle = wall_handle;
	wall4.sprite.dim = { 150, 150 };
	wall4.transform.angle = 0.0f;

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
	wall0.collider.box.extents = { wall0.sprite.dim.x,wall0.sprite.dim.y };
	wall1.collider.box.extents = { wall1.sprite.dim.x,wall1.sprite.dim.y };
	wall2.collider.box.extents = { wall2.sprite.dim.x, wall2.sprite.dim.y };
	wall3.collider.box.extents = { wall3.sprite.dim.x, wall3.sprite.dim.y };
	wall4.collider.box.extents = { 75, 75 };
	presents.collider.box.extents = { 30, 30 };
	bluePresent.collider.box.extents = { 15,15 };
	greenPresent.collider.box.extents = { 15,15 };
	santa.collider.box.extents = { 50,50 };
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
		sfw::drawTextureMatrix3(wall0.sprite.handle, 0, WHITE, (mat3::identity() * wall0.transform.getGlobalTransform() * translate(wall0.sprite.offset) * scale(wall0.sprite.dim)).m);
		sfw::drawTextureMatrix3(wall1.sprite.handle, 0, WHITE, (mat3::identity() * wall1.transform.getGlobalTransform() * translate(wall1.sprite.offset) * scale(wall1.sprite.dim)).m);
		sfw::drawTextureMatrix3(wall2.sprite.handle, 0, WHITE, (mat3::identity() * wall2.transform.getGlobalTransform() * translate(wall2.sprite.offset) * scale(wall2.sprite.dim)).m);
		sfw::drawTextureMatrix3(wall3.sprite.handle, 0, WHITE, (mat3::identity() * wall3.transform.getGlobalTransform() * translate(wall3.sprite.offset) * scale(wall3.sprite.dim)).m);
		sfw::drawTextureMatrix3(wall4.sprite.handle, 0, WHITE, (mat3::identity() * wall4.transform.getGlobalTransform() * translate(wall4.sprite.offset) * scale(wall4.sprite.dim)).m);
		sfw::drawTextureMatrix3(presents.sprite.handle, 0, WHITE, (mat3::identity() * presents.transform.getGlobalTransform() * translate(presents.sprite.offset) * scale(presents.sprite.dim)).m);
		sfw::drawTextureMatrix3(bluePresent.sprite.handle, 0, WHITE, (mat3::identity() * bluePresent.transform.getGlobalTransform() * translate(bluePresent.sprite.offset) * scale(bluePresent.sprite.dim)).m);
		sfw::drawTextureMatrix3(greenPresent.sprite.handle, 0, WHITE, (mat3::identity() * greenPresent.transform.getGlobalTransform() * translate(greenPresent.sprite.offset) * scale(greenPresent.sprite.dim)).m);
		sfw::drawTextureMatrix3(santa.sprite.handle, 0, WHITE, (mat3::identity() * santa.transform.getGlobalTransform() * translate(santa.sprite.offset) * scale(santa.sprite.dim)).m);


		//sfw::drawTextureMatrix3(block_handle, bk[0], WHITE, m.m)
		DrawMatrix(link.transform.getGlobalTransform(),40);
		drawAABB(block.collider.getGlobalBox(block.transform),MAGENTA);
		drawAABB(link.collider.getGlobalBox(link.transform), MAGENTA);
		drawAABB(wall0.collider.getGlobalBox(wall0.transform), MAGENTA);
		drawAABB(wall1.collider.getGlobalBox(wall1.transform), MAGENTA);
		drawAABB(wall2.collider.getGlobalBox(wall2.transform), MAGENTA);
		drawAABB(wall3.collider.getGlobalBox(wall3.transform), MAGENTA);
		drawAABB(wall4.collider.getGlobalBox(wall4.transform), MAGENTA);
		drawAABB(presents.collider.getGlobalBox(presents.transform), MAGENTA);
		drawAABB(bluePresent.collider.getGlobalBox(bluePresent.transform), MAGENTA);
		drawAABB(greenPresent.collider.getGlobalBox(greenPresent.transform), MAGENTA);
		drawAABB(santa.collider.getGlobalBox(santa.transform), MAGENTA);

		//DrawMatrix(block.transform.getGlobalTransform(), 40);
		//link.rigidbody.force = { 5,5 };
		doCollision(block, link);
		wallCollision(wall0, link);
		block_wallCollision(wall0, block);
		wallCollision(wall1, link);
		block_wallCollision(wall1, block);
		wallCollision(wall2, link);
		block_wallCollision(wall2, block);
		wallCollision(wall3, link);
		block_wallCollision(wall3, block);
		wallCollision(wall4, link);
		block_wallCollision(wall4, block);
		block_wallCollision(wall0, presents);
		block_wallCollision(wall1, presents);
		block_wallCollision(wall2, presents);
		block_wallCollision(wall3, presents);
		block_wallCollision(wall4, presents);
		doCollision(presents, link);
		block_blockCollision(block, presents);
		block_blockCollision(block, bluePresent);
		block_blockCollision(presents, bluePresent);

		block_wallCollision(wall0, bluePresent);
		block_wallCollision(wall1, bluePresent);
		block_wallCollision(wall2, bluePresent);
		block_wallCollision(wall3, bluePresent);
		block_wallCollision(wall4, bluePresent);
		doCollision(bluePresent, link);

		block_wallCollision(wall0, greenPresent);
		block_wallCollision(wall1, greenPresent);
		block_wallCollision(wall2, greenPresent);
		block_wallCollision(wall3, greenPresent);
		block_wallCollision(wall4, greenPresent);
		doCollision(greenPresent, link);

		block_wallCollision(wall0, santa);
		block_wallCollision(wall1, santa);
		block_wallCollision(wall2, santa);
		block_wallCollision(wall3, santa);
		block_wallCollision(wall4, santa);
		doCollision(santa, link);
	}

	sfw::termContext();

}