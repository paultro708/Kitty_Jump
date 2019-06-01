#pragma once
#include "consts.h"

class State
{
public:
	State();
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

