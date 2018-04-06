#ifndef GLSHADER_PROGRAM_H
#define GLSHADER_PROGRAM_H

#include <map>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class GLShaderProgram
{
public:
    GLShaderProgram();
    ~GLShaderProgram();

    enum ShaderType
    {
        VERTEX,
        FRAGMENT,
        PROGRAM
    };

    GLuint getProgram() const;
    bool loadShaders(const char* vsFilename, const char* fsFilename);
    void use();

    void setUniform(const GLchar* name, const glm::vec2& v);
    void setUniform(const GLchar* name, const glm::vec3& v);
    void setUniform(const GLchar* name, const glm::vec4& v);

private:

    std::string fileToString(const std::string& filename);
    void checkCompileErrors(GLuint shader, ShaderType type);
    GLint getUniformLocation(const GLchar* name);

    GLuint mHandle;
    std::map<std::string, GLint> mUniformLocations;
};

#endif
