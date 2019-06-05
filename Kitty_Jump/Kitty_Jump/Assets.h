#pragma once
#include "consts.h"


class Assets
{
private:
	string loadTextureError = "Can not open the file\n";
	string loadFontError = "Can not load font from file\n";
public:
	Assets();
	~Assets();
	void addTexture(Texture &texture, const string &name);
	void addFont(Font &font, string name);

	Texture BACKGROUND_TEXTURE;
	Texture PLATFORM_TEXTURE;
	Texture KITTY_LEFT_TEXTURE;
	Texture KITTY_RIGHT_TEXTURE;
	//Texture BUTTON_ACTIVE_TEXTURE;
	//Texture BUTTON_INACTIVE_TEXTURE;

	Font RAVIE;
};

