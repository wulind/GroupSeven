#ifndef PLATFORMMENU_H
#define PLATFORMMENU_H

#include "../include/GameState.h"
#include <SFML/Graphics.hpp>
//TODO: Merge with FinishButton
namespace escape{
  class PlatformMenu{
     public:
         PlatformMenu();
         PlatformMenu(sf::RenderWindow *App);

         sf::RenderWindow *App;

         sf::Texture texture;
         sf::Sprite menu;
         sf::Font font;
         sf::Text title;

         int screenX;
         int screenY;

         void update(GameState *state);
  };
}
#endif
