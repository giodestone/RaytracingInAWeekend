#pragma once

#include <memory>
#include <SDL.h>
#include <vector>

class Scene;

class App
{
	bool isRunning;

	SDL_Window* window;
	SDL_Renderer* renderer;

	std::vector<std::unique_ptr<Scene>> scenes;

public:	
	// Constructors
	
	App();
	~App() = default;


	// Properties
	
	SDL_Renderer* Renderer() { return renderer; }
	SDL_Window* Window() { return window; }
	bool IsRunning() { return isRunning; }

	// Constants

	static constexpr auto aspectRatio() { return static_cast<double>(windowHeight) / static_cast<double>(windowWidth); }
	
	static constexpr size_t windowWidth = 1280;
	static constexpr size_t windowHeight = 720;

	
	// Application loop functions
	
	int OnExecute();

	bool OnInit();

	void OnEvent(SDL_Event* event);

	void OnLoop();

	void OnRender();

	void OnCleanup();


	// SDL related functions
	
	SDL_Texture* MakeTexture(int width = windowWidth, int height = windowHeight);

private:
	void AddScenes();
};

