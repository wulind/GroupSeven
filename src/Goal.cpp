#include "Goal.h"

static const float SCALE = 30.f;

using namespace escape;

/*
* Constructor
*/
Goal::Goal(){
  this -> width = 250;
  this -> height = 110;

  this -> xCoord = 350;
  this -> yCoord = 550;
}

/*
* Constructor
*/
Goal::Goal(int xCoord, int yCoord){
  this -> width = 250;
  this -> height = 110;

  this -> xCoord = xCoord;
  this -> yCoord = yCoord;
}

/*
* Sets the world for Box2D
* @param *World: current B2D world
*/
void Goal::setWorld(b2World* World){
	//Creates Box2D Body. Static body so that It won't move.
	b2BodyDef BodyDef;
  BodyDef.position = b2Vec2(this -> xCoord/SCALE, this -> yCoord/SCALE);
  BodyDef.type = b2_staticBody;
  this -> Body = World -> CreateBody(&BodyDef);

  b2PolygonShape shape;
  const float density = 100.f;

  shape.SetAsBox(2/SCALE, this -> height/4/SCALE, b2Vec2((-this -> width/2 + 4)/SCALE, this -> height/4/SCALE), 0);//Headlights of van
  this -> Body -> CreateFixture(&shape, density);

  shape.SetAsBox(10/SCALE, this -> height/SCALE, b2Vec2((-this -> width/2 + 55)/SCALE, this -> height/2/SCALE), 0);//Left van body
  this -> Body -> CreateFixture(&shape, density);

  shape.SetAsBox(this -> width - 10/SCALE, 5/SCALE, b2Vec2((-this -> width/2 + 10)/SCALE, (this -> height/2 - 15)/SCALE), 0);//Bottom van body
  this -> Body -> CreateFixture(&shape, density);

  shape.SetAsBox(5/SCALE, this -> height/SCALE, b2Vec2((this -> width/2 - 20)/SCALE, this -> height/2/SCALE), 0);//Right van body & butt of the van
  this -> Body -> CreateFixture(&shape, density);
}

/*
* Detects win
* @param &stolenObject: stolen object needed to detect collision
*/
int Goal::detectWin(StolenObject &stolenObject){
  //Checks if object is awake, and if it is moving slow enough, then kill it if its moving too slowly
  if(stolenObject.Body -> IsAwake()){
    if(stolenObject.Body -> GetLinearVelocity().y == 0 && abs(stolenObject.Body -> GetLinearVelocity().x) < 1 && !(stolenObject.Body -> GetLinearVelocity().y == 0 && stolenObject.Body -> GetLinearVelocity().x == 0)){
      stolenObject.killSpeed();
    }
    return -1;
  }

  //Determines the left, right, and top boundaries
  bool left = stolenObject.bounds.left > this -> bounds.left ? true: false;
  bool right = stolenObject.bounds.left + stolenObject.bounds.width < this -> bounds.left + this -> width ? true: false;;
  bool top = stolenObject.bounds.top > this -> bounds.top ? true: false;

  //Detects of ball is in goal and alive
  if(left && right && top){
    if (stolenObject.health != 0){
      return 1;
    }
  }

  return 0;
}
