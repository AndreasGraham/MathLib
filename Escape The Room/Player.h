#pragma once
#include "Vec2.h"
#include "Rigidbody.h"
#include "transform.h"
#include "Collider.h"
#include "Controller.h"
#include "Sprite.h"

class Player {
public:
	Transform transform;
	RigidBody rigidbody;
	Collider collider;
	Controller controller;
	Sprite sprite;
	//Player();
	vec2 pos;

	/*void update();
	void draw();*/
};

class moveableBlock
{
public:
	Transform transform;
	RigidBody rigidbody;
	Collider collider;
	Sprite sprite;
};

class wall {
public:
	Transform transform;
	RigidBody rigidbody;
	Collider collider;
	Sprite sprite;
};

void wallCollision(wall &wall, Player &player);
void doCollision(moveableBlock &block, Player &player);