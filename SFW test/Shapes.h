#pragma once

#include "transform.h"
class Heroes {
public:
	int health;
	Transform myT;

	

	virtual  void ability1();
	virtual void ability2();
	virtual void ability3();
	bool enabled;
	virtual void draw();
	virtual void update();
};