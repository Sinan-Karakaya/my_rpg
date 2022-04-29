uniform sampler2D texture;
uniform vec3 normal;
uniform vec3 light_dir;

void main()
{
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
    vec3 normal_normalize = normalize(normal);
    float dot_product = dot(normal_normalize, light_dir);
    float clamp_dot_product = dot_product * 0.5 + 0.7;
    clamp_dot_product = pow(clamp_dot_product, .4545);
    gl_FragColor = pixel * vec4(vec3(clamp_dot_product), 1);
}