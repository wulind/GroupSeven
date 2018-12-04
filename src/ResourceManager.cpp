#include "ResourceManager.h"

using namespace escape;

/*
* Resource Manager Constructor
*/
ResourceManager::ResourceManager(){

	if (!this -> font.loadFromFile("../data/aliensCows.ttf")){}

	if (!this->numFont.loadFromFile("../data/Roboto.ttf")) {}

  if (!mapTexture.loadFromFile("../data/LevelSelectionBlank.png")) {}

	if (!levelDot.loadFromFile("../data/LevelDot.png")) {}

  if (!backgroundSpriteSheet.loadFromFile("../data/BackgroundsSpriteSheet.png")) {}

	if (!objectSpriteSheet.loadFromFile("../data/StolenObjectsSpriteSheet.png")) {}
}

/*
* Returns aliens & cows font
*/
sf::Font* ResourceManager::getFont(){
  	return &this -> font;
}

/*
* Returns aliens & cows font
*/
sf::Font* ResourceManager::getNumFont() {
	return &this->numFont;
}

/*
 * Returns Blank Map Texture
 */
sf::Texture *ResourceManager::getMapTexture(){
    return &this -> mapTexture;
}

/*
* Returns the level dot texture for the levels unlocked on the level select screen
*/
sf::Texture *ResourceManager::getLevelDot(){
    return &this -> levelDot;
}

/*
* Returns the background texture for the levels unlocked on the level select screen
*/
sf::Texture *ResourceManager::getBackgroundTexture(){
    return &this -> backgroundSpriteSheet;
}

/*
* Returns the object texture for the levels unlocked on the level select screen
*/
sf::Texture *ResourceManager::getObjectTexture(){
    return &this -> objectSpriteSheet;
}
