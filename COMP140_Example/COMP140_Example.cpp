// 01SDLInitialisation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"

//Window Dimensions
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int main(int argc, char ** argsv)
{
	Game * MyGame = new Game();

	if (!MyGame->Init())
	{
		delete MyGame;
		MyGame = nullptr;
	}

	MyGame->Run();

	if (MyGame)
	{
		delete MyGame;
		MyGame = nullptr;
	}
	return 0;
}

