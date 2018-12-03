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

	if (!music.openFromFile("../data/GreatEscapeTheiveryTheme.wav")){
	}

	if (buffer.loadFromFile("../data/thump.wav")){
		thump.setBuffer(buffer);
	}

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
void GameView::update(Level &level, bool play){
	this -> App.clear();
  this -> drawBackground(level);

	if(level.finishButton.show){//if GameState setup
		sf::RectangleShape menu(sf::Vector2f(180, this -> screenY));
		menu.setPosition(this -> screenX - 180, 0);
		menu.setFillColor(sf::Color(0, 0, 0, 100));

		this -> drawRectangle(menu);

		this -> drawText(level.finishButton.button);
		this -> drawText(level.platformMenu.title);
	}

	//Platforms
	sf::RectangleShape platform;
	int i = 0;
	for (i; i < level.platforms.size(); ++i){
		if(play && level.platforms[i].show){
			platform = this -> makeRectangle(level.platforms[i].width, level.platforms[i].height, level.platforms[i].xCoord, level.platforms[i].yCoord, level.platforms[i].rotation);
			platform.setFillColor(sf::Color::White);

			level.platforms[i].bounds = platform.getGlobalBounds();
			level.platforms[i].origin = platform.getPosition();

			this -> drawRectangle(platform);
		}else if (!play){
			platform = this -> makeRectangle(level.platforms[i].width, level.platforms[i].height, level.platforms[i].xCoord, level.platforms[i].yCoord, level.platforms[i].rotation);
			platform.setFillColor(sf::Color::White);

			level.platforms[i].bounds = platform.getGlobalBounds();
			level.platforms[i].origin = platform.getPosition();

			this -> drawRectangle(platform);
		}

	}

	//Obstacles
	i = 0;
	for (i; i < level.obstacles.size(); ++i){
		platform = this -> makeRectangle(level.obstacles[i].width, level.obstacles[i].height, level.obstacles[i].xCoord, level.obstacles[i].yCoord, level.obstacles[i].rotation);
		platform.setFillColor(sf::Color::Black);

		level.obstacles[i].bounds = platform.getGlobalBounds();
		level.obstacles[i].origin = platform.getPosition();

		this -> drawRectangle(platform);
	}

	//Goal
	sf::RectangleShape goal = this -> makeRectangle(level.goal.width, level.goal.height, level.goal.xCoord, level.goal.yCoord, 0);
	goal.setFillColor(sf::Color(111, 82, 194));
	level.goal.bounds = goal.getGlobalBounds();
	this -> drawRectangle(goal);

	//StolenObject
	sf::CircleShape circle = this -> makeStolenObject(level.stolenObject.radius, level.stolenObject.xCoord, level.stolenObject.yCoord, level.stolenObject.rotation);
	level.stolenObject.bounds = circle.getGlobalBounds();
	circle.setTextureRect(sf::IntRect(level.stolenObject.spriteSheetStartX, level.stolenObject.spriteSheetStartY, 256, 256));
	this -> drawCircle(circle);

	if (level.stolenObject.playSound){
		this -> thump.play();
		level.stolenObject.playSound = false;
	}

	this -> App.display();
}

sf::RectangleShape GameView::makeRectangle(int width, int height, float xCoord, float yCoord, int rotation){
	sf::RectangleShape rectangle(sf::Vector2f(width, height));
	rectangle.setOrigin(width/2, height/2);
	rectangle.setPosition(xCoord, yCoord);
	rectangle.setRotation(rotation);

	return rectangle;
}

sf::CircleShape GameView::makeStolenObject(int radius, float xCoord, float yCoord, float rotation){
	sf::CircleShape circle(radius);
	circle.setOrigin(radius, radius);
	circle.setPosition(xCoord, yCoord);
	circle.setTexture(this -> objectSpriteSheet, false);
	circle.setRotation(rotation);

	return circle;
}

/*
* Pauses music associated with playing a level
*/
void GameView::pauseMusic(){
	this -> music.pause();
}

/*
* Plays menu music when playing a level
*/
void GameView::playMusic(){
	this -> music.play();
}
