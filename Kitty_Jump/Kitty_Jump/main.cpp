#include "Game.h"
#include "Pause.h"
#include "GameOver.h"
#include <typeinfo> 



int main()
{
	RenderWindow window(VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), WINDOW_TITLE);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(WINDOW_FRAME_LIMIT);

	srand(time(NULL));
	Event event;
	State *state = NULL;
	Game* newgame = new Game();
	//Pause* pause = new Pause();
	GameOver* gameover = new GameOver();

	//state = newgame;
	state = newgame;
	//state->doTheLoop(event);

	while (window.isOpen())
	{ 
		//const type_info& type = typeid(*state);
		state->doTheLoop(event, window);
		
		if (typeid(*state) == typeid(Game))
		{
			if (state->gameOver)
				state = gameover;
		}
	}

	return 0;
}