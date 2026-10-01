#include "../lib/GLAD/glad/glad.h"
#include "../lib/GLFW/glfw3.h"
#include <stdio.h>
#include <string.h>
#include "window.h"
#include "input.h"



int main(void) {
    GLFWwindow* windowID = createWindow(800, 600, "eshkere");

    float vertices[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f, 0.5f, 0.0f
    };

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    while (!glfwWindowShouldClose(windowID))
    {
        processInput(windowID);

        /* Render here */
        glClearColor(0.5f, 1.0f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        updateWindow(windowID);
    }

    closeWindow();
    return 0;
}