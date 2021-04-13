#include "gpu.hpp"




#include "avgpool_layer.h"
#include "dark_cuda.h"

__global__ void forward_avgpool_layer_kernel(int n, int w, int h, int c, float *input, float *output)
{
    int id = (blockIdx.x + blockIdx.y*gridDim.x) * blockDim.x + threadIdx.x;
    if(id >= n) return;

    int k = id % c;
    id /= c;
    int b = id;

    int i;
    int out_index = (k + c*b);
    output[out_index] = 0;
    for(i = 0; i < w*h; ++i){
        int in_index = i + h*w*(k + b*c);
        output[out_index] += input[in_index];
    }
    output[out_index] /= w*h;
}

__global__ void backward_avgpool_layer_kernel(int n, int w, int h, int c, float *in_delta, float *out_delta)
{
    int id = (blockIdx.x + blockIdx.y*gridDim.x) * blockDim.x + threadIdx.x;
    if(id >= n) return;

    int k = id % c;
    id /= c;
    int b = id;

    int i;
    int out_index = (k + c*b);
    for(i = 0; i < w*h; ++i){
        int in_index = i + h*w*(k + b*c);
        in_delta[in_index] += out_delta[out_index] / (w*h);
    }
}

extern "C" void forward_avgpool_layer_gpu(avgpool_layer layer, network_state state)
{
    size_t n = layer.c*layer.batch;


    CHECK_CUDA(cudaPeekAtLastError());
}

extern "C" void backward_avgpool_layer_gpu(avgpool_layer layer, network_state state)
{
    size_t n = layer.c*layer.batch;


    CHECK_CUDA(cudaPeekAtLastError());
}
