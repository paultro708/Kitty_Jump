#include "State.h"

State::State() 
{

}

int State::getScore()
{
	return this->actualScore;
}

void State::resetScore()
{
	this->actualScore = 0;
}


