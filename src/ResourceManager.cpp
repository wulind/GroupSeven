#include "ResourceManager.h"

using namespace escape;

/*
* Resource Manager Constructor
*/
ResourceManager::ResourceManager(){

	if (!this -> font.loadFromFile("../data/aliensCows.ttf")){}

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

sf::Texture *ResourceManager::getBackgroundTexture(){
    return &this -> backgroundSpriteSheet;
}

sf::Texture *ResourceManager::getObjectTexture(){
    return &this -> objectSpriteSheet;
}
