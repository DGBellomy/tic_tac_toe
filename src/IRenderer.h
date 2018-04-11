#ifndef IRenderer_H
#define IRenderer_H

class IRenderer {
public:
    virtual ~IRenderer() {}

public:
    virtual void Init(float center_x, float center_y, float width, float height) = 0;
    virtual void Draw() = 0;
};

#endif // IRenderer_H
