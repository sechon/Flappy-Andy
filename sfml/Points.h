//Flappy Andy
//CPTS 122 PA9
//Braxton Chatman, Jacob Chong, Molly Morris, Spencer Echon

//Points.h

#pragma once
#include "Rules.h"

class Points {
public:
	Points();

	sf::Texture Zero, One, Two, Three, Four, Five, Six, Seven, Eight, Nine;
	sf::Sprite ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, DOUBLEONE, DOUBLETWO, DOUBLETHREE;

	void showPoints(sf::RenderWindow& window, int points, int x, int y);
	void showPointsLarge(sf::RenderWindow& window, int points, int x, int y);
};