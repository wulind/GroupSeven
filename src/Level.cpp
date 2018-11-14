#include "Level.h"

using namespace escape;

Level::Level(){}

Level::Level(b2World* World){
  this -> World = World;
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
*/
void Level::makePlatform(int platform){
  //for (i; i < platform; i++){

  this -> platform = Platform(50, 50, 10, 50, this -> World);
  this -> base = Platform(0, 550, 10, 600, this -> World);
  //}
}

/*
* Sets Filename for stolen object
*/
void Level::setStolenObjectFile(const char *_stolenObjectFile){
  this -> stolenObject = StolenObject(50, 100, 25, this -> World);
  this -> stolenObjectFile = _stolenObjectFile;
}
