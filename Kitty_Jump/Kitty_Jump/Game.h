#pragma once
#include "State.h"
#include "Kitty.h"
#include "Platform.h"
#include <random>

class Game: public State
{
public:
	Game();
	~Game();
	void doTheLoop(Event &event, RenderWindow &window);
	void checkEvents(Event &event, RenderWindow &window);
	void render(RenderWindow &window);
	bool checkGameEnd();

private:
	float dy = 0;
	Clock clock;
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

