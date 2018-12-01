#include "ResourceManager.h"

using namespace escape;

/*
* Resource Manager Constructor
*/
ResourceManager::ResourceManager(){

	if (!this -> font.loadFromFile("../data/aliensCows.ttf")){
		// TODO:error...
	}
	
    if (!mapTexture.loadFromFile("../data/LevelSelectionBlank.png")) {

    }
	
	
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
