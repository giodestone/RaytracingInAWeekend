#pragma once
#include "SDL.h"
#include "Vec3.h"

class App;

class Image
{
	SDL_Texture* texture;

	size_t width;
	size_t height;
public:
	Image(App& app, size_t width, size_t height);
	virtual ~Image();

	SDL_Texture* GetTexture() { return texture; }
	size_t GetWidth() { return width; }
	size_t GetHeight() { return height; }
	
	/// <summary>
	/// Set a pixel on the texture.
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="r">Red 0-255</param>
	/// <param name="g">Green 0-255</param>
	/// <param name="b">Blue 0-255</param>
	void SetPixelRGB(int x, int y, int r, int g, int b);

	void SetPixelRGB(int x, int y, Color c);
};

