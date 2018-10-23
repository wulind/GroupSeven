#ifndef menu_h
#define menu_h
#include "gameState.hpp"

class Menu{
    public:
        sf::Texture texture;
        sf::Sprite menu;
        sf::Font font;
        sf::Text menuTopText;

        int screenX;
        int screenY;

    
        //Menu();


    void update(sf::RenderWindow *App, GameState *gs);
};


#endif
