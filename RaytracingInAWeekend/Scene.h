#pragma once

#include "App.h"

/// <summary>
/// Base class for a scene. Should be extended.
/// </summary>
class Scene
{
private:
	std::reference_wrapper<App> app;
protected:
	std::reference_wrapper<App> GetApp() { return app; }
public:
	Scene(std::reference_wrapper<App> app)
		: app(app) {}
	~Scene() = default;

	virtual void OnInit();
	virtual void OnRender();
	virtual void OnLoop();
	virtual void OnEvent(SDL_Event* event);
	virtual void OnExit();
};

