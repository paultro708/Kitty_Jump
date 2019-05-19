#include "Game.h"

int main()
{
	
	Event event;
	State *state = NULL;
	Game* newgame = new Game();
	state = newgame;
	state->doTheLoop(event);

	return 0;
}