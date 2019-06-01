#pragma once
#include "consts.h"
#include "State.h"

class GameOver: public State
{
public:
	GameOver();
	~GameOver();
	void doTheLoop(Event &event, RenderWindow &window);
	void checkEvents(Event &event, RenderWindow &window);
	void render(RenderWindow &window);

private:
	Text textGameOver;
	Font font;
};

