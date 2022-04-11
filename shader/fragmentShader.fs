#ifdef GL_ES
precision mediump float;
#endif

#extension GL_OES_standard_derivatives : enable

uniform vec2 resolution;
uniform float time;

void main(void)
{
    vec2 pos = ((gl_FragCoord.xy / resolution.xy) - vec2(0.5));
    pos.x *= resolution.x / resolution.y;

    float z = (pos.x * pos.x + pos.y * pos.y);
    float u = mod(8.0 * pos.x / z + time, 1.0);
    float v = mod(8.0 * pos.y / z + time, 1.0);
    float color = sin(u * 3.14) * sin(v * 6.28);
    if (z < 0.25)
        color *= (z * 4.0);

    gl_FragColor = vec4(vec3(color * z * u * v * 16.0, color * u, color * v), 1.0);
}
