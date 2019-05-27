#include "Game.h"

int main()
{
	srand(time(NULL));
	Event event;
	State *state = NULL;
	Game* newgame = new Game();
	state = newgame;
	state->doTheLoop(event);

	return 0;
}