#include "bullet.h"
#include "sfwdraw.h"

void Bullet::update() {
	pos += Dir * speed;
	end = (pos + (Dir * 3));
	lifetime -= sfw::getDeltaTime();
	if (lifetime < 0)
	{
		enabled = false;
	}
}

void Bullet::draw() {
	sfw::drawLine(pos.x, pos.y, end.x, end.y, RED);
}