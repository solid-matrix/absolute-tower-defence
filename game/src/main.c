#include "v2d.h"

void Load(void *state, V2D_AppContext *app_ctx) {
    SDL_Log("load");
}

void Update(void *state, V2D_AppContext *app_ctx, float dt) {
}

void Render(void *state, V2D_AppContext *app_ctx, V2D_RenderContext *render_ctx) {
}

void Event(void *state, V2D_AppContext *app_ctx, SDL_Event *event) {
}

void Unload(void *state, V2D_AppContext *app_ctx) {
    SDL_Log("unload");
}

int main(int argc, char *argv[]) {
    V2D_Config config = V2D_CreateDefaultConfig();
    config.window_title = "Absolute Tower Defence";
    config.window_resiable = true;
    config.debug = true;
    config.onLoad = Load;
    config.onUpdate = Update;
    config.onRender = Render;
    config.onEvent = Event;
    config.onUnload = Unload;

    return V2D_Run(&config, NULL);
}