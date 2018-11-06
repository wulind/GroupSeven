#include "../include/FinishButton.h"

using namespace escape;

FinishButton::FinishButton(){}

FinishButton::FinishButton(sf::RenderWindow *App){
  this -> App = App;
  this -> scale = .2f;
}

void FinishButton::update(GameState &state){
  //Position of the finish button relative to the screen size defined. (Set to 800,600 by default).
  int relativeX = .8 * this -> App->getSize().x;
  int relativeY = .85 * this -> App->getSize().y;

  //Used with the mouse click event when resizing the window to keep the button coordinates relative
  if (!texture.loadFromFile("../data/finish_button.png")){
    // error
  }

  //Game is in design mode
  if(state.getState() == GameState::State::SETUP){
    //Setup finish button
    button.setTexture(texture);
    button.setScale(sf::Vector2f(scale, scale));
    button.setPosition(relativeX, relativeY);

    sf::FloatRect size = button.getLocalBounds();

    App -> draw(button);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        //If left mouse click, get mouse
        int clickX = sf::Mouse::getPosition(*this -> App).x;
        int clickY = sf::Mouse::getPosition(*this -> App).y;

        if(clickX >= relativeX && clickX <= relativeX+size.width && clickY >= relativeY && clickY <= relativeY+size.height){
          //If the mouse clicks on the finish button then call clickButton()
          clickButton(state);
        }
      }
  }
}

void FinishButton::clickButton(GameState &state){
    //Finish button is pressed
    //Gamestate is now play
     state.setState(GameState::State::PLAY);
}
