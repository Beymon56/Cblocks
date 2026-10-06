#version 330 core
out vec4 FragColor;  
in vec3 fColor;

uniform float test1;
  
void main()
{
    FragColor = vec4(fColor.xyz, 1.0);
}