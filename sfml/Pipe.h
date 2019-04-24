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

	void setPipePosition(float x, float y);

	bool isCollision(float AndyTop, float AndyBottom);

};