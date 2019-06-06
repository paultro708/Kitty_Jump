#include "Menu.h"



Menu::Menu(shared_ptr <Assets> ptr_assets) :
	playButton(ptr_assets, "Play", 300),
	quitButton(ptr_assets, "Quit", 500)
{
	assets = ptr_assets;
	logo.setTexture(assets->LOGO_TEXT);
	//logo.setPosition(0, 0);


	background.setTexture(assets->BACKGROUND_TEXTURE);
	kitty.setTexture(assets->KITTY);
	//kitty.setScale({ 1.5, 1.5 });
	kitty.setPosition(  100, WINDOW_SIZE.y - KITTY_SIZE.y);
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
	window.draw(background);
	window.draw(logo);
	window.draw(kitty);
	playButton.draw(window);
	quitButton.draw(window);
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
