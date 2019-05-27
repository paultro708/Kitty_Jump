#include "Game.h"



Game::Game()
{
	/*for (int i = 0; i < NUMBER_PLATFORMS; i++)
	{
		Platform plat;
		this->Ptab.push_back(plat);
	}*/
	gen_platforms();
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
		this->update_jumping();
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
	draw_platforms(this->window);
	//tmp.draw(this->window);
	window.display();
}

void Game::gen_platforms()
{
	/*Vector2f platformPos;
	for (int i = 0; i < NUMBER_PLATFORMS; i++) {
		platformPos.x = std::rand() % WINDOW_SIZE.x;
		platformPos.y = std::rand() % WINDOW_SIZE.y;

		tmp.setPosition(platformPos);
		Ptab.push_back(platformPos);
	}*/

	Vector2f pos;
	for (int i = 0; i < NUMBER_PLATFORMS; i++)
	{
		pos = genRandomVectf();
		tmpPlatform.setPosition(pos);
		Ptab.push_back(tmpPlatform);
	}
}

void Game::update_platform(Vector2f &platformPos)
{
	platformPos.y -= dy;
	if (platformPos.y > WINDOW_SIZE.y) // new platform on the top
	{
		platformPos.y = 0;
		platformPos.x = genRandomVectf().x;
	}
}

void Game::update_jumping()
{
	dy += 0.2; //faliing 
	Vector2f tmpKittyPos = my_kitty.getPosition();
	tmpKittyPos.y += dy;
	Vector2f tmpPlatformPos;

	if (tmpKittyPos.y < MAX_KITTY_JUMP_HEIGHT)
		for (int i = 0; i < Ptab.size(); i++)
		{
			tmpKittyPos.y = MAX_KITTY_JUMP_HEIGHT;
			my_kitty.setPosition(tmpKittyPos);

			tmpPlatformPos = Ptab[i].getPosition();
			update_platform(tmpPlatformPos); //moving down and generating platforms on the top

			Ptab[i].setPosition(tmpPlatformPos);
		}

	//detection jumping on the platform
	for (int i = 0; i < Ptab.size(); i++)
	{ //do dopracowania 
		Vector2f tmpKittyPos = my_kitty.getPosition();
		Vector2f tmpPlatformPos = Ptab[i].getPosition();
		if ((my_kitty.getPosition().x + KITTY_RIGHT_BOUNDING_BOX < Ptab[i].getPosition().x)
			&& (my_kitty.getPosition().x + KITTY_LEFT_BOUNDING_BOX < Ptab[i].getPosition().x + PLATFORM_SIZE.x)
			&& (my_kitty.getPosition().y + KITTY_SIZE.y >= Ptab[i].getPosition().y)
			&& (my_kitty.getPosition().y + KITTY_SIZE.y < Ptab[i].getPosition().y + PLATFORM_SIZE.y)
			&& (dy > 0))
		{
			dy = -10;
		}
	}
	my_kitty.setPosition(tmpKittyPos);
}

void Game::draw_platforms(RenderWindow &window)
{
	for (int i = 0; i < Ptab.size(); i++)
	{
		Ptab[i].draw(window);
	}
}

Vector2f Game::genRandomVectf()
{
	Vector2f pos;
	pos.x = rand() % (int)(WINDOW_SIZE.x - PLATFORM_SIZE.x);
	pos.y = rand() % (int)(WINDOW_SIZE.y - PLATFORM_SIZE.y);
	return pos;
}

