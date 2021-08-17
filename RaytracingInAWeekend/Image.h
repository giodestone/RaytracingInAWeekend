#pragma once
#include "SDL.h"

class Image
{
	SDL_Texture* texture;

	size_t width;
	size_t height;
public:
	Image(SDL_Texture* texture, size_t width, size_t height);
	virtual ~Image();

	SDL_Texture* GetTexture() { return texture; }
	
	/// <summary>
	/// Set a pixel on the texture.
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="r">Red 0-255</param>
	/// <param name="g">Green 0-255</param>
	/// <param name="b">Blue 0-255</param>
	void SetPixelRGB(float x, float y, float r, float g, float b);
};

