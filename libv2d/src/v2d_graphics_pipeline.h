#ifndef __V2D_GRAPHICS_PIPELINE_H
#define __V2D_GRAPHICS_PIPELINE_H

#include "v2d.h"
#include "v2d_context.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_gpu.h>
#include <SDL3/SDL_stdinc.h>

// SDL_GPUShader *V2D_CreateVertShader(V2D_AppContext *app, V2D_Data *code, SDL_GPUShaderFormat format, Uint32 num_samplers, Uint32 num_storage_textures, Uint32 num_storage_buffers, Uint32 num_uniform_buffers);

// SDL_GPUShader *V2D_CreateFragShader(V2D_AppContext *app, V2D_Data *code, SDL_GPUShaderFormat format, Uint32 num_samplers, Uint32 num_storage_textures, Uint32 num_storage_buffers, Uint32 num_uniform_buffers);

// SDL_GPUGraphicsPipeline *V2D_CreateGraphicsPipeline(V2D_AppContext *app, SDL_GPUShader *vert_shader, SDL_GPUShader *frag_shader);

SDL_GPUGraphicsPipeline *V2D_CreateDefaultGraphicsPipeline(V2D_AppContext *app);

/*
// template
SDL_GPUGraphicsPipelineCreateInfo pipeline_info = {
    // The vertex shader used by the graphics pipeline.
    .vertex_shader = NULL,
    // The fragment shader used by the graphics pipeline.
    .fragment_shader = NULL,

    // The primitive topology of the graphics pipeline.
    .primitive_type = SDL_GPU_PRIMITIVETYPE_TRIANGLELIST,

    // The number of vertex buffer descriptions in the above array.
    .vertex_input_state.num_vertex_buffers = 0,
    // A pointer to an array of vertex buffer descriptions.
    .vertex_input_state.vertex_buffer_descriptions = NULL,
    // The number of vertex attribute descriptions in the above array.
    .vertex_input_state.num_vertex_attributes = 0,
    // A pointer to an array of vertex attribute descriptions.
    .vertex_input_state.vertex_attributes = NULL,

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
    .target_info.num_color_targets = 0,
    // A pointer to an array of color target descriptions.
    .target_info.color_target_descriptions = NULL,
    // true specifies that the pipeline uses a depth-stencil target.
    .target_info.has_depth_stencil_target = false,
    // The pixel format of the depth-stencil target. Ignored if has_depth_stencil_target is false.
    .target_info.depth_stencil_format = SDL_GPU_TEXTUREFORMAT_INVALID,
};
 */

#endif