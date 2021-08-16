#include "App.h"

#include <stdexcept>

App::App()
	: isRunning(true)
	, window(nullptr)
	, renderer(nullptr)
	, renderTexture(nullptr)
{
}

int App::OnExecute()
{
	SDL_SetMainReady();
	if (OnInit() == false)
	{
		throw std::exception("Failed to initialize application.");
	}

	SDL_Event event;

	while (isRunning)
	{
		while (SDL_PollEvent(&event))
		{
			OnEvent(&event);
		}

		OnLoop();
		OnRender();
	}

	OnCleanup();

	return 0;
}

bool App::OnInit()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		throw std::exception("Failed to initialise SDL.");
		return false;
	}

	window = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	if (window == nullptr)
	{
		throw std::exception("Failed to create window.");
		return false;
	}
	
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == nullptr)
	{
		throw std::exception("Failed to initialise renderer.");
		return false;
	}

	renderTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STREAMING, windowWidth, windowHeight);

	if (renderTexture == nullptr)
	{
		throw std::exception("Failed to initialise render texture.");
		return false;
	}

	SDL_RendererInfo rendererInfo;
	if (SDL_GetRendererInfo(renderer, &rendererInfo) == 0)
	{
		if (!(rendererInfo.flags | SDL_RENDERER_TARGETTEXTURE))
		{
			throw  std::exception("Render target texture not supported by renderer.");
			return false;
		}
	}
	else
	{
		throw std::exception("Unable to get render info.");
		return false;
	}

	return true;
}

void App::OnEvent(SDL_Event* event)
{
	switch (event->type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	}
}

void App::OnLoop()
{
	// # Test writing to texture

	//// unlock texture for speed

	//SDL_UnlockTexture(renderTexture);

	// set this pixel to be purple.
	SDL_Rect rect;
	rect.x = 10;
	rect.y = 10;
	rect.h = 1;
	rect.w = 1;

	uint32_t pixelColor = (255 << 16 | 0 << 8 | 255 << 0);
	
	if (SDL_UpdateTexture(renderTexture, &rect, &pixelColor, sizeof(pixelColor)) != 0)
		throw std::exception("Error setting pixel!");

	//// # lock texture for speed.
	//void* texturePixels; // access to texture pixels.
	//int texturePitch; // the current texture's pitch.
	//SDL_LockTexture(renderTexture, NULL, &texturePixels, &texturePitch);
}

void App::OnRender()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, renderTexture, nullptr, nullptr);
	SDL_RenderPresent(renderer);
}

void App::OnCleanup()
{
	SDL_Quit();
}
