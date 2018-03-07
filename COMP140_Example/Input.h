#pragma once
#include "Keyboard.h"

class Input
{
public:
	Input();
	~Input();

	void Update();

	Keyboard * GetKeyboard()
	{
		return &CurrentKeyBoardState;
	}
private:
	Keyboard CurrentKeyBoardState;
};