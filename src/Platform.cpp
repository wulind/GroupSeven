#include "../include/Platform.h"

static const float SCALE = 30.f;

using namespace escape;

Platform::Platform(){};

Platform::Platform(float x, float y, int height, int width, b2World* World){
	//TODO: Update this to be in the menu
	this -> xCoord = x;
	this -> yCoord = y;
  this -> mouseDragOffsetX = 0;
	this -> mouseDragOffsetY = 0;

	this -> height = height;
	this -> width = width;

	this -> isBeingDragged = false;

	this -> color = sf::Color::White;

	this -> World = World;

	b2BodyDef BodyDef;
    	BodyDef.position = b2Vec2(x/SCALE, y/SCALE);
   	BodyDef.type = b2_staticBody;
    	b2Body* Body = this -> World -> CreateBody(&BodyDef);
	
	b2PolygonShape Shape;
	Shape.SetAsBox((((float)height)/2)/SCALE, ((float)width/2)/SCALE);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.f;
	FixtureDef.shape = &Shape;
	Body->CreateFixture(&FixtureDef);
	this -> Body = Body;
}


void Platform::updateDragPosition(float mouseX, float mouseY) {
	if (!this -> isBeingDragged){
		this -> xCoord = this -> Body -> GetPosition().x * SCALE;
		this -> yCoord = this -> Body -> GetPosition().y * SCALE;
		return;
	}

	//this -> Body -> SetTransform(b2Vec2(this -> xCoord, this -> yCoord),this -> Body -> GetAngle());
	this -> xCoord = mouseX - mouseDragOffsetX;
	this -> yCoord = mouseY - mouseDragOffsetY;
	this -> Body -> SetTransform(b2Vec2(this -> xCoord / SCALE, this -> yCoord / SCALE), 0);
}
