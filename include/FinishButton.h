#ifndef FINISHBUTTON_H
#define FINISHBUTTON_H

#include "../include/GameState.h"
#include <SFML/Graphics.hpp>

namespace escape {
  class FinishButton{

    public:
       FinishButton();
       FinishButton(sf::RenderWindow *App);

       sf::RenderWindow* App;

       sf::Sprite button;
       sf::Texture texture;

       float scale;

       void update(GameState *state);

       void clickButton(GameState *state);
  };
}
#endif
