#include "Platform.h"



void Platform::move(Vector2f & deltaPos)
{
	plat_sprite.move(deltaPos);
	plat_pos += deltaPos;
}

Vector2f Platform::getPosition()
{
	return this->plat_pos;
}

void Platform::setPosition(Vector2f & newPos)
{
	plat_sprite.setPosition(newPos);
}

void Platform::draw(RenderWindow & window)
{
	window.draw(this->plat_sprite);
}

Platform::Platform()
{
	this->plat_pos = PLATFORM_INITIAL_POSITION;
	this->plat_txt.loadFromFile(plat_png);
	this->plat_sprite.setTexture(plat_txt);
	this->plat_sprite.setPosition(plat_pos);

}


Platform::~Platform()
{
}
