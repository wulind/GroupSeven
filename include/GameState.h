#ifndef GAMESTATE_H
#define GAMESTATE_H

namespace escape{
  class GameState{

    public:
      GameState();

      //Possible game states
      enum State {TITLE, LEVELSELECT, LOADING, SETUP, PLAY, SUCCESS, FAIL, STORY};

      void setState(GameState::State _state);
      void incrementCurrentLevel();
      void setCurrentLevel(int level);

      GameState::State getState();
      int getCurrentLevel();

    private:
      State state; //Current game state
      int currentLevel;

  };
}
#endif
