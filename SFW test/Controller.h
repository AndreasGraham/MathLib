#pragma once
#include "Rigidbody.h"
#include "transform.h"
#include "sfwdraw.h"
//contoller --> motoer --> rigidbody --> transform

//poll for input and apply changes to the rigidbody
class Controller {

public:
	void poll(RigidBody, &rb, const Transform &t) {
		if (sfw::getKey('W'))rigidbody.force += transform.getGlobalTransform()[1].xy * 2;
		if (sfw::getKey('A'))rigidbody.torqu += 360;
		if (sfw::getKey('D'))rigidbody.torqu += -360;
		if (sfw::getKey('Q'))rigidbody.impulse += -transform.getGlobalTransform()[1].xy * 10;

	}

};