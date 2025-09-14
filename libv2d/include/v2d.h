#ifndef __V2D_H
#define __V2D_H

#ifdef _WIN32
#ifdef DLL_EXPORT
#define V2D_DECLSPEC __declspec(dllexport)
#else

#define V2D_DECLSPEC __declspec(dllimport)
#endif

#define V2D_CALL __cdecl

#else
#define V2D_DECLSPEC
#define V2D_CALL
#endif

#include "SDL3/SDL.h"
#include <stdbool.h>
#include <stddef.h>

typedef struct V2D_Config V2D_Config;

typedef struct V2D_Data V2D_Data;

typedef struct V2D_AppContext V2D_AppContext;

typedef struct V2D_RenderContext V2D_RenderContext;

typedef void (*V2D_LoadFunc)(void *state, V2D_AppContext *app_ctx);

typedef void (*V2D_UpdateFunc)(void *state, V2D_AppContext *app_ctx, float dt);

typedef void (*V2D_RenderFunc)(void *state, V2D_AppContext *app_ctx, V2D_RenderContext *render_ctx);

typedef void (*V2D_EventFunc)(void *state, V2D_AppContext *app_ctx, SDL_Event *event);

typedef void (*V2D_UnloadFunc)(void *state, V2D_AppContext *app_ctx);

struct V2D_Config {

    V2D_LoadFunc onLoad;
    V2D_UpdateFunc onUpdate;
    V2D_RenderFunc onRender;
    V2D_EventFunc onEvent;
    V2D_UnloadFunc onUnload;

    // TODO console_enabled;
    bool debug;

    char *window_title;
    int window_width;
    int window_height;

    // TODO icon

    bool window_borderless;
    bool window_resiable;
    bool window_fullscreen;

    // TODO window_vsync;
};

typedef struct {
    float x;
    float y;
} V2D_Point;

typedef struct {
    float width;
    float height;
} V2D_Extent;

typedef struct {
    float r;
    float g;
    float b;
    float a;
} V2D_Color;

V2D_DECLSPEC V2D_Config V2D_CALL V2D_CreateDefaultConfig();

V2D_DECLSPEC int V2D_CALL V2D_Run(V2D_Config *config, void *state);

V2D_DECLSPEC void V2D_CALL V2D_Quit(V2D_AppContext *app, int return_code);

#endif