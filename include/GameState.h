#ifndef GAMESTATE_H
#define GAMESTATE_H

namespace escape{
  class GameState{
   public:
        //Constructor
         GameState();
         int play;  //Represents designing and playing (0 for design and 1 for playing)
         //Set the state of the game
         void setState(int state);
  };
}
#endif
