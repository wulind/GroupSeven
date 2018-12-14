#ifndef PLATFORMMENU_H
#define PLATFORMMENU_H

#include <SFML/Graphics.hpp>
#include "GameState.h"

namespace escape{
        //Holds variables and methods for the graphical side menu (which holds the platforms to drag) and the finish button.
  class PlatformMenu{

  public:
     //Graphical variables for the menu
     sf::Text title;

     //Constructor
    PlatformMenu();
  };
}
#endif
