#include "consts.h"
#include "Kitty.h"
#include <iostream>

int main()
{
	RenderWindow window(VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), WINDOW_TITLE);
	window.setFramerateLimit(WINDOW_FRAME_LIMIT);
	Kitty *my_kitty = new Kitty();
	Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

		}

		if (event.type == Event::KeyPressed)
			switch (event.key.code)
			{
			case Keyboard::Left:
				my_kitty->directX = Left;
				break;
			case Keyboard::Right:
				my_kitty->directX = Right;
				break;
			default:
				my_kitty->directX = None;
			}

		if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case Keyboard::Left:
				my_kitty->directX = None;
				break;
			case Keyboard::Right:
				my_kitty->directX = None;
				break;
			default:
				break;
			}
		}

		my_kitty->update();
		window.clear(Color::White);
		window.draw(my_kitty->kitty_sprite);
		window.display();
	}
	return 0;
}