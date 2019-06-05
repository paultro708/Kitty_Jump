#include "GameOver.h"



GameOver::GameOver(shared_ptr <Assets> ptr_assets)
{
	this->gameOver = true; 
	assets = ptr_assets;
	textGameOver.setFont(assets->RAVIE); 
	textGameOver.setPosition(50, WINDOW_SIZE.y / 2 - 50);
	textGameOver.setString("Game Over!");
	textGameOver.setCharacterSize(34);
	textGameOver.setFillColor(sf::Color::Red);
	textGameOver.setStyle(Text::Bold);

	backgroundSprite.setTexture(assets->BACKGROUND_TEXTURE);
}


GameOver::~GameOver()
{
}

void GameOver::doTheLoop(Event & event, RenderWindow &window)
{
	window.clear(Color::White);
	this->checkEvents(event, window);
	this->render(window);
	window.display();
}

void GameOver::checkEvents(Event & event, RenderWindow &window)
{
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();
	}
}

void GameOver::render(RenderWindow &window)
{
	window.draw(backgroundSprite);
	window.draw(textGameOver);
}
