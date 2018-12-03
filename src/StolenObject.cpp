#include "../include/StolenObject.h"

static const float SCALE = 30.f;

using namespace escape;

StolenObject::StolenObject(){}

/*
* Constructor
* @param x: x coordinate of stolen object
* @param y: y coordinate of stolen object
* @param radius: radius of stolen object
* @param World: Box2D Object where the object will be placed
*/
StolenObject::StolenObject(float x, float y, int radius){
	this -> xCoord = x;
	this -> yCoord = y;

	this -> radius = radius;

	float r = (float) radius;

	this -> rotation  = 0;
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
	FixtureDef.restitution = .5f;
	this -> Body -> CreateFixture(&FixtureDef);
	// this -> Body-> SetAngularDamping(0);
  // this -> Body-> SetLinearDamping(0);
	this -> Body -> SetAwake(1);
}

/*
* Update the Position of a Stolen Object based on Box2D Physics.
*/
void StolenObject::updatePosition(){
	this -> xCoord = this -> Body -> GetPosition().x * SCALE;
	this -> yCoord = this -> Body -> GetPosition().y * SCALE;
	this -> rotation = this -> Body -> GetAngle() * 180 / b2_pi;
}
