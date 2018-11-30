#include "Goal.h"

static const float SCALE = 30.f;

using namespace escape;

/*
* Constructor
*/
Goal::Goal(){
  this -> width = 250;
  this -> height = 55;

  this -> xCoord = 670;
  this -> yCoord = 570;
}

/*
* Sets the world for Box2D
* @param *World: current B2D world
*/
void Goal::setWorld(b2World* World){
	//Creates Box2D Body. Static body so that It won't move.
	this -> World = World;
	b2BodyDef BodyDef;
  BodyDef.position = b2Vec2(this -> xCoord/SCALE, this -> yCoord/SCALE);
  BodyDef.type = b2_staticBody;
  this -> Body = this -> World -> CreateBody(&BodyDef);

  b2PolygonShape shape;
  const float density = 100.f;

  shape.SetAsBox(10/SCALE, this -> height/2/SCALE, b2Vec2(this -> xCoord/SCALE, this -> yCoord/SCALE), 0);
  this -> Body -> CreateFixture(&shape, density);

  // shape.SetAsBox(this -> width/2/SCALE, 10/SCALE, b2Vec2(this -> xCoord/SCALE, (this -> yCoord + this -> height - 20)/SCALE), 0);
  // this -> Body -> CreateFixture(&shape, density);

  shape.SetAsBox(10/SCALE, this -> height/2/SCALE, b2Vec2((this -> xCoord + this -> width - 20)/SCALE, this -> yCoord/SCALE), 0);
  this -> Body -> CreateFixture(&shape, density);
}

/*
* Detects win
* @param &stolenObject: stolen object needed to detect collision
*/
bool Goal::detectWin(StolenObject &stolenObject){

  bool intersect = this -> bounds.intersects(stolenObject.bounds);
  bool bottom = (stolenObject.bounds.top + (stolenObject.radius * 2)) == 600? true: false;
  if(intersect && bottom){
    return true;
  }
  return false;
}
