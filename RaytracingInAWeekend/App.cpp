#include "App.h"

#include <stdexcept>

App::App()
	: isRunning(true)
	, surfaceDisplay(nullptr)
	, window(nullptr)
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
		return false;
	}

	window = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	return window != nullptr;
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
}

void App::OnRender()
{
}

void App::OnCleanup()
{
	SDL_Quit();
}
