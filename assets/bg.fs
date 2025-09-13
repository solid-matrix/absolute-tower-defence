#version 330 core

in vec2 fragTexCoord;
in vec4 fragColor;

out vec4 finalColor;

uniform float time;
uniform vec2 resolution;

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

void main() {
    const float pixel_size = 1.0;
    vec2 screen_coords = floor((gl_FragCoord.xy) / pixel_size) * pixel_size;

    vec3 o = render(screen_coords);

    //o = crt(o.xyz, screen_coords);

    finalColor = vec4(o, 1.0);
}
