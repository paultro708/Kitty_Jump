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
	virtual void doTheLoop(Event &event) = 0;
	virtual void checkEvents(Event &event)=0;
	virtual void render() = 0;

	//StateType Gstate;
	float actualScore;
	RenderWindow window;

};

