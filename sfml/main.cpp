//Flappy Andy
//CPTS 122 PA9
//Braxton Chatman, Jacob Chong, Molly Morris, Spencer Echon

#include "FlappyAndy.h"

int main(){
	//Declare main wrapper
	FlappyAndy run;
	Rules rules;

	//time
	sf::Clock clock;
	sf::Time elapsed = clock.getElapsedTime();
	bool checkTime = false;

	//set window resolution
	sf::RenderWindow window(sf::VideoMode(1300, 700), "Flappy Andy Main Menu");
	
	//turn off repeated key strokes
	window.setKeyRepeatEnabled(false);

	//declare music
	sf::Music country;
	country.openFromFile("audio/country.ogg");

	//play background music
	country.play();

	//declare textures
	sf::Texture background, cursor;
	sf::Sprite Background, Cursor;

	background.loadFromFile("pics/draft2.png");
	Background.setTexture(background);
	Background.scale(adjustX,adjustY);

	cursor.loadFromFile("pics/cursor.png");
	Cursor.setTexture(cursor);
	Cursor.scale(adjustX, adjustY);
	Cursor.setPosition(520,350);

	while (window.isOpen()){
		//set frame rate limit
		window.setFramerateLimit(60);
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(Background);
		window.draw(Cursor);
		window.display();

		//increment elapsed time
		elapsed = clock.getElapsedTime();

		//start movements

		//menu options y positions
		////start: 350
		////rules: 405
		////select: 460
		////exit: 515

		//cursor up/down movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && checkTime == false) {
			if (Cursor.getPosition().y == 350) {
				Cursor.setPosition(Cursor.getPosition().x, 515);
			}
			else {
				Cursor.setPosition(Cursor.getPosition().x, Cursor.getPosition().y - 55);
			}
			//time reset
			clock.restart();
			elapsed = clock.getElapsedTime();
			//reset check
			checkTime = true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && checkTime == false) {
			if (Cursor.getPosition().y == 515) {
				Cursor.setPosition(Cursor.getPosition().x, 350);
			}
			else {
				Cursor.setPosition(Cursor.getPosition().x, Cursor.getPosition().y + 55);
			}
			//time reset
			clock.restart();
			elapsed = clock.getElapsedTime();
			//reset check
			checkTime = true;
		}

		////cursor side to side movement //not working
		//if (Cursor.getPosition().x >= 520) {//move right
		//	Cursor.move(0.5, 0);
		//}
		//if (Cursor.getPosition().x <= 600) {//move right
		//	Cursor.move(-0.5, 0);
		//}


		//choose option using enter
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			//play
			if (Cursor.getPosition().y == 350) {
				run.runApp();
			}
			//rules
			if (Cursor.getPosition().y == 405) {
				rules.showRules();
			}
			//select
			if (Cursor.getPosition().y == 460) {

			}
			//exit
			if (Cursor.getPosition().y == 515) {
				window.close();
			}
		}

		//choose option using space
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			//play
			if (Cursor.getPosition().y == 350) {
				run.runApp();
			}
			//rules
			if (Cursor.getPosition().y == 405) {
				rules.showRules();
			}
			//select
			if (Cursor.getPosition().y == 460) {

			}
			//exit
			if (Cursor.getPosition().y == 515) {
				window.close();
			}
		}
		//reset time check after set time
		if (checkTime == true && elapsed >= sf::milliseconds(100)) {
			checkTime = false;
		}

	}

	return 0;
}