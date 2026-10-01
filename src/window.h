#include "../lib/GLAD/glad/glad.h"
#include "../lib/GLFW/glfw3.h"
#include <stdio.h>

void closeWindow();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);



GLFWwindow* createWindow(int sizeH, int sizeV, char *name)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        
    GLFWwindow* window = glfwCreateWindow(sizeH, sizeV, name, NULL, NULL);
    glfwMakeContextCurrent(window);
    
    if (window == NULL)
    {
        printf("failed to create window!\n");
        closeWindow();
    }

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("error on load glad!\n");
    }

    glViewport(0, 0, sizeH, sizeV);
    
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    

    return window;
}

void updateWindow(GLFWwindow* window)
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}


void closeWindow()
{
    glfwTerminate();
}
