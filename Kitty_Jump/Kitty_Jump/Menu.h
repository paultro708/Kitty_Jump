#pragma once
#include "State.h"
#include "Button.h"

class Menu: public State
{
private:
	//MenuStates currentMenuState;
	Button playButton;
	Button quitButton;
	shared_ptr <Assets> assets;
	Sprite background;
	Sprite kitty;
	Sprite logo;

public:
	Menu(shared_ptr <Assets> ptr_assets);
	~Menu();
	void doTheLoop(Event &event, RenderWindow &window);
	void checkEvents(Event &event, RenderWindow &window);
	void render(RenderWindow &window);
	//void setMenuState(MenuStates newState);
	//MenuStates getMenuState();
};

