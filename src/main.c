#include "../lib/GLAD/glad/glad.h"
#include "../lib/GLFW/glfw3.h"
#include <stdio.h>
#include <string.h>
#include "window.h"
#include "input.h"
#include "render.h"
#include "shaders.h"
#include "../lib/CGLM/cglm.h"
#include <math.h>
#define STB_IMAGE_IMPLEMENTATION
#include "../lib/STB/stb_image.h"



int main(void) {
    GLFWwindow* windowID = createWindow(800, 600, "eshkere");
    unsigned int shaderProgramID = createShaderProgram();

    float vertices[] = {
     0.5f,  0.5f, 0.0f,     1.0f, 1.0f, //top right
     0.5f,  -0.5f, 0.0f,     1.0f, 0.0f, //botton right
     -0.5f, -0.5f, 0.0f,     0.0f, 0.0f, //bottom left
    -0.5f, 0.5f, 0.0f,     0.0f, 1.0f, //top left
    };
    unsigned int indices[] = {
        0, 2, 1,
        0, 3, 2,
    };

    

    int width, height, nrChannels;
    unsigned char *data = stbi_load("res/roflit512x.png", &width, &height, &nrChannels, 0);
    unsigned int textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);



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
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    //texture attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE,  5 * sizeof(float), (void*)(4* sizeof(float)));
    glEnableVertexAttribArray(1);
    
    
    

    
    

    while (!glfwWindowShouldClose(windowID))
    {
        processInput(windowID);
        
        render(shaderProgramID, VAO, textureID);
        
        updateWindow(windowID);
    }

    closeWindow();
    return 0;
}