//Flappy Andy
//CPTS 122 PA9
//Braxton Chatman, Jacob Chong, Molly Morris, Spencer Echon

//Pipe.h
#pragma once
#include "Andy.h"

class Pipe : public CreateSprite {

private:
	float frontOfPipe, heightFromFloor;
public:
	Pipe(string name, float frontOfPipe, float heightFromFloor);
	Pipe(string name);
	Pipe();
	void setInitLocation();

	void setFront(float newFront);
	void setHeight(float newHeight);

	float getFront();
	float getHeight();

	void initializePipe();

	void scalePipe();

	void setPipePosition(float x, float y);

	void movePipe(float x, float y);

	bool isCollision(float AndyTop, float AndyBottom);

};