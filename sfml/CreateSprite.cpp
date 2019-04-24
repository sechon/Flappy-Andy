//Flappy Andy
//CPTS 122 PA9
//Braxton Chatman, Jacob Chong, Molly Morris, Spencer Echon


//CreateSprite.cpp
#include "CreateSprite.h"
CreateSprite::CreateSprite() {

	fileName = "";

}

CreateSprite::CreateSprite(const string fileName) {

	this->fileName = fileName;

}

void CreateSprite::initializeSprite() {

	myTexture.loadFromFile(fileName);
	mySprite.setTexture(myTexture);
	setInitLocation();

}

void CreateSprite::setInitLocation() {

	mySprite.setPosition(0, 0);

}

void CreateSprite::setName(const string newName) {

	fileName = newName;

}
void CreateSprite::setSprite(Sprite newSprite) {

	mySprite = newSprite;

}

string CreateSprite::getName() {

	return fileName;

}
Sprite CreateSprite::getSprite() {

	return mySprite;

}

