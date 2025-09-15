#include "v2d_internal.h"
#include <SDL3/SDL_stdinc.h>

V2D_AppConfig V2D_CreateDefaultConfig() {
    return (V2D_AppConfig){
        .onLoad = NULL,
        .onUpdate = NULL,
        .onRender = NULL,
        .onEvent = NULL,
        .onUnload = NULL,

        .debug = false,
        .window_title = "",
        .window_width = 800,
        .window_height = 600,
        .window_borderless = false,
        .window_resiable = false,
        .window_fullscreen = false,
    };
}