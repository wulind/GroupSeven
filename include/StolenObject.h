#ifndef STOLENOBJECT_H
#define STOLENOBJECT_H

#include <SFML/Graphics.hpp>

namespace escape {
	class StolenObject {

		public:
      StolenObject();
			StolenObject(float x, float y, int radius);

			float xCoord;
			float yCoord;

			int radius;//TODO: make this pertain to other shapes

			sf::Color color;
	};
}
#endif
