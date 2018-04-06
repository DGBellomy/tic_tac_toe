#ifndef GLTexture2D_H
#define GLTexture2D_H

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class GLTexture2D
{
public:
    GLTexture2D();
    virtual ~GLTexture2D();

    bool loadTexture(const std::string &filename, bool generateMipMaps = true);
    void bind(GLuint texUnit = 0);

private:
    GLuint mTexture;
};

#endif
