#include "LevelSelect.h"

using namespace escape;

/*
* Constructor
* @param *App: Render Window
*/
LevelSelect::LevelSelect(){
}

/* Draws the background image into a texture
 * @param *App: pointer to game window
 */
void LevelSelect::drawBackground(sf::RenderWindow *App){
	//Load the background map as a texture
    sf::Texture mapTexture;
    if (!mapTexture.loadFromFile("../data/LevelSelectionBlank.png")) {

    }
    //Use the texture as a sprite
    sf::Sprite mapSprite(mapTexture);
    mapSprite.setScale(this -> screenX / this -> imageX, this -> screenY / this -> imageY);
    App -> draw(mapSprite);

}

/* Draws the individual level dots that represent unlocked levels to select a level
 * @param *App: pointer to game window
 */

void LevelSelect::drawLevelDots(sf::RenderWindow *App){

	  sf::Texture levelDot;
    if (!levelDot.loadFromFile("../data/LevelDot.png")) {

    }

    //Sets the size, texture, and coordinates of the level 1 dot
    
    this -> level1.setRadius(25);
    this -> level1.setTexture(&levelDot);
    this -> level1.setPosition(190, 243);

    this -> level2.setRadius(25);
    this -> level2.setTexture(&levelDot);
    this -> level2.setPosition(90, 173);





    if(this -> levelUnlocked >= 1){
        App -> draw(level1);
    }
    if(this -> levelUnlocked >= 2){
        App -> draw(level2);
    }
    drawText();
    App -> draw(titleText);
}


/*
*   Draws the text on the level select screen using the game font
*
*/
void LevelSelect::drawText(){
    if (!font.loadFromFile("../data/aliensCows.ttf"))
    {
    // error...
    }

    
    titleText.setFont(font);
    titleText.setCharacterSize(74); 
    titleText.setString("Select A Level");
    titleText.setPosition(380,520);
    titleText.setFillColor(sf::Color::White);

}

void LevelSelect::availableLevels(){

}


/* Handles the mouse clicking on a level selection dot. Changes the game state to loading if level is selected.
 * @param *App: pointer to game window
 * @param *state: pointer to the game state
 */
void LevelSelect::levelClick(sf::Vector2i mousePosition, GameState &state){
    //Get the level selection dot coordinaes
    sf::FloatRect bound1 = this -> level1.getGlobalBounds();
    sf::FloatRect bound2 = this -> level2.getGlobalBounds();
    sf::FloatRect bound3 = this -> level3.getGlobalBounds();

    //If the mouse clicks on the level 1 selector dot then change the state to game loading.
    if(bound1.contains(mousePosition.x, mousePosition.y)){
        state.setState(GameState::State::LOADING);
        }

    if(bound2.contains(mousePosition.x, mousePosition.y)){
        state.setState(GameState::State::LOADING);
        }
}
