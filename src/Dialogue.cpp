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
			this -> text.setCharacterSize(24);
			this -> text.setString("We’re looking to form a crew, and we heard you were pretty good.\nWell Player, we’re going to have to test your skills first.\nTry stealing a Michael Jordan autographed ball from the Chicago Cubs.\nUse the platform to guide it into our truck.\nWe’ll be waiting for you on the ground.");
			break;

		case 2:
			this -> text.setCharacterSize(30);
			this -> text.setString("Not bad, Player. Alright you’re in.\nFirst job’s easy.\nAll you gotta do is get some money from the bank.\nWe gotta fund our heists somehow.");
			break;

		case 3:
			this -> text.setCharacterSize(30);
			this -> text.setString("Good work Player. Let's step this up a bit.\nI hear there's some pretty expensive porcelain in Russia.");
			break;
			
		case 4:
			this -> text.setCharacterSize(30);
			this -> text.setString("Alright you've proven yourself to be trustworthy.\nI'll let you in on the real jobs now.\nThe Koh-i-Noor is in India temporarily. I want it in my truck.");
			break;
		
		case 5:
			this -> text.setCharacterSize(30);
			this -> text.setString("Let's bring it home to the Big Apple.\nTiffany's just launched their new collection.\nLet's do a little collectin' of our own.");
			break;
			
		case 6:
			this -> text.setCharacterSize(30);
			this -> text.setString("I don't know what's so valuable about this Liberty coin,\nbut there are some people willing to pay big money.");
			break;
		
		case 7:
			this -> text.setCharacterSize(30);
			this -> text.setString("Overheard someone talking about this dragon coin in China.\nKind of peaked my interest.");
			break;
		
		case 8:
			this -> text.setCharacterSize(30);
			this -> text.setString("Some scientists created the world's roundest object.\nI bet it's worth some real money");
			break;
		
		case 9:
			this -> text.setCharacterSize(30);
			this -> text.setString("You've done well so far.\nLet's relax a little bit.\nI hear that Paros is rather nice this time of year");
			break;
		
		case 10:
			this -> text.setCharacterSize(30);
			this -> text.setString("One last run.\nMy daddy's a Babe Ruth Fan, and his birthday's coming up.\nWhat do you say you help me get his gift?");
			break;
		
		case 11:
			this -> text.setCharacterSize(30);
			this -> text.setString("Thanks for the help, player.\nThey were right.\nYou're the best there ever was.");
			break;
	}
	
/*
* Dialogue if the player loses a level
*/
}
void Dialogue::loseLevel(){
	this -> text.setCharacterSize(30);
	this -> text.setString("You're never gonna make it big if you can't do this.\nGive it another shot.");
}

void Dialogue::winLevel(){
	this -> text.setCharacterSize(30);
	this -> text.setString("Nice job player.");
}

void Dialogue::winGame(){
	this -> text.setCharacterSize(30);
	this -> text.setString("They were right about you.\n You really are the best of the best.");
}