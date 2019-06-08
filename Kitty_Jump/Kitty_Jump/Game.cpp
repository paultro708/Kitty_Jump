#include "Game.h"



Game::Game(shared_ptr <Assets> ptr_assets) : my_kitty(ptr_assets), tmpPlatform(ptr_assets)
{
	assets = ptr_assets;
	backgroundSprite.setTexture(assets->BACKGROUND_TEXTURE);
	score.setFont(assets->RAVIE);
	score.setString("Score: " + to_string(actualScore));
	score.setCharacterSize(16);
	score.setFillColor(Color::White);//Color(0, 158, 242));
	score.setPosition(Vector2f(0, 0));
	gamePaused = false;
	gen_platforms();
	//init one of platform under the kitty initial position to not over the game on start
	Ptab[0].setPosition(Vector2f(KITTY_INITIAL_POSITION.x- 20, KITTY_INITIAL_POSITION.y + 200));
}

Game::~Game()
{
}

void Game::doTheLoop(Event &event, RenderWindow &window)
{
	this->checkEvents(event, window);
	if (!gamePaused) {
		this->my_kitty.update();
		this->update_jumping();
		this->checkGameEnd();
	}
	this->render(window);
}

void Game::checkEvents(Event & event, RenderWindow &window)
{
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();
	}

	if (Keyboard::isKeyPressed(Keyboard::P))
	{
		if (gamePaused)
			gamePaused = false;
		else
			gamePaused = true;
	}
	if (!gamePaused) {

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
}

void Game::render(RenderWindow &window)
{
	window.clear(Color::White);
	window.draw(backgroundSprite);
	my_kitty.draw(window);
	draw_platforms(window);
	score.setString("Score: " + to_string(actualScore));
	score.setPosition({ 0,0 });
	window.draw(score);
	//tmp.draw(this->window);
	cout << actualScore << endl;

	window.display();
}

bool Game::checkGameEnd()
{
	if (my_kitty.getPosition().y + KITTY_SIZE.y > WINDOW_SIZE.y)
	{
		cout << "gae=me over!";
		this->gameOver = true;
		return gameOver;
	}
	else return gameOver;
}

void Game::reset()
{
	gamePaused = false;
	gameOver = false;
	resetScore();
	Ptab.clear();
	my_kitty.reset();
	gen_platforms();

	//init one of platform under the kitty initial position to not over the game on start
	Ptab[0].setPosition(Vector2f(KITTY_INITIAL_POSITION.x - 20, KITTY_INITIAL_POSITION.y + 200));
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
		for (int i = 0; i < NUMBER_PLATFORMS; i++)
		{
			tmpKittyPos.y = MAX_KITTY_JUMP_HEIGHT;
			my_kitty.setPosition(tmpKittyPos);

			tmpPlatformPos = Ptab[i].getPosition();
			update_platform(tmpPlatformPos); //moving down and generating platforms on the top

			Ptab[i].setPosition(tmpPlatformPos);
		}

	if (tmpKittyPos.y == MAX_KITTY_JUMP_HEIGHT && dy < (-2))
		actualScore++;

	//detection jumping on the platform
	for (int i = 0; i < NUMBER_PLATFORMS; i++)
	{ //do dopracowania 
		//Vector2f tmpKittyPos = my_kitty.getPosition();
		Vector2f tmpPlatformPos = Ptab[i].getPosition();
		if (checkJumping() && dy > 0)
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

bool Game::checkJumping()
{
	for (int i = 0; i < NUMBER_PLATFORMS; i++)
	{
		Vector2f platformPos = Ptab[i].getPosition();
		Vector2f kittyPos = my_kitty.getPosition();
		if (((kittyPos.y + KITTY_SIZE.y >= platformPos.y) //check vertical collision
			&& (kittyPos.y + KITTY_SIZE.y <= platformPos.y + PLATFORM_SIZE.y)
			&& (kittyPos.x + KITTY_RIGHT_BOUNDING_BOX >= platformPos.x) //check hozizontal
			&& (kittyPos.x + KITTY_LEFT_BOUNDING_BOX - PLATFORM_SIZE.x <= platformPos.x)))
			// checking bounding box to detect jump with only kitty's paws, not at whole width of sprite
		{
			return true;
		}
	}
	return false;
}

Vector2f Game::genRandomVectf()
{
	Vector2f pos;
	pos.x = rand() % (int)(WINDOW_SIZE.x - PLATFORM_SIZE.x);
	pos.y = rand() % (int)(WINDOW_SIZE.y - PLATFORM_SIZE.y);
	return pos;
}
//
//void Game::falling(float &offsetY)
//{
//	float tmpSpeed = PLATFORM_DELTA_REFLECT;
//	if (checkJumping())
//	{
//		my_kitty.setSpeedY(my_kitty.getSpeedY() + ACCELERATION / 8);
//		offsetY= my_kitty.getSpeedY();
//	}
//	else {
//		my_kitty.setSpeedY(-tmpSpeed);
//	}
//}
//
//void Game::jumping(float &offsetY)
//{
//	my_kitty.setSpeedY(my_kitty.getSpeedY() + ACCELERATION);
//	offsetY = my_kitty.getSpeedY();
//}
//
//float Game::getKittyVerticalOffset()
//{
//	float offsetY = 0;
//
//	if (my_kitty.getSpeedY() < 0)
//	{
//		jumping(offsetY);
//	}
//	else
//		falling(offsetY);
//	return offsetY;
//}
//
//void Game::moveKitty()
//{
//	Vector2f pos;
//	pos.x = my_kitty.getHorizontalOffset();
//	pos.y = getKittyVerticalOffset();
//	my_kitty.move(pos);
//}
//
