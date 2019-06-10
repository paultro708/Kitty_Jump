#include "GameOver.h"



GameOver::GameOver(shared_ptr <Assets> ptr_assets) : playAgain(ptr_assets, "Play again", 320), quit(ptr_assets, "Quit", 450)
{
//	this->play = false;
	//this->gameOver = true;
	setStateType(GAMEOVER);
	assets = ptr_assets;
	textGameOver.setFont(assets->RAVIE);
	textGameOver.setString("Game Over!");
	textGameOver.setCharacterSize(45);
	textGameOver.setFillColor(Color::Red);
	textGameOver.setStyle(Text::Bold);
	//textGameOver.setPosition(50, WINDOW_SIZE.y / 2 - 50);

	FloatRect textGameOverRect = textGameOver.getLocalBounds();
	textGameOver.setOrigin(textGameOverRect.left + textGameOverRect.width / 2.0f, textGameOverRect.top + textGameOverRect.height / 2.0f);
	textGameOver.setPosition(Vector2f(WINDOW_SIZE.x / 2.0f, WINDOW_SIZE.y / 2.0f - 200));

	backgroundSprite.setTexture(assets->BACKGROUND_TEXTURE);
	//actualScore = score;
	textScore.setFont(assets->RAVIE);
//	textScore.setString("Your score: " + to_string(actualScore));
	textScore.setCharacterSize(35);
	textScore.setFillColor(Color::Red);

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
	Vector2i mousePos = Mouse::getPosition();
	playAgain.mouseOn(Vector2f(mousePos));
	if (playAgain.checkButtonClick(event))
	{
		cout << "Play again button clicked\n";
		//play = true;
		setStateType(GAME);
	}
	
	quit.mouseOn(Vector2f(mousePos));
	if (quit.checkButtonClick(event))
		window.close();
}

void GameOver::render(RenderWindow &window)
{

	textScore.setString("Your score: " + to_string(actualScore));

	FloatRect textScoreRect = textScore.getLocalBounds();
	textScore.setOrigin(textScoreRect.left + textScoreRect.width / 2.0f, textScoreRect.top + textScoreRect.height / 2.0f);
	textScore.setPosition(Vector2f(WINDOW_SIZE.x / 2.0f, WINDOW_SIZE.y / 2.0f - 150));

	window.draw(backgroundSprite);
	window.draw(textGameOver);
	window.draw(textScore);
	playAgain.draw(window);
	quit.draw(window);
}
