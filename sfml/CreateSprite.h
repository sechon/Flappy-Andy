//Flappy Andy
//CPTS 122 PA9
//Braxton Chatman, Jacob Chong, Molly Morris, Spencer Echon


//CreateSprite.h
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using std::string;
using sf::Sprite;
using sf::Texture;

#define adjustX 0.72
#define adjustY 0.58
#define andyX 200
#define andyY 300
#define ANDYSIZE 227

class CreateSprite {
protected:
	string fileName;
	Sprite mySprite;
	Texture myTexture;

public:
	CreateSprite(const string fileName);
	CreateSprite();

	void initializeSprite();

	virtual void setInitLocation();

	void setName(const string newName);
	void setSprite(Sprite newSprite);

	string getName();
	Sprite getSprite();

};