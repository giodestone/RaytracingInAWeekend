#pragma once
#include "Vec3.h"

class Ray
{
private:
	Vec3 origin;
	Vec3 direction;
	
public:
	Ray() = default;
	Ray(const Vec3& origin, const Vec3& direction)
		: origin(origin), direction(direction) {};
	~Ray() = default;
	
	Vec3 Origin() { return origin; }
	Vec3 Direction() { return direction; }

	Vec3 At(double time) { return origin + (time * direction); }
};

