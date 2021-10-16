#pragma once

#include <cmath>
#include <iostream>

/// <summary>
/// Class for representing a point in 3D space, or a color (see aliases at bottom of this file).
/// </summary>
class Vec3
{
	typedef double RealDataType;
	
	RealDataType x;
	RealDataType y;
	RealDataType z;

public:
	Vec3(const RealDataType x=0, const RealDataType y=0, const RealDataType z=0) : x(x), y(y), z(z) {}

	RealDataType X() const { return x; }
	RealDataType Y() const { return y; }
	RealDataType Z() const { return z; }

	/// <summary>
	/// For accessing the vector like an array.
	/// </summary>
	/// <param name="i"></param>
	/// <returns></returns>
	RealDataType operator[](size_t i) const
	{
		switch (i)
		{
		case 0:
			return x;
			break;
		case 1:
			return y;
			break;
		case 2:
			return z;
			break;
		default:
			throw std::out_of_range("This vector only has three values, you have asked for too many!");
			break;
		}
	}

	/// <summary>
	/// For accessing the vector like an array.
	/// </summary>
	/// <param name="i"></param>
	/// <returns></returns>
	RealDataType & operator[](size_t i)
	{
		switch (i)
		{
		case 0:
			return x;
			break;
		case 1:
			return y;
			break;
		case 2:
			return z;
			break;
		default:
			throw std::out_of_range("This vector only has three values, you have asked for too many!");
			break;
		}
	}
	
	Vec3 operator-() const { return { -x, -y, -z }; }
	// Vec3 operator-(const Vec3 rhs) const { return { rhs.x - x, rhs.y - y, rhs.z - z }; } <-- no bad idea don't do this.

	Vec3& operator+=(const Vec3& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	}
	
	Vec3& operator*= (const RealDataType scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
		return *this;
	}

	Vec3& operator/= (const RealDataType scalar)
	{
		x /= scalar;
		y /= scalar;
		z /= scalar;
		return *this;
	}
	
	RealDataType GetLength() const
	{
		return sqrt(GetLengthSquared());
	}

	RealDataType GetLengthSquared() const
	{
		return x * x + y * y + z * z;
	}
};

// aliases

using Point3 = Vec3;
using Color = Vec3;