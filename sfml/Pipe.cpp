//Flappy Andy
//CPTS 122 PA9
//Braxton Chatman, Jacob Chong, Molly Morris, Spencer Echon

//Pipe.cpp

//redefine
#define PIPEGAP 0
#define PIPEWIDTH 0

#include "Pipe.h"
Pipe::Pipe(const string name, float frontOfPipe, float heightFromFloor) {

	fileName = name;
	this->frontOfPipe = frontOfPipe;
	this->heightFromFloor = heightFromFloor;

}

Pipe::Pipe() {

	fileName = "";
	frontOfPipe = 0;
	heightFromFloor = 0;

}

Pipe::Pipe(string name) {

	fileName = name;
	frontOfPipe = 0;
	heightFromFloor = 0;

}

void Pipe::setInitLocation() {

	mySprite.setPosition(910, 0);

}

void Pipe::setFront(float newFront) {

	frontOfPipe = newFront;

}
void Pipe::setHeight(float newHeight) {

	heightFromFloor = newHeight;

}

void Pipe::scalePipe() {
	
	mySprite.scale(adjustX,adjustY);

}

float Pipe::getFront() {

	return frontOfPipe;

}
float Pipe::getHeight() {

	return heightFromFloor;

}

void Pipe::initializePipe() {

	initializeSprite();

}

void Pipe::setPipePosition(float x, float y) {

	mySprite.setPosition(x,y);

}

void Pipe::movePipe(float x, float y) {

	mySprite.move(x,y);

}

bool Pipe::isCollision(float AndyTop, float AndyBottom)
{
	if (AndyTop<(heightFromFloor - PIPEGAP) || AndyBottom>heightFromFloor)
		return true;

	return false;
}
