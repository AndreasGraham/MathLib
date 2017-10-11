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

	std::cout << Distance(g, f) << std::endl;

	while (true) {}

}