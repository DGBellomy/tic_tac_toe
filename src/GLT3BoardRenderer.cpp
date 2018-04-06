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

void GLT3BoardRenderer::Init()
{
    // Create Vertices
    //   Interleaved
    GLfloat vertices[] = {
         // POSITION           // TEXT_COORD
        -1.0f,  1.0f, 0.0f,    0.0f, 1.0f, // top left
         1.0f,  1.0f, 0.0f,    1.0f, 1.0f, // top right
         1.0f, -1.0f, 0.0f,    1.0f, 0.0f, // bottom right
        -1.0f, -1.0f, 0.0f,    0.0f, 0.0f  // bottom left
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
    //Texture2D texture1;
    m_T3BoardTex.loadTexture("/usr/local/assets/textures/t3_board.png", true);
    //m_T3BoardTex.loadTexture("/usr/local/assets/textures/gow_logo.png", true);

    //Texture2D texture2;
    //texture2.loadTexture(texture2Filename, true);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void GLT3BoardRenderer::Draw()
{
    m_T3BoardTex.bind(0);
    //texture2.bind(1);

    m_Shader.use();

    glUniform1i(glGetUniformLocation(m_Shader.getProgram(), "TicTacToeBoard"), 0);
    //glUniform1i(glGetUniformLocation(shaderProgram.getProgram(), "myTexture2"), 1);

    // Make active/current
    glBindVertexArray(m_VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    // Disconnect
    glBindVertexArray(0);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
