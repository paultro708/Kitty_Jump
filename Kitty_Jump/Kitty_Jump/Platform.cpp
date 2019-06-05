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
	plat_pos = newPos;
	plat_sprite.setPosition(newPos);
}

void Platform::draw(RenderWindow & window)
{
	window.draw(this->plat_sprite);
}

Platform::Platform(shared_ptr<Assets> ptr_assets)
{
	assets = ptr_assets;
	this->plat_pos = PLATFORM_INITIAL_POSITION;
	this->plat_sprite.setTexture(assets->PLATFORM_TEXTURE);
	this->plat_sprite.setPosition(plat_pos);
}

Platform::~Platform()
{
}
