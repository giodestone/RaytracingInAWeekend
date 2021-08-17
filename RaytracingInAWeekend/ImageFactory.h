#pragma once
#include <memory>

#include "Image.h"

class App;

class ImageFactory
{
public:
	ImageFactory() = default;
	virtual ~ImageFactory() = default;

	std::unique_ptr<Image> MakeGradientImage(App& app);
};

