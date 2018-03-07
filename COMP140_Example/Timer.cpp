#include "stdafx.h"
#include "Timer.h"

Timer::Timer()
{
	CurrentTime = 0.0f;
	ElapsedTime = 0.0f;
	LastTime = 0.0f;
}

Timer::~Timer()
{
}

void Timer::Start()
{
	LastTime = (float)(SDL_GetPerformanceCounter() / SDL_GetPerformanceFrequency());
}

void Timer::Stop()
{
}

void Timer::Update()
{
	CurrentTime = (float)(SDL_GetPerformanceCounter() / SDL_GetPerformanceFrequency());

	ElapsedTime = CurrentTime - LastTime;

	LastTime = CurrentTime;
}
