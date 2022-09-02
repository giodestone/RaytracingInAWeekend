#pragma once

#include <memory>
#include <SDL.h>
#include <vector>

#include "Image.h"
#include "ImageFactory.h"
#include "Scene.h"

class App
{
	bool isRunning;

	SDL_Window* window;
	SDL_Renderer* renderer;
	std::unique_ptr<Image> image;

	ImageFactory imageFactory;

	std::vector<Scene> scenes;

public:
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

	
	SDL_Texture* MakeTexture(int width = windowWidth, int height = windowHeight);
	void AddScenes();
};

