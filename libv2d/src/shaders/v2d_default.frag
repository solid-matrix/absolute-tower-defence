// #version 460

// layout(location = 0) in vec4 v_color;
// layout(location = 0) out vec4 FragColor;

// layout(std140, set = 3, binding = 0) uniform UniformBlock {
//     vec2 resolution;
//     float time;
// };

// void main()
// {
//     float pulse = sin(time) * 0.5 + 0.5; // range [0, 1]
//     float effect_ratio = 1.0;
//     float effect_min = 0.0;

//     FragColor = vec4(v_color.rgb * (effect_min + pulse * effect_ratio), v_color.a);
// }

#version 460

layout(location = 0) in vec4 v_color;
layout(location = 0) out vec4 FragColor;

layout(std140, set = 3, binding = 0) uniform UniformBlock {
    vec2 resolution;
    float time;
};

vec3 render(vec2 screen_coords) {
    const float speed = 0.2;

    vec3 o = vec3(0);

    vec2 uv = (screen_coords + screen_coords - resolution.xy) / resolution.y;

    vec2 z = vec2(0) + 4.0 - 4.0 * abs(0.7 - dot(uv, uv));
    vec2 f = uv * z;

    for (int i = 1; i < 8; i++) {
        f += cos(f.yx * i + vec2(0, i) + time * speed) / i + .7;

        o += (sin(f) + 1.0).xyy * abs(f.x - f.y) * 2.0;
    }

    o = tanh(7.0 * exp(z.x - 4.0 - uv.y * vec3(-1, 1, 1)) / o);

    return o;
}

vec3 crt(vec3 c, vec2 screen_coords) {
    const float scan = 0.25;
    const float freq = 3;

    float apply = abs(sin(screen_coords.y / freq) / 2.0 * scan);

    return mix(c, vec3(0.0), apply);
}

void main()
{
    const float pixel_size = 1.0;
    vec2 screen_coords = floor((gl_FragCoord.xy) / pixel_size) * pixel_size;

    vec3 o = render(screen_coords);

    o = crt(o.xyz, screen_coords);

    FragColor = vec4(o, 1.0);
}
