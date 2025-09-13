#ifndef V2D_CONFIG_H
#define V2D_CONFIG_H

#include "v2d_export.h"
#include <stdbool.h>

typedef struct V2D_Config V2D_Config;

struct V2D_Config {
    // bool console_enabled;
    bool debug;

    char *window_title;
    int window_width;
    int window_height;
    // char *window_icon;
    bool window_borderless;
    bool window_resiable;
    bool window_fullscreen;
    bool window_vsync;
};

V2D_DECLSPEC V2D_Config *V2D_CALL V2D_CreateDefaultConfig();

V2D_DECLSPEC void V2D_CALL V2D_DestroyConfig(V2D_Config *config);

#endif