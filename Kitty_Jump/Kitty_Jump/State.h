#pragma once
#include "consts.h"
#include "Assets.h"

class State
{
public:
	State();
	shared_ptr<Assets> assets;
	virtual ~State() {};
	float getScore();
	void setScore(float deltaScore);
	void resetScore();
	bool gameOver = false;
	virtual void doTheLoop(Event &event, RenderWindow &window) = 0;
	virtual void checkEvents(Event &event, RenderWindow &window)=0;
	virtual void render(RenderWindow &window) = 0;

	//StateType Gstate;
	float actualScore;

};

