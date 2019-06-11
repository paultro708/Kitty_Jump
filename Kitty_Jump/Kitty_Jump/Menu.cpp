#include "stdafx.h"
#include "Menu.h"



Menu::Menu(shared_ptr <Assets> ptr_assets) :
	playButton(ptr_assets, "Play", 300),
	quitButton(ptr_assets, "Quit", 450)
{
	setStateType(MENU);
	assets = ptr_assets;
	logo.setTexture(assets->LOGO_TEXT);

	background.setTexture(assets->BACKGROUND_TEXTURE);
	kitty.setTexture(assets->KITTY);
	kitty.setPosition(  100, WINDOW_SIZE.y - KITTY_SIZE.y);
}


Menu::~Menu()
{
}

void Menu::doTheLoop(Event & event, RenderWindow & window)
{
	this->checkEvents(event, window);
	this->render(window);
}

void Menu::checkEvents(Event & event, RenderWindow & window)
{
	while (window.pollEvent(event))
	{
		if ((event.type == Event::Closed)||getStateType()==QUIT)
			window.close();
	}
	Vector2i mousePos = Mouse::getPosition();
	playButton.mouseOn(Vector2f(mousePos));
	if (playButton.checkButtonClick(event))
	{
		setStateType(GAME);
	}
	quitButton.mouseOn(Vector2f(mousePos));
	if (quitButton.checkButtonClick(event))
	{
		setStateType(QUIT);
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
	window.display();
}