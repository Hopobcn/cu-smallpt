#pragma once

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include "common/vector.hpp"

#include <iostream>


//-----------------------------------------------------------------------------
// Declarations and Definitions
//-----------------------------------------------------------------------------
namespace smallpt
{

struct Ray
{
public:
	using depth_t = std::uint32_t;

	//---------------------------------------------------------------------
	// Constructors and Destructors
	//---------------------------------------------------------------------

	HOST_DEVICE
	explicit Ray(Vector3 o, Vector3 d, double tmin = 0.0, double tmax = std::numeric_limits<double>::infinity(), std::uint32_t depth = 0u) noexcept
		: m_o(std::move(o))
		, m_d(std::move(d))
		, m_tmin(tmin)
		, m_tmax(tmax)
		, m_depth(depth)
	{};
	Ray(const Ray& ray) noexcept = default;
	Ray(Ray&& ray) noexcept = default;
	~Ray() = default;

	//---------------------------------------------------------------------
	// Assignment Operators
	//---------------------------------------------------------------------

	Ray& operator=(const Ray& ray) = default;
	Ray& operator=(Ray&& ray) = default;

	//---------------------------------------------------------------------
	// Member Methods
	//---------------------------------------------------------------------

	HOST_DEVICE
	const Vector3 operator()(double t) const noexcept
	{
		return m_o + m_d * t;
	}

	//---------------------------------------------------------------------
	// Member Variables
	//---------------------------------------------------------------------

	Vector3 m_o, m_d;
	mutable double m_tmin, m_tmax;
	depth_t m_depth;
};

} // end namespace smallpt