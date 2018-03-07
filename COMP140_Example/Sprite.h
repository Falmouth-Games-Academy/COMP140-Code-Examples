#pragma once

//Class to draw a texture to the screen
class Sprite
{
public:
	//Constructor
	Sprite();
	//virtual deconstructor because we will override this class
	virtual ~Sprite();

	//Set Position on screen
	void SetXPosition(int x);
	void SetYPosition(int y);
	//Set Width & height on Screen
	void SetDestinationWidth(int width);
	void SetDestinationHeight(int height);
	//Set the rectangle on the screen
	void SetDestinationRectangle(SDL_Rect& rect);
	void SetDestinationRectangle(int x, int y, int w, int h);

	//Set the source x and y, this is where the sprite is situated in the sprite sheet
	void SetSourceX(int x);
	void SetSourceY(int y);
	//Sets the source width and height
	void SetSourceWidth(int width);
	void SetSourceHeight(int height);
	//set the source rectangle
	void SetSourceRectangle(SDL_Rect& rect);
	void SetSourceRectangle(int x, int y, int w, int h);

	//sets the texture which will be used
	void SetTexture(SDL_Texture * texture);

	//Get the source and dest rectangles
	const SDL_Rect& GetSourceRectangle();
	const SDL_Rect& GetDestinationRectangle();
	//Get the texture
	SDL_Texture* GetTexture();

	virtual void Update() {}
protected:
	SDL_Texture *Texture;
	SDL_Rect SourceRectangle;
	SDL_Rect DestinationRectangle;
};