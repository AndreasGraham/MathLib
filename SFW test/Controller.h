#pragma once
#include "Rigidbody.h"
#include "transform.h"
#include "sfwdraw.h"
//contoller --> motoer --> rigidbody --> transform

//poll for input and apply changes to the rigidbody
class Controller {

public:
	void poll(RigidBody &rb, const Transform &t) {
		if (sfw::getKey('W'))
		{
			rb.force += t.getGlobalTransform()[1].xy * 2;
		}
			if (sfw::getKey('A'))rb.torqu += 360;
		if (sfw::getKey('D'))rb.torqu += -360;
		if (sfw::getKey('Q'))rb.impulse += -t.getGlobalTransform()[1].xy * 10;

	}

};