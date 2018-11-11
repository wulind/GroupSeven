#include "LevelSelect.h"

using namespace escape;

/*
* Constructor
* @param *App: Render Window
*/
LevelSelect::LevelSelect(sf::RenderWindow *App){
	this -> App = App;

}

void LevelSelect::drawBackground(){
	//Load the background map as a texture
    sf::Texture mapTexture;
    if (!mapTexture.loadFromFile("../data/LevelSelectionBlank.png")) {
        
    }
    //Use the texture as a sprite
    sf::Sprite mapSprite(mapTexture);
    mapSprite.setScale(this -> screenX / this -> imageX, this -> screenY / this -> imageY);
    this -> App -> draw(mapSprite);

}

void LevelSelect::drawLevelDots(){
	sf::Texture levelDot;
    if (!levelDot.loadFromFile("../data/LevelDot.png")) {
        
    }

    sf::CircleShape level1;
    level1.setRadius(25);
    level1.setTexture(&levelDot);
	level1.setPosition(190, 246);
	
	this -> App -> draw(level1);

}

void LevelSelect::availableLevels(){

}

