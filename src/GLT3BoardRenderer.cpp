#include "GLT3BoardRenderer.h"

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "GLShaderProgram.h"
#include "GLTexture2D.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// CONSTRUCTORS & DECONSTRUCTOR
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

GLT3BoardRenderer::GLT3BoardRenderer()
    : m_Hide(false)
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

GLT3BoardRenderer::~GLT3BoardRenderer()
{
    glDeleteVertexArrays(1, &m_VAO);
    glDeleteBuffers(1, &m_VBO);
    glDeleteBuffers(1, &m_IBO);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// PUBLIC METHODS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void GLT3BoardRenderer::Init(float center_x, float center_y, float width, float height)
{
    //GLfloat half_width = (m_Width / 2.0f) / 400.0f;
    //GLfloat half_height = (m_Height / 2.0f) / 300.0f;
    GLfloat _screen_width = 800.0f;
    GLfloat _screen_height = 600.0f;

    GLfloat _top = ((height / 2.0f) + center_y) / (_screen_height / 2.0f);
    GLfloat _left = (-1.0f * (width / 2.0f) + center_x) / (_screen_width / 2.0f);
    GLfloat _bottom = (-1.0f * (height / 2.0f) + center_y) / (_screen_height / 2.0f);
    GLfloat _right = ((width / 2.0f) + center_x) / (_screen_width / 2.0f);;

    // Create Vertices
    //   Interleaved
    GLfloat vertices[] = {
        // POSITION      // TEXT_COORD
        _left,  _top,    0.0f,   0.0f, 1.0f, // top left
        _right, _top,    0.0f,   1.0f, 1.0f, // top right
        _right, _bottom, 0.0f,   1.0f, 0.0f, // bottom right
        _left,  _bottom, 0.0f,   0.0f, 0.0f  // bottom left
    };

    GLuint indices[] = {
        0, 1, 2,  // tri 0
        0, 2, 3   // tri 1
    };

    //  Load Buffer - used to hold meshes
    //GLuint vbo, ibo, vao; // Vertex Buffer Object, Vertex Array Object

    // Vertex Buffer
    glGenBuffers(1, &m_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Load Vertex Array Object
    glGenVertexArrays(1, &m_VAO);
    glBindVertexArray(m_VAO);

    // Describe format of a Vertex (index, # of items for this attribute, type of data, ???, stride, offset)
    // Position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 5, NULL);
    glEnableVertexAttribArray(0);

    // Text Coord
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 5, (GLvoid*)(sizeof(GLfloat) * 3));
    glEnableVertexAttribArray(1);

    // Index Buffer
    glGenBuffers(1, &m_IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    //ShaderProgram shaderProgram;
    //const char* vsFile = "/usr/local/assets/shaders/t3_board.vs.glsl";
    //const char* fsFile = "/usr/local/assets/shaders/t3_board.fs.glsl";
    m_Shader.loadShaders(
            "/usr/local/assets/shaders/t3_board.vs.glsl",
            "/usr/local/assets/shaders/t3_board.fs.glsl");

    // Texture
    m_T3BoardTex.loadTexture("/usr/local/assets/textures/t3_board.png", true);

    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void GLT3BoardRenderer::Draw()
{
    if (m_Hide) return;

    m_T3BoardTex.bind(0);

    m_Shader.use();

    glUniform1i(glGetUniformLocation(m_Shader.getProgram(), "TicTacToeBoard"), 0);

    // Make active/current
    glBindVertexArray(m_VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    // Disconnect
    glBindVertexArray(0);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void GLT3BoardRenderer::Hide(bool hide)
{
    m_Hide = hide;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
