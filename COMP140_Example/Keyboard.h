#pragma once

class Keyboard
{
public:
	Keyboard();
	~Keyboard();

	void Update();

	bool IsKeyDown(SDL_Scancode keyCode);

private:
	const Uint8 * CurrentKeyState;
};
