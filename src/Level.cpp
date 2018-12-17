#include "Level.h"
using namespace escape;

Level::Level(){}

/*
* Sets the world for Box2D for current level
* @param *World: current B2D world
*/
void Level::setWorld(b2World* World){
  int i = 0;
  for (i; i < this -> platforms.size(); i++){
    this -> platforms[i].setWorld(World);
  }

  i = 0;
  for (i; i < this -> obstacles.size(); i++){
    this -> obstacles[i].setWorld(World);
  }

  this -> stolenObject.setWorld(World);
  this -> goal.setWorld(World);

  World -> SetContactListener(&this -> contactListener);
}

/*
* Sets starting x and y for image in sprite sheet
* @param *_backgroundStartX: starting x coordinate on sprite sheet of background
* @param *_backgroundStartY: starting y coordinate on sprite sheet of background
*/
void Level::setBackgroundFile(const char *_backgroundStartX, const char *_backgroundStartY){
  this -> backgroundStartX = std::atoi(_backgroundStartX);
  this -> backgroundStartY = std::atoi(_backgroundStartY);
}

/*
* Makes platforms available for level
* @param rotation: rotation in degrees of platform
* @param xPos: x axis position on screen
* @param yPos: y axis position on screen
* @param width: width of platform
* @param height: height of platform
* @param *color: pointer to array where array values are [red, green, blue, alpha]
* @param draggable: true if platform can be dragged by user
*/
void Level::makePlatform(int rotation, int xPos, int yPos, int width, int height, int* color, bool draggable){
  Platform platform(xPos, yPos, height, width);
  platform.setRotation(rotation);
  platform.color = sf::Color(color[0], color[1], color[2], color[3]);

  if(draggable){
    this -> platforms.push_back(platform);
  }
  else{
    platform.show = true;
    this -> obstacles.push_back(platform);
  }
}

/*
* Sets starting x and y for image in sprite sheet
* @param *_objStartX: starting x coordinate on sprite sheet of object
* @param *_objStartY: starting y coordinate on sprite sheet of object
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
  this -> obstacles.clear();
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
* @param x: x coordinate for stolen object
* @param y: y coordinate for stolen object
* @param radius: Radius of stolen object
* @param restitution: bounciness of stolen object
*/
void Level::setStolenObject(int x, int y, int radius, float restitution){
  this -> stolenObject = StolenObject(x, y, radius, restitution);
}

/*
* Sets the goal for the level.
* @param xCoord: x coordinate for goal
* @param yCoord: y coordinate for goal
*/
void Level::setGoal(int xCoord, int yCoord){
  this -> goal = Goal(xCoord, yCoord);
}
