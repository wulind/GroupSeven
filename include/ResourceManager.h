#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>

namespace escape {
	class ResourceManager {

		private:
			sf::Font font;

			//TODO: Add sprite sheets here

		public:
			ResourceManager();

      sf::Font* getFont();
	};
}
#endif
