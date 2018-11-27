#ifndef PLATFORMMENU_H
#define PLATFORMMENU_H

#include <SFML/Graphics.hpp>
#include "GameState.h"

namespace escape{
        //Holds variables and methods for the graphical side menu (which holds the platforms to drag) and the finish button.
  class PlatformMenu{

  private:

         //Graphical variables for the finish button
         sf::Texture buttonTexture;
         sf::Sprite finishButton;
         float scale;

  public:
         //Graphical variables for the menu
         sf::Font font;
         sf::Text title;
         sf::RectangleShape menu;

         //Constructor
        PlatformMenu();
  };
}
#endif
