#pragma once

#ifdef __CUDACC__

#define HOST __host__
#define DEVICE __device__
#define HOST_DEVICE HOST DEVICE
#define HOST_DEVICE_INLINE HOST_DEVICE inline

#else

#define HOST
#define DEVICE
#define HOST_DEVICE HOST DEVICE
#define HOST_DEVICE_INLINE HOST_DEVICE constexpr

#endif
