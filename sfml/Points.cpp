//Flappy Andy
//CPTS 122 PA9
//Braxton Chatman, Jacob Chong, Molly Morris, Spencer Echon

//Points.cpp

#include "Points.h"

//default constructor
Points::Points() {
	One.loadFromFile("pics/numbers.png", sf::IntRect(0, 0, 24, 67));
	Two.loadFromFile("pics/numbers.png", sf::IntRect(39, 0, 37, 67));
	Three.loadFromFile("pics/numbers.png", sf::IntRect(91, 0, 37, 67));
	Four.loadFromFile("pics/numbers.png", sf::IntRect(144, 0, 37, 67));
	Five.loadFromFile("pics/numbers.png", sf::IntRect(195, 0, 37, 67));
	Six.loadFromFile("pics/numbers.png", sf::IntRect(248, 0, 37, 67));
	Seven.loadFromFile("pics/numbers.png", sf::IntRect(301, 0, 37, 67));
	Eight.loadFromFile("pics/numbers.png", sf::IntRect(353, 0, 37, 67));
	Nine.loadFromFile("pics/numbers.png", sf::IntRect(405, 0, 37, 67));
	Zero.loadFromFile("pics/numbers.png", sf::IntRect(457, 0, 37, 67));

	ONE.setTexture(One);
	TWO.setTexture(Two);
	THREE.setTexture(Three);
	FOUR.setTexture(Four);
	FIVE.setTexture(Five);
	SIX.setTexture(Six);
	SEVEN.setTexture(Seven);
	EIGHT.setTexture(Eight);
	NINE.setTexture(Nine);
	ZERO.setTexture(Zero);
	DOUBLEONE.setTexture(One);
	DOUBLETWO.setTexture(Two);
	DOUBLETHREE.setTexture(Three);

	ONE.scale(adjustX, adjustY);
	TWO.scale(adjustX, adjustY);
	THREE.scale(adjustX, adjustY);
	FOUR.scale(adjustX, adjustY);
	FIVE.scale(adjustX, adjustY);
	SIX.scale(adjustX, adjustY);
	SEVEN.scale(adjustX, adjustY);
	EIGHT.scale(adjustX, adjustY);
	NINE.scale(adjustX, adjustY);
	ZERO.scale(adjustX, adjustY);
	DOUBLEONE.scale(adjustX, adjustY);
	DOUBLETWO.scale(adjustX, adjustY);
	DOUBLETHREE.scale(adjustX, adjustY);
}

void Points::showPoints(sf::RenderWindow& window, int points, int x, int y) {
	if (points < 10) {
		ONE.setPosition(x, y);
		TWO.setPosition(x, y);
		THREE.setPosition(x, y);
		FOUR.setPosition(x, y);
		FIVE.setPosition(x, y);
		SIX.setPosition(x, y);
		SEVEN.setPosition(x, y);
		EIGHT.setPosition(x, y);
		NINE.setPosition(x, y);
		ZERO.setPosition(x, y);

		switch (points) {
		case 0:
			window.draw(ZERO);
			break;
		case 1:
			window.draw(ONE);
			break;
		case 2:
			window.draw(TWO);
			break;
		case 3:
			window.draw(THREE);
			break;
		case 4:
			window.draw(FOUR);
			break;
		case 5:
			window.draw(FIVE);
			break;
		case 6:
			window.draw(SIX);
			break;
		case 7:
			window.draw(SEVEN);
			break;
		case 8:
			window.draw(EIGHT);
			break;
		case 9:
			window.draw(NINE);
			break;
		}
	}

}

void Points::showPointsLarge(sf::RenderWindow& window, int points, int x, int y) {
	ONE.setScale(1.6, 1.6);
	TWO.setScale(1.6, 1.6);
	THREE.setScale(1.6, 1.6);
	FOUR.setScale(1.6, 1.6);
	FIVE.setScale(1.6, 1.6);
	SIX.setScale(1.6, 1.6);
	SEVEN.setScale(1.6, 1.6);
	EIGHT.setScale(1.6, 1.6);
	NINE.setScale(1.6, 1.6);
	ZERO.setScale(1.6, 1.6);
	DOUBLEONE.setScale(1.6, 1.6);
	DOUBLETWO.setScale(1.6, 1.6);
	DOUBLETHREE.setScale(1.6, 1.6);
	
	if (points < 10) {

		ONE.setPosition(x, y);
		TWO.setPosition(x, y);
		THREE.setPosition(x, y);
		FOUR.setPosition(x, y);
		FIVE.setPosition(x, y);
		SIX.setPosition(x, y);
		SEVEN.setPosition(x, y);
		EIGHT.setPosition(x, y);
		NINE.setPosition(x, y);
		ZERO.setPosition(x, y);

		switch (points) {
		case 0:
			window.draw(ZERO);
			break;
		case 1:
			window.draw(ONE);
			break;
		case 2:
			window.draw(TWO);
			break;
		case 3:
			window.draw(THREE);
			break;
		case 4:
			window.draw(FOUR);
			break;
		case 5:
			window.draw(FIVE);
			break;
		case 6:
			window.draw(SIX);
			break;
		case 7:
			window.draw(SEVEN);
			break;
		case 8:
			window.draw(EIGHT);
			break;
		case 9:
			window.draw(NINE);
			break;
		}
	}

}