#include "State.h"


State::State() 
{

}

float State::getScore()
{
	return this->actualScore;
}

void State::setScore(float deltaScore)
{
	this->actualScore += deltaScore;
}

void State::resetScore()
{
	this->actualScore = 0.f;
}


