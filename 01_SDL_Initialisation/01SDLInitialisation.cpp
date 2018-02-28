// 01SDLInitialisation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//Window Dimensions
const int SCREEN_WIDTH = 860;
const int SCREEN_HEIGHT = 640;

int main(int argc, char ** argsv)
{
	//SDL Window pointer
	SDL_Window * Window = nullptr;
	//Boolean to control the game loop
	bool IsRunning = true;

	//Initialise SDL Library,, if we fail display an error message to the console
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Can't initialise SDL " << SDL_GetError() << std::endl;
		return -1;
	}

	//Create a winodw, with a title and dimensions specfied. The last value is the flags, which we will revisit
	Window = SDL_CreateWindow("My First Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	//Check to see if the window has been created
	if (Window == nullptr)
	{
		std::cout << "Can't create Window" << SDL_GetError() << std::endl;
		SDL_Quit();
		return -1;
	}

	//The variable to hold SDL Events
	SDL_Event currentEvent;

	//Game Loop
	while (IsRunning)
	{
		//SDL Event pump, keep Polling while we have events to handle
		while (SDL_PollEvent(&currentEvent))
		{
			//Check the type of event
			switch (currentEvent.type)
			{
				//If this is a quit message then stop the game loop
				case SDL_QUIT:
				{
					IsRunning = false;
					break;
				}
			}
		}

		//Event loop done, now we have some time to update our game and draw stuff

	}
	
	//Cleanup in reverse order!

	//Destroy the Window
	SDL_DestroyWindow(Window);
	//Quit SDL
	SDL_Quit();
    
	return 0;
}

