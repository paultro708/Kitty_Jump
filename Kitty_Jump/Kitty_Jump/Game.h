#pragma once
#include "State.h"
#include "Kitty.h"
#include "Platform.h"


class Game: public State
{
public:
	Game();
	~Game();
	void doTheLoop(Event &event);
	void checkEvents(Event &event);
	void render();

private:
	Clock clock;
	Kitty my_kitty;
	vector <Platform> Ptab;
};

