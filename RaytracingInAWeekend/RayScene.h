#pragma once
#include "Image.h"
#include "Ray.h"
#include "Scene.h"
class RayScene :
    public Scene
{
private:
	std::unique_ptr<Image> renderTexture;

	// Render Texture Properties
	static constexpr auto imageWidth = 400;
	static constexpr auto imageHeight = static_cast<int>(imageWidth / App::aspectRatio());

	// Camera
	static constexpr auto viewportHeight = 2.0;
	static constexpr auto viewportWidth = App::aspectRatio() * viewportHeight;
	static constexpr auto focalLength = 1.0;

	Point3 origin;
	Vec3 horizontal;
	Vec3 vertical;
	Vec3 lowerLeftCorner;

public:
	RayScene(std::reference_wrapper<App> app);

	void OnInit() override;
	void OnLoop() override;
	void OnRender() override;

private:
	Color rayColor(const Ray& ray);
	
};

