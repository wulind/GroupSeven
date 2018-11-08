#ifndef GAMESTATE_H
#define GAMESTATE_H

namespace escape{
  class GameState{

    public:
      GameState();

      //Possible game states
      enum State {TITLE, LEVELSELECT, LOADING, SETUP, PLAY, SUCCESS, FAIL};

      void setState(GameState::State _state);
      GameState::State getState();

    private:
      State state; //Current game state

  };
}
#endif
