#include "Player.h"
#include "sfwdraw.h"
#include <iostream>
#include "Collision.h"


//Player::Player()
//{
//	sprite.dim = { 10,10 };
//}

//void Player::update() {
//	vec2 movement = {0,0};
//
//	int momentum = 1;
//	float time = 0;
//
//	if (sfw::getKey('E')) {
//		
//		
//		time = sfw::getDeltaTime() + time;
//		std::cout << time << std::endl;
//		momentum = 10;
//
//	}
//
//	if (sfw::getKey('W')) {
//		movement.y += momentum;
//	}
//	if (sfw::getKey('S')) {
//		movement.y -= momentum;
//	}
//	if (sfw::getKey('A')) {
//		movement.x -= momentum;
//	}
//	if (sfw::getKey('D')) {
//		movement.x += momentum;
//	}
//
//	pos += movement;
//}

//void Player::draw() {
//	sfw::drawCircle(pos.x, pos.y, 30.f);
//}

// what do i need, on a key press, increase the movement per call in the direction
// next, while key is pressed, track time, if that time is greater than 3, set momentum back to 1


//static collision
void static_resolution(vec2 & pos, vec2 & vel, const Collision & result, float elasticity) {
	// for position, we need to correct:
	pos += result.axis * result.handedness * result.penetrationDepth;

	// for velocity, we need to reflect:
	vel = -reflect(vel, result.axis*result.handedness) * elasticity;
}

void dynamic_resolution(vec2 & Apos, vec2 & Avel, float Amass, vec2 & Bpos, vec2 & Bvel, float Bmass, const Collision & result, float elasticity) {
	// law of conservation 
	/*
	mass * vel = momentum

	AP + BP = 'Ap + 'BP // Conservation of Momentum
	Avel*Amass + Bvel*Bmass = fAvel*Amass + fBvel*Bmass
	Avel - Bvel = -(Fbvel -fAvel)	
	*/

	vec2 normal = result.axis * result.handedness;

	vec2 Rvel = Avel - Bvel;

	float j = -(1 + elasticity)*Dot(Rvel, normal) / Dot(normal, normal *(1 / Amass + 1 / Bmass));

	Avel += (j / Amass) * normal;
	Bvel -= (j / Bmass) * normal;

	Apos += normal * result.penetrationDepth * Amass / (Amass + Bmass);
	Bpos += normal * result.penetrationDepth * Bmass / (Amass + Bmass);
}

void doCollision(moveableBlock & block, Player & player)
{
	//result basically just checks if thew two objects are colliding by recording a penetration depth, a handedness (-1, or 1 depending on which is deeper)
	// and a vec 2. it checks each in a 1 dimensional manner (is there an x dimensional collision, or y dimensional collision?)
	Collision result = collides(block.transform, block.collider, player.transform, player.collider);
	// hit = result
	if (result.penetrationDepth > 0)
	{
		//Static collision against a non moving agent
		static_resolution(block.transform.position, block.rigidbody.velocity, result, 1.0f);
		
		//				OR
		//Dynamic collision against a moving agents


		//This is like a trigger collision
		std::cout << "In Collision" << std::endl;
		/*vec2 dir = normalize(block.transform.position - player.transform.position);
		block.rigidbody.force += dir * 500;*/
	}

}


void wallCollision(const wall & w, Player & p) {
	Collision result = collides(w.transform, w.collider, p.transform, p.collider);
	result.handedness *= -1;
	if (result.penetrationDepth > 0)
	{
		static_resolution(p.transform.position,	p.rigidbody.velocity, result,0);
	}
}

void block_wallCollision(const wall & w, moveableBlock & b) {
	Collision result = collides(w.transform, w.collider, b.transform, b.collider);
	result.handedness *= -1;
	if (result.penetrationDepth > 0)
	{
		static_resolution(b.transform.position, b.rigidbody.velocity, result, 0);
	}
}

void block_blockCollision(moveableBlock & a, moveableBlock & b) {
	Collision result = collides(a.transform, a.collider, b.transform, b.collider);
	result.handedness *= -1;
	if (result.penetrationDepth > 0)
	{
		static_resolution(b.transform.position, b.rigidbody.velocity, result, 0);
	}
}

