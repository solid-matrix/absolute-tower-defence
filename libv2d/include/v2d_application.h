#ifndef __V2D_APPLICATION_H
#define __V2D_APPLICATION_H

#include "v2d_config.h"
#include "v2d_export.h"
#include <SDL3/SDL_gpu.h>
#include <SDL3/SDL_video.h>

typedef struct V2D_Application V2D_Application;

struct V2D_Application {
    SDL_Window *window;
    SDL_GPUDevice *device;
    SDL_GPURenderPass *render_pass;
    SDL_GPUCommandBuffer *command_buffer;
    float prevTime;
};

V2D_DECLSPEC V2D_Application *V2D_CALL V2D_CreateApplication(V2D_Config *config);

V2D_DECLSPEC void V2D_CALL V2D_DestroyApplication(V2D_Application *app);

V2D_DECLSPEC void V2D_CALL V2D_BeginRender(V2D_Application *app);

V2D_DECLSPEC void V2D_CALL V2D_EndRender(V2D_Application *app);

#endif