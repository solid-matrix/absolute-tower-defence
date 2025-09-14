#include "v2d_buffer.h"
#include "v2d_context.h"
#include <SDL3/SDL_gpu.h>
#include <SDL3/SDL_stdinc.h>

SDL_GPUBuffer *V2D_CreateBuffer(V2D_AppContext *app, void *data, Uint32 size, SDL_GPUBufferUsageFlags usage) {
    SDL_GPUBufferCreateInfo buffer_info = {
        .size = size,
        .usage = usage,
    };

    SDL_GPUBuffer *buffer = SDL_CreateGPUBuffer(app->device, &buffer_info);

    SDL_GPUTransferBufferCreateInfo transfer_info = {
        .size = size,
        .usage = SDL_GPU_TRANSFERBUFFERUSAGE_UPLOAD,
    };
    SDL_GPUTransferBuffer *transfer_buffer = SDL_CreateGPUTransferBuffer(app->device, &transfer_info);
    void *transfer_data = SDL_MapGPUTransferBuffer(app->device, transfer_buffer, false);
    SDL_memcpy(transfer_data, data, size);
    SDL_UnmapGPUTransferBuffer(app->device, transfer_buffer);

    // start a copy pass
    SDL_GPUCommandBuffer *command_buffer = SDL_AcquireGPUCommandBuffer(app->device);
    SDL_GPUCopyPass *copy_pass = SDL_BeginGPUCopyPass(command_buffer);

    // where is the data
    SDL_GPUTransferBufferLocation location = {
        .transfer_buffer = transfer_buffer,
        .offset = 0,
    };

    // where to upload the data
    SDL_GPUBufferRegion region = {
        .buffer = buffer,
        .size = size,
        .offset = 0,
    };

    // upload the data
    SDL_UploadToGPUBuffer(copy_pass, &location, &region, true);

    // end the copy pass
    SDL_EndGPUCopyPass(copy_pass);
    SDL_SubmitGPUCommandBuffer(command_buffer);
    SDL_ReleaseGPUTransferBuffer(app->device, transfer_buffer);

    return buffer;
}