#ifndef __V2D_INTERNAL_H

#define __V2D_INTERNAL_H

#include "v2d.h"

#include <cglm/cglm.h>

#include <SDL3/SDL_gpu.h>
#include <cglm/types.h>

typedef struct {
    V2D_Point position;
    V2D_Color color;
} V2D_DefaultVertex;

typedef struct {
    mat4 model;
    mat4 view;
    mat4 projection;
} V2D_TransformUniformBuffer;

typedef struct {
    V2D_Extent resolution;
    float time;
} V2D_DefaultUniformBuffer1;

extern const V2D_Const V2D;

V2D_AppConfig V2D_CreateDefaultConfig();

int V2D_Run(V2D_AppConfig *config, void *state);

void V2D_Quit(V2D_AppContext *app, int return_code);

SDL_GPUBuffer *V2D_CreateBuffer(V2D_AppContext *app, void *data, Uint32 size, SDL_GPUBufferUsageFlags usage);

V2D_AppContext *V2D_CreateAppContext(V2D_AppConfig *config);

void V2D_DestroyAppContext(V2D_AppContext *app);

V2D_RenderContext *V2D_BeginRenderContext(V2D_AppContext *app);

void V2D_EndRenderContext(V2D_AppContext *app, V2D_RenderContext *draw_context);

void V2D_Quit(V2D_AppContext *app, int return_code);

SDL_GPUGraphicsPipeline *V2D_CreateDefaultGraphicsPipeline(V2D_AppContext *app);

// void V2D_DrawRectangleFill(V2D_RenderContext *ctx, V2D_Brush *brush, V2D_Point position, V2D_Extent size);

// void V2D_DrawRectangleLine(V2D_RenderContext *ctx, V2D_Pen *pen, V2D_Point position, V2D_Extent size);

void V2D_DrawRect(V2D_RenderContext *ctx, V2D_Rect rect, V2D_Brush *brush);

void V2D_FillRectSolidColor(V2D_RenderContext *ctx, V2D_Rect rect, V2D_Color color);

#endif