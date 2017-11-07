#include "transform.h"
#include <iostream>
#include "sfwdraw.h"

Transform::Transform() {
	position = vec2{ 0 ,0 };
	dimension = vec2{ 1,1 };
	angle = 0;
	e_parent = nullptr;
}

mat3 Transform::getLocalTransofrm() const {
	return translate(position) * rotate(angle) * scale(dimension) ;
}


mat3 Transform::getGlobalTransform() const {
	if (e_parent != nullptr) {
		return e_parent->getGlobalTransform() * getLocalTransofrm();
	}
	else {
		return getLocalTransofrm();
	}
}

void DrawMatrix(const mat3 &t, float drawing_scale) {
	vec2 pos = t[2].xy;

	//angle related
	//std::cout << t[1].xy.v << std::endl;
	//std::cout << t[1].xy.x << std::endl;
	//std::cout << t[1].xy.y << std::endl;

	////angle related
	//std::cout << t[0].xy.v << std::endl;
	//std::cout << t[0].xy.x << std::endl;
	//std::cout << t[0].xy.y << std::endl;

	////position
	//std::cout << t[2].xy.v << std::endl;
	//std::cout << t[2].xy.x << std::endl;
	//std::cout << t[2].xy.y << std::endl;

	vec2 right_ep = (pos + t[0].xy) * drawing_scale;
	vec2 up_ep = pos + t[1].xy * drawing_scale;

	sfw::drawLine(pos.x, pos.y, right_ep.x, right_ep.y, RED);
	sfw::drawLine(pos.x, pos.y, up_ep.x, up_ep.y, GREEN);
	
	sfw::drawCircle(pos.x, pos.y, drawing_scale / 4);
}