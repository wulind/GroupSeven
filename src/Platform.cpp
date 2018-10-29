#include "../include/Platform.h"

static const float SCALE = 30.f;

using namespace escape;

Platform::Platform(){
	this -> xCoord = 50;
	this -> yCoord = 50;
  	this -> mouseDragOffsetX = 0;
	this -> mouseDragOffsetY = 0;

	this -> height = 20;
	this -> width = 100;

	this -> isBeingDragged = false;

	this -> color = sf::Color::White;
}

Platform::Platform(b2World* World){
	this -> xCoord = 50;
	this -> yCoord = 50;
  	this -> mouseDragOffsetX = 0;
	this -> mouseDragOffsetY = 0;

	this -> height = 20;
	this -> width = 100;

	this -> isBeingDragged = false;

	this -> color = sf::Color::White;

	this -> World = World;

	b2BodyDef BodyDef;
    	BodyDef.position = b2Vec2(this -> xCoord/SCALE, this -> yCoord/SCALE);
   	BodyDef.type = b2_dynamicBody;
    	b2Body* Body = this -> World -> CreateBody(&BodyDef);
	
	b2PolygonShape Shape;
	Shape.SetAsBox((32.f/2)/SCALE, (32.f/2)/SCALE);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.f;
	FixtureDef.friction = 0.7f;
	FixtureDef.shape = &Shape;
	Body->CreateFixture(&FixtureDef);
	this -> Body = Body;

}

void Platform::updateDragPosition(float mouseX, float mouseY) {
	if (!this -> isBeingDragged){
		this -> xCoord = this -> Body -> GetPosition().x;
		this -> yCoord = this -> Body -> GetPosition().y;
		return;
	}

	//this -> Body -> SetTransform(b2Vec2(this -> xCoord, this -> yCoord),this -> Body -> GetAngle());
	this -> xCoord = mouseX - mouseDragOffsetX;
	this -> yCoord = mouseY - mouseDragOffsetY;
	this -> Body -> SetTransform(b2Vec2(this -> xCoord, this -> yCoord),this -> Body -> GetAngle());
}
