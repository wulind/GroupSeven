#ifndef Gamestate_h
#define Gamestate_h
#include <SFML/Graphics.hpp>

class GameState{
	public:
        int play;
    
        void init();

        void setState(int state);

};

#endif
