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
StolenObject::StolenObject(float x, float y, int radius, b2World* World){
	this -> xCoord = x;
	this -> yCoord = y;

	this -> radius = radius;

	this -> color = sf::Color::White;

	float r = (float) radius;

	//Box2D Information
	this -> World = World;

	//Box2D body with a dynamic body so it moves.
	b2BodyDef BodyDef;
  BodyDef.position = b2Vec2(x/SCALE, y/SCALE);
  BodyDef.type = b2_dynamicBody;
  b2Body* Body = this -> World -> CreateBody(&BodyDef);

	//Shape is a circle with radius r
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


/*
* Update the Position of a Stolen Object based on Box2D Physics.
*/
void StolenObject::UpdatePosition(){
	//Set body to awake in case of it being 0 velocity in both x and y direction to prevent
	//Freezing
	this -> Body -> SetAwake(1);

	this -> xCoord = this -> Body -> GetPosition().x * SCALE;
	this -> yCoord = this -> Body -> GetPosition().y * SCALE;

	/*Keeping this Debug information for now to keep track of b2World Objects
	for (b2Body* BodyIterator = this -> World -> GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
        {
		printf("Obj %i is at x:%f y:%f\n", BodyIterator, BodyIterator -> GetPosition().x * SCALE, BodyIterator -> GetPosition().y * SCALE);
		printf("is active %i", this -> Body -> IsActive());
	}
	printf("\n");
	*/
}
