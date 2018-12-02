#include "Level.h"
using namespace escape;

Level::Level(){
  // this -> platforms.push_back(Platform(0, 300, 10, 200, this -> World));//TODO: move into respective places
  this -> base = Platform(0, 600, 10, 800);
  this -> stolenObject = StolenObject(50, 100, 32);

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
  this -> goal.setWorld(World);
}

/*
* Sets Filename for background
* Sets starting x and y for image in sprite sheet
*/
void Level::setBackgroundFile(const char *_backgroundStartX, const char *_backgroundStartY){
  this -> backgroundStartX = std::atoi(_backgroundStartX);
  this -> backgroundStartY = std::atoi(_backgroundStartY);
}

/*
* Makes platforms available for level
* @param rotation: rotation in degrees of platform
* @param yPos: y axis position on screen
*/
void Level::makePlatform(int rotation, int yPos){
  Platform platform(700, yPos, 10, 100);

  platform.setRotation(rotation);

  this -> platforms.push_back(platform);

}

/*
* Sets Filename for stolen object
*/
void Level::setStolenObjectFile(const char *_objStartX, const char *_objStartY){
  this -> stolenObject.spriteSheetStartX = std::atoi(_objStartX);
  this -> stolenObject.spriteSheetStartY = std::atoi(_objStartY);
}

/*
* Clears the level object for the next level
*/
void Level::clearLevel(){
  this -> platforms.clear();
}
