#include "Goal.h"

using namespace escape;

/*
* Constructor
*/
Goal::Goal(){
  this -> width = 250;
  this -> height = 150;

  this -> xCoord = 550;
  this -> yCoord = 450;
}

bool Goal::detectWin(StolenObject &stolenObject){

  bool intersect = this -> bounds.intersects(stolenObject.bounds);
  bool bottom = (stolenObject.bounds.top + (stolenObject.radius * 2)) == 600? true: false;
  if(intersect && bottom){
    return true;
  }
  return false;
}
