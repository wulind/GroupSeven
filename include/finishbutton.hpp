#ifndef Finishbutton_h
#define Finishbutton_h
#include "gameState.hpp"

class FinishButton{

public:
    
    sf::Sprite button;
    sf::Texture texture;
    float scale = .2f;
    
    int posX;
    int posY;
    
    int clickX;
    int clickY;
    
    int screenX;
    int screenY;

    void update(sf::RenderWindow *App, GameState *gs){
        
    }

    void clickButton(GameState *gs){

    }
};
#endif
