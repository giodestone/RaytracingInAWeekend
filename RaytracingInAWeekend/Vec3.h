#pragma once

#include <cmath>
#include <iostream>

typedef double VectorRealDataType;

/// <summary>
/// Class for representing a point in 3D space, or a color (see aliases at bottom of this file).
/// </summary>
class Vec3
{	
	VectorRealDataType x;
	VectorRealDataType y;
	VectorRealDataType z;

public:
	Vec3(const VectorRealDataType x=0, const VectorRealDataType y=0, const VectorRealDataType z=0) : x(x), y(y), z(z) {}

	VectorRealDataType X() const { return x; }
	VectorRealDataType Y() const { return y; }
	VectorRealDataType Z() const { return z; }

	/// <summary>
	/// For accessing the vector like an array.
	/// </summary>
	/// <param name="i"></param>
	/// <returns></returns>
	VectorRealDataType operator[](size_t i) const
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
	VectorRealDataType & operator[](size_t i)
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
	
	Vec3& operator*= (const VectorRealDataType scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
		return *this;
	}

	Vec3& operator/= (const VectorRealDataType scalar)
	{
		x /= scalar;
		y /= scalar;
		z /= scalar;
		return *this;
	}
	
	VectorRealDataType GetLength() const
	{
		return sqrt(GetLengthSquared());
	}

	VectorRealDataType GetLengthSquared() const
	{
		return x * x + y * y + z * z;
	}
};

// aliases

using Point3 = Vec3;
using Color = Vec3;

#pragma region VectorUtilityFunctions
inline std::ostream& operator<<(std::ostream& out, const Vec3& v)
{
	return out << "(" << v.X() << ", " << v.Y() << ", " << v.Z() << ")";
}

inline Vec3 operator+ (const Vec3& lhs, const Vec3& rhs)
{
	return { lhs.X() + rhs.X(), lhs.Y() + rhs.Y(), lhs.Z() + rhs.Z() };
}

inline Vec3 operator- (const Vec3& lhs, const Vec3& rhs)
{
	return { lhs.X() - rhs.X(), lhs.Y() - rhs.Y(), lhs.Z() - rhs.Z() }; // does NOT fix a - b problems.
}

inline Vec3 operator* (const Vec3& lhs, const Vec3& rhs)
{
	return { lhs.X() * rhs.X(), lhs.Y() * rhs.Y(), lhs.Z() * rhs.Z() };
}

inline Vec3 operator* (const Vec3& lhs, const VectorRealDataType scalar)
{
	return { lhs.X() * scalar, lhs.Y() * scalar, lhs.Z() * scalar };
}

inline Vec3 operator* (const VectorRealDataType scalar, const Vec3& rhs)
{
	return { rhs.X() * scalar, rhs.Y() * scalar, rhs.Z() * scalar };
}

inline Vec3 operator/ (Vec3 v, VectorRealDataType scalar)
{
	return (1 / scalar) * v;
}

inline VectorRealDataType Dot(const Vec3& a, const Vec3& b)
{
	return a[0] * b[0] +
		a[1] * b[1] +
		a[2] * a[2];
}

inline Vec3 GetUnitVector(Vec3 v)
{
	return v / v.GetLength();
}
#pragma endregion VectorUtilityFunctions

#pragma region ColorUtilityFunctions
void WriteColor(std::ostream &out, Color color)
{
	out << static_cast<int> (255.999 * color[0]) << ' '
		<< static_cast<int> (255.999 * color[1]) << ' '
		<< static_cast<int> (255.999 * color[2]);
}
#pragma endregion ColorUtilityFunctions