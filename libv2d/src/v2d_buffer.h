#ifndef __V2D_BUFFER_H
#define __V2D_BUFFER_H

#include "v2d.h"
#include <SDL3/SDL_gpu.h>

SDL_GPUBuffer *V2D_CreateBuffer(V2D_AppContext *app, void *data, Uint32 size, SDL_GPUBufferUsageFlags usage);

#endif