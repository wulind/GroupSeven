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



    levels.resize(10);
    levels[0].setRadius(25);
    levels[0].setTexture(&levelDot);
    levels[0].setPosition(190, 243);
    
    levels[1].setRadius(25);
    levels[1].setTexture(&levelDot);
    levels[1].setPosition(90, 173);



    for(int i = 0; i < levelUnlocked; i++){
        App -> draw(levels[i]);
    }


}



/* Handles the mouse clicking on a level selection dot. Changes the game state to loading if level is selected.
 * @param *App: pointer to game window
 * @param *state: pointer to the game state
 */
void LevelSelect::levelClick(sf::Vector2i mousePosition, GameState &state){

    //This should be the same as the EventManger checkMouseOverPlatforms method.
    //Return an int of the level selected
    //In greatEscape.cpp, have level = levelSelect.levelClick().
    //int level will be a global variable in greatEscape




        for (int i = 0; i < levelUnlocked; ++i){
            if(this -> levels[i].getGlobalBounds().contains(mousePosition.x, mousePosition.y)){
                state.setState(GameState::State::STORY);
                state.setCurrentLevel(i+1);
            }
        }

}
