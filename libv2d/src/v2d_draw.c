#include "v2d.h"
#include "v2d_enums.h"
#include "v2d_internal.h"
#include <SDL3/SDL_gpu.h>
#include <cglm/cam.h>
#include <cglm/mat3.h>

void V2D_DrawRect(V2D_RenderContext *ctx, V2D_Rect rect, V2D_Brush *brush) {
    if (brush->type == V2D_BRUSH_SOLID) {
        V2D_SolidBrush solid_brush = brush->solid_brush;

        V2D_DefaultVertex vertices[6] = {
            {{rect.x, rect.y}, solid_brush.color},
            {{rect.x, rect.y + rect.height}, solid_brush.color},
            {{rect.x + rect.width, rect.y + rect.height}, solid_brush.color},
            {{rect.x, rect.y}, solid_brush.color},
            {{rect.x + rect.width, rect.y + rect.height}, solid_brush.color},
            {{rect.x + rect.width, rect.y}, solid_brush.color},
        };

        SDL_GPUBuffer *vertex_buffer = V2D_CreateBuffer(ctx->app, vertices, sizeof(vertices), SDL_GPU_BUFFERUSAGE_VERTEX);

        V2D_TransformUniformBuffer transform = {};
        glm_mat4_identity(transform.model);
        glm_mat4_identity(transform.view);
        glm_ortho(0.0, (float)ctx->width, (float)ctx->height, 0.0, 0.0, 1.0, transform.projection);

        V2D_DefaultUniformBuffer1 uniform = {
            .time = ctx->app->currentTime,
            .resolution.width = (float)ctx->width,
            .resolution.height = (float)ctx->height,
        };

        if (ctx->graphics_pipeline != ctx->app->default_graphics_pipeline) {
            SDL_BindGPUGraphicsPipeline(ctx->render_pass, ctx->app->default_graphics_pipeline);
        }

        SDL_GPUBufferBinding bufferBindings[] = {
            {.buffer = vertex_buffer, .offset = 0},
        };

        SDL_BindGPUVertexBuffers(ctx->render_pass, 0, bufferBindings, 1);

        SDL_PushGPUVertexUniformData(ctx->command_buffer, 0, &transform, sizeof(transform));

        SDL_PushGPUFragmentUniformData(ctx->command_buffer, 0, &uniform, sizeof(uniform));

        SDL_DrawGPUPrimitives(ctx->render_pass, sizeof(vertices) / sizeof(V2D_DefaultVertex), 1, 0, 0);

        SDL_ReleaseGPUBuffer(ctx->app->device, vertex_buffer);
    }
}

void V2D_FillRectSolidColor(V2D_RenderContext *ctx, V2D_Rect rect, V2D_Color color) {
    V2D_DefaultVertex vertices[6] = {
        {{rect.x, rect.y}, color},
        {{rect.x, rect.y + rect.height}, color},
        {{rect.x + rect.width, rect.y + rect.height}, color},
        {{rect.x, rect.y}, color},
        {{rect.x + rect.width, rect.y + rect.height}, color},
        {{rect.x + rect.width, rect.y}, color},
    };

    SDL_GPUBuffer *vertex_buffer = V2D_CreateBuffer(ctx->app, vertices, sizeof(vertices), SDL_GPU_BUFFERUSAGE_VERTEX);

    V2D_TransformUniformBuffer transform = {};
    glm_mat4_identity(transform.model);
    glm_mat4_identity(transform.view);
    glm_ortho(0.0, (float)ctx->width, (float)ctx->height, 0.0, 0.0, 1.0, transform.projection);

    V2D_DefaultUniformBuffer1 uniform = {
        .time = ctx->app->currentTime,
        .resolution.width = (float)ctx->width,
        .resolution.height = (float)ctx->height,
    };

    if (ctx->graphics_pipeline != ctx->app->default_graphics_pipeline) {
        SDL_BindGPUGraphicsPipeline(ctx->render_pass, ctx->app->default_graphics_pipeline);
        ctx->graphics_pipeline = ctx->app->default_graphics_pipeline;
    }

    SDL_GPUBufferBinding bufferBindings[] = {
        {.buffer = vertex_buffer, .offset = 0},
    };

    SDL_BindGPUVertexBuffers(ctx->render_pass, 0, bufferBindings, 1);

    SDL_PushGPUVertexUniformData(ctx->command_buffer, 0, &transform, sizeof(transform));

    SDL_PushGPUFragmentUniformData(ctx->command_buffer, 0, &uniform, sizeof(uniform));

    SDL_DrawGPUPrimitives(ctx->render_pass, sizeof(vertices) / sizeof(V2D_DefaultVertex), 1, 0, 0);

    SDL_ReleaseGPUBuffer(ctx->app->device, vertex_buffer);
}