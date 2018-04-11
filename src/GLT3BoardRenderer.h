#ifndef GLT3BoardRenderer_H
#define GLT3BoardRenderer_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "GLShaderProgram.h"
#include "GLTexture2D.h"
#include "IRenderer.h"

class GLT3BoardRenderer : public IRenderer {
public:
    GLT3BoardRenderer();
    ~GLT3BoardRenderer();

    GLT3BoardRenderer(const GLT3BoardRenderer& rhs) = delete;
    GLT3BoardRenderer& operator=(const GLT3BoardRenderer& rhs) = delete;

public:
    void Init(float center_x, float center_y, float width, float height) final;
    void Draw() final;

private:
    GLuint m_VBO, m_IBO, m_VAO;
    GLShaderProgram m_Shader;
    GLTexture2D m_T3BoardTex;

};

#endif // GLT3BoardRenderer_H
