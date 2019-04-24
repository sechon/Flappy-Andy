//Flappy Andy
//CPTS 122 PA9
//Braxton Chatman, Jacob Chong, Molly Morris, Spencer Echon


//Andy.cpp
#include "Andy.h"
Andy::Andy(const string name) {

	fileName = name;
	andyBottom = 0;
	andyTop = 0;

}
Andy::Andy(const string name, Sprite sprite) {

	fileName = name;
	mySprite = sprite;

}
Andy::Andy(const string name, Sprite sprite, float andyTop) {

	fileName = name;
	mySprite = sprite;
	this->andyTop = andyTop;
	andyBottom = andyTop + ANDYSIZE;

}

void Andy::initializeAndy() {

	initializeSprite();
	mySprite.setScale(0.5, 0.5);
	setInitLocation();
	setAndyTop(300);


}


void Andy::setInitLocation() {

	mySprite.setPosition(andyX, andyY);

}

float Andy::getAndyTop() {

	return andyTop;

}
float Andy::getAndyBottom() {

	return andyBottom;

}

float Andy::getPositionY() {
	return mySprite.getPosition().y;
}

float Andy::getPositionX() {
	return mySprite.getPosition().x;
}

float Andy::getGlobalWidth() {
	return mySprite.getGlobalBounds().width;
}

float Andy::getGlobalHeight() {
	return mySprite.getGlobalBounds().height;
}

void Andy::setAndyTop(float newTop) {

	andyTop = newTop;
	andyBottom = newTop + ANDYSIZE;

}
void Andy::setAndyBottom(float newBottom) {

	andyBottom = newBottom;
	andyTop = newBottom - ANDYSIZE;

}

void Andy::moveAndy(float x, float y) {

	mySprite.move(x, y);

}

void Andy::rotateAndy(float angle) {

	mySprite.setRotation(angle);

}

void Andy::setAndy(float x, float y) {
	mySprite.setPosition(x, y);

}