//Flappy Andy
//CPTS 122 PA9
//Braxton Chatman, Jacob Chong, Molly Morris, Spencer Echon

//Rules.cpp

#include "Rules.h"

void Rules::showRules() {
	sf::RenderWindow window(sf::VideoMode(1300, 700), "Flappy Andy Rules");
	
	//declerations
	sf::Texture rules;
	sf::Sprite Rules;

	rules.loadFromFile("pics/rules.png");
	Rules.setTexture(rules);
	Rules.setScale(adjustX, adjustY);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(Rules);
		window.display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
		}
	}
}