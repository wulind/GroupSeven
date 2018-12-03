#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "tinyxml2.h"

namespace escape {
	class ResourceManager {

		private:
			sf::Font font;
      sf::Texture mapTexture;

      //Sprite Sheets
			sf::Texture backgroundSpriteSheet;
      sf::Texture objectSpriteSheet;

		public:
			ResourceManager();

    	sf::Font* getFont();
      sf::Texture* getMapTexture();
      sf::Texture* getBackgroundTexture();
      sf::Texture* getObjectTexture();

    };
}
#endif
