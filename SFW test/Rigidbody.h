#pragma once
#include "Vec2.h"
#include "transform.h"
class RigidBody {
public:
	float mass;
	vec2 velocity, // speed * direction
		acceleration,// A = F/M  F = MA
		force,// use it
		impulse; // huge force of acceleration of a very specific amount on a single frame (boosts, in speed, exposions etc) used instead of forces, applied quickly and diminish quickly
	float drag; // drag is anything that slows us down (returns us back to neutral) like wind applied using a dampening force
	float angularVelocity,
		angularAcceleration,
		torqu;
	float angulardrag;
	RigidBody() : velocity{ 0, 0 },
		acceleration{ 0,0 },
		force{ 0,0 },
		impulse{ 0,0 },
		mass{ 1 },
		drag{ 1 }, // usually defaulted to zero
		angularVelocity{0},
		angularAcceleration{ 0 },
		torqu{ 0 }, // replaces force
		angulardrag{ 0 } // all the angular stuff works the same way as linear motion it just replaces a few things
		          
	{

	}

	void integrate(Transform &t, float dt) {
		acceleration = force / mass;
		velocity += acceleration * dt + impulse/mass; 
		impulse = {0,0};
		t.position += velocity * dt; //dt is delta time, added for consistent rate of movement. iv velocity is 1, you will move 1 unity per second
		force = -velocity * drag; //dampening force, moving against current direction (air resistance possibly)
		
		angularAcceleration = torqu / mass;
		angularVelocity += angularAcceleration * dt;
		t.angle += angularVelocity * dt;
		torqu = angularVelocity * angulardrag;
	}
};