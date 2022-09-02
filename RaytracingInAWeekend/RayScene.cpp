#include "RayScene.h"

RayScene::RayScene(std::reference_wrapper<App> app)
	: Scene(app)
	, origin(0, 0, 0)
	, horizontal(viewportWidth, 0, 0)
	, vertical(0, viewportHeight, 0)
{
	lowerLeftCorner = origin - (horizontal / 2) - (vertical / 2) - Vec3(0, 0, focalLength);
}

void RayScene::OnInit()
{
	renderTexture = std::make_unique<Image>(GetApp().get(), imageWidth, imageHeight);

	std::clog << "Image Width: " << imageWidth << "\n"
		<< "Image Height: " << imageHeight << "\n";
}

void RayScene::OnLoop()
{
}

void RayScene::OnRender()
{
	for (auto j = imageHeight - 1; j >= 0; j--)
	{
		for (auto i = 0; i < imageWidth; i++)
		{
			auto u = static_cast<double>(i) / static_cast<double>(imageWidth - 1);
			auto v = static_cast<double>(j) / static_cast<double>(imageHeight - 1);
			Ray r(origin, lowerLeftCorner + (u * horizontal) + (v * vertical) - origin);
			Color pixelColor = rayColor(r);
			renderTexture->SetPixelRGB(i, j, pixelColor);
		}
	}
	
	SDL_RenderCopy(GetApp().get().Renderer(), renderTexture->GetTexture(), nullptr, nullptr);
}

Color RayScene::rayColor(const Ray& ray)
{
	Vec3 unitDirection = GetUnitVector(ray.Direction());
	auto t = 0.5 * (unitDirection.Y() + 1.0);
	return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}
