#pragma once

#include "Sprite.h"

class Game
{
public:
	Game();
	virtual ~Game();

	virtual bool Init();
	virtual void Shutdown();

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

};