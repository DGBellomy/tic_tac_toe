#ifndef GLT3PieceRenderer_H
#define GLT3PieceRenderer_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "GLShaderProgram.h"
#include "GLTexture2D.h"
#include "IRenderer.h"

class GLT3PieceRenderer : public IRenderer {
public:
    GLT3PieceRenderer();
    ~GLT3PieceRenderer();

    GLT3PieceRenderer(const GLT3PieceRenderer& rhs) = delete;
    GLT3PieceRenderer& operator=(const GLT3PieceRenderer& rhs) = delete;

public:
    void Init(float center_x, float center_y, float width, float height) final;
    void Draw() final;
    virtual void Hide(bool hide=false) final;

private:
    GLuint m_VBO, m_IBO, m_VAO;
    GLShaderProgram m_Shader;
    GLTexture2D m_T3PieceX;
    GLTexture2D m_T3PieceO;
    bool m_Hide;

};

#endif // GLT3PieceRenderer_H
