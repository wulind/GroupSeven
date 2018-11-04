#include "../include/StolenObject.h"

using namespace escape;

StolenObject::StolenObject(){}

StolenObject::StolenObject(float x, float y, int radius){
  this -> xCoord = x;
	this -> yCoord = y;

  this -> radius = radius;

  this -> color = sf::Color::White;
}
