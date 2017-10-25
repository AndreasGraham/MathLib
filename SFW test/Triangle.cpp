#include "Triangle.h"
#include "sfwdraw.h"

//shooting


Triangle::Triangle()
{
}

Triangle::Triangle(vec2 pos, vec2 scale, float angle, char upK, char downK, char leftK, char rightK, char shotK)
{
	myT.position = pos;
	myT.dimension = scale;
	myT.angle = angle;

	up = upK;
	down = downK;
	left = leftK;
	right = rightK;
	shoot = shotK;


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

	if (health > 0) {
		drawTriangle(myT.position.x, myT.position.y, (myT.position.x - 25.0f), (myT.position.y - 25.0f), (myT.position.x + 25.0f), (myT.position.y - 25.0f));
	}

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
	vec2 dummy = aim - myT.position;
	mat3 T = myT.getGlobalTransform();

	vec2 movement = normalize(T[1].xy);

	int momentum = 4;
	float time = 0;

	if (sfw::getKey(shoot))
	{
		for (int i = 0; i < ammo; i++)
		{
			if (magazine[i].enabled == false)
			{
				magazine[i].pos = myT.position;
				//magazine[i].Dir = normalize(dummy); //normalize(aim); //normalize(T[1].xy);
				magazine[i].Dir = movement;
				magazine[i].speed = 30;
				magazine[i].lifetime = 3;

				magazine[i].enabled = true;
				break;
			}
		}
	}

	if (sfw::getKey(up)) {
		//movement.y += momentum;
		myT.position += movement;
	}
	if (sfw::getKey(down)) {
		//movement.y -= momentum;
		myT.position -= movement;
	}
	if (sfw::getKey(left)) {
		myT.angle += 1;
		movement.x -= momentum;
	}
	if (sfw::getKey(right)) {
		myT.angle -= 1;
		//movement.x += momentum;
	}

	


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
