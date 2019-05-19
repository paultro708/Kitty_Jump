#pragma once
#include "consts.h"

class Kitty
{
protected:
	Vector2f kitty_pos; //position of player

	string left_png = "images/kitty_left.png";
	string right_png = "images/kitty_right.png";

	Texture kitty_txtL, kitty_txtR; //textures of left and right

public:
	Sprite kitty_sprite;
	DirectionX directX = None;
	Kitty();
	~Kitty();
	void moveLeft();
	void moveRight();
	void move(Vector2f &deltaPos);
	Vector2f getPosition();
	void setPosition(Vector2f &newPos);
	void checkCylinderEffect(); //chceck go outside the boards in width
	void update();
	Vector2f getOffset();
	void draw(RenderWindow &window);
};

