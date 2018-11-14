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
    this -> level1.setPosition(190, 246);

    App -> draw(level1);
}

void LevelSelect::availableLevels(){

}


/* Handles the mouse clicking on a level selection dot. Changes the game state to loading if level is selected.
 * @param *App: pointer to game window
 * @param *state: pointer to the game state
 */
void LevelSelect::levelClick(sf::RenderWindow &App, GameState &state){
    //Get the mouse coordinates
    sf::Vector2i mousePosition = sf::Mouse::getPosition(App);
    //Get the level selection dot coordinaes
    sf::FloatRect boundOne = this -> level1.getGlobalBounds();

    //If the mouse clicks on the level 1 selector dot then change the state to game loading.
	  if(boundOne.contains(mousePosition.x, mousePosition.y)){
      state.setState(GameState::State::LOADING);
    }

}
