#pragma once
#include <SDL.h>
#include <memory>

#include "Image.h"
#include "ImageFactory.h"
#include "Scene.h"
class GradientImageScene :
    public Scene
{
private:
	std::unique_ptr<Image> gradientImage;
	ImageFactory imageFactory;
	
public:
	GradientImageScene(std::reference_wrapper<App> app)
		: Scene(app) {}
	
    void OnInit() override;
	void OnRender() override;
};

