#include "mathutills.h"
#include "Vec2.h"`
#include <assert.h>
#include <iostream>

int main()
{

	int val = min(1, 3);
	vec2 test;
	test.x = 5;
	test.y = 20;

	vec2 testb;
	testb.x = 13;
	testb.y = 20;

	vec2 result = test + testb;

	vec2 num;
	num.x = 0;
	num.y = 0;
	
	num += test;
	//num.NormalizeMyThing();
	normalizeReference(num);
	vec2 numNorm = normalize(num);
	bool eq = num == test;
	bool ieq = num == testb;

	vec2 a = { 0,0 };
	vec2 b = { 0,0 };
	vec2 c = { 0,1 };

	assert(a == b);

	vec2 g;
	g.x = 5;
	g.y = 12;

	vec2 f;
	f.x = 7;
	f.y = 4;

	vec2 mag = { 3, 4 };
	vec2 bag = { 1, 1 };

	std::cout << Distance(g, f) << std::endl;
	assert(magnitude(mag) == 5);
	//std::cout << normalize(mag).x << std::endl;
	assert(normalize(mag).x == 0.6f);
	assert(Dot(mag, bag) == 7.0f);
	//2, 3, 4, 9, 13
	assert(Distance(mag, bag) == sqrtf(13));
	assert(Perpendicular(mag).x == -4.0f);
	//std::cout << Lerp(bag, mag, 1).x << std::endl;
	assert(Lerp(bag, mag, 1).x == 2.0f);
	assert(min(mag, bag).x = 1.0f);
	assert(max(mag, bag).x = 3);




	while (true) {}

}