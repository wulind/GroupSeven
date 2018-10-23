#include "menu.hpp"
#include <iostream>

   /* Menu::Menu(){
        int screenX = 800;
        int screenY = 600;
    }
*/
    void Menu::update(sf::RenderWindow *App, GameState *gs){
       int screenX = 800;
        int screenY = 600;
        
        //Game is in design mode
        if(gs->play == 0){
            //Load texture for side menu and font for text
            if (!texture.loadFromFile("../data/menutexture.png"))
            {
                std::cout<<"Error loading menu texture \n";
                // error...
            }
            if (!font.loadFromFile("../data/sansation.ttf"))
            {
                std::cout<<"Error font\n";
                // error...
            }
            
            this -> menuTopText.setFont(font);
            this -> menuTopText.setPosition(screenX-165,5);
            this -> menuTopText.setString("Click & Drag");
            this -> menuTopText.setCharacterSize(24);
            this -> menuTopText.setFillColor(sf::Color::Black);
            
            this -> menu.setTextureRect(sf::IntRect(125, 300, 180, 600));
            this -> menu.setPosition(sf::Vector2f(screenX-180, 0)); // absolute position
            this -> menu.setTexture(texture);
            
            App->draw(menu);
            App->draw(menuTopText);
            
            
            
            
        }
        
        
        
    }
  
