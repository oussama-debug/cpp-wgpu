#include <iostream>
#include <webgpu/webgpu.h>

int main (int, char**) {
    WGPUInstanceDescriptor desc = {};
    desc.nextInChain = nullptr;

    WGPUInstance instance = wgpuCreateInstance(&desc);

    if (!instance) {
        std::cerr << "Could not initialize WebGPU!" << std::endl;
        return 1;
    }
 
    std::cout << "WGPU instance: " << instance << std::endl;

    return 0;
}
