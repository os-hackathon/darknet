
#ifdef __HIP_ROCclr__

#include <hip/hip_runtime.h>
#include <rocrand.h>
#include <hiprand.h>
#include <hipblas.h>

#define SHFL_DOWN(val, offset) shfl_xor(val, offset)
#define cudaDeviceSynchronize hipDeviceSynchronize
#define cudaError hipError_t
#define cudaError_t hipError_t
#define cudaErrorInsufficientDriver hipErrorInsufficientDriver
#define cudaErrorNoDevice hipErrorNoDevice
#define cudaEvent_t hipEvent_t
#define cudaEventCreate hipEventCreate
#define cudaEventElapsedTime hipEventElapsedTime
#define cudaEventRecord hipEventRecord
#define cudaEventSynchronize hipEventSynchronize
#define cudaFree hipFree
#define cudaFreeHost hipHostFree
#define cudaGetDevice hipGetDevice
#define cudaGetDeviceProperties hipGetDeviceProperties
#define cudaGetDeviceCount hipGetDeviceCount
#define cudaGetErrorString hipGetErrorString
#define cudaGetLastError hipGetLastError
#define cudaHostAlloc hipHostMalloc
#define cudaHostAllocDefault hipHostMallocDefault
#define cudaMalloc hipMalloc
#define cudaMemcpy hipMemcpy
#define cudaMemcpyAsync hipMemcpyAsync
#define cudaMemcpyDeviceToHost hipMemcpyDeviceToHost
#define cudaMemcpyHostToDevice hipMemcpyHostToDevice
#define cudaMemGetInfo hipMemGetInfo
#define cudaMemset hipMemset
#define cudaReadModeElementType hipReadModeElementType
#define cudaSetDevice hipSetDevice
#define cudaSuccess hipSuccess
#define cudaMemcpyDefault hipMemcpyDefault
#define cudaStream_t hipStream_t
#define cudaPeekAtLastError hipPeekAtLastError
#define cudaEventDestroy hipEventDestroy
#define cudaStreamSynchronize hipStreamSynchronize
#define cudaStreamWaitEvent hipStreamWaitEvent
#define cudaRuntimeGetVersion hipRuntimeGetVersion
#define cudaDriverGetVersion hipDriverGetVersion
#define cudaHostAlloc hipHostMalloc
#define cudaDeviceProp hipDeviceProp_t
#define cudaHostRegisterMapped hipHostRegisterMapped
#define cudaStreamNonBlocking hipStreamNonBlocking
#define cudaEventDisableTiming hipEventDisableTiming
#define cudaEventCreateWithFlags hipEventCreateWithFlags
#define cudaStreamCreateWithFlags hipStreamCreateWithFlags
#define cudaDeviceScheduleBlockingSync hipDeviceScheduleBlockingSync
#define cudaSetDeviceFlags hipSetDeviceFlags

// Contexts
#define CUcontext hipCtx_t
#define cuCtxGetCurrent hipCtxGetCurrent
#define CUresult hipError_t



//CUBLAS -> HIPBLAS
#define cublasSetStream hipblasSetStream
#define cublasHandle_t hipblasHandle_t 
#define CUBLAS_OP_N HIPBLAS_OP_N
#define CUBLAS_OP_T HIPBLAS_OP_T
#define cublasSgemm hipblasSgemm
#define cublasStatus_t hipblasStatus_t
#define cublasCreate hipblasCreate

//CURAND -> HIPRAND
#define CURAND_RNG_PSEUDO_DEFAULT HIPRAND_RNG_PSEUDO_DEFAULT
#define curandGenerator_t hiprandGenerator_t
#define curandGenerateUniform hiprandGenerateUniform
#define curandSetPseudoRandomGeneratorSeed hiprandSetPseudoRandomGeneratorSeed
#define curandCreateGenerator hiprandCreateGenerator

#else

#include <cuda.h>
#include <cuda_runtime.h>
#include <cuda_runtime_api.h>
#include <curand.h>
#include <cublas_v2.h>

#endif
