uniform sampler2D texture;
uniform vec3 point1;
uniform vec3 point2;
uniform vec3 point3;
uniform vec3 light_dir;

vec3 GetNormal(vec3 p1, vec3 p2, vec3 p3) {
	vec3 normal;
    normal.x = (p2.y - p1.y) * (p3.z - p1.z) - (p2.z - p1.z) * (p3.y - p1.y);
    normal.y = (p2.z - p1.z) * (p3.x - p1.x) - (p2.x - p1.x) * (p3.z - p1.z);
    normal.z = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
    return normal;
}

void main()
{
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
    vec3 normal = GetNormal(point1, point2, point3);
    float dot_product = dot(normal, light_dir);
    float clamp_dot_product = dot_product * 0.5 + 0.7;
    clamp_dot_product = pow(clamp_dot_product, .4545);
    gl_FragColor = pixel * vec4(vec3(clamp_dot_product), 1);
}