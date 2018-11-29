#include "Goal.h"

static const float SCALE = 30.f;

using namespace escape;

/*
* Constructor
*/
Goal::Goal(){
  this -> width = 250;
  this -> height = 150;

  this -> xCoord = 670;
  this -> yCoord = 520;
}

/*
* Sets the world for Box2D
* @param *World: current B2D world
*/
void Goal::setWorld(b2World* World){
	//Creates Box2D Body.  Static body so that It won't move.
	this -> World = World;
	b2BodyDef BodyDef;
  BodyDef.position = b2Vec2(this -> xCoord/SCALE, this -> yCoord/SCALE);
  BodyDef.type = b2_staticBody;
  this -> Body = this -> World -> CreateBody(&BodyDef);

	//Add a rectangle to go with the platform body TODO:Finish
  b2Vec2 vertices[5];
  vertices[0].Set(this -> xCoord,  this -> yCoord);
  vertices[1].Set(this -> xCoord,  this -> yCoord);
  vertices[2].Set(this -> xCoord,  this -> yCoord);
  vertices[3].Set(this -> xCoord,  this -> yCoord);
  vertices[4].Set(this -> xCoord,  this -> yCoord);

  b2PolygonShape shape;
  polygonShape.Set(vertices, 5);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 100.f;
	FixtureDef.shape = &Shape;
	this -> Body -> CreateFixture(&FixtureDef);
}

bool Goal::detectWin(StolenObject &stolenObject){

  bool intersect = this -> bounds.intersects(stolenObject.bounds);
  bool bottom = (stolenObject.bounds.top + (stolenObject.radius * 2)) == 600? true: false;
  if(intersect && bottom){
    return true;
  }
  return false;
}
