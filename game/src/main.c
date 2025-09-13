#define USE_V2D_MAIN
#include "v2d.h"

void V2DAPP_Config(V2D_Config *config) {
    config->window_title = "Absolute Tower Defence";
    config->window_width = 1280;
    config->window_height = 960;
    config->debug = true;
}

void V2DAPP_Init(V2D_Application *app, int argc, char **argv) {
    SDL_Log("init");
}

void V2DAPP_Update(V2D_Application *app, float dt) {
}

void V2DAPP_Draw(V2D_Application *app) {
    SDL_Delay(50);
}

void V2DAPP_Event(V2D_Application *app, SDL_Event *event) {
}

void V2DAPP_Quit() {
    SDL_Log("quit");
}