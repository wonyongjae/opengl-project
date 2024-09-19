#include "G_Scene.h"

bool G_Scene::init()
{
    m_DefaultFBO.Init(WINDOW_WIDTH, WINDOW_HEIGHT);

    if (!m_DefaultFBOTech.Init())
    {
        printf("Error initializing the m_DefaultFBOTech technique\n");
        return false;
    }

    if (IsGLVersionHigher(4, 5)) {
        glBindTextureUnit(DEFAULT_FBO_TEXTURE_UNIT - GL_TEXTURE0, m_DefaultFBO.GetTexture());
    }
    else {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(DEFAULT_FBO_TEXTURE_UNIT - GL_TEXTURE_2D, m_DefaultFBO.GetTexture());
    }
    return true;
}

void G_Scene::defaultFBOWrite()
{
    /* 요소를 그릴 기본 프레임 버퍼 바인딩 */
    m_DefaultFBO.BindForWriting();
}

void G_Scene::defaultFBODraw()
{
    /* 요소가 그려진 기본 프레임 버퍼 언바인딩 */
    m_DefaultFBO.UnbindWriting();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_DefaultFBOTech.Enable();
    m_DefaultFBOTech.SetTextureUnit(DEFAULT_FBO_TEXTURE_UNIT_INDEX);

    renderQuad();
}

void G_Scene::renderQuad()
{
    if (quadVAO == 0)
    {
        GLfloat quadVertices[] = {
             // Positions        // Texture Coords
            -1.0f,  1.0f, 0.0f,  0.0f, 1.0f,  // Top-left
            -1.0f, -1.0f, 0.0f,  0.0f, 0.0f,  // Bottom-left
             1.0f, -1.0f, 0.0f,  1.0f, 0.0f,
            -1.0f,  1.0f, 0.0f,  0.0f, 1.0f,
             1.0f, -1.0f, 0.0f,  1.0f, 0.0f,  // Bottom-right
             1.0f,  1.0f, 0.0f,  1.0f, 1.0f   // Top-right
        };

        glGenVertexArrays(1, &quadVAO);
        glGenBuffers(1, &quadVBO);
        glBindVertexArray(quadVAO);
        glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    }
    glBindVertexArray(quadVAO);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 6);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glBindVertexArray(0);
}
