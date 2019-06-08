#include "Game.h"
#include "GameOver.h"
#include "Menu.h"
#include <typeinfo> 


int main()
{
	RenderWindow window(VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), WINDOW_TITLE);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(WINDOW_FRAME_LIMIT);
	window.setPosition({ 431, 0 });


	srand(time(NULL));
	Event event;
	shared_ptr <Assets> ptr_assets(new Assets());

	State *state = NULL;
	GameOver *gameover = NULL;
	Game *newgame = new Game(ptr_assets);
	Menu *menu = new Menu(ptr_assets);

	//state = newgame;
	state = newgame;
	state = menu;
	//state->doTheLoop(event);

	while (window.isOpen())
	{ 
		//const type_info& type = typeid(*state);
		state->doTheLoop(event, window);
		
		if (typeid(*state) == typeid(Menu))
		{
			if (state->play)
				state = newgame;
		}

		else if (typeid(*state) == typeid(Game))
		{
			if (state->gameOver)
			{
				gameover = new GameOver(ptr_assets, state->getScore());
				state = gameover;
			}
		}
		else if (typeid(*state) == typeid(GameOver))
		{
			if (state->play)
			{
				state->play = false;
				newgame->reset();
				//newgame= new Game(ptr_assets);
				state = newgame;
			}
		}
	}

	delete newgame, gameover, menu;
	_CrtDumpMemoryLeaks();
	return 0;
}