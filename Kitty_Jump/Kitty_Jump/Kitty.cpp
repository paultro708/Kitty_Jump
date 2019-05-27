#include "Kitty.h"



Kitty::Kitty()
{
	this->kitty_pos = KITTY_INITIAL_POSITION;
	this->kitty_txtR.loadFromFile(right_png);
	this->kitty_txtL.loadFromFile(left_png);
	this->kitty_sprite.setTexture(kitty_txtR);
	this->kitty_sprite.setPosition(KITTY_INITIAL_POSITION);
}


Kitty::~Kitty()
{
}

void Kitty::moveLeft()
{
	this->kitty_pos.x -= STEP;
}

void Kitty::moveRight()
{
	this->kitty_pos.x += STEP;
	//this->kitty_sprite.setPosition(position);
	this->kitty_sprite.move(kitty_pos.x, kitty_pos.y);
}

void Kitty::move(Vector2f & offset)
{
	kitty_sprite.move(offset);
	kitty_pos += offset;
}

Vector2f Kitty::getPosition()
{
	//return position;
	return kitty_pos;
	//return this->kitty_sprite.getPosition();
}

void Kitty::setPosition(Vector2f & newPos)
{
	kitty_sprite.setPosition(newPos);
}


void Kitty::checkCylinderEffect()
{
	if (getPosition().x >= WINDOW_SIZE.x)
	{
		kitty_pos.x = 0;
		setPosition(Vector2f(kitty_pos));
	}
	if (getPosition().x <= -KITTY_SIZE.x)
	{
		kitty_pos.x = WINDOW_SIZE.x - KITTY_SIZE.x;
		setPosition(Vector2f(kitty_pos));
	}
}

void Kitty::update()
{

	checkCylinderEffect();
	this->move(getOffset());
	this->kitty_pos += getOffset();
	this->kitty_pos = kitty_sprite.getPosition();

	switch (directX)
	{
	case Right:
		this->kitty_sprite.setTexture(kitty_txtR);
		break;
	case Left:
		this->kitty_sprite.setTexture(kitty_txtL);
		break;
	default:
		break;
	}
	
}

Vector2f Kitty::getOffset()
{
	float posX = 0;
	switch (directX)
	{
	case Right:
		posX += STEP;
		break;
	case Left:
		posX -= STEP;
		break;
	default:
		break;
	}
	//to do jumping mechanism
	return Vector2f(posX, 0);
}

void Kitty::draw(RenderWindow & window)
{
	window.draw(this->kitty_sprite);
}
