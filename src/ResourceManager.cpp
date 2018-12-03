#include "ResourceManager.h"

using namespace escape;

/*
* Resource Manager Constructor
*/
ResourceManager::ResourceManager(){

	if (!this -> font.loadFromFile("../data/aliensCows.ttf")){}

  if (!mapTexture.loadFromFile("../data/LevelSelectionBlank.png")) {}


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
 * Returns Blank Map Texture
 */
sf::Texture *ResourceManager::getMapTexture(){
    return &this -> mapTexture;
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
