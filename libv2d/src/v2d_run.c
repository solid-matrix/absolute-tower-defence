#include "v2d.h"
#include "v2d_internal.h"

#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_gpu.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_timer.h>
#include <cglm/cglm.h>
#include <cglm/mat3.h>

int V2D_Run(V2D_AppConfig *config, void *state) {
    if (!SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC | SDL_INIT_GAMEPAD | SDL_INIT_EVENTS | SDL_INIT_SENSOR | SDL_INIT_CAMERA)) {
        SDL_Log("failed to init sdl: %s", SDL_GetError());
        return -1;
    }

    V2D_AppContext *app = V2D_CreateAppContext(config);

    if (config->onLoad)
        config->onLoad(state, app);

    app->currentTime = SDL_GetTicks() / 1000.0f;

    while (!app->should_close) {
        // TODO fps control

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                app->should_close = true;
            }

            if (config->onEvent)
                config->onEvent(state, app, &event);
        }

        if (app->should_close) {
            break;
        }

        float currentTime = SDL_GetTicks() / 1000.0f;
        float dt = currentTime - app->currentTime;
        app->currentTime = currentTime;

        if (config->onUpdate)
            config->onUpdate(state, app, dt);

        if (app->should_close)
            break;

        V2D_RenderContext *render_context = V2D_BeginRenderContext(app);

        if (config->onRender)
            config->onRender(state, app, render_context);

        V2D_EndRenderContext(app, render_context);
    }

    if (config->onUnload)
        config->onUnload(state, app);

    V2D_DestroyAppContext(app);

    return app->return_code;
}