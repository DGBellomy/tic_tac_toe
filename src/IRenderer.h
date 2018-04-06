#ifndef IRenderer_H
#define IRenderer_H

class IRenderer {
public:
    virtual ~IRenderer() {}

public:
    virtual void Init() = 0;
    virtual void Draw() = 0;
};

#endif // IRenderer_H
