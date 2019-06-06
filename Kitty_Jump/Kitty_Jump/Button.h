#pragma once
#include "consts.h"
#include "Assets.h"

class Button{

private:
	shared_ptr <Assets> assets;
	Sprite sprite;
	Text text;
	Vector2f position;

public:
	Button(shared_ptr <Assets> ptr_assets, string txt, float posY);
	~Button();
	void draw(RenderWindow &window);


};