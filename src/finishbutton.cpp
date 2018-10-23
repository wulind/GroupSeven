#include "../finishbutton.hpp"

class FinishButton{




    

    FinishButton::FinishButton() :
        scale(.2f),
        screenX(800),
        screenY(600) {

        
    }

    finishbutton::update(sf::RenderWindow *App, GameState *gs){
        posX = .85*screenX;
        posY = .85*screenY;
        
        //Position of the finish button relative to the screen size defined. (Set to 800,600 by default).
        
        int relativeX = .8*App->getSize().x;
        int relativeY = .85*App->getSize().y;
        //Used with the mouse click event when resizing the window to keep the button coordinates relative
        
        if (!texture.loadFromFile("../data/finish_button.png")) {
                    // error...
        }
        
        //Game is in design mode
        if(gs->play == 0){
            //Setup finish button icon
            button.setTexture(texture);
            button.setScale(sf::Vector2f(scale, scale));
            button.setPosition(posX,posY);
            sf::FloatRect size = button.getLocalBounds();
            App->draw(button);
            
            
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                //If left mouse click, get mouse coordinates
                clickX = sf::Mouse::getPosition(*App).x;
                clickY = sf::Mouse::getPosition(*App).y;
                
                if(clickX >= relativeX && clickX <= relativeX+size.width && clickY >= relativeY && clickY <= relativeY+size.height){
                    //If the mouse clicks on the finish button then call clickButton()
                    clickButton(gs);
                }
            }
            

        }
    }

    finishbutton::clickButton(GameState *gs){
        //Finish button is pressed
        //Gamestate is now play
    	gs->play = 1;
    }
}