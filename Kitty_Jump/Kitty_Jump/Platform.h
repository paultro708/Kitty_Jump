#pragma once
#include "consts.h"

class Platform
{

protected:
	Vector2f plat_pos; //position of platform
	string plat_png = "images/platform.png";
	Texture plat_txt; 

public:
	Sprite plat_sprite;
	void move(Vector2f &deltaPos);
	Vector2f getPosition();
	void setPosition(Vector2f &newPos);
	void draw(RenderWindow &window);

public:
	Platform();
	~Platform();
};

