#pragma once

#include <SDL.h>

/// <summary>
/// Base class for a rendering scene. For all logic to do with rendering it.
/// </summary>
class Scene
{
private:
	class App* app;
public:
	Scene(App* app)
		: app(app)	{}
	~Scene() = default;

	virtual void OnInit();
	virtual void OnRender();
	virtual void OnLoop();
	virtual void OnEvent(SDL_Event* event);
	virtual void OnExit();
};

