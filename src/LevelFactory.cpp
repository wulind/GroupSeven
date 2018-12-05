#include "LevelFactory.h"
using namespace escape;

LevelFactory::LevelFactory(){}

/*
* Builds and returns a level object that represents current level that the user is playing
* @param levelToLoad: Level that needs to be loaded
* @param *World: Box2D world
*/
Level LevelFactory::makeLevel(int levelToLoad){
  Level level;
  tinyxml2::XMLDocument doc;
  doc.LoadFile( "../data/GreatEscape.xml" );
  //get to element that contains information for current level
  tinyxml2::XMLElement *levelRoot = doc.FirstChildElement("Level");

  while(std::atoi(levelRoot -> Attribute("level")) != levelToLoad){
    levelRoot = levelRoot -> NextSiblingElement();
  }

  level.setBackgroundFile(levelRoot -> FirstChildElement("Background") -> Attribute("startX"), levelRoot -> FirstChildElement("Background") -> Attribute("startY"));
  this -> makePlatforms(level, levelRoot);
  level.setStolenObject(std::atoi(levelRoot -> FirstChildElement("StolenObject") -> Attribute("xPos")), std::atoi(levelRoot -> FirstChildElement("StolenObject") -> Attribute("yPos")), std::atoi(levelRoot -> FirstChildElement("StolenObject") -> Attribute("radius")), std::stof(levelRoot -> FirstChildElement("StolenObject") -> Attribute("restitution")));
  level.setStolenObjectFile(levelRoot -> FirstChildElement("StolenObject") -> Attribute("startX"), levelRoot -> FirstChildElement("StolenObject") -> Attribute("startY"));
  level.setGravity(std::stof(levelRoot -> FirstChildElement("Gravity") -> Attribute("value")));
  level.setGoal(std::atoi(levelRoot -> FirstChildElement("Goal") -> Attribute("xPos")), std::atoi(levelRoot -> FirstChildElement("Goal") -> Attribute("yPos")));

  return level;
}

/*
* Makes the orbs for the level select page
* Only makes one orb because only one new level can be unlocked per visit to the level select page
* @param level: level which orb that needs to be created
*/
LevelSelect::SelectOrb LevelFactory::makeOrbs(int level){
  tinyxml2::XMLDocument doc;
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
void LevelFactory::makePlatforms(Level &level, tinyxml2::XMLElement *levelRoot){
  tinyxml2::XMLElement *child = levelRoot -> FirstChildElement("Platforms") -> FirstChildElement("Platform");

  while(child != nullptr){
    bool draggable;
    if (std::atoi(child -> Attribute("draggable"))){
      draggable = true;
    }
    else{
      draggable = false;
    }

    int rotation = std::atoi(child -> Attribute("rotation"));
    int xPos = std::atoi(child -> Attribute("xPos"));
    int yPos = std::atoi(child -> Attribute("yPos"));
    int width = std::atoi(child -> Attribute("width"));
    int height = std::atoi(child -> Attribute("height"));

    int color[4];//[red value, green value, blue value, alpha value]
    color[0] = std::atoi(child -> Attribute("red"));
    color[1] = std::atoi(child -> Attribute("green"));
    color[2] = std::atoi(child -> Attribute("blue"));
    color[3] = std::atoi(child -> Attribute("alpha"));

    level.makePlatform(rotation, xPos, yPos, width, height, color, draggable);

    child = child -> NextSiblingElement();
  }
}
