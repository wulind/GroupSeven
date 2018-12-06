#include "Dialogue.h"

using namespace escape;

Dialogue::Dialogue(){
	this -> text.setPosition(10,5);
	this -> funFact.setPosition(10, 300);
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
			this -> text.setString("We are looking to form a crew, and we heard you were pretty good.\n We are going to have to test your skills first.\n You will need a code name... How about Eagle. \nTry stealing a Michael Jordan autographed ball from the Chicago Cubs.\nUse the platform to guide it into our truck.\nWe’ll be waiting for you on the ground.");

			this -> funFact.setCharacterSize(24);
			this -> funFact.setString("Fun fact. Michael Jordan \nplayed NCAA Basketball for UNC Chapel Hill");
			break;

		case 2:
			this -> text.setCharacterSize(30);
			this -> text.setString("Not bad, Eagle. Alright you’re in.\nFirst job’s easy.\nAll you gotta do is get some money from the bank.\nWe gotta fund our heists somehow.");

			this -> text.setCharacterSize(30);
			this -> funFact.setString("Fun fact. The highest mountain in South America is Aconcagua in Argentina.");

			break;

		case 3:
			this -> text.setCharacterSize(30);
			this -> text.setString("Good work . Let's step this up a bit.\nI hear there's some pretty expensive porcelain in Russia.");

			this -> text.setCharacterSize(30);
			this -> funFact.setString("Fun fact. St. Basil's cathedral was built by Ivan The Terrible.");
			break;

		case 4:
			this -> text.setCharacterSize(30);
			this -> text.setString("Alright you've proven yourself to be trustworthy.\nI'll let you in on the real jobs now.\nThe Koh-i-Noor is in India temporarily. I want it in my truck.");
			this -> text.setCharacterSize(30);
			this -> funFact.setString("Fun fact. The Taj Mahal is made out of white marble.");

			break;

		case 5:
			this -> text.setCharacterSize(30);
			this -> text.setString("Let's visit the Old Country, Italy.\nTiffany's just launched their new collection.\nLet's do a little collectin' of our own.");

			this -> text.setCharacterSize(30);
			this -> funFact.setString("Fun fact. This Tiffany's necklace is over 91-carats of uniquley cut diamonds set in platinum. We're gonna grab it before its even released.");

			break;

		case 6:
			this -> text.setCharacterSize(30);
			this -> text.setString("I don't know what's so valuable about this Liberty coin,\nbut there are some people willing to pay big money.");
			this -> text.setCharacterSize(30);
			this -> funFact.setString("Fun fact. The Forbidden City is the worlds largest palace.");

			break;

		case 7:
			this -> text.setCharacterSize(30);
			this -> text.setString("Overheard someone talking about this dragon coin in China.\nKind of peaked my interest.");

			this -> text.setCharacterSize(30);
			this -> funFact.setString("Fun fact. The Grand Bazaar in Istanbul is one of the largest markets in the world.");
			break;

		case 8:
			this -> text.setCharacterSize(30);
			this -> text.setString("Some scientists created the world's roundest object.\nI bet it's worth some real money");

			this -> text.setCharacterSize(30);
			this -> funFact.setString("Fun fact. Perfectly round spheres do not occur in nature. This is one of its kind.");
			break;

		case 9:
			this -> text.setCharacterSize(30);
			this -> text.setString("You've done well so far.\nLet's relax a little bit.\nI hear that Paris is rather nice this time of year");
			this -> text.setCharacterSize(30);
			this -> funFact.setString("Fun fact. Originally the Louvre was a fortress, not a museum.");
			break;

		case 10:
			this -> text.setCharacterSize(30);
			this -> text.setString("One last run.\nMy daddy's a Babe Ruth Fan, and his birthday's coming up.\nWhat do you say you help me get his gift?");
			break;
			this -> text.setCharacterSize(30);
			this -> funFact.setString("Fun fact. Babe Ruth was elected to the baseball hall of fame in Nineteen thirty six");

		case 11:
			this -> text.setCharacterSize(30);
			this -> text.setString("Eagle, we're going to the North Pole in search of Atlantis. Dress appropriately, but you should know what to do considering you're the best.");
			this -> text.setCharacterSize(30);
			this -> funFact.setString("Fun fact. This lost city of Atlantis is real.");
			break;

		case 12:
				this -> text.setCharacterSize(30);
				this -> text.setString("Thanks for the help, Eagle.\nThey were right.\nYou're the best there ever was.");
				this -> text.setCharacterSize(30);
				this -> funFact.setString("Fun fact. Atlantis holds great treasures that we cannot even comprehend today.");
				break;

	}

/*
* Dialogue if the player loses a level
*/
}
void Dialogue::loseLevel(){
	this -> text.setCharacterSize(30);
	this -> text.setString("You're never gonna make it big if you can't do this.\nGive it another shot.");
	this -> funFact.setString("");
}

void Dialogue::winLevel(){
	this -> text.setCharacterSize(30);
	this -> text.setString("Nice job Eagle.");
	this -> funFact.setString("");
}

void Dialogue::winGame(){
	this -> text.setCharacterSize(30);
	this -> text.setString("They were right about you.\nYou really are the best of the best.");
	this -> funFact.setString("");
}
