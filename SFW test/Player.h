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
	Spri te sprite;
	Player();
	vec2 pos;

	void update();
	void draw();
};