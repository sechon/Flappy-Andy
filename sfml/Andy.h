//Flappy Andy
//CPTS 122 PA9
//Braxton Chatman, Jacob Chong, Molly Morris, Spencer Echon


//Andy.h
#pragma once
#include "CreateSprite.h"


class Andy : public CreateSprite {

private:
	float andyTop, andyBottom;
public:
	Andy(const string name);
	Andy(const string name, Sprite sprite);
	Andy(const string name, Sprite sprite, float andyTop);

	void moveAndy(float x, float y);
	void rotateAndy(float angle);

	void initializeAndy();

	void setInitLocation();

	float getAndyTop();
	float getAndyBottom();
	float getPositionY();
	float getPositionX();
	float getGlobalWidth();
	float getGlobalHeight();

	void setAndyTop(float newTop);
	void setAndyBottom(float newBottom);
	void setAndy(float x, float y);
};