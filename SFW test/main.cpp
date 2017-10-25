#include "sfwdraw.h"
#include "Player.h"
#include "transform.h"
#include "Triangle.h"
#include "Square.h"
#include "Circle.h"
#include <iostream>

bool checkCollision(Triangle &tri, Bullet &bul)
{
	float aXmin = tri.myT.position.x - 25.0f;
	float aXmax = tri.myT.position.x + 25.0f;
	float aYmin = tri.myT.position.y - 25.0f;
	float aYmax = tri.myT.position.y;

	float bXmin = bul.pos.x - 2.0f;
	float bXmax = bul.pos.x + 2.0f;
	float bYmin = bul.pos.y - 2.0f;
	float bYmax = bul.pos.y + 2.0f;
	if (aXmin < bXmax && aXmax > bXmax && aYmin < bYmax && aYmax > bYmin)
	{
		return true;
	}

	return false;
}

int main() {
	sfw::initContext();
	sfw::setCursorVisible(true);

	Transform myTransform;
	myTransform.position = vec2{ 200,400 };
	myTransform.dimension = vec2{ 2,2 };
	myTransform.angle = 45;

	//make an int for a color switchboard
	Triangle Nei(vec2{ 400,400 }, vec2{ 1,1 }, 0, 'W', 'S', 'A', 'D', 'Q');
	Triangle Bei(vec2{ 500,400 }, vec2{ 1,1 }, 0, 'H', 'Y', 'G', 'J', 'T');
	Circle Mercy(vec2{ 500, 500 }, vec2{ 1,1 }, 0);
	Circle Ana(vec2{ 500, 500 }, vec2{ 1,1 }, 0);

	Square Rein(vec2{ 400, 400 }, vec2{ 1,1 }, 0);
	Transform myBaby;
	myBaby.position = vec2{ 50,50 };
	myBaby.dimension = vec2{ 1,1 };
	myBaby.angle = 0;
	myBaby.e_parent = &myTransform;


	while (sfw::stepContext()) 
	{
		
		// 
		Bei.draw();
		Bei.update();
		Nei.draw();
		Nei.update();
		Rein.draw();
		Rein.update();
		Mercy.draw();
		Mercy.update();
		Ana.draw();
		Ana.update();
		

		for (int i = 0; i < 25; i++)
		{
			if (checkCollision(Bei, Nei.magazine[i]))
			{
				std::cout << "get rekt\n";
				Bei.health -= 1;

			}
			if (checkCollision(Nei, Bei.magazine[i]))
			{
				std::cout << "get rekt\n";
				Nei.health -= 1;

			}

		}
		
		if (Distance(Mercy.myT.position, Bei.myT.position) < 100) {
			
			if (sfw::getKey('E')) {

				Bei.health += 1;
				std::cout << Bei.health;
			}
		}

		if (Distance(Ana.myT.position, Nei.myT.position) < 100) {

			if (sfw::getKey('E')) {

				Nei.health += 1;
				std::cout << Nei.health;
			}
		}

		DrawMatrix(Nei.myT.getGlobalTransform(), 40);
		DrawMatrix(Bei.myT.getGlobalTransform(), 40);

		//DrawMatrix(myTransform.getLocalTransofrm(), 40);
		//DrawMatrix(myBaby.getGlobalTransform(), 30);
		
	}

	sfw::termContext();

}