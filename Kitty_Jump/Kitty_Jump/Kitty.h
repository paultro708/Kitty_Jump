#pragma once
#include "consts.h"
#include "Assets.h"

class Kitty
{
private:
	shared_ptr<Assets> assets;
	Vector2f kitty_pos; 
	Sprite kitty_sprite;
	void checkCylinderEffect(); //chceck go outside the boards in width
	Vector2f getHorizontalOffset();

public:
	DirectionX directX = None;
	Kitty(shared_ptr<Assets> ptr_assets);
	~Kitty();
	void move(Vector2f &deltaPos);
	Vector2f getPosition();
	void setPosition(Vector2f &newPos);
	void update();
	void draw(RenderWindow &window);

	/*
	float getSpeedY();
	void setSpeedY(float newSpeed);*/


	//	float getHorizontalOffset();
};

