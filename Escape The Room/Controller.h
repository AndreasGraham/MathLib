#pragma once
#include "Rigidbody.h"
#include "transform.h"
#include "sfwdraw.h"
#include "Sprite.h"
//contoller --> motoer --> rigidbody --> transform

//poll for input and apply changes to the rigidbody
class Controller {

public:
	
	void poll(RigidBody &rb, Transform &t, int up[], int down[], int left[], int right[], Sprite sprite, int i) {
		
		if(sfw::getKey())
		if (sfw::getKey('W'))
		{
			sprite.animeCycle(up, t, 2, sfw::getDeltaTime(), i);
			//rb.force += t.getGlobalTransform()[1].xy * 10;
			t.position.y += 2;
		}
		if (sfw::getKey('A')) {
			sprite.animeCycle(left, t, 2, sfw::getDeltaTime(), i);
			//rb.torqu += 5;
			t.position.x -= 2;
		}
		if (sfw::getKey('D')) { 
			sprite.animeCycle(right, t, 2, sfw::getDeltaTime(), i);
			//rb.torqu += -5; 
			t.position.x += 2;
		}
		if (sfw::getKey('S')) {
			sprite.animeCycle(down, t, 2, sfw::getDeltaTime(), i);
			//rb.impulse += -t.getGlobalTransform()[1].xy * 10; 
			t.position.y -= 2;
		}

	}

};