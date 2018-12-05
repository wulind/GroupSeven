#include "Options.h"

using namespace escape;

Options::Options(){}

void Options::adjustVolume(){
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
{
    this -> masterVolume--;
    // break;
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
{
  this -> masterVolume++;
  // break;
}
if(this->masterVolume < 0){
  masterVolume = 0;
}
if(this->masterVolume > 1){
  masterVolume = 1;
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
