#ifndef IGame_H
#define IGame_H

class IGame {
public:
    virtual ~IGame() {}

public:
    virtual void Init() = 0;
    virtual void Start() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
};

#endif // IGame_H
