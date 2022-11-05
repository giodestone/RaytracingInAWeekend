#pragma once
#include "Scene.h"
#include "Vec3.h"

class Image;
class Ray;

class SphereScene : public Scene
{
	std::unique_ptr<Image> renderTexture;

	// Render Texture Properties
	static constexpr auto imageWidth = 400;
	static constexpr auto imageHeight = static_cast<int>(imageWidth * App::aspectRatio());

	// Camera
	static constexpr auto viewportWidth = 3.0;
	static constexpr auto viewportHeight = App::aspectRatio() * viewportWidth;
	static constexpr auto focalLength = 1.0;

	Point3 origin;
	Vec3 horizontal;
	Vec3 vertical;
	Vec3 lowerLeftCorner;

public:
	SphereScene(std::reference_wrapper<App> app);

	void OnInit() override;
	void OnEvent(SDL_Event* event) override;
	void OnRender() override;

private:
	bool hasHitSphere(const Vec3& centre, double radius, const Ray& ray, double& outNormals);
	Color getRayColor(const Ray& ray);
};
