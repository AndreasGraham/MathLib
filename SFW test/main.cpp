#include "sfwdraw.h"
#include "Player.h"
#include "transform.h"
#include "Triangle.h"


int main() {
	sfw::initContext();

	Transform myTransform;
	myTransform.position = vec2{ 200,400 };
	myTransform.dimension = vec2{ 2,2 };
	myTransform.angle = 45;
	Triangle Nei(vec2{ 400,300 }, vec2{1,1}, 0);
	Transform myBaby;
	myBaby.position = vec2{ 50,50 };
	myBaby.dimension = vec2{ 1,1 };
	myBaby.angle = 0;
	myBaby.e_parent = &myTransform;


	while (sfw::stepContext()) 
	{
		
		// 
		Nei.draw();
		Nei.update();

		DrawMatrix(Nei.myT.getGlobalTransform(), 40);

		DrawMatrix(myTransform.getLocalTransofrm(), 40);
		DrawMatrix(myBaby.getGlobalTransform(), 30);
		
	}

	sfw::termContext();

}