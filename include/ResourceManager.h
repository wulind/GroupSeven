#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>

namespace escape {
	class ResourceManager {

		private:
			sf::Font font;
			sf::Texture objTexture;
			sf::Texture levelDot;
            sf::Texture mapTexture;

            //Sprite Sheets
			sf::Texture backgroundSpriteSheet;
            

		public:
			ResourceManager();

            sf::Font* getFont();
            sf::Texture* getMapTexture();
            sf::Texture* getLevelDot();
            sf::Texture* getBackgroundTexture();
	};
}
#endif
