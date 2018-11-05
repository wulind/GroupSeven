#ifndef PLATFORMMENU_H
#define PLATFORMMENU_H

#include "../include/GameState.h"
#include <SFML/Graphics.hpp>
//TODO: Merge with FinishButton
namespace escape{
  class PlatformMenu{

     private:
         sf::RenderWindow *App;
         //Graphical variables for the menu
         sf::Font font;
         sf::Texture menu;
         sf::Text title;
         //Graphical variables for the finish button
         sf::Texture buttonTexture;
         sf::Sprite finishButton;

         float scale;


     public:

        PlatformMenu();
        PlatformMenu(sf::RenderWindow *App);  
        void update(GameState *state);



        

  };
}
#endif
