#include "../include/StolenObject.h"

static const float SCALE = 30.f;

using namespace escape;

StolenObject::StolenObject(){}

StolenObject::StolenObject(float x, float y, int radius, b2World* World){
  this -> xCoord = x;
	this -> yCoord = y;

  this -> radius = radius;

  this -> color = sf::Color::White;

	//Box2D Information
	this -> World = World;

	b2BodyDef BodyDef;
    	BodyDef.position = b2Vec2(x/SCALE, y/SCALE);
   	BodyDef.type = b2_dynamicBody;
    	b2Body* Body = this -> World -> CreateBody(&BodyDef);
	
	b2CircleShape Shape;
	Shape.m_p.Set(((float)x/2)/SCALE, ((float)y/2)/SCALE);
	Shape.m_radius = radius / SCALE;
	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.f;
	FixtureDef.friction = 0.7f;
	FixtureDef.shape = &Shape;
	Body->CreateFixture(&FixtureDef);
	this -> Body = Body;
}

void StolenObject::UpdatePosition(){
	this -> xCoord = this -> Body -> GetPosition().x * SCALE;
	this -> yCoord = this -> Body -> GetPosition().y * SCALE;
}
