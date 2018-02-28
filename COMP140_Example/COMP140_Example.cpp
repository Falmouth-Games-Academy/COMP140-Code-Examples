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
	SDL_Renderer * Renderer = nullptr;

	//Boolean to control the game loop
	bool IsRunning = true;

	//Initialise SDL Library,, if we fail display an error message to the console
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Can't initialise SDL " << SDL_GetError() << std::endl;
		return -1;
	}

	//use image flags to request support for the following image formats
	int imgFlag = IMG_INIT_PNG | IMG_INIT_JPG;
	//Initialise the IMG library and check the results
	int imgFlagResults = IMG_Init(imgFlag);
	if (imgFlagResults != imgFlag)
	{
		//We failed then we can only use BMPs
		std::cout << "Can't load in PNG and JPG support, we can use BMPs " << IMG_GetError() << std::endl;
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

	//Create Hardware Renderer
	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);

	if (Renderer == nullptr)
	{
		std::cout << "Can't create renderer " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(Window);
		IMG_Quit();
		SDL_Quit();
		return -1;
	}

	//Create a temp surface to load image
	SDL_Surface * imageSurface = IMG_Load("assets/images/roguelikeChar_transparent.png");
	//Convert to a texture so we can store this in GPU memory
	SDL_Texture * rogueCharTexture = SDL_CreateTextureFromSurface(Renderer, imageSurface);
	//We no longer need the surface, delete it!
	SDL_FreeSurface(imageSurface);

	//source rect, this for copy from the texture
	SDL_Rect srcRect;
	srcRect.x = 0;
	srcRect.y = 51;
	srcRect.w = 16;
	srcRect.h = 16;

	//dest rect, this is where the image is going to be displayed
	SDL_Rect destRect;
	destRect.x = 100;
	destRect.y = 100;
	destRect.w = 64;
	destRect.h = 64;

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
		SDL_SetRenderDrawColor(Renderer, 255, 0, 0, 255);
		SDL_RenderClear(Renderer);

		//Render Copy, this will draw the image to the backbuffer and the renderer will present it later
		SDL_RenderCopy(Renderer, rogueCharTexture, &srcRect, &destRect);

		SDL_RenderPresent(Renderer);
	}
	
	//Cleanup in reverse order!

	SDL_DestroyTexture(rogueCharTexture);
	//Destroy Renderer
	SDL_DestroyRenderer(Renderer);
	//Destroy the Window
	SDL_DestroyWindow(Window);
	//Quit Image
	IMG_Quit();
	//Quit SDL
	SDL_Quit();
    
	return 0;
}

