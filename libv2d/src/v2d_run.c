#include "v2d.h"
#include "v2d_buffer.h"
#include "v2d_context.h"
#include "v2d_default.h"

#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_gpu.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_timer.h>

int V2D_Run(V2D_Config *config, void *state) {
    if (!SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC | SDL_INIT_GAMEPAD | SDL_INIT_EVENTS | SDL_INIT_SENSOR | SDL_INIT_CAMERA)) {
        SDL_Log("failed to init sdl: %s", SDL_GetError());
        return -1;
    }

    V2D_AppContext *app = V2D_CreateAppContext(config);

    if (app->onLoad)
        app->onLoad(state, app);

    app->prevTime = SDL_GetTicks() / 1000.0f;

    //---------------
    V2D_DefaultVertex vertices[] = {
        {{-1.0f, +1.0f}, {0.0f, 0.0f, 0.0f, 1.0f}},
        {{-1.0f, -1.0f}, {0.0f, 0.0f, 0.0f, 1.0f}},
        {{+1.0f, -1.0f}, {0.0f, 0.0f, 0.0f, 1.0f}},

        {{-1.0f, +1.0f}, {0.0f, 0.0f, 0.0f, 1.0f}},
        {{+1.0f, -1.0f}, {0.0f, 0.0f, 0.0f, 1.0f}},
        {{+1.0f, +1.0f}, {0.0f, 0.0f, 0.0f, 1.0f}},
    };

    SDL_GPUBuffer *vertex_buffer = V2D_CreateBuffer(app, &vertices, sizeof(vertices), SDL_GPU_BUFFERUSAGE_VERTEX);

    V2D_DefaultUniformBuffer uniform = {
        .time = 0,
    };
    //---------------

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

        //---------------
        {
            SDL_BindGPUGraphicsPipeline(render_context->render_pass, app->default_graphics_pipeline);

            SDL_GPUBufferBinding bufferBindings[] = {
                {.buffer = vertex_buffer, .offset = 0},
            };

            SDL_BindGPUVertexBuffers(render_context->render_pass, 0, bufferBindings, 1);

            uniform.time = currentTime;
            uniform.resolution.width = (float)render_context->width;
            uniform.resolution.height = (float)render_context->height;
            SDL_PushGPUFragmentUniformData(render_context->command_buffer, 0, &uniform, sizeof(uniform));

            // issue a draw call
            SDL_DrawGPUPrimitives(render_context->render_pass, sizeof(vertices) / sizeof(V2D_DefaultVertex), 1, 0, 0);
        }
        //---------------

        if (app->onRender)
            app->onRender(state, app, render_context);

        V2D_EndRenderContext(app, render_context);
    }

    SDL_ReleaseGPUBuffer(app->device, vertex_buffer);

    if (app->onUnload)
        app->onUnload(state, app);

    V2D_DestroyAppContext(app);

    return app->return_code;
}