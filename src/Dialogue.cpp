#include "Dialogue.h"

using namespace escape;

Dialogue::Dialogue(){
	this -> text.setPosition(10,300);
}

/*
* Draws dialogue depending on the level the player selected.
* Currently hardcoded, will use xml later
* @param &levelSelected: level that the user selected & wants to play
*/
void Dialogue::playStory(int levelSelected){

//Hardcoded story text to draw on the screen depending on the level the player selected
	switch(levelSelected){
		case 1:
			this -> text.setCharacterSize(20);
			this -> text.setString("We’re looking to form a crew, and we heard you were pretty good once upon a time.\n Well Player, we’re going to have to test your skills first. \nTry stealing that bag of money from the Bank of McGlothlin. \nUse the platform to guide it into our truck. We’ll be waiting for you on the ground.");
			break;

		case 2:
			this -> text.setCharacterSize(24);
			this -> text.setString("Not bad, Player. Alright you’re in. First job’s easy: the Met.");
			break;

		case 3:
			this -> text.setCharacterSize(24);
			this -> text.setString("Good work Player. Next job’s easy: the Louvre.");
			break;
	}
/*
* Dialogue if the player loses a level
*/
}
void Dialogue::loseLevel(){
	this -> text.setCharacterSize(24);
	this -> text.setString("You're never gonna make it big if you can't do this. Give it another shot.");
}

void Dialogue::winLevel(){
	this -> text.setCharacterSize(24);
	this -> text.setString("Nice job player.");
}
