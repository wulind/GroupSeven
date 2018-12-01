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
* Sets starting x and y for image in sprite sheet
*/
void Level::setBackgroundFile(const char *_backgroundFile, const char *_startX, const char *_startY){
  //Pull
  this -> backgroundFile = _backgroundFile;
  this -> startX = std::atoi(_startX);
  this -> startY = std::atoi(_startY);
}

/*
* Makes platforms available for level
* @param rotation: rotation in degrees of platform
* @param yPos: y axis position on screen
*/
void Level::makePlatform(int rotation, int xPos, int yPos, int width, int height, bool draggable){
  Platform platform(xPos, yPos, height, width);

  platform.setRotation(rotation);

  platform.draggable = draggable;

  this -> platforms.push_back(platform);

}

/*
* Sets Filename for stolen object
*/
void Level::setStolenObjectFile(const char *_stolenObjectFile){
  // this -> stolenObject = StolenObject(50, 100, 25, this -> World);
  this -> stolenObjectFile = _stolenObjectFile;
}

/*
* Sets the gravity for the level.
* @param g: gravity for the level. Negative gravity is up on the screen
*/
void Level::setGravity(float g){
  this -> gravity = g;
}
