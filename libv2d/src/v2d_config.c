#include "v2d_config.h"
#include <SDL3/SDL_stdinc.h>

V2D_Config *V2D_CreateDefaultConfig() {
    V2D_Config *config = SDL_malloc(sizeof(V2D_Config));

    if (!config)
        return NULL;

    config->debug = false;
    config->window_title = "";
    config->window_width = 800;
    config->window_height = 600;
    config->window_borderless = false;
    config->window_resiable = false;
    config->window_fullscreen = false;
    config->window_vsync = true;

    return config;
}

void V2D_DestroyConfig(V2D_Config *config) {
    SDL_free(config);
}
