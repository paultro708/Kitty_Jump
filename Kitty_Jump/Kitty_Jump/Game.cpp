#include "Game.h"


Game::Game()
{
	for (int i = 0; i < NUMBER_PLATFORMS; i++)
	{
		Platform plat;
		this->Ptab.push_back(plat);
	}
}


Game::~Game()
{
}

void Game::doTheLoop(Event &event)
{
	while (window.isOpen())
	{
		this->checkEvents(event);
		this->my_kitty.update();
		
		this->render();
		
	}
}

void Game::checkEvents(Event & event)
{
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();

	}

	if (event.type == Event::KeyPressed)
		switch (event.key.code)
		{
		case Keyboard::Left:
			my_kitty.directX = Left;
			break;
		case Keyboard::Right:
			my_kitty.directX = Right;
			break;
		default:
			my_kitty.directX = None;
		}

	if (event.type == sf::Event::KeyReleased)
	{
		switch (event.key.code)
		{
		case Keyboard::Left:
			my_kitty.directX = None;
			break;
		case Keyboard::Right:
			my_kitty.directX = None;
			break;
		default:
			break;
		}
	}
}

void Game::render()
{
	window.clear(Color::White);
	my_kitty.draw(this->window);
	//for (int i = 0; i < NUMBER_PLATFORMS; i++)
	//	Ptab[i].draw(this->window);
	tmp.draw(this->window);
	window.display();
}