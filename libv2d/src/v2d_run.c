#include "v2d.h"
#include "v2d_app_context.h"
#include "v2d_draw_context.h"

#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>

int V2D_Run(V2D_Config *config, void *state) {
    if (!SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC | SDL_INIT_GAMEPAD | SDL_INIT_EVENTS | SDL_INIT_SENSOR | SDL_INIT_CAMERA)) {
        SDL_Log("failed to init sdl: %s", SDL_GetError());
        return -1;
    }

    V2D_AppContext *app = V2D_CreateAppContext(config);

    if (app->onLoad)
        app->onLoad(state, app);

    app->prevTime = SDL_GetTicks() / 1000.0f;

    while (!app->should_close) {
        // TODO fps control

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                app->should_close = true;
            }

            if (app->onEvent)
                app->onEvent(state, app, &event);
        }

        if (app->should_close) {
            break;
        }

        float currentTime = SDL_GetTicks() / 1000.0f;
        float dt = currentTime - app->prevTime;
        app->prevTime = currentTime;

        if (app->onUpdate)
            app->onUpdate(state, app, dt);

        if (app->should_close) {
            break;
        }

        V2D_RenderContext *render_context = V2D_BeginRenderContext(app);

        if (app->onRender)
            app->onRender(state, app, render_context);

        V2D_EndRenderContext(app, render_context);
    }

    if (app->onUnload)
        app->onUnload(state, app);

    V2D_DestroyAppContext(app);

    return app->return_code;
}