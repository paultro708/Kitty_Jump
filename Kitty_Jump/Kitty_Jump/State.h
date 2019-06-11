#pragma once
#include "consts.h"
#include "Assets.h"

class State
{
public:
	State();
	shared_ptr<Assets> assets;
	virtual ~State() {};
	int getScore();
	void setScore(const int newScore);
	void resetScore();
	virtual void doTheLoop(Event &event, RenderWindow &window) = 0;
	virtual void checkEvents(Event &event, RenderWindow &window) = 0;
	virtual void render(RenderWindow &window) = 0;
	void setStateType(StateType newState);
	StateType getStateType();
	int actualScore = 0;
	StateType stateType;

};

