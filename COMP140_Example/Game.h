#pragma once

#include "Sprite.h"
#include "Timer.h"
#include "Input.h"

class Game
{
public:
	Game();
	virtual ~Game();

	virtual bool Init();
	virtual void Shutdown();

	void Run();

	void ProcessInput();

	virtual void Update();
	virtual void Render();

	bool CreateWindow(int width, int height, const std::string& title, bool fullScreen);
	bool CreateRenderer();

	bool IsRunning()
	{
		return Running;
	};
protected:
	SDL_Window * Window;
	SDL_Renderer * Renderer;
	SDL_Event CurrentEvent;
	bool Running;

	std::vector<Sprite*> DisplayList;

	Timer GameTimer;
	Input InputSystem;

};