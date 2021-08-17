#include "Image.h"

#include <exception>

Image::Image(SDL_Texture* texture, size_t width, size_t height)
	: texture(texture)
	, width(width)
	, height(height)
{
}

Image::~Image()
{
	SDL_DestroyTexture(texture);
	texture = nullptr;
}

void Image::SetPixelRGB(float x, float y, float r, float g, float b)
{
	SDL_Rect pixelRect;
	pixelRect.x = static_cast<int>(x);
	pixelRect.y = static_cast<int>(y);
	pixelRect.h = 1;
	pixelRect.w = 1;

	uint32_t pixelColor = (static_cast<uint32_t>(r) << 16 | static_cast<uint32_t>(g) << 8 | static_cast<uint32_t>(b) << 0);
	
#ifdef _DEBUG
	if (SDL_UpdateTexture(texture, &pixelRect, &pixelColor, sizeof(pixelColor)) != 0)
		throw std::exception("Error setting pixel!");
#else
	SDL_UpdateTexture(texture, &rect, &pixelColor, sizeof(pixelColor))
#endif

	//// # lock texture for speed.
	//void* texturePixels; // access to texture pixels.
	//int texturePitch; // the current texture's pitch.
	//SDL_LockTexture(renderTexture, NULL, &texturePixels, &texturePitch);

	//// unlock texture for speed
	//SDL_UnlockTexture(renderTexture);
}
