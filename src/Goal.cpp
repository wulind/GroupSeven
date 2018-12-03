#include "Goal.h"
#include <math.h>

static const float SCALE = 30.f;

using namespace escape;

/*
* Constructor
*/
Goal::Goal(){
  this -> width = 250;
  this -> height = 110;

  this -> xCoord = 350;//670
  this -> yCoord = 550;//570
}

/*
* Constructor
*/
Goal::Goal(int xCoord, int yCoord){
  this -> width = 250;
  this -> height = 110;

  this -> xCoord = xCoord;//670
  this -> yCoord = yCoord;//570
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

  shape.SetAsBox(10/SCALE, this -> height/SCALE, b2Vec2((-this -> width/2 + 10)/SCALE, this -> height/2/SCALE), 0);
  this -> Body -> CreateFixture(&shape, density);

  shape.SetAsBox(this -> width/SCALE, 5/SCALE, b2Vec2((-this -> width/2 + 10)/SCALE, (this -> height/2 - 5)/SCALE), 0);
  this -> Body -> CreateFixture(&shape, density);

  shape.SetAsBox(10/SCALE, this -> height/SCALE, b2Vec2((this -> width/2 - 10)/SCALE, this -> height/2/SCALE), 0);
  this -> Body -> CreateFixture(&shape, density);

  this -> World = World;
}

/*
* Detects win
* @param &stolenObject: stolen object needed to detect collision
*/
int Goal::detectWin(StolenObject &stolenObject){
  if(stolenObject.Body -> IsAwake()){return -1;}

  bool intersect = this -> bounds.intersects(stolenObject.bounds);
  bool top = stolenObject.bounds.top < this -> yCoord ? true: false;
  if(intersect && top){
    return 1;
  }
  return 0;

}
