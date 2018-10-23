
#ifndef menu_h
#define menu_h
#include "menu.hpp"
#include "gameState.hpp"
class Menu{
    public:
    sf::Texture texture;
    sf::Sprite menu;
    sf::Font font;
    sf::Text menuTopText;

    int screenX = 800;
    int screenY = 600;

    
    void update(sf::RenderWindow *App, GameState *gs){
        //Game is in design mode
        if(gs->play == 0){
            //Load texture for side menu and font for text
            if (!texture.loadFromFile("../data/menutexture.png"))
            {
                // error...
            }
            if (!font.loadFromFile("../data/sansation.ttf"))
            {
                // error...
            }
            
            menuTopText.setFont(font);
            menuTopText.setPosition(screenX-165,5);
            menuTopText.setString("Click & Drag");
            menuTopText.setCharacterSize(24);
            menuTopText.setFillColor(sf::Color::White);
            
            menu.setTextureRect(sf::IntRect(125, 300, 180, 600));
            menu.setPosition(sf::Vector2f(screenX-180, 0)); // absolute position
            menu.setTexture(texture);
            
            App->draw(menu);
            App->draw(menuTopText);
            
            
            
            
        }
        
        
        
    }
    
};


#endif /* menu_h */
