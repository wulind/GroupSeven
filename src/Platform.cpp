#include "../include/Platform.h"
#include <iostream>


static const float SCALE = 30.f;

using namespace escape;

Platform::Platform(){}

/*
* Constructor
* @param x: x coordinate of platform
* @param y: y coordinate of platform
* @param height: height of platform
* @param width: width of platform
* @param World: Box2D World where platform is to be placed
*/
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

	float h = (float) height;
	float w = (float) width;

	//Creates Box2D Body.  Static body so that It won't move.
	b2BodyDef BodyDef;
  BodyDef.position = b2Vec2(x/SCALE, y/SCALE);
  BodyDef.type = b2_staticBody;
  b2Body* Body = this -> World -> CreateBody(&BodyDef);

	// //Add a rectangle to go with the platform body
	b2PolygonShape Shape;
	Shape.SetAsBox((float)(width/2)/SCALE, (float)(height/2)/SCALE);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 100.f;
	FixtureDef.shape = &Shape;
	Body->CreateFixture(&FixtureDef);
	this -> Body = Body;

}


/*
* Updates position of platform when it's being dragged across the screen
* @param mouseX: x coordinate of mouse Position
* @param mouseY: y coordinate of mouse Position
*/
void Platform::updateDragPosition(float mouseX, float mouseY) {
	//Need to update platform based on Box2D if not being dragged
	if (!this -> isBeingDragged){
		this -> xCoord = this -> Body -> GetPosition().x * SCALE;
		this -> yCoord = this -> Body -> GetPosition().y * SCALE;
	}
	else{
		this -> xCoord = mouseX - mouseDragOffsetX;
		this -> yCoord = mouseY - mouseDragOffsetY;
		this -> Body -> SetTransform(b2Vec2(this -> xCoord / SCALE, this -> yCoord / SCALE), M_PI);
	}
	return;
}
