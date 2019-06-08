#pragma once
#include "consts.h"
#include "Assets.h"

class Button{

private:
	shared_ptr <Assets> assets;
	Sprite sprite;
	Text text;
	Vector2f position;
	bool is_mouseOn = false;
	bool is_click = false;
	void buttonClick(Event &event);
public:
	Button(shared_ptr <Assets> ptr_assets, string txt, float posY);
	~Button();
	void draw(RenderWindow &window);
	void setPosition(Vector2f newPos);
	Vector2f getPosition();
	void mouseOn(Vector2f &mousePosition);
	bool checkButtonClick(Event &event);


};