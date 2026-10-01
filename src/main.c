#include "../lib/GLAD/glad/glad.h"
#include "../lib/GLFW/glfw3.h"
#include <stdio.h>
#include <string.h>
#include "window.h"

int main(void) {
    GLFWwindow* window = createWindow(800, 600, "eshkere");

    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClearColor(0.5f, 1.0f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        updateWindow(window);
    }

    closeWindow();
    return 0;
}