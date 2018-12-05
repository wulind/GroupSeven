#include "LevelSelect.h"

using namespace escape;

/*
* Constructor
*/
LevelSelect::LevelSelect(){}


/*
* Adds the next glowing orb that represents the next level available
* Only adds one at a time because only one new level can be unlocked at a time
* @param orb: orb to append
*/
void LevelSelect::appendDot(SelectOrb orb){
  this -> levels.push_back(orb);
}

/*
 * Handles the mouse clicking on a level selection dot. Changes the game state to loading if level is selected.
 * @param mousePosition: position of mouse as it relates to the window
 * @param &state: current game state
 */
void LevelSelect::levelClick(sf::Vector2i mousePosition, GameState &state){
    for (int i = 0; i < this -> levels.size(); ++i){
        if(this -> levels[i].circle.getGlobalBounds().contains(mousePosition.x, mousePosition.y)){
            state.setState(GameState::State::STORY);
            state.setCurrentLevel(i+1);
            break;
        }
    }
}
