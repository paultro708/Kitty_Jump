#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <memory>

using namespace sf;
using namespace std;

static const Vector2u WINDOW_SIZE = { 500, 650 };

static const string WINDOW_TITLE = "Kitty Jump!";
static const unsigned WINDOW_FRAME_LIMIT = 60;



static const Vector2f KITTY_SIZE = { 70,70 };
static const Vector2f KITTY_INITIAL_POSITION = 0.5f * (Vector2f(WINDOW_SIZE) - KITTY_SIZE) ;
static const unsigned MAX_KITTY_JUMP_HEIGHT = 150.f;
static const unsigned PLATFORM_DELTA_REFLECT =  22.f;

static const Vector2f PLATFORM_SIZE = { 63, 14 };
static const unsigned NUMBER_PLATFORMS = 10;
static const Vector2f PLATFORM_INITIAL_POSITION = {0,0}; // vector for checking
//{ WINDOW_SIZE.x / 2.f, WINDOW_SIZE.y + KITTY_INITIAL_POSITION.y };

static const auto STEP = 6.f;

const int KITTY_LEFT_BOUNDING_BOX = 25;
const int KITTY_RIGHT_BOUNDING_BOX = 45;

enum DirectionX
{
	None = 0,
	Left,
	Right
};

enum MenuStates
{
	Play = 0,
	Help,
	Ranking,
	Quit
};

//enum StateType
//{
//	Menu=0,
//	Game,
//	Pause,
//	GameOver
//};