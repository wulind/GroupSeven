#include "Level.h"

using namespace escape;

Level::Level(){
  // this -> platforms.push_back(Platform(0, 300, 10, 200, this -> World));//TODO: move into respective places
  this -> base = Platform(0, 600, 10, 800);
  this -> stolenObject = StolenObject(50, 100, 25);
  this -> finishButton = FinishButton();

}

/*
* Sets the world for Box2D for current level
* @param *World: current B2D world
*/
void Level::setWorld(b2World* World){
  int i = 0;
  for (i; i < this -> platforms.size(); i++){
    this -> platforms[i].setWorld(World);
  }
  this -> base.setWorld(World);
  this -> stolenObject.setWorld(World);
}

/*
* Sets Filename for background
* TODO: put all of this info into the respective classes
*/
void Level::setBackgroundFile(const char *_backgroundFile){
  this -> backgroundFile = _backgroundFile;
}

/*
* Makes platforms available for level
* @param count: the amount of platforms needed in the level
*/
void Level::makePlatform(int count){
  int i = 0;
  for (i; i < count; i++){
    this -> platforms.push_back(Platform(100, 300, 10, 100));//DO NOT CHANGER
  }
}

/*
* Sets Filename for stolen object
*/
void Level::setStolenObjectFile(const char *_stolenObjectFile){
  // this -> stolenObject = StolenObject(50, 100, 25, this -> World);
  this -> stolenObjectFile = _stolenObjectFile;
}
