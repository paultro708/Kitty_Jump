#pragma once
#include "consts.h"
#include <random>
#include "Assets.h"

class Platform
{

private:
	Vector2f plat_pos; //position of platform
	shared_ptr<Assets> assets;
	Sprite plat_sprite;

public:
	void move(Vector2f &deltaPos);
	Vector2f getPosition();
	void setPosition(Vector2f &newPos);
	void draw(RenderWindow &window);

	Platform(shared_ptr<Assets> ptr_assets);
	~Platform();
};

