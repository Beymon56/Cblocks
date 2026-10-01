#include "../lib/GLAD/glad/glad.h"
#include "../lib/GLFW/glfw3.h"
#include <stdio.h>
#include <string.h>
#include "window.h"
#include "input.h"



int main(void) {
    GLFWwindow* windowID = createWindow(800, 600, "eshkere");

    float vertices[] = {
     0.5f,  0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
    -0.5f,  0.5f, 0.0f,
    };
    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3,
    };


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

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    unsigned int EBO;
    glGenBuffers(1, &EBO);
    
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    


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
    

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); wireframe mode enable, super ahuennaya shtuka
    //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); wireframe mode disable
    

    while (!glfwWindowShouldClose(windowID))
    {
        processInput(windowID);

        glClearColor(0.5f, 1.0f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgramID);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
        
        updateWindow(windowID);
    }

    closeWindow();
    return 0;
}