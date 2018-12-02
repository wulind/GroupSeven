#include "../include/GameView.h"

using namespace escape;

GameView::GameView(){}

/*
* @param *App: pointer to game window
* @param &font: reference to Cows & Aliens font used throughout the game
*/
GameView::GameView(sf::Font* font, sf::Texture* backgroundSprite, sf::Texture* objectSprite){
	this -> App.create(sf::VideoMode(800, 600, 32), "The Great Escape", sf::Style::Titlebar|sf::Style::Close);

	this -> font = font;

    this -> backgroundSpriteSheet = backgroundSprite;
    this -> objectSpriteSheet = objectSprite;
}

/*
* Returns current window
*/
sf::RenderWindow* GameView::getApp(){
	return &this -> App;
}

/*
* Gets current position of mouse in relation to the current render window
*/
sf::Vector2i GameView::getMousePosition(){
	return sf::Mouse::getPosition(this -> App);
}

/*
* Draws any text needed for the level
* @param text: text to draw
*/
void GameView::drawText(sf::Text &text) {
	text.setFont(*this -> font);
	text.setFillColor(sf::Color::White);
	this -> App.draw(text);
}

/*
* TODO: get rid of these
*/
void GameView::drawRectangle(sf::RectangleShape &rect) {
	this -> App.draw(rect);
}

/*
 * Draws the CircleShape Object
 * @param &circle: circle shape to draw
 */
void GameView::drawCircle(sf::CircleShape &circle) {
	this -> App.draw(circle);
}

/*
 * Draws the level background using sprite sheet coordinates from the XML
 * @param level: Level object
 */
void GameView::drawBackground(Level &level){
    sf::Sprite background(*this -> backgroundSpriteSheet, sf::IntRect(level.backgroundStartX, level.backgroundStartY, 800, 600));
    this -> App.draw(background);
}

/*
* Writes dialogue pages
*/
void GameView::displayLevelStory(sf::Text &text){
	this -> App.clear();
	this -> drawText(text);

	sf::Text escapePage;
	escapePage.setCharacterSize(20);
	escapePage.setString("Click anywhere or press any key to continue.");
	escapePage.setPosition(10,500);

	this -> drawText(escapePage);

	this -> App.display();
}

/*
* Creates all of the SFML-related objects that need to be drawn
* @param level: Level object representing current level
*/
void GameView::update(Level &level){
	this -> App.clear();
    this -> drawBackground(level);

	if(level.finishButton.show){//if GameState setup
		sf::RectangleShape menu(sf::Vector2f(180, screenY));
		menu.setPosition(sf::Vector2f(620, 0)); // absolute position do not change
		menu.setFillColor(sf::Color(0, 0, 0, 100));
		this -> drawRectangle(menu);

		this -> drawText(level.finishButton.button);
		this -> drawText(level.platformMenu.title);
	}

	int i = 0;
	for (i; i < level.platforms.size(); ++i){

		sf::RectangleShape platform(sf::Vector2f(level.platforms[i].width, level.platforms[i].height));
		platform.setOrigin(level.platforms[i].width/2, level.platforms[i].height/2);
		platform.setPosition(level.platforms[i].xCoord, level.platforms[i].yCoord);
		platform.setFillColor(level.platforms[i].color);

		level.platforms[i].bounds = platform.getGlobalBounds();
		level.platforms[i].origin = platform.getPosition();

		platform.setRotation(level.platforms[i].rotation);
		this -> drawRectangle(platform);
	}

	sf::RectangleShape base(sf::Vector2f(level.base.width, level.base.height));
	base.setOrigin(level.base.width/2, level.base.height/2);
	base.setPosition(level.base.xCoord, level.base.yCoord);
	base.setFillColor(level.base.color);


//     objectSprite.setOrigin(level.stolenObject.radius, level.stolenObject.radius);

    sf::CircleShape stolenObject(level.stolenObject.radius);
    stolenObject.setOrigin(level.stolenObject.radius, level.stolenObject.radius);
    stolenObject.setPosition(level.stolenObject.xCoord, level.stolenObject.yCoord);
    stolenObject.setTexture(this -> objectSpriteSheet, false);
    stolenObject.setTextureRect(sf::IntRect(level.objectStartX,level.objectStartY,256,256));
		stolenObject.setRotation(level.stolenObject.rotation);


//     sf::Sprite stolenObject(*this -> objectSpriteSheet, sf::IntRect(0,0,256,256));/*
//     stolenObject.setScale(sf::Vector2f(.3, .3));
//     stolenObject.setOrigin(sf::Vector2f(.3 * (256/2), 0.3 * 256/2));
//     stolenObject.setPosition(level.stolenObject.xCoord, level.stolenObject.yCoord)*/;

	this -> drawRectangle(base);
    this -> App.draw(stolenObject);
	this -> App.display();
}
