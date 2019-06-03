#pragma once
#include "State.h"

class Pause: public State
{
public:
	Pause();
	~Pause();

	void doTheLoop(Event &event, RenderWindow &window);
	void checkEvents(Event &event, RenderWindow &window);
	void render(RenderWindow &window);
	View currentView;
};

