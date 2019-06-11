#include "stdafx.h"
#include "State.h"

State::State() 
{

}

int State::getScore()
{
	return this->actualScore;
}

void State::setScore(const int newScore)
{
	this->actualScore = newScore;
}

void State::resetScore()
{
	this->actualScore = 0;
}

void State::setStateType(StateType newState)
{
	this->stateType = newState;
}

StateType State::getStateType()
{
	return this->stateType;
}

