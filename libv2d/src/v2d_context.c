#include "v2d_internal.h"

#include <SDL3/SDL_gpu.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_video.h>

V2D_AppContext *V2D_CreateAppContext(V2D_AppConfig *config) {
    V2D_AppContext *app = SDL_malloc(sizeof(V2D_AppContext));
    if (!app)
        return NULL;

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

    app->default_graphics_pipeline = V2D_CreateDefaultGraphicsPipeline(app);

    SDL_ShowWindow(app->window);
    return app;
}

void V2D_DestroyAppContext(V2D_AppContext *app) {
    if (app->default_graphics_pipeline) {
        SDL_ReleaseGPUGraphicsPipeline(app->device, app->default_graphics_pipeline);
    }

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

V2D_RenderContext *V2D_BeginRenderContext(V2D_AppContext *app) {
    V2D_RenderContext *render_context = SDL_malloc(sizeof(V2D_RenderContext));

    render_context->app = app;
    render_context->command_buffer = SDL_AcquireGPUCommandBuffer(app->device);
    render_context->graphics_pipeline = NULL;

    if (!SDL_WaitAndAcquireGPUSwapchainTexture(render_context->command_buffer, app->window, &render_context->swapchain_texture, &render_context->width, &render_context->height) || !render_context->swapchain_texture) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "failed to acquire swapchain texture %s", SDL_GetError());
        SDL_SubmitGPUCommandBuffer(render_context->command_buffer);
        // TODO error handling
        //return SDL_APP_CONTINUE;
    }

    // create the color target
    SDL_GPUColorTargetInfo color_target_info = {
        .texture = render_context->swapchain_texture,
        .mip_level = 0,
        .layer_or_depth_plane = 0,
        .clear_color = {1.0f, 1.0f, 1.0f, 1.0f},
        .load_op = SDL_GPU_LOADOP_CLEAR,
        .store_op = SDL_GPU_STOREOP_STORE,
        .resolve_texture = NULL,
        .resolve_mip_level = 0,
        .resolve_layer = 0,
        .cycle = false,
        .cycle_resolve_texture = false,
    };

    render_context->render_pass = SDL_BeginGPURenderPass(render_context->command_buffer, &color_target_info, 1, NULL);

    return render_context;
}

void V2D_EndRenderContext(V2D_AppContext *app, V2D_RenderContext *render_context) {
    // end the render pass
    SDL_EndGPURenderPass(render_context->render_pass);

    // submit the command buffer
    SDL_SubmitGPUCommandBuffer(render_context->command_buffer);
}