#include "Game.h"
#include "Pause.h"
#include "GameOver.h"
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
	Game *newgame = new Game(ptr_assets);
	GameOver *gameover = new GameOver(ptr_assets);

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

	cout << "\nuzyto:" << ptr_assets.use_count() << "accounts" << endl;
	delete newgame, gameover;
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}