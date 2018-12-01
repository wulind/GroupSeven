#include "LevelFactory.h"
#include <iostream>
using namespace escape;

LevelFactory::LevelFactory(){
  this -> level = Level();
}

Level* LevelFactory::makeLevel(int levelToLoad){
  this -> readXML(levelToLoad);

  return &this -> level;
}

void LevelFactory::readXML(int levelToLoad){
  tinyxml2::XMLDocument doc;//TODO: move into resource manager
  doc.LoadFile( "../data/GreatEscape.xml" );

  //get to element that contains information for current level
  tinyxml2::XMLElement *root = doc.FirstChildElement("Level");
  while(std::atoi(root -> Attribute("level")) != levelToLoad){
    root = root -> NextSiblingElement();
  }

  this -> level.setBackgroundFile(root -> FirstChildElement("Background") -> Attribute("Filename"), root -> FirstChildElement("Background") -> Attribute("startX"), root -> FirstChildElement("Background") -> Attribute("startY"));
  this -> makePlatforms(root);
  this -> level.setStolenObjectFile(root -> FirstChildElement("StolenObject") -> Attribute("Filename"));
  this -> level.setStolenObject(std::atoi(root -> FirstChildElement("StolenObject") -> Attribute("xPos")), std::atoi(root -> FirstChildElement("StolenObject") -> Attribute("yPos")), std::atoi(root -> FirstChildElement("StolenObject") -> Attribute("radius")));
  this -> level.setGravity(std::stof(root -> FirstChildElement("Gravity") -> Attribute("value")));
}

void LevelFactory::makePlatforms(tinyxml2::XMLElement *root){
  //int yPos = 200;
  tinyxml2::XMLElement *child = root -> FirstChildElement("Platforms") -> FirstChildElement("Platform");

  while(child != nullptr){
    bool draggable;
    std::cout << child -> Attribute("draggable") << "\n";
    if (std::atoi(child -> Attribute("draggable")) == 1){
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


    this -> level.makePlatform(rotation, xPos, yPos, width, height, draggable);

    //yPos += 100;
    child = child -> NextSiblingElement();
  }

}
