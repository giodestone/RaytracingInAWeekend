#pragma once

#include <SDL.h>

class App
{
	bool isRunning;

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* renderTexture;

	static constexpr size_t windowWidth = 1280;
	static constexpr size_t windowHeight = 720;
	
public:
	App();

	int OnExecute();

	bool OnInit();

	void OnEvent(SDL_Event* event);

	void OnLoop();

	void OnRender();

	void OnCleanup();
};

