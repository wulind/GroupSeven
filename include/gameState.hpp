#ifndef Gamestate_h
#define Gamestate_h

class GameState{
	public:
        int play;
    
    void init(){
        //Level starts in level planning mode
        play = 0;
    }
		//play 0 - Level Planning
		//play 1 - Level Playing
};

#endif
