#version 460

layout(location = 0) in vec2 a_position;
layout(location = 1) in vec4 a_color;

layout(location = 0) out vec4 v_color;

layout(std140, set = 1, binding = 0) uniform Tramsform {
    mat4 model;
    mat4 view;
    mat4 projection;
};

void main()
{
    gl_Position = projection * view * model * vec4(a_position, 0.0, 1.0);
    v_color = a_color;
}
