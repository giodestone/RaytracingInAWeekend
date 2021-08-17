#include "ImageFactory.h"

#include "App.h"

std::unique_ptr<Image> ImageFactory::MakeGradientImage(App& app)
{
	auto img = std::make_unique<Image>(app, app.windowWidth, app.windowHeight);

	for (auto y = 0; y < img->GetHeight(); ++y)
	{
		for (auto x = 0; x < img->GetWidth(); ++x)
		{
			const auto r = static_cast<float>(x) / static_cast<float>(img->GetWidth() - 1);
			const auto g = static_cast<float>(y) / static_cast<float>(img->GetHeight() - 1);
			const auto b = 0.25f;

			const auto intR = static_cast<int>(255.999f * r);
			const auto intG = static_cast<int>(255.999f * g);
			const auto intB = static_cast<int>(255.999f * b);
			
			img->SetPixelRGB(x, y, intR, intG, intB);
		}
	}

	return img;
}
