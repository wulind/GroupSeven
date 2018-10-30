#ifndef LEVEL_FACTORY
#define LEVEL_FACTORY

#include <vector>
#include "../include/Platform.h"

namespace factory {
	class LevelFactory {
		public:
			LevelFactory();

			std::vector <escape::Platform> getPlatforms(int newLevelNum);

			int levelNum;
	};
}
#endif