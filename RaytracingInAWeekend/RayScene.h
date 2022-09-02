#pragma once
#include "Image.h"
#include "Scene.h"
class RayScene :
    public Scene
{
private:
	std::unique_ptr<Image> renderTexture;
	
public:
	RayScene(std::reference_wrapper<App> app)
		: Scene(app) {}

	void OnInit() override;
	void OnLoop() override;
	void OnRender() override;
};

