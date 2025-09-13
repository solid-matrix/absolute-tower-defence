#define SDL_MAIN_USE_CALLBACKS
#include "SDL3/SDL_main.h"

#include "v2d_application.h"
#include "v2d_config.h"
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_video.h>

void V2DAPP_Config(V2D_Config *config);
void V2DAPP_Init(V2D_Application *app, int argc, char **argv);
void V2DAPP_Update(V2D_Application *app, float dt);
void V2DAPP_Draw(V2D_Application *app);
void V2DAPP_Event(V2D_Application *app, SDL_Event *event);
void V2DAPP_Quit();

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv) {
    // setup config
    V2D_Config *config = V2D_CreateDefaultConfig();
    V2DAPP_Config(config);

    // setup application
    V2D_Application *app = V2D_CreateApplication(config);

    V2DAPP_Init(app, argc, argv);

    app->prevTime = SDL_GetTicks() / 1000.0f;

    *appstate = app;

    V2D_DestroyConfig(config);
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
    V2D_Application *app = appstate;

    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }

    V2DAPP_Event(app, event);

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate) {
    V2D_Application *app = appstate;

    float currentTime = SDL_GetTicks() / 1000.0f;
    float dt = currentTime - app->prevTime;
    app->prevTime = currentTime;
    V2DAPP_Update(app, dt);

    V2D_BeginRender(app);
    V2DAPP_Draw(app);
    V2D_EndRender(app);

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {
    V2D_Application *app = appstate;

    V2D_DestroyApplication(app);

    V2DAPP_Quit();
}