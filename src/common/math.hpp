#pragma once

//-----------------------------------------------------------------------------
//  Includes
//-----------------------------------------------------------------------------

#include "common/platform.hpp"

//-----------------------------------------------------------------------------
// System Includes
//-----------------------------------------------------------------------------

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <limits>


//-----------------------------------------------------------------------------
// Declarations and Definitions
//-----------------------------------------------------------------------------

namespace smallpt
{
namespace math
{


//-------------------------------------------------------------------------
// Constants
//-------------------------------------------------------------------------

constexpr double g_pi = 3.14159265358979323846;

//-------------------------------------------------------------------------
// Utilities
//-------------------------------------------------------------------------

template <typename T, typename = std::enable_if_t<!std::is_floating_point<T>::value>>
HOST_DEVICE_INLINE
const T& Min(const T& a, const T& b)
{
	return std::min(a, b);
}

HOST_DEVICE_INLINE
double Min(const double a, const double b)
{
#if defined(__CUDA_ARCH__)
	return fmin(a, b);
#else
	return std::min(a, b);
#endif
}

template <typename T, typename = std::enable_if_t<std::is_floating_point<T>::value>>
HOST_DEVICE_INLINE
const T& Max(const T& a, const T& b)
{
	return std::max(a, b);
}

HOST_DEVICE_INLINE
double Max(const double a, const double b)
{
#if defined(__CUDA_ARCH__)
	return fmax(a, b);
#else
	return std::max(a, b);
#endif
}

HOST_DEVICE_INLINE
double Clamp(double v, double low = 0.0, double high = 1.0) noexcept
{
	return fmin(fmax(v, low), high);
}

inline
std::uint8_t ToByte(double color, double gamma = 2.2) noexcept
{
	const double gcolor = std::pow(color, 1.0 / gamma);
	return static_cast< std::uint8_t >(Clamp(255.0 * gcolor, 0.0, 255.0));
}

} // end namespace math
} // end namespace smallpt