#include "../lib/GLAD/glad/glad.h"
#include <stdio.h>

const char* vertexShaderSourse =
    "#version 330 core\n"
    "layout (location = 0) in vec3 pos;\n"
    "void main()\n"
    "{gl_Position = vec4(pos.x, pos.y, pos.z, 1.0);}";

const char* fragmentShaderSourse =
    "#version 330 core\n"
    "out vec4 FragColor\n;"
    "void main()\n"
    "{FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);}";

   

unsigned int createShaderProgram()
{
    unsigned int vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);


    glShaderSource(vertexShaderID, 1, &vertexShaderSourse, NULL);
    glCompileShader(vertexShaderID);
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShaderID, 512, NULL, infoLog);
        printf("error on compilation vertex shader: %s", infoLog);
    }



    glShaderSource(fragmentShaderID, 1, &fragmentShaderSourse, NULL);
    glCompileShader(fragmentShaderID);
    glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShaderID, 512, NULL, infoLog);
        printf("error on compilation fragment shader: %s", infoLog);
    }

    unsigned int shaderProgramID = glCreateProgram();
    glAttachShader(shaderProgramID, vertexShaderID);
    glAttachShader(shaderProgramID, fragmentShaderID);
    glLinkProgram(shaderProgramID);



    glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgramID, 512, NULL, infoLog);
        printf("error on linking program: %s", infoLog);
    }

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
    return shaderProgramID;
}