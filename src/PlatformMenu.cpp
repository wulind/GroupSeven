#include "../include/PlatformMenu.h"

using namespace escape;

PlatformMenu::PlatformMenu(){}

PlatformMenu::PlatformMenu(sf::RenderWindow *App){
  this -> App = App;
  this -> scale = .2f;
}

void PlatformMenu::update(sf::RenderWindow *App, GameState *state){
  int screenX = 800; //TODO: make it more flexible to App's changing frame
  int screenY = 600;

  if (!menu.loadFromFile("../data/menutexture.png")){
    // TODO:error...
  }
  if (!font.loadFromFile("../data/arial.ttf")){
    // TODO:error...
  }

  this -> title.setFont(font);
  this -> title.setPosition(screenX-165,5);
  this -> title.setString("Click & Drag");
  this -> title.setCharacterSize(24);
  this -> title.setFillColor(sf::Color::White);

  this -> menu.setTextureRect(sf::IntRect(125, 300, 180, 600));
  this -> menu.setPosition(sf::Vector2f(screenX-180, 0)); // absolute position
  this -> menu.setTexture(menu);



  //Position of the finish button relative to the screen size defined. (Set to 800,600 by default).
  int relativeX = .8 * this -> App->getSize().x;
  int relativeY = .85 * this -> App->getSize().y;

  //Used with the mouse click event when resizing the window to keep the button coordinates relative
  if (!buttonTexture.loadFromFile("../data/finish_button.png")){
    // error
  }

  //Game is in design mode
  if(state -> play == 0){
    //Setup finish button
    finishButton.setTexture(buttonTexture);
    finishButton.setScale(sf::Vector2f(scale, scale));
    finishButton.setPosition(relativeX, relativeY);

    sf::FloatRect size = finishButton.getLocalBounds();

    this -> App -> draw(fini);

  }
}