#pragma once
#include "State.h"
#include "Button.h"

class GameOver: public State
{
public:
	GameOver(shared_ptr <Assets> ptr_assets, int score);
	~GameOver();
	void doTheLoop(Event &event, RenderWindow &window);
	void checkEvents(Event &event, RenderWindow &window);
	void render(RenderWindow &window);

private:
	Text textGameOver;
	Text textScore;
	Sprite backgroundSprite;

	Button playAgain;
	Button quit;
	//Button quit;
};

