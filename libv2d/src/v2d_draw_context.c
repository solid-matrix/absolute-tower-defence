#include "v2d_draw_context.h"
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_stdinc.h>

V2D_RenderContext *V2D_BeginRenderContext(V2D_AppContext *app) {
    V2D_RenderContext *draw_context = SDL_malloc(sizeof(V2D_RenderContext));

    draw_context->command_buffer = SDL_AcquireGPUCommandBuffer(app->device);

    if (!SDL_WaitAndAcquireGPUSwapchainTexture(draw_context->command_buffer, app->window, &draw_context->swapchain_texture, &draw_context->width, &draw_context->height) || !draw_context->swapchain_texture) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "failed to acquire swapchain texture %s", SDL_GetError());
        SDL_SubmitGPUCommandBuffer(draw_context->command_buffer);
        // TODO error handling
        //return SDL_APP_CONTINUE;
    }

    // create the color target
    SDL_GPUColorTargetInfo color_target_info = {
        .clear_color = {0.0f, 0.0f, 0.0f, 0.0f},
        .load_op = SDL_GPU_LOADOP_CLEAR,
        .mip_level = 0,
        .store_op = SDL_GPU_STOREOP_STORE,
        .texture = draw_context->swapchain_texture,
        .cycle = true,
        .layer_or_depth_plane = 0,
        .cycle_resolve_texture = false,
    };

    draw_context->render_pass = SDL_BeginGPURenderPass(draw_context->command_buffer, &color_target_info, 1, NULL);

    return draw_context;
}

void V2D_EndRenderContext(V2D_AppContext *app, V2D_RenderContext *draw_context) {
    // end the render pass
    SDL_EndGPURenderPass(draw_context->render_pass);

    // submit the command buffer
    SDL_SubmitGPUCommandBuffer(draw_context->command_buffer);
}
