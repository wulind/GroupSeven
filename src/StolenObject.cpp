#include "../include/StolenObject.h"
#include <stdio.h>

static const float SCALE = 30.f;

using namespace escape;

StolenObject::StolenObject(){}

/*
* Constructor
* @param x: x coordinate of stolen object
* @param y: y coordinate of stolen object
* @param radius: radius of stolen object
*/
StolenObject::StolenObject(float x, float y, int radius, b2World* World){
  this -> xCoord = x;
	this -> yCoord = y;

  this -> radius = radius;

  this -> color = sf::Color::White;

	float r = (float) radius;

	//Box2D Information
	this -> World = World;

	b2BodyDef BodyDef;
    	BodyDef.position = b2Vec2(x/SCALE, y/SCALE);
   	BodyDef.type = b2_dynamicBody;
    	b2Body* Body = this -> World -> CreateBody(&BodyDef);
	
	b2CircleShape Shape;
	Shape.m_p.Set(0, 0);
	Shape.m_radius = (float) r / SCALE;
	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.f;
	FixtureDef.friction = 0.7f;
	FixtureDef.shape = &Shape;
	FixtureDef.restitution = .5f;
	Body->CreateFixture(&FixtureDef);
	this -> Body = Body;
	this -> Body -> SetAwake(1);
}

void StolenObject::UpdatePosition(){
	/*
	if (this -> xCoord == this -> Body -> GetPosition().x * SCALE && this -> yCoord == this -> Body -> GetPosition().y * SCALE){
		this -> Body -> ApplyForce(b2Vec2(0,1), this -> Body -> GetWorldCenter());
	}
*/
	this -> Body -> SetAwake(1);

	this -> xCoord = this -> Body -> GetPosition().x * SCALE;
	this -> yCoord = this -> Body -> GetPosition().y * SCALE;
	//printf("Stolen Object xCoord: %f, yCoord: %f\n", this -> xCoord, this -> yCoord);
	//printf("Stolen Object b2x   : %f, b2y:    %f\n", this -> Body -> GetPosition().x * SCALE, this -> Body -> GetPosition().y * SCALE);
	for (b2Body* BodyIterator = this -> World -> GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
        {
		printf("Obj %i is at x:%f y:%f\n", BodyIterator, BodyIterator -> GetPosition().x * SCALE, BodyIterator -> GetPosition().y * SCALE);
		printf("is active %i", this -> Body -> IsActive());
	}
	printf("\n");
}
