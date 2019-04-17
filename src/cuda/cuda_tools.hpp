#pragma once

//-----------------------------------------------------------------------------
// CUDA Includes
//-----------------------------------------------------------------------------

#include "cuda_runtime.h"


//-----------------------------------------------------------------------------
// System Includes
//-----------------------------------------------------------------------------

#include <cstdio>
#include <cstdlib>


//-----------------------------------------------------------------------------
// Declarations and Definitions
//-----------------------------------------------------------------------------
namespace smallpt
{

inline void HandleError(cudaError_t err, const char* file, int line)
{
	if (cudaSuccess != err)
	{
		std::printf("%s in %s at line %d\n", cudaGetErrorString(err), file, line);
		std::exit(EXIT_FAILURE);
	}
}

} // end namespace smallpt

//-----------------------------------------------------------------------------
// Defines
//-----------------------------------------------------------------------------

#define HANDLE_ERROR(err) (HandleError( err, __FILE__, __LINE__ ))


#define HANDLE_NULL(a) {if (a == NULL) { \
	std::printf( "Host memory failed in %s at line %d\n", __FILE__, __LINE__ ); \
    std::exit( EXIT_FAILURE );}}
