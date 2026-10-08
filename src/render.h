#include "../lib/GLAD/glad/glad.h"

void render(unsigned int shaderProgramID, unsigned int vaoID, unsigned int textureID)
{
    //clear color buffer and fill it with blank color
    glClearColor(0.5f, 1.0f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //activate shader
    glUseProgram(shaderProgramID);

    //render triangle
    glBindTexture(GL_TEXTURE_2D, textureID);
    glBindVertexArray(vaoID);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}