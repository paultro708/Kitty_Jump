#include "State.h"
#include "State.h"



State::State(): window(VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), WINDOW_TITLE)
{

	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(WINDOW_FRAME_LIMIT);
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
