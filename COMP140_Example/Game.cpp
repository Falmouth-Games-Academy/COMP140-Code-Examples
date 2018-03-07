#include "stdafx.h"
#include "Game.h"

Game::Game()
{
	Window = nullptr;
	Renderer = nullptr;
	Running = false;
}

Game::~Game()
{
	Shutdown();
}

bool Game::Init()
{
	//Initialise SDL Library,, if we fail display an error message to the console
	if (SDL_Init(SDL_INIT_VIDEO| SDL_INIT_TIMER) < 0)
	{
		std::cout << "Can't initialise SDL " << SDL_GetError() << std::endl;
		return false;
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

	if (!CreateWindow(1240, 720, "Game", false))
		return false;

	if (!CreateRenderer())
		return false;

	Running = true;

	//Create a temp surface to load image
	SDL_Surface * imageSurface = IMG_Load("assets/images/roguelikeChar_transparent.png");
	//Convert to a texture so we can store this in GPU memory
	SDL_Texture * rogueCharTexture = SDL_CreateTextureFromSurface(Renderer, imageSurface);
	//We no longer need the surface, delete it!
	SDL_FreeSurface(imageSurface);

	//Create a test sprite, you will be deriving new classes from this
	Sprite * testSprite = new Sprite();
	//set the texture we are using, please note we are using one big texture and indexing
	//using the source rectangel
	testSprite->SetTexture(rogueCharTexture);
	//we are taking a slice of the texture from 0,85 on x and y with a width of 16, 16
	//see spritesheetInfo in assets/sprites folder for details
	testSprite->SetSourceRectangle(0, 85, 16, 16);
	//we are drawing thje sprite at 0,0 with the width and height of 16
	testSprite->SetDestinationRectangle(0, 0, 64, 64);

	DisplayList.push_back(testSprite);

	GameTimer.Start();

	return true;
}

bool Game::CreateWindow(int width, int height, const std::string & title, bool fullScreen)
{
	//Create a winodw, with a title and dimensions specfied. The last value is the flags, which we will revisit
	Uint32 flags = SDL_WINDOW_SHOWN;
	if (fullScreen)
	{
		flags = SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN;
	}
	Window = SDL_CreateWindow(title.c_str() , SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);
	//Check to see if the window has been created
	if (Window == nullptr)
	{
		std::cout << "Can't create Window" << SDL_GetError() << std::endl;
		Shutdown();
		return false;
	}
	return true;
}

bool Game::CreateRenderer()
{
	//Create Hardware Renderer
	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);

	if (Renderer == nullptr)
	{
		std::cout << "Can't create renderer " << SDL_GetError() << std::endl;
		Shutdown();
		return false;
	}
	return true;
}

void Game::Shutdown()
{
	for (auto iter = DisplayList.begin(); iter != DisplayList.end();)
	{
		if ((*iter))
		{
			delete (*iter);
			(*iter) = nullptr;
			iter = DisplayList.erase(iter);
		}
		else
		{
			iter++;
		}
	}
	//Destroy Renderer
	SDL_DestroyRenderer(Renderer);
	//Destroy the Window
	SDL_DestroyWindow(Window);
	//Quit Image
	IMG_Quit();
	//Quit SDL
	SDL_Quit();
}

void Game::Update()
{


	//Update our game
	for (Sprite * s : DisplayList)
	{
		s->Update();
	}
}

void Game::Render()
{
	SDL_SetRenderDrawColor(Renderer, 255, 0, 0, 255);
	SDL_RenderClear(Renderer);

	for (Sprite * s : DisplayList)
	{
		SDL_RenderCopy(Renderer, s->GetTexture(), &s->GetSourceRectangle(), &s->GetDestinationRectangle());
	}

	
	SDL_RenderPresent(Renderer);
}

void Game::Run()
{
	float lag = 0.0f;
	const float MS_PER_UPDATE = 0.01f;
	
	while (Running)
	{
		//SDL Event pump, keep Polling while we have events to handle
		while (SDL_PollEvent(&CurrentEvent))
		{
			//Check the type of event
			switch (CurrentEvent.type)
			{
				//If this is a quit message then stop the game loop
				case SDL_QUIT:
				{
					Running = false;
					break;
				}
			}
		}

		GameTimer.Update();

		lag += GameTimer.GetElpasedTime();

		ProcessInput();

		while (lag >= MS_PER_UPDATE)
		{
			Update();
			lag -= MS_PER_UPDATE;
		}

		Render();
	}
}

void Game::ProcessInput()
{
	InputSystem.Update();
	Keyboard * currentKeyboardState = InputSystem.GetKeyboard();
	if (currentKeyboardState->IsKeyDown(SDL_SCANCODE_ESCAPE)) 
	{
		Running = false;
	}
}


