#include "Level.h"
using namespace escape;

Level::Level(){
  this -> base = Platform(0, 600, 10, 800);
<<<<<<< HEAD
=======
  this -> stolenObject = StolenObject(50, 100, 32);
  this -> finishButton = FinishButton();

>>>>>>> parent of 5446823... Merge pull request #22 from wulind/LindaWu/goal
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
void Level::setBackgroundFile(const char *_backgroundStartX, const char *_backgroundStartY){  
  this -> backgroundStartX = std::atoi(_backgroundStartX);
  this -> backgroundStartY = std::atoi(_backgroundStartY);
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
void Level::setStolenObjectFile(const char *_objStartX, const char *_objStartY){
  this -> objectStartX = std::atoi(_objStartX);
  this -> objectStartY = std::atoi(_objStartY);
  
  
}

/*
* Sets the gravity for the level.
* @param g: gravity for the level. Negative gravity is up on the screen
*/
void Level::setGravity(float g){
  this -> gravity = g;
}

/*
* Sets the stolen object for the level.
* @param x: xCoord for stolen object
* @param y: yCoord for stolen Object
* @param radius: radius for stolen object
*/
void Level::setStolenObject(int x, int y, int radius){
  this -> stolenObject = StolenObject(x, y, radius);
}
