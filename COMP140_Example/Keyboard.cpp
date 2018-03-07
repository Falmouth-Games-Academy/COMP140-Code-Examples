#include "stdafx.h"
#include "Keyboard.h"

Keyboard::Keyboard()
{
}

Keyboard::~Keyboard()
{
}

void Keyboard::Update()
{
	CurrentKeyState = SDL_GetKeyboardState(NULL);
}

bool Keyboard::IsKeyDown(SDL_Scancode keyCode)
{
	return CurrentKeyState[keyCode];
}
