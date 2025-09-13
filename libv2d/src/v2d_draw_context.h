#ifndef __V2D_DRAW_CONTEXT_H
#define __V2D_DRAW_CONTEXT_H

#include "v2d.h"
#include "v2d_app_context.h"
#include "v2d_config.h"

struct V2D_RenderContext {
    SDL_GPUCommandBuffer *command_buffer;
    Uint32 width;
    Uint32 height;
    SDL_GPUTexture *swapchain_texture;
    SDL_GPURenderPass *render_pass;
};

V2D_DECLSPEC V2D_RenderContext *V2D_CALL V2D_BeginRenderContext(V2D_AppContext *app);

V2D_DECLSPEC void V2D_CALL V2D_EndRenderContext(V2D_AppContext *app, V2D_RenderContext *draw_context);

#endif