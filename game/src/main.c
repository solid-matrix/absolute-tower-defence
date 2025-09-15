#include "SDL3/SDL_log.h"
#include "v2d.h"

void Load(void *state, V2D_AppContext *app_ctx) {
    SDL_Log("load");
}

void Update(void *state, V2D_AppContext *app_ctx, float dt) {
}

void Render(void *state, V2D_AppContext *app_ctx, V2D_RenderContext *render_ctx) {

    V2D_FillRectSolidColor(render_ctx, (V2D_Rect){50, 100, 200, 400}, (V2D_Color){1.0, 0.0, 0.0, 0.5});
    V2D_FillRectSolidColor(render_ctx, (V2D_Rect){100, 50, 400, 200}, (V2D_Color){0.0, 0.0, 1.0, 0.5});
}

void Event(void *state, V2D_AppContext *app_ctx, SDL_Event *event) {
}

void Unload(void *state, V2D_AppContext *app_ctx) {
    SDL_Log("unload");
}

int main(int argc, char *argv[]) {
    V2D_AppConfig config = V2D_CreateDefaultConfig();

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