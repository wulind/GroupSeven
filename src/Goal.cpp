#include "Goal.h"
#include <math.h>
#include <iostream>

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

  shape.SetAsBox(10/SCALE, this -> height/SCALE, b2Vec2((-this -> width/2 + 10)/SCALE, this -> height/2/SCALE), 0);
  this -> Body -> CreateFixture(&shape, density);

  shape.SetAsBox(this -> width/SCALE, 5/SCALE, b2Vec2((-this -> width/2 + 10)/SCALE, (this -> height/2 - 5)/SCALE), 0);
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &shape;
  fixtureDef.density = density;
  fixtureDef.friction = 1.0f;
  this -> Body -> CreateFixture(&fixtureDef);

  shape.SetAsBox(10/SCALE, this -> height/SCALE, b2Vec2((this -> width/2 - 10)/SCALE, this -> height/2/SCALE), 0);
  this -> Body -> CreateFixture(&shape, density);
}

/*
* Detects win
* @param &stolenObject: stolen object needed to detect collision
*/
int Goal::detectWin(StolenObject &stolenObject){
  std::cout << stolenObject.Body -> GetLinearVelocity().x << ", " << stolenObject.Body -> GetLinearVelocity().y << std::endl;

  if(stolenObject.Body -> IsAwake()){
    if(stolenObject.Body -> GetLinearVelocity().y == 0 && abs(stolenObject.Body -> GetLinearVelocity().x) < 1){
      stolenObject.Body -> SetLinearVelocity(b2Vec2(0.f,0.f));
    }
    return -1;
  }

  bool left = stolenObject.bounds.left > this -> bounds.left ? true: false;
  bool right = stolenObject.bounds.left + stolenObject.bounds.width < this -> bounds.left + this -> width ? true: false;;
  bool top = stolenObject.bounds.top > this -> bounds.top ? true: false;

  if(left && right && top){
    return 1;
  }

  return 0;

}
