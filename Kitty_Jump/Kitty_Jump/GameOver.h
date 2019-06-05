#pragma once
#include "State.h"

class GameOver: public State
{
public:
	GameOver(shared_ptr <Assets> ptr_assets);
	~GameOver();
	void doTheLoop(Event &event, RenderWindow &window);
	void checkEvents(Event &event, RenderWindow &window);
	void render(RenderWindow &window);

private:
	Text textGameOver;
	Sprite backgroundSprite;
};

