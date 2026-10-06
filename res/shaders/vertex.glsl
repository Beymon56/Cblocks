#version 330 core
layout (location = 0) in vec3 Vpos;
layout (location = 1) in vec3 Vcolor;

out vec3 fColor;

void main()
{
    gl_Position = vec4(Vpos.xyz, 1.0);
    fColor = Vcolor;
}