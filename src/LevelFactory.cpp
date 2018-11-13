#include "LevelFactory.h"
#include <iostream>
using namespace escape;

void LevelFactory::readXML(){
  tinyxml2::XMLDocument doc;
  doc.Parse("../data/level.xml");
  const char* title = doc.FirstChildElement( "Level" ) -> GetText();
	std::cout << title << std::endl;
}
