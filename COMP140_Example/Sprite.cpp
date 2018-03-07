#include "stdafx.h"
#include "Sprite.h"

Sprite::Sprite()
{
	Texture = nullptr;
	
	SourceRectangle.x = 0;
	SourceRectangle.y = 0;
	SourceRectangle.w = 32;
	SourceRectangle.h = 32;

	DestinationRectangle.x = 0;
	DestinationRectangle.y = 0;
	DestinationRectangle.w = 32;
	DestinationRectangle.h = 32;
}

Sprite::~Sprite()
{
}

void Sprite::SetXPosition(int x)
{
	DestinationRectangle.x = x;
}

void Sprite::SetYPosition(int y)
{
	DestinationRectangle.y = y;
}

void Sprite::SetDestinationWidth(int width)
{
	DestinationRectangle.w = width;
}

void Sprite::SetDestinationHeight(int height)
{
	DestinationRectangle.h = height;
}

void Sprite::SetDestinationRectangle(SDL_Rect & rect)
{
	DestinationRectangle = rect;
}

void Sprite::SetDestinationRectangle(int x, int y, int w, int h)
{
	DestinationRectangle.x = x;
	DestinationRectangle.y = y;
	DestinationRectangle.w = w;
	DestinationRectangle.h = h;
}

void Sprite::SetSourceX(int x)
{
	SourceRectangle.x = x;
}

void Sprite::SetSourceY(int y)
{
	SourceRectangle.y = y;
}

void Sprite::SetSourceWidth(int width)
{
	SourceRectangle.w = width;
}

void Sprite::SetSourceHeight(int height)
{
	SourceRectangle.h = height;
}

void Sprite::SetSourceRectangle(SDL_Rect & rect)
{
	SourceRectangle = rect;
}

void Sprite::SetSourceRectangle(int x, int y, int w, int h)
{
	SourceRectangle.x = x;
	SourceRectangle.y = y;
	SourceRectangle.w = w;
	SourceRectangle.h = h;
}

void Sprite::SetTexture(SDL_Texture * texture)
{
	Texture = texture;
}

const SDL_Rect & Sprite::GetSourceRectangle()
{
	return SourceRectangle;
}

const SDL_Rect & Sprite::GetDestinationRectangle()
{
	return DestinationRectangle;
}

SDL_Texture * Sprite::GetTexture()
{
	return Texture;
}
