#ifndef PLATFORMMENU_H
#define PLATFORMMENU_H

#include "../include/GameState.h"
#include <SFML/Graphics.hpp>

namespace escape{
        //Holds variables and methods for the graphical side menu (which holds the platforms to drag) and the finish button.
  class PlatformMenu{

     private:
         sf::RenderWindow *App;
         //Graphical variables for the menu
         sf::Font font;
         sf::Text title;
         sf::Sprite menu;
         sf::Texture menuTexture;
         //Graphical variables for the finish button
         sf::Texture buttonTexture;
         sf::Sprite finishButton;
         float scale;


     public:
         //Constructor
        PlatformMenu();
        PlatformMenu(sf::RenderWindow *App);  
        //Updates the visuals of the platform menu based on the game state
        void update(GameState *state);
  };
}
#endif
