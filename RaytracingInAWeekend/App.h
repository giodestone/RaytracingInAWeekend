#pragma once

#include <memory>
#include <SDL.h>
#include "Image.h"

class App
{
	bool isRunning;

	SDL_Window* window;
	SDL_Renderer* renderer;
	std::unique_ptr<Image> image;

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

