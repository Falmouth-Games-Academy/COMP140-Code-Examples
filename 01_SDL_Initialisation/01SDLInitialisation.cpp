// 01SDLInitialisation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

const int SCREEN_WIDTH = 860;
const int SCREEN_HEIGHT = 640;

int main(int argc, char ** argsv)
{
	SDL_Window * Window = nullptr;
	bool IsRunning = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Can't initialise SDL " << SDL_GetError() << std::endl;
		return -1;
	}

	Window = SDL_CreateWindow("My First Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (Window == nullptr)
	{
		std::cout << "Can't create Window" << SDL_GetError() << std::endl;
		SDL_Quit();
		return -1;
	}

	SDL_Event currentEvent;

	while (IsRunning)
	{
		while (SDL_PollEvent(&currentEvent))
		{
			switch (currentEvent.type)
			{
				case SDL_QUIT:
				{
					IsRunning = false;
					break;
				}
			}
		}

		//Game stuff

	}
	

	SDL_DestroyWindow(Window);
	SDL_Quit();
    return 0;
}

