#include "sfwdraw.h"
#include "Player.h"
#include "transform.h"


int main() {
	sfw::initContext();

	Transform myTransform;
	myTransform.position = vec2{ 300,400 };
	myTransform.dimension = vec2{ 1,1 };

	while (sfw::stepContext()) 
	{
		
		DrawMatrix(myTransform.getLocalTransofrm(), 40);
		
	}

	sfw::termContext();

}