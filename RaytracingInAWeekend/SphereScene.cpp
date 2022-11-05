#include "SphereScene.h"

#include "Ray.h"
#include "Image.h"

SphereScene::SphereScene(std::reference_wrapper<App> app) :
	Scene(app)
	, origin(0, 0, 0)
	, horizontal(viewportWidth, 0, 0)
	, vertical(0, viewportHeight, 0)
{
	lowerLeftCorner = origin - (horizontal / 2) - (vertical / 2) - Vec3(0, 0, focalLength);
}
void SphereScene::OnInit()
{
	Scene::OnInit();

	renderTexture = std::make_unique<Image>(GetApp().get(), imageWidth, imageHeight);
}

void SphereScene::OnEvent(SDL_Event* event)
{
	Scene::OnEvent(event);
}

void SphereScene::OnRender()
{
	Scene::OnRender();

	for (auto j = 0; j < imageHeight; j++)
	{
		for (auto i = 0; i < imageWidth; i++)
		{
			auto u = static_cast<double>(i) / static_cast<double>(imageWidth - 1);
			auto v = static_cast<double>(j) / static_cast<double>(imageHeight - 1);
			Ray r(origin, lowerLeftCorner + (u * horizontal) + (v * vertical) - origin);
			Color pixelColor = getRayColor(r);
			renderTexture->SetPixelRGB(i, j, pixelColor);
		}
	}

	SDL_RenderCopy(GetApp().get().Renderer(), renderTexture->GetTexture(), nullptr, nullptr);
}

bool SphereScene::hasHitSphere(const Vec3& centre, double radius, const Ray& ray, double& outNormals)
{
	Vec3 oc = ray.Origin() - centre;
	auto a = Dot(ray.Direction(), ray.Direction());
	auto b = 2.0 * Dot(oc, ray.Direction());
	auto c = Dot(oc, oc) - radius * radius;
	auto discriminant = (b * b) - (4.0 * a * c);

	if (discriminant >= 0.)
	{
		outNormals = (-b - sqrt(discriminant)) / (2.0 * a);
		return true;
	}
	else
		return false;
}

Color SphereScene::getRayColor(const Ray& ray)
{
	double normal;
	if (hasHitSphere(Point3(0., 0., -1.), 0.5, ray, normal))
	{
		auto n = GetUnitVector(ray.At(normal) - Vec3(0., 0., -1.));
		return 0.5 * Color(n.X() + 1., n.Y() + 1., n.Z() + 1.);
	}

	auto unitDirection = GetUnitVector(ray.Direction());
	auto t = 0.5 * (unitDirection.Y() + 1.);

	return (1. - t) * Color(1., 1., 1.) + t * Color(0.5, 0.7, 1.0);
}
