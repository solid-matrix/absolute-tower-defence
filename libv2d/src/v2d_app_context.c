#include "v2d_app_context.h"
#include <SDL3/SDL_gpu.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_video.h>

V2D_AppContext *V2D_CreateAppContext(V2D_Config *config) {
    V2D_AppContext *app = SDL_malloc(sizeof(V2D_AppContext));
    if (!app)
        return NULL;

    app->onLoad = config->onLoad;
    app->onUpdate = config->onUpdate;
    app->onRender = config->onRender;
    app->onEvent = config->onEvent;
    app->onUnload = config->onUnload;

    app->should_close = false;
    app->return_code = 0;

    SDL_WindowFlags windowFlags = SDL_WINDOW_HIDDEN;

    if (config->window_resiable)
        windowFlags |= SDL_WINDOW_RESIZABLE;

    if (config->window_fullscreen)
        windowFlags |= SDL_WINDOW_FULLSCREEN;

    if (config->window_borderless)
        windowFlags |= SDL_WINDOW_BORDERLESS;

    // create a window
    app->window = SDL_CreateWindow(config->window_title, config->window_width, config->window_height, windowFlags);
    if (!app->window) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "failed to create window %s", SDL_GetError());
        SDL_free(app);
        return NULL;
    }

    // create device
    app->device = SDL_CreateGPUDevice(SDL_GPU_SHADERFORMAT_SPIRV | SDL_GPU_SHADERFORMAT_DXIL | SDL_GPU_SHADERFORMAT_METALLIB, config->debug, NULL);
    if (!app->device) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "failed to create gpu device: %s", SDL_GetError());
        SDL_DestroyWindow(app->window);
        SDL_free(app);
        return NULL;
    }

    // claim window for GPU device
    if (!SDL_ClaimWindowForGPUDevice(app->device, app->window)) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "failed to claim window for device: %s", SDL_GetError());
        SDL_DestroyGPUDevice(app->device);
        SDL_DestroyWindow(app->window);
        SDL_free(app);
        return NULL;
    }

    SDL_ShowWindow(app->window);
    return app;
}

void V2D_DestroyAppContext(V2D_AppContext *app) {
    if (app->device && app->window) {
        SDL_WaitForGPUIdle(app->device);
        SDL_ReleaseWindowFromGPUDevice(app->device, app->window);
    }

    if (app->device)
        SDL_DestroyGPUDevice(app->device);

    if (app->window)
        SDL_DestroyWindow(app->window);

    if (app)
        SDL_free(app);
}

void V2D_Quit(V2D_AppContext *app, int return_code) {
    app->should_close = true;
    app->return_code = return_code;
}