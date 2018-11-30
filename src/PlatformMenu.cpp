#include "../include/PlatformMenu.h"

using namespace escape;
/*
 * Constructor
 */
PlatformMenu::PlatformMenu(){
  this -> title.setPosition(635, 5);
  this -> title.setString("Click & Drag");
  this -> title.setCharacterSize(24);
  this -> title.setFillColor(sf::Color::White);
}
