#include "LevelFactory.h"


using namespace escape;

LevelFactory::LevelFactory(){}

LevelFactory::LevelFactory(Level &_level){
  this -> level = level;
}

void LevelFactory::readXML(int levelToLoad){
  tinyxml2::XMLDocument doc;//TODO: move into resource manager
  doc.LoadFile( "../data/GreatEscape.xml" );

  //get to element that contains information for current level
  tinyxml2::XMLElement *root = doc.FirstChildElement("Level");
  while(std::atoi(root -> Attribute("level")) != levelToLoad){
    root = root -> NextSiblingElement();
  }

  this -> level.setBackgroundFile(root -> FirstChildElement("Background") -> Attribute("Filename"));
  this -> level.makePlatform(std::atoi(root -> FirstChildElement("Platform") -> GetText()));
  this -> level.setStolenObjectFile(root -> FirstChildElement("StolenObject") -> Attribute("Filename"));
}
