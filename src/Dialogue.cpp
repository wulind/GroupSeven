#include "Dialogue.h"

using namespace escape;

Dialogue::Dialogue(){
	this -> text.setPosition(10, 20);
	this -> funFact.setPosition(10, 300);
}

/*
* Sets dialogue depending on the level the player selected.
* Currently hardcoded, will use xml later
* @param text: story of the level
* @param funFact: fun fact of the level
*/
void Dialogue::setStory(const char* text, const char* funFact){
		this -> text.setCharacterSize(24);
		this -> funFact.setCharacterSize(24);

		this -> text.setString(text);
		this -> funFact.setString(funFact);

}

/*
* Dialogue if the player loses a level
*/
void Dialogue::loseLevel(){
	this -> text.setCharacterSize(30);
	this -> text.setString("You're never gonna make it big if you can't do this.\nGive it another shot.");
	this -> funFact.setString("");
}

/*
* Dialogue if player wins a level
*/
void Dialogue::winLevel(){
	this -> text.setCharacterSize(30);
	this -> text.setString("Nice job Eagle.");
	this -> funFact.setString("");
}

/*
* Dialgue if player wins the game
*/
void Dialogue::winGame(){
	this -> text.setCharacterSize(30);
	this -> text.setString("They were right about you.\nYou really are the best of the best.");
	this -> funFact.setString("");
}
