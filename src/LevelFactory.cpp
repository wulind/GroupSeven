#include "LevelFactory.h"
using namespace escape;

LevelFactory::LevelFactory(){
  this -> level = Level();
}

/*
* Builds and returns a level object that represents current level that the user is playing
* @param levelToLoad: Level that needs to be loaded
* @param *World: Box2D world
*/
Level* LevelFactory::makeLevel(int levelToLoad, b2World* World){
  tinyxml2::XMLDocument doc;//TODO: move into resource manager
  doc.LoadFile( "../data/GreatEscape.xml" );

  //get to element that contains information for current level
  tinyxml2::XMLElement *levelRoot = doc.FirstChildElement("Level");

  while(std::atoi(levelRoot -> Attribute("level")) != levelToLoad){
    levelRoot = levelRoot -> NextSiblingElement();
  }

  this -> level.setBackgroundFile(levelRoot -> FirstChildElement("Background") -> Attribute("Filename"), levelRoot -> FirstChildElement("Background") -> Attribute("startX"), levelRoot -> FirstChildElement("Background") -> Attribute("startY"));
  this -> makePlatforms(levelRoot);
  this -> level.setStolenObjectFile(levelRoot -> FirstChildElement("StolenObject") -> Attribute("Filename"), levelRoot -> FirstChildElement("StolenObject") -> Attribute("startX"), levelRoot -> FirstChildElement("StolenObject") -> Attribute("startY"));

  this -> level.setWorld(World);

  return &this -> level;
}

/*
* Makes the orbs for the level select page
* Only makes one orb because only one new level can be unlocked per visit to the level select page
* @param level: level which orb that needs to be created
*/
LevelSelect::SelectOrb LevelFactory::makeOrbs(int level){
  tinyxml2::XMLDocument doc;//TODO: move into resource manager
  doc.LoadFile( "../data/GreatEscape.xml" );

  //get to element that contains information for current level
  tinyxml2::XMLElement *levelRoot = doc.FirstChildElement("Level");

  while(std::atoi(levelRoot -> Attribute("level")) != level){
    levelRoot = levelRoot -> NextSiblingElement();
  }

  LevelSelect::SelectOrb orb;
  orb.xCoord = std::atoi(levelRoot -> FirstChildElement("SelectOrb") -> Attribute("mapX"));
  orb.yCoord = std::atoi(levelRoot -> FirstChildElement("SelectOrb") -> Attribute("mapY"));
  return orb;
}

/*
* Makes the platforms for the level
*/
void LevelFactory::makePlatforms(tinyxml2::XMLElement *levelRoot){
  int yPos = 200;
  tinyxml2::XMLElement *child = levelRoot -> FirstChildElement("Platforms") -> FirstChildElement("Platform");

  while(child != nullptr){
    this -> level.makePlatform(std::atoi(child -> Attribute("rotation")), yPos);\

    yPos += 100;
    child = child -> NextSiblingElement();
  }
}
