#include "../lib/GLAD/glad/glad.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* readShaderSourse(const char* soursePath);
unsigned int shaderProgramID;
int wireframeSwitch = 0;

unsigned int createShaderProgram()
{
    if (wireframeSwitch == 1)
    {
        //wireframe mode enable, super ahuennaya shtuka (GL_FILL - disable) 
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); 
    }
    char* buffer;
    buffer = readShaderSourse("res/shaders/vertex.glsl");
    const char* vertexShaderSourse = buffer;
    buffer = readShaderSourse("res/shaders/fragment.glsl");
    const char* fragmentShaderSourse = buffer;
    free(buffer);
    
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

    shaderProgramID = glCreateProgram();
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



char* readShaderSourse(const char* soursePath)
{
    FILE* file = fopen(soursePath, "rb");
    if (!file) {
        fprintf(stderr, "error on reading: %s\n", soursePath);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    if (size <= 0) {
        fclose(file);
        return NULL;
    }

    char* buffer = (char*)malloc(size + 1);
    if (!buffer) {
        fclose(file);
        return NULL;
    }

    size_t read = fread(buffer, 1, size, file);
    buffer[read] = '\0';

    fclose(file);
    return buffer;
}



void setFloat(const char* name, float value)
{
    int location = glGetUniformLocation(shaderProgramID, name);
    glUniform1f(location, value);
}


void setInt(const char* name, int value)
{
    int location = glGetUniformLocation(shaderProgramID, name);
    glUniform1i(location, value);
}

