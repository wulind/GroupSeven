#ifndef FINISHBUTTON_H
#define FINISHBUTTON_H

#include "../include/GameState.h"
#include <SFML/Graphics.hpp>

namespace escape {
  class FinishButton{

    public:
       FinishButton();

       sf::Text button;

       float scale;
       bool show;

       void changeToPlay(sf::Vector2i mousePosition, GameState &state);
  };
}
#endif
