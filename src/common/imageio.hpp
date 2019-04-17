#pragma once

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include "common/vector.hpp"

//-----------------------------------------------------------------------------
// System Includes
//-----------------------------------------------------------------------------

#include <cstdio>

//-----------------------------------------------------------------------------
// Declarations and Definitions
//-----------------------------------------------------------------------------
namespace smallpt
{

inline void WritePPM(std::uint32_t w, std::uint32_t h, const Vector3* Ls, const char* fname) noexcept
{
	std::FILE* fp = fopen(fname, "w");

	std::fprintf(fp, "P3\n%u %u\n%u\n", w, h, 255u);
	for (std::size_t i = 0; i < w * h; ++i)
	{
		std::fprintf(fp, "%u %u %u ",
					 math::ToByte(Ls[i].m_x),
					 math::ToByte(Ls[i].m_y),
					 math::ToByte(Ls[i].m_z));
	}

	std::fclose(fp);
}

} // end namespace smallpt