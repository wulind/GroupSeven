#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>

namespace escape {
	class ResourceManager {

		private:
			sf::Font font;

//             float screenX = 800;
// 			float screenY = 600;
            
//             float imageX = 1114;
//             float imageY = 590;
            
            
			//TODO: Add sprite sheets here

		public:
            sf::Texture mapTexture;
			ResourceManager();

            sf::Font* getFont();
            sf::Texture* getMapTexture();
	};
}
#endif
