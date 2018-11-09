#include "ResourceManager.h"

using namespace escape;

/*
* Resource Manager Constructor
*/
ResourceManager::ResourceManager(){

	if (!this -> font.loadFromFile("../data/aliensCows.ttf")){
		// TODO:error...
	}

}

/*
* Returns aliens & cows font
*/
sf::Font* ResourceManager::getFont(){
  return &this -> font;
}
