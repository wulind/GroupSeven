#include "../include/PlatformMenu.h"

using namespace escape;
/*
 * Constructor
 * */
PlatformMenu::PlatformMenu(){}
/*
 * Constructor with App RenderWindow
 */
PlatformMenu::PlatformMenu(sf::RenderWindow *App){
  this -> App = App;
  this -> scale = .2f;
}

/*
 * Update the grahics of the side menu and the finish button
 */
void PlatformMenu::update(GameState *state){
  int screenX = 800; //TODO: make it more flexible to App's changing frame
  int screenY = 600;

  int relativeX = .8 * this -> App->getSize().x;
  int relativeY = .85 * this -> App->getSize().y;

  if (!menuTexture.loadFromFile("../data/menutexture.png")){
    // TODO:error...
  }
  if (!font.loadFromFile("../data/arial.ttf")){
    // TODO:error...
  }

  //Set text which is placed over the side menu
  this -> title.setFont(font);
  this -> title.setPosition(screenX-165,5);
  this -> title.setString("Click & Drag");
  this -> title.setCharacterSize(24);
  this -> title.setFillColor(sf::Color::White);

  //Sets the texture for the side menu which is displayed on the right side of the screen
  this -> menu.setTextureRect(sf::IntRect(125, 300, 180, 600));
  this -> menu.setPosition(sf::Vector2f(screenX-180, 0)); // absolute position
  this -> menu.setTexture(menuTexture);



  //Used with the mouse click event when resizing the window to keep the button coordinates relative
  if (!buttonTexture.loadFromFile("../data/finish_button.png")){
    // error
  }

  //Game is in design mode
  if(state -> getState() == state -> SETUP){//TODO: fix
    //Setup finish button
    finishButton.setTexture(buttonTexture);
    finishButton.setScale(sf::Vector2f(scale, scale));
    finishButton.setPosition(relativeX, relativeY);

    this -> App -> draw(finishButton);

  }
}
