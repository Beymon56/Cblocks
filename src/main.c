#include "../lib/GLAD/glad/glad.h"
#include "../lib/GLFW/glfw3.h"
#include <stdio.h>
#include <string.h>
#include "window.h"
#include "input.h"
#include "render.h"
#include "shaders.h"



int main(void) {
    GLFWwindow* windowID = createWindow(800, 600, "eshkere");
    unsigned int shaderProgramID = createShaderProgram();

    float vertices[] = {
     0.5f,  0.5f, 0.0f,     1.0f, 0.0f, 0.0f,
     0.5f, -0.5f, 0.0f,     0.0f, 1.0f, 0.0f,
    -0.5f, -0.5f, 0.0f,     0.0f, 0.0f, 1.0f,
    -0.5f,  0.5f, 0.0f,     0.0f, 0.0f, 0.0f,
    };
    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3,
    };

    

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
    //position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    //color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,  6 * sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);
    


    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); wireframe mode enable, super ahuennaya shtuka
    //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); wireframe mode disable
    

    while (!glfwWindowShouldClose(windowID))
    {
        processInput(windowID);
        
        render(shaderProgramID, VAO);
        
        updateWindow(windowID);
    }

    closeWindow();
    return 0;
}