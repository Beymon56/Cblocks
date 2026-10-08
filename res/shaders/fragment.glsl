#version 330 core
out vec4 FragColor;  
in vec2 fTexCoord;

uniform sampler2D Stexture;
  
void main()
{
    FragColor = texture2D(Stexture, fTexCoord);
}