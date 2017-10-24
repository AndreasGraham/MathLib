#include "Triangle.h"
#include "sfwdraw.h"

//shooting


Triangle::Triangle()
{
}

Triangle::Triangle(vec2 pos, vec2 scale, float angle)
{
	myT.position = pos;
	myT.dimension = scale;
	myT.angle = angle;
	for (int i = 0; i < ammo; i++)
	{
		magazine[i].enabled = false;
	}
}


void Triangle::drawTriangle(float ax, float ay, float bx, float by, float cx, float cy) {
	sfw::drawLine(ax, ay, bx, by, RED);
	sfw::drawLine(ax, ay, cx, cy, RED);
	sfw::drawLine(cx, cy, bx, by, RED);
}

void Triangle::draw()
{
	//DrawTriangle

	//	 * position
	//	/ \ position-Xvalue, position - Yvalue, position + Xvalue, position - Yvalue

	//sfw::drawCircle(myT.position.x, myT.position.y, 20);
	drawTriangle(myT.position.x, myT.position.y, (myT.position.x-25.0f),(myT.position.y-25.0f),(myT.position.x+25.0f), (myT.position.y-25.0f));

	for (int i = 0; i < ammo; i++)
	{
		if (magazine[i].enabled == true)
		{
			magazine[i].draw();
		}
	}
}

void Triangle::update()
{
	vec2 aim = { sfw::getMouseX(), sfw::getMouseY() };
	mat3 T = myT.getGlobalTransform();

	vec2 movement = { 0,0 };

	int momentum = 1;
	float time = 0;

	if (sfw::getMouseButton(0))
	{
		for (int i = 0; i < ammo; i++)
		{
			if (magazine[i].enabled == false)
			{
				magazine[i].pos = myT.position;
				magazine[i].Dir = normalize(aim); //normalize(T[1].xy);
				magazine[i].speed = 30;
				magazine[i].lifetime = 3;

				magazine[i].enabled = true;
				break;
			}
		}
	}

	if (sfw::getKey('W')) {
		movement.y += momentum;
	}
	if (sfw::getKey('S')) {
		movement.y -= momentum;
	}
	if (sfw::getKey('A')) {
		movement.x -= momentum;
	}
	if (sfw::getKey('D')) {
		movement.x += momentum;
	}

	myT.position += movement;


	for (int i = 0; i < ammo; i++)
	{
		if (magazine[i].enabled == true)
		{
			magazine[i].update();
		}
	}
}

void Triangle::ability1()
{
	
}

void Triangle::ability2()
{
}

void Triangle::ability3()
{
}
