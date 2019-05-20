#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

static const Vector2u WINDOW_SIZE = { 500, 650 };

static const string WINDOW_TITLE = "Kitty Jump!";
static const unsigned WINDOW_FRAME_LIMIT = 60;


static const Vector2f KITTY_SIZE = { 70,70 };
static const Vector2f KITTY_INITIAL_POSITION = 0.5f * (Vector2f(WINDOW_SIZE) - KITTY_SIZE) ;



static const Vector2f PLATE_SIZE = { 63, 14 };
static const unsigned NUMBER_PLATFORMS = 50;
static const Vector2f PLATFORM_INITIAL_POSITION = {0,0}; // vector for checking
//{ WINDOW_SIZE.x / 2.f, WINDOW_SIZE.y + KITTY_INITIAL_POSITION.y };

static const auto STEP = 6.f;


enum DirectionX
{
	None = 0,
	Left,
	Right
};

//enum StateType
//{
//	Menu=0,
//	Game,
//	Pause,
//	GameOver
//};