#include "Button.h"


Button::Button(shared_ptr<Assets> ptr_assets, string txt, float posY)
{
	assets = ptr_assets;
	//Color kolor(0, 158, 242);

	FloatRect buttonRect = sprite.getLocalBounds();
	sprite.setTexture(assets->BUTTON_TEXTURE);
	sprite.setOrigin(sprite.getTextureRect().left + BUTTON_SIZE.x / 2.0f, sprite.getTextureRect().top + BUTTON_SIZE.y / 2.0f);
	sprite.setPosition(WINDOW_SIZE.x/2, posY);

	text.setFont(assets->RAVIE);
	text.setString(txt);
	text.setFillColor(Color(0, 158, 242)); 
	text.setCharacterSize(45);

	FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	text.setPosition({ WINDOW_SIZE.x/2.0f, posY+ 15});
}

Button::~Button()
{
}

void Button::draw(RenderWindow & window)
{
	window.draw(sprite);
	window.draw(text);
}
