#include "../include/StolenObject.h"

using namespace escape;

StolenObject::StolenObject(){}

/*
* Constructor
* @param x: x coordinate of stolen object
* @param y: y coordinate of stolen object
* @param radius: radius of stolen object
*/
StolenObject::StolenObject(float x, float y, int radius){
  this -> xCoord = x;
	this -> yCoord = y;

  this -> radius = radius;

  this -> color = sf::Color::White;
}
