#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>

namespace escape {
	class ResourceManager {

		private:
			sf::Font font;
			sf::Texture objTexture;
			sf::Texture levelDot;

            
			//TODO: Add sprite sheets here

		public:
            sf::Texture mapTexture;
			ResourceManager();

            sf::Font* getFont();
            sf::Texture* getMapTexture();
            sf::Texture* getLevelDot();
	};
}
#endif
