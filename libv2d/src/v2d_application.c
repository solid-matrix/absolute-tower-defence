#include "v2d_application.h"

#include <SDL3/SDL_gpu.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_video.h>

V2D_Application *V2D_CreateApplication(V2D_Config *config) {
    V2D_Application *app = SDL_malloc(sizeof(V2D_Application));
    if (!app)
        return NULL;

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

void V2D_DestroyApplication(V2D_Application *app) {
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

void V2D_BeginRender(V2D_Application *app) {
    SDL_GPUTexture *swapchain_texture;
    Uint32 width, height;

    app->command_buffer = SDL_AcquireGPUCommandBuffer(app->device);

    if (!SDL_WaitAndAcquireGPUSwapchainTexture(app->command_buffer, app->window, &swapchain_texture, &width, &height) || !swapchain_texture) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "failed to acquire swapchain texture %s", SDL_GetError());
        SDL_SubmitGPUCommandBuffer(app->command_buffer);
        // TODO error handling
        //return SDL_APP_CONTINUE;
    }

    // create the color target
    SDL_GPUColorTargetInfo color_target_info = {
        .clear_color = {1.0f, 1.0f, 1.0f, 1.0f},
        .load_op = SDL_GPU_LOADOP_CLEAR,
        .mip_level = 0,
        .store_op = SDL_GPU_STOREOP_STORE,
        .texture = swapchain_texture,
        .cycle = true,
        .layer_or_depth_plane = 0,
        .cycle_resolve_texture = false,
    };

    // begin a render pass
    app->render_pass = SDL_BeginGPURenderPass(app->command_buffer, &color_target_info, 1, NULL);
}

void V2D_EndRender(V2D_Application *app) {

    // end the render pass
    SDL_EndGPURenderPass(app->render_pass);

    // submit the command buffer
    SDL_SubmitGPUCommandBuffer(app->command_buffer);
}