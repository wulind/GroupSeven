#include "Options.h"

using namespace escape;

Options::Options(){}

void Options::adjustVolume(GameState &state){
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
{
    this -> masterVolume--;
}
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
  this -> masterVolume++;
}
  if(this->masterVolume < 0){
    masterVolume = 0;
  }
  if(this->masterVolume > 1){
    masterVolume = 1;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
    state.setState(GameState::State::TITLE);
  }


}

char* Options::getVolume(){
    switch(this -> masterVolume){
        case 0:
          return "Volume: Off";
        break;
        case 1:
          return "Volume: On";
        break;
    }
}

bool Options::volumeOn(){
  if(masterVolume == 0)
    return false;
  return true;

}
