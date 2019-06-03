#pragma once
#include "State.h"

class Menu: public State
{
private:
	MenuStates currentMenuState;
public:
	Menu();
	~Menu();
	void doTheLoop(Event &event, RenderWindow &window);
	void checkEvents(Event &event, RenderWindow &window);
	void render(RenderWindow &window);
	void setMenuState(MenuStates newState);
	MenuStates getMenuState();
};

