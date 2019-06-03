#include "Menu.h"



Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::doTheLoop(Event & event, RenderWindow & window)
{
	this->checkEvents(event, window);
	//updating choose
	//if  Choose records/ help
	//switch
	this->render(window);
}

void Menu::checkEvents(Event & event, RenderWindow & window)
{
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();
	}
}

void Menu::render(RenderWindow & window)
{
	window.clear(Color::White);
	//my_kitty.draw(window);
	//draw_platforms(window);
	window.display();
}

void Menu::setMenuState(MenuStates newState)
{
	currentMenuState = newState;
}

MenuStates Menu::getMenuState()
{
	return currentMenuState;
}
