#include "../include/PlatformMenu.h"

using namespace escape;

PlatformMenu::PlatformMenu(){}

PlatformMenu::PlatformMenu(sf::RenderWindow *App){
  this -> App = App;
}

void PlatformMenu::update(){
  int screenX = 800; //TODO: make it more flexible to App's changing frame
  int screenY = 600;

  /*
  if (!texture.loadFromFile("../data/menutexture.png")){
    // TODO:error...
  }
  if (!font.loadFromFile("../data/arial.ttf")){
    // TODO:error...
  }
  */

  this -> title.setFont(font);
  this -> title.setPosition(screenX-165,5);
  this -> title.setString("Click & Drag");
  this -> title.setCharacterSize(24);
  this -> title.setFillColor(sf::Color::White);

  this -> menu.setTextureRect(sf::IntRect(125, 300, 180, 600));
  this -> menu.setPosition(sf::Vector2f(screenX-180, 0)); // absolute position
  this -> menu.setTexture(texture);
}
