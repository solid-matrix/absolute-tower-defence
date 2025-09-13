#ifndef __V2D_APP_CONTEXT_H
#define __V2D_APP_CONTEXT_H

#include "v2d_config.h"
#include <SDL3/SDL_gpu.h>
#include <SDL3/SDL_video.h>

struct V2D_AppContext {
    SDL_Window *window;
    SDL_GPUDevice *device;

    V2D_LoadFunc onLoad;
    V2D_UpdateFunc onUpdate;
    V2D_RenderFunc onRender;
    V2D_EventFunc onEvent;
    V2D_UnloadFunc onUnload;

    bool should_close;
    int return_code;

    float prevTime;
};

V2D_AppContext *V2D_CreateAppContext(V2D_Config *config);

void V2D_DestroyAppContext(V2D_AppContext *app);

void V2D_Quit(V2D_AppContext *app, int return_code);

#endif