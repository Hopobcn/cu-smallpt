#pragma once

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include "common/platform.hpp"
#include "common/math.hpp"

//-----------------------------------------------------------------------------
// Declarations and Definitions
//-----------------------------------------------------------------------------
namespace smallpt
{

//-------------------------------------------------------------------------
// Vector3
//-------------------------------------------------------------------------

struct Vector3
{
public:

	//---------------------------------------------------------------------
	// Constructors and Destructors
	//---------------------------------------------------------------------

	HOST_DEVICE_INLINE
	explicit Vector3(double xyz = 0.0) noexcept : Vector3(xyz, xyz, xyz) {}
	HOST_DEVICE_INLINE
	Vector3(double x, double y, double z) noexcept : m_x(x), m_y(y), m_z(z) {}
	Vector3(const Vector3& v) noexcept = default;
	Vector3(Vector3&& v) noexcept = default;
	~Vector3() = default;

	//---------------------------------------------------------------------
	// Assignment Operators
	//---------------------------------------------------------------------

	Vector3& operator=(const Vector3& v) = default;
	Vector3& operator=(Vector3&& v) = default;

	//---------------------------------------------------------------------
	// Member Methods
	//---------------------------------------------------------------------

	HOST_DEVICE
	bool HasNaNs() const noexcept
	{
		return std::isnan(m_x) || std::isnan(m_y) || std::isnan(m_z);
	}

	HOST_DEVICE_INLINE
	const Vector3 operator-() const noexcept
	{
		return { -m_x, -m_y, -m_z };
	}

	HOST_DEVICE_INLINE
	const Vector3 operator+(const Vector3& v) const noexcept
	{
		return { m_x + v.m_x, m_y + v.m_y, m_z + v.m_z };
	}

	HOST_DEVICE_INLINE
	const Vector3 operator-(const Vector3& v) const noexcept
	{
		return { m_x - v.m_x, m_y - v.m_y, m_z - v.m_z };
	}

	HOST_DEVICE_INLINE
	const Vector3 operator*(const Vector3& v) const noexcept
	{
		return { m_x * v.m_x, m_y * v.m_y, m_z * v.m_z };
	}

	HOST_DEVICE_INLINE
	const Vector3 operator/(const Vector3& v) const noexcept
	{
		return { m_x / v.m_x, m_y / v.m_y, m_z / v.m_z };
	}

	HOST_DEVICE_INLINE
	const Vector3 operator+(double a) const noexcept
	{
		return { m_x + a, m_y + a, m_z + a };
	}

	HOST_DEVICE_INLINE
	const Vector3 operator-(double a) const noexcept
	{
		return { m_x - a, m_y - a, m_z - a };
	}

	HOST_DEVICE_INLINE
	const Vector3 operator*(double a) const noexcept
	{
		return { m_x * a, m_y * a, m_z * a };
	}

	HOST_DEVICE_INLINE
	const Vector3 operator/(double a) const noexcept
	{
		const double inv_a = 1.0 / a;
		return { m_x * inv_a, m_y * inv_a, m_z * inv_a };
	}

	HOST_DEVICE
	Vector3& operator+=(const Vector3& v) noexcept
	{
		m_x += v.m_x;
		m_y += v.m_y;
		m_z += v.m_z;
		return *this;
	}

	HOST_DEVICE
	Vector3& operator-=(const Vector3& v) noexcept
	{
		m_x -= v.m_x;
		m_y -= v.m_y;
		m_z -= v.m_z;
		return *this;
	}

	HOST_DEVICE
	Vector3& operator*=(const Vector3& v) noexcept
	{
		m_x *= v.m_x;
		m_y *= v.m_y;
		m_z *= v.m_z;
		return *this;
	}

	HOST_DEVICE
	Vector3& operator/=(const Vector3& v) noexcept
	{
		m_x /= v.m_x;
		m_y /= v.m_y;
		m_z /= v.m_z;
		return *this;
	}

	HOST_DEVICE
	Vector3& operator+=(double a) noexcept
	{
		m_x += a;
		m_y += a;
		m_z += a;
		return *this;
	}

	HOST_DEVICE
	Vector3& operator-=(double a) noexcept
	{
		m_x -= a;
		m_y -= a;
		m_z -= a;
		return *this;
	}

	HOST_DEVICE
	Vector3& operator*=(double a) noexcept
	{
		m_x *= a;
		m_y *= a;
		m_z *= a;
		return *this;
	}

	HOST_DEVICE
	Vector3& operator/=(double a) noexcept
	{
		const double inv_a = 1.0 / a;
		m_x *= inv_a;
		m_y *= inv_a;
		m_z *= inv_a;
		return *this;
	}

	HOST_DEVICE_INLINE
	double Dot(const Vector3& v) const noexcept
	{
		return m_x * v.m_x + m_y * v.m_y + m_z * v.m_z;
	}

	HOST_DEVICE_INLINE
	const Vector3 Cross(const Vector3& v) const noexcept
	{
		return {
			m_y * v.m_z - m_z * v.m_y,
			m_z * v.m_x - m_x * v.m_z,
			m_x * v.m_y - m_y * v.m_x
		};
	}

	HOST_DEVICE_INLINE
	bool operator==(const Vector3& rhs) const noexcept
	{
		return m_x == rhs.m_x && m_y == rhs.m_y && m_z == rhs.m_z;
	}

	HOST_DEVICE_INLINE
	bool operator!=(const Vector3& rhs) const noexcept
	{
		return !(*this == rhs);
	}

	HOST_DEVICE
	double& operator[](std::size_t i) noexcept
	{
		return (&m_x)[i];
	}

	HOST_DEVICE_INLINE
	double operator[](std::size_t i) const noexcept
	{
		return (&m_x)[i];
	}

	HOST_DEVICE_INLINE
	std::size_t MinDimension() const noexcept
	{
		return (m_x < m_y && m_x < m_z) ? 0u : ((m_y < m_z) ? 1u : 2u);
	}

	HOST_DEVICE_INLINE
	std::size_t MaxDimension() const noexcept
	{
		return (m_x > m_y && m_x > m_z) ? 0u : ((m_y > m_z) ? 1u : 2u);
	}

	HOST_DEVICE_INLINE
	double Min() const noexcept
	{
		return math::Min(m_x, math::Min(m_y, m_z));
	}

	HOST_DEVICE_INLINE
	double Max() const noexcept
	{
		return math::Max(m_x, math::Max(m_y, m_z));
	}

	HOST_DEVICE_INLINE
	double Norm2_squared() const noexcept
	{
		return m_x * m_x + m_y * m_y + m_z * m_z;
	}

	HOST_DEVICE_INLINE
	double Norm2() const noexcept
	{
		return std::sqrt(Norm2_squared());
	}

	HOST_DEVICE
	void Normalize() noexcept
	{
		const double a = 1.0 / Norm2();
		m_x *= a;
		m_y *= a;
		m_z *= a;
	}

	//---------------------------------------------------------------------
	// Member Variables
	//---------------------------------------------------------------------

	double m_x, m_y, m_z;
};

//-------------------------------------------------------------------------
// Vector3 Utilities
//-------------------------------------------------------------------------

HOST_DEVICE_INLINE
const Vector3 operator+(double a, const Vector3& v) noexcept
{
	return { a + v.m_x, a + v.m_y, a + v.m_z };
}

HOST_DEVICE_INLINE
const Vector3 operator-(double a, const Vector3& v) noexcept
{
	return { a - v.m_x, a - v.m_y, a - v.m_z };
}

HOST_DEVICE_INLINE
const Vector3 operator*(double a, const Vector3& v) noexcept
{
	return { a * v.m_x, a * v.m_y, a * v.m_z };
}

HOST_DEVICE_INLINE
const Vector3 operator/(double a, const Vector3& v) noexcept
{
	return { a / v.m_x, a / v.m_y, a / v.m_z };
}

HOST_DEVICE_INLINE
const Vector3 Sqrt(const Vector3& v) noexcept
{
	return {
		std::sqrt(v.m_x),
		std::sqrt(v.m_y),
		std::sqrt(v.m_z)
	};
}

HOST_DEVICE_INLINE
const Vector3 Pow(const Vector3& v, double a) noexcept
{
	return {
		std::pow(v.m_x, a),
		std::pow(v.m_y, a),
		std::pow(v.m_z, a)
	};
}

HOST_DEVICE_INLINE
const Vector3 Abs(const Vector3& v) noexcept
{
	return {
		std::abs(v.m_x),
		std::abs(v.m_y),
		std::abs(v.m_z)
	};
}

HOST_DEVICE_INLINE
const Vector3 Min(const Vector3& v1, const Vector3& v2) noexcept
{
	return {
		math::Min(v1.m_x, v2.m_x),
		math::Min(v1.m_y, v2.m_y),
		math::Min(v1.m_z, v2.m_z)
	};
}

HOST_DEVICE_INLINE
const Vector3 Max(const Vector3& v1, const Vector3& v2) noexcept
{
	return {
		math::Max(v1.m_x, v2.m_x),
		math::Max(v1.m_y, v2.m_y),
		math::Max(v1.m_z, v2.m_z)
	};
}

HOST_DEVICE_INLINE
const Vector3 Round(const Vector3& v) noexcept
{
	return {
		std::round(v.m_x),
		std::round(v.m_y),
		std::round(v.m_z)
	};
}

HOST_DEVICE_INLINE
const Vector3 Floor(const Vector3& v) noexcept
{
	return {
		std::floor(v.m_x),
		std::floor(v.m_y),
		std::floor(v.m_z)
	};
}

HOST_DEVICE_INLINE
const Vector3 Ceil(const Vector3& v) noexcept
{
	return {
		std::ceil(v.m_x),
		std::ceil(v.m_y),
		std::ceil(v.m_z)
	};
}

HOST_DEVICE_INLINE
const Vector3 Trunc(const Vector3& v) noexcept
{
	return {
		std::trunc(v.m_x),
		std::trunc(v.m_y),
		std::trunc(v.m_z)
	};
}

HOST_DEVICE_INLINE
const Vector3 Clamp(const Vector3& v, double low = 0.0, double high = 1.0) noexcept
{
	return {
		math::Clamp(v.m_x, low, high),
		math::Clamp(v.m_y, low, high),
		math::Clamp(v.m_z, low, high) }
	;
}

HOST_DEVICE_INLINE
const Vector3 Lerp(double a, const Vector3& v1, const Vector3& v2) noexcept
{
	return v1 + a * (v2 - v1);
}

template<std::size_t X, std::size_t Y, std::size_t Z>
HOST_DEVICE_INLINE
const Vector3 Permute(const Vector3& v) noexcept
{
	return { v[X], v[Y], v[Z] };
}

HOST_DEVICE_INLINE
const Vector3 Normalize(const Vector3& v) noexcept
{
	const double a = 1.0 / v.Norm2();
	return a * v;
}

} // end namespace smallpt