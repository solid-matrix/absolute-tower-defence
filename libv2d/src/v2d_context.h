#ifndef __V2D_APP_CONTEXT_H
#define __V2D_APP_CONTEXT_H

#include "v2d_config.h"
#include <SDL3/SDL_gpu.h>
#include <SDL3/SDL_video.h>

typedef struct V2D_AppContext {
    V2D_LoadFunc onLoad;
    V2D_UpdateFunc onUpdate;
    V2D_RenderFunc onRender;
    V2D_EventFunc onEvent;
    V2D_UnloadFunc onUnload;

    SDL_Window *window;
    SDL_GPUDevice *device;
    SDL_GPUGraphicsPipeline *default_graphics_pipeline;

    bool should_close;
    int return_code;

    float prevTime;
} V2D_AppContext;

typedef struct V2D_RenderContext {
    V2D_AppContext *app;
    SDL_GPUCommandBuffer *command_buffer;
    Uint32 width;
    Uint32 height;
    SDL_GPUTexture *swapchain_texture;
    SDL_GPURenderPass *render_pass;
} V2D_RenderContext;

V2D_AppContext *V2D_CreateAppContext(V2D_Config *config);

void V2D_DestroyAppContext(V2D_AppContext *app);

V2D_DECLSPEC V2D_RenderContext *V2D_CALL V2D_BeginRenderContext(V2D_AppContext *app);

V2D_DECLSPEC void V2D_CALL V2D_EndRenderContext(V2D_AppContext *app, V2D_RenderContext *draw_context);

void V2D_Quit(V2D_AppContext *app, int return_code);

#endif