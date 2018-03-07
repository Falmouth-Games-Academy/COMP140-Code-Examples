#include "stdafx.h"
#include "Input.h"

Input::Input()
{
}

Input::~Input()
{
}

void Input::Update()
{
	CurrentKeyBoardState.Update();
}
