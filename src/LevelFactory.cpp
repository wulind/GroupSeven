#include "../include/LevelFactory.h"
#include "../include/Platform.h"
#include <vector>

using namespace factory;
using namespace escape; 

LevelFactory::LevelFactory() :
	levelNum(1) {
	
}

std::vector <escape::Platform> LevelFactory::getPlatforms(int newLevelNum) {

	this->levelNum = newLevelNum;
	std::vector <escape::Platform> platforms(2);

	switch (newLevelNum) {
		case 1:
			platforms[0] = Platform(625, 50, 20, 100);
			platforms[1] = Platform(625, 300, 30, 150);
		default:
			break;
	}

	return platforms;
}