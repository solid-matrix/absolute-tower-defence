#include "shaders/v2d_default_frag.h"
#include "shaders/v2d_default_vert.h"
#include "v2d_internal.h"

#include <SDL3/SDL_gpu.h>

SDL_GPUGraphicsPipeline *V2D_CreateDefaultGraphicsPipeline(V2D_AppContext *app) {
    SDL_GPUShader *vert_shader = SDL_CreateGPUShader(app->device, &V2D_DEFAULT_VERT_CREATE_INFO);
    SDL_GPUShader *frag_shader = SDL_CreateGPUShader(app->device, &V2D_DEFAULT_FRAG_CREATE_INFO);

    SDL_GPUVertexBufferDescription vertex_buffer_descs[] = {
        {
            .slot = 0,
            .input_rate = SDL_GPU_VERTEXINPUTRATE_VERTEX,
            .instance_step_rate = 0,
            .pitch = sizeof(V2D_DefaultVertex),
        },
    };

    // describe the vertex attribute
    SDL_GPUVertexAttribute vertex_attributes[] = {
        // position
        {
            .buffer_slot = 0,
            .location = 0,
            .format = SDL_GPU_VERTEXELEMENTFORMAT_FLOAT2,
            .offset = 0,
        },
        // color
        {
            .buffer_slot = 0,
            .location = 1,
            .format = SDL_GPU_VERTEXELEMENTFORMAT_FLOAT4,
            .offset = sizeof(float) * 2,
        }};

    // describe the color target
    SDL_GPUColorTargetDescription color_target_descs[] = {
        {
            .format = SDL_GetGPUSwapchainTextureFormat(app->device, app->window),

            .blend_state.enable_blend = true,

            .blend_state.src_color_blendfactor = SDL_GPU_BLENDFACTOR_SRC_ALPHA,
            .blend_state.dst_color_blendfactor = SDL_GPU_BLENDFACTOR_ONE_MINUS_SRC_ALPHA,
            .blend_state.color_blend_op = SDL_GPU_BLENDOP_ADD,

            .blend_state.src_alpha_blendfactor = SDL_GPU_BLENDFACTOR_ONE,
            .blend_state.dst_alpha_blendfactor = SDL_GPU_BLENDFACTOR_ZERO,
            .blend_state.alpha_blend_op = SDL_GPU_BLENDOP_ADD,

            .blend_state.color_write_mask = SDL_GPU_COLORCOMPONENT_R | SDL_GPU_COLORCOMPONENT_G | SDL_GPU_COLORCOMPONENT_B | SDL_GPU_COLORCOMPONENT_A,
            .blend_state.enable_color_write_mask = false,
        },
    };

    SDL_GPUGraphicsPipelineCreateInfo graphics_pipeline_create_info = {
        // The vertex shader used by the graphics pipeline.
        .vertex_shader = vert_shader,
        // The fragment shader used by the graphics pipeline.
        .fragment_shader = frag_shader,

        // The primitive topology of the graphics pipeline.
        .primitive_type = SDL_GPU_PRIMITIVETYPE_TRIANGLELIST,

        // The number of vertex buffer descriptions in the above array.
        .vertex_input_state.num_vertex_buffers = sizeof(vertex_buffer_descs) / sizeof(SDL_GPUVertexBufferDescription),
        // A pointer to an array of vertex buffer descriptions.
        .vertex_input_state.vertex_buffer_descriptions = vertex_buffer_descs,
        // The number of vertex attribute descriptions in the above array.
        .vertex_input_state.num_vertex_attributes = sizeof(vertex_attributes) / sizeof(SDL_GPUVertexAttribute),
        // A pointer to an array of vertex attribute descriptions.
        .vertex_input_state.vertex_attributes = vertex_attributes,

        // Whether polygons will be filled in or drawn as lines.
        .rasterizer_state.fill_mode = SDL_GPU_FILLMODE_FILL,
        // The facing direction in which triangles will be culled.
        .rasterizer_state.cull_mode = SDL_GPU_CULLMODE_NONE,
        // The vertex winding that will cause a triangle to be determined as front-facing.
        .rasterizer_state.front_face = SDL_GPU_FRONTFACE_COUNTER_CLOCKWISE,
        // true to bias fragment depth values.
        .rasterizer_state.enable_depth_bias = false,
        // A scalar factor controlling the depth value added to each fragment.
        .rasterizer_state.depth_bias_constant_factor = 0,
        // The maximum depth bias of a fragment.
        .rasterizer_state.depth_bias_clamp = 0,
        // A scalar factor applied to a fragment's slope in depth calculations.
        .rasterizer_state.depth_bias_slope_factor = 0,
        // true to enable depth clip, false to enable depth clamp.
        .rasterizer_state.enable_depth_clip = false,

        // The number of samples to be used in rasterization.
        .multisample_state.sample_count = SDL_GPU_SAMPLECOUNT_1,

        // The comparison operator used for depth testing.
        .depth_stencil_state.compare_op = SDL_GPU_COMPAREOP_INVALID,
        // The stencil op state for back-facing triangles.
        .depth_stencil_state.back_stencil_state.compare_op = SDL_GPU_COMPAREOP_INVALID,
        .depth_stencil_state.back_stencil_state.depth_fail_op = SDL_GPU_STENCILOP_INVALID,
        .depth_stencil_state.back_stencil_state.fail_op = SDL_GPU_STENCILOP_INVALID,
        .depth_stencil_state.back_stencil_state.pass_op = SDL_GPU_STENCILOP_INVALID,
        // The stencil op state for front-facing triangles.
        .depth_stencil_state.front_stencil_state.compare_op = SDL_GPU_COMPAREOP_INVALID,
        .depth_stencil_state.front_stencil_state.depth_fail_op = SDL_GPU_STENCILOP_INVALID,
        .depth_stencil_state.front_stencil_state.fail_op = SDL_GPU_STENCILOP_INVALID,
        .depth_stencil_state.front_stencil_state.pass_op = SDL_GPU_STENCILOP_INVALID,
        // Selects the bits of the stencil values participating in the stencil test.
        .depth_stencil_state.compare_mask = 0x00,
        // Selects the bits of the stencil values updated by the stencil test.
        .depth_stencil_state.write_mask = 0x00,
        // true enables the depth test.
        .depth_stencil_state.enable_depth_write = false,
        // true enables depth writes. Depth writes are always disabled when enable_depth_test is false.
        .depth_stencil_state.enable_depth_test = false,
        // true enables the stencil test.
        .depth_stencil_state.enable_stencil_test = false,

        // The number of color target descriptions in the above array.
        .target_info.num_color_targets = sizeof(color_target_descs) / sizeof(SDL_GPUColorTargetDescription),
        // A pointer to an array of color target descriptions.
        .target_info.color_target_descriptions = color_target_descs,
        // true specifies that the pipeline uses a depth-stencil target.
        .target_info.has_depth_stencil_target = false,
        // The pixel format of the depth-stencil target. Ignored if has_depth_stencil_target is false.
        .target_info.depth_stencil_format = SDL_GPU_TEXTUREFORMAT_INVALID,

    };

    SDL_GPUGraphicsPipeline *pipeline = SDL_CreateGPUGraphicsPipeline(app->device, &graphics_pipeline_create_info);

    SDL_ReleaseGPUShader(app->device, vert_shader);
    SDL_ReleaseGPUShader(app->device, frag_shader);

    return pipeline;
}