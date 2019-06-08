#include "Button.h"


void Button::mouseOn(Vector2f &mousePosition)
{
	//Vector2f buttonPos = this->getPosition();
	//FloatRect buttonRect = sprite.getLocalBounds();

	Sprite tmp = sprite;
	//FloatRect buttonRect = sprite.getLocalBounds();
	tmp.setOrigin(0,0);
	Vector2f position = tmp.getPosition();
	position.x +=( BUTTON_SIZE.x/2.0f + 100); //zmniejszyc size
	position.y -= (BUTTON_SIZE.y / 2.0f -50);
	FloatRect buttonBounds = FloatRect(position , BUTTON_SIZE);

	if (buttonBounds.contains(mousePosition))
	{
		sprite.setTexture(assets->BUTTON_ACTIVE_TEXTURE);
		is_mouseOn = true;
		cout << "contains\n";
	}
	else
	{
		sprite.setTexture(assets->BUTTON_TEXTURE);
		is_mouseOn = false;
		cout<<"no contains\n";
	}
}

void Button::buttonClick(Event & event)
{
	const Vector2i mousePosition(event.mouseButton.x, event.mouseButton.y);
	//mouseOn(Vector2f(mousePosition));
	if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
	{
		//auto buttonPosition = m_body->getPosition();
		if (is_mouseOn)
		{
			//setTexture(m_assets.BUTTON_INACTIVE_TEXTURE);
			is_click = true;
		}			
	}
	else 
		is_click = false;
}

Button::Button(shared_ptr<Assets> ptr_assets, string txt, float posY)
{
	assets = ptr_assets;
	//Color kolor(0, 158, 242);
	sprite.setTexture(assets->BUTTON_TEXTURE);

	text.setFont(assets->RAVIE);
	text.setString(txt);
	text.setFillColor(Color(0, 158, 242)); 
	text.setCharacterSize(45);

	setPosition(Vector2f(WINDOW_SIZE.x / 2, posY));

}

Button::~Button()
{
}

void Button::draw(RenderWindow & window)
{
	window.draw(sprite);
	window.draw(text);
}

void Button::setPosition(Vector2f newPos)
{
	FloatRect buttonRect = sprite.getLocalBounds();
	sprite.setOrigin(sprite.getTextureRect().left + BUTTON_SIZE.x / 2.0f, sprite.getTextureRect().top + BUTTON_SIZE.y / 2.0f);
	sprite.setPosition(newPos);

	FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	text.setPosition({ newPos.x, newPos.y + 15 });
	this->position = sprite.getPosition();
}

Vector2f Button::getPosition()
{
	return this->position;
}

bool Button::checkButtonClick(Event &event)
{
	this->buttonClick(event);
	return is_click;
}
