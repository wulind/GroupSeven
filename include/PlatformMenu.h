#ifndef PLATFORMMENU_H
#define PLATFORMMENU_H

#include "../include/GameState.h"
#include <SFML/Graphics.hpp>
//TODO: Merge with FinishButton
namespace escape{
  class PlatformMenu{

     private:
         sf::RenderWindow *App;

         sf::Font font;
         sf::Texture texture;

     public:

        PlatformMenu();
        PlatformMenu(sf::RenderWindow *App);

        sf::Sprite menu;
        sf::Text title;

        void updateMenu();

        // FinishButton();
        // FinishButton(sf::RenderWindow *App);

        sf::RenderWindow* App;

        sf::Sprite button;
        sf::Texture texture;

        float scale;

        void updateFinish(GameState *state);

  };
}
#endif
