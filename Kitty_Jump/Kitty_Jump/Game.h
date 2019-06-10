#pragma once
#include "State.h"
#include "Kitty.h"
#include "Platform.h"
#include <random>

class Game: public State
{
public:
	Game (shared_ptr <Assets> ptr_assets);
	~Game();
	void doTheLoop(Event &event, RenderWindow &window);
	void checkEvents(Event &event, RenderWindow &window);
	void render(RenderWindow &window);
	void checkGameEnd();
	void reset();

private:
	Text score;
	Sprite backgroundSprite;
	float dy = 0;
	Kitty my_kitty;
	vector <Platform> Ptab;
	Platform tmpPlatform;
	void gen_platforms();
	void update_platform(Vector2f &platformPos);
	void update_jumping();
	void draw_platforms(RenderWindow &window);
	bool checkJumping();
	Vector2f genRandomVectf();
};

