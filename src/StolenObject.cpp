#include "StolenObject.h"
#include <cmath>

static const float SCALE = 30.f;

using namespace escape;

StolenObject::StolenObject(){}

/*
* Constructor
* @param x: x coordinate of stolen object
* @param y: y coordinate of stolen object
* @param radius: radius of stolen object
* @param restitution: bounciness of stolen object
*/
StolenObject::StolenObject(float x, float y, int radius, float restitution){
	this -> xCoord = x;
	this -> yCoord = y;

	this -> restitution = restitution; //0.5f is average

	this -> radius = radius;

	float r = (float) radius;

	this -> rotation  = 0;

	this -> timeSinceLastDamage = this -> timer.getElapsedTime().asMilliseconds();

	this -> playSound = false;
}

/*
* Sets the world for Box2D
* @param *World: current B2D world
*/
void StolenObject::setWorld(b2World* World){
	//Box2D body with a dynamic body so it moves.
	b2BodyDef BodyDef;
  BodyDef.position = b2Vec2(this -> xCoord/SCALE, this -> yCoord/SCALE);
  BodyDef.type = b2_dynamicBody;
  this -> Body = World -> CreateBody(&BodyDef);

	//Shape is a circle with radius r
	b2CircleShape Shape;
	Shape.m_p.Set(0, 0);
	Shape.m_radius = (float) this -> radius / SCALE;

	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.f;
	FixtureDef.friction = .7f;
	FixtureDef.shape = &Shape;
	FixtureDef.restitution = this -> restitution;

	this -> Body -> CreateFixture(&FixtureDef);
	this -> Body -> SetAwake(1);
	this -> Body -> SetUserData( this );

	this -> health = 10;
}

/*
* Update the Position of a Stolen Object based on Box2D Physics.
*/
void StolenObject::updatePosition(){
	this -> xCoord = this -> Body -> GetPosition().x * SCALE;
	this -> yCoord = this -> Body -> GetPosition().y * SCALE;
	this -> rotation = this -> Body -> GetAngle() * 180 / b2_pi;
}

/*
* Procedures to do when stolen object touches something
*/
void StolenObject::startContact(float yVel){
	//Decrease health.
	//TODO: change functionality to have variable damage

	double newTime = this -> timer.getElapsedTime().asMilliseconds();
	if (newTime > (this -> timeSinceLastDamage + 500)){
		if (this -> health >= 0)
			this -> health -= floor(abs(yVel) / 4);
			if (this -> health < 0){
				this -> health = 0;
			}

		this -> playSound = true;
	}

	this -> timeSinceLastDamage = newTime;
}

/*
* Kills the momentum of object
*/
void StolenObject::killSpeed(){
	this -> Body -> SetLinearVelocity(b2Vec2(0.f,0.f));
	this -> Body -> SetAwake(0);
}
