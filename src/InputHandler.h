#ifndef InputHandler_H
#define InputHandler_H

class InputHandler {
public:
    static InputHandler* GetInstance();

private:
    static InputHandler* m_Instance;

public:
    InputHandler();
    ~InputHandler();

    InputHandler(const InputHandler& rhs) = delete;
    InputHandler& operator=(const InputHandler& rhs) = delete;

public:
    bool MouseDown();
    double MouseXPos();
    double MouseYPos();

    void MouseDown(bool down);
    void MousePos(double xpos, double ypos);

private:
    double m_MouseXPos;
    double m_MouseYPos;
    bool m_MouseDown;
};

#endif // InputHandler_H
