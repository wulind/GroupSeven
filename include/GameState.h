#ifndef GAMESTATE_H
#define GAMESTATE_H

namespace escape{
  class GameState{

    public:
      GameState();

      //Possible game states
      enum State {TITLE, LEVELSELECT, STORY, LOADING, SETUP, PLAY, SUCCESS, FAIL, FINISHGAME, OPTIONS};

      void setState(GameState::State _state);
      void incrementUnlockedLevels();
      void setCurrentLevel(int level);

      GameState::State getState();
      int getCurrentLevel();
      int getUnlockedLevels();

    private:
      State state; //Current game state
      int unlockedLevels; //How many levels are unlocked
      int currentLevel; //Which level the player is currently playing
  };
}
#endif
