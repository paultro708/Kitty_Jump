#include "Assets.h"



Assets::Assets()
{
	addTexture(this->BACKGROUND_TEXTURE, "images/background.png" );
	addTexture(KITTY_LEFT_TEXTURE, "images/kitty_left.png");
	addTexture(KITTY_RIGHT_TEXTURE, "images/kitty_right.png");
	addTexture(PLATFORM_TEXTURE, "images/platform.png");

	addFont(RAVIE, "font/RAVIE.ttf");
}


Assets::~Assets()
{
}

void Assets::addTexture(Texture & texture, const string &name)
{
	try {
		if (!texture.loadFromFile(name))
		throw loadTextureError;
	}
	catch (string loadTextureError) {
		cerr << loadTextureError;
		exit(1);
	}
}

void Assets::addFont(Font & font, string name)
{
	try {
		if (!font.loadFromFile(name))
		throw loadFontError;
	}
	catch (string loadFontError) {
		cerr << loadFontError;
		exit(1);
	}
}

