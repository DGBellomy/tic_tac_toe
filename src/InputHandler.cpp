#include "InputHandler.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// CLASS VARIABLES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

InputHandler* InputHandler::m_Instance = nullptr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// CLASS METHODS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

InputHandler* InputHandler::GetInstance()
{
    if (m_Instance == nullptr)
        m_Instance = new InputHandler();
    return m_Instance;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// CONSTRUCTORS & DECONSTRUCTOR
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

InputHandler::InputHandler()
    : m_MouseXPos(0.0),
      m_MouseYPos(0.0),
      m_MouseDown(false) {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

InputHandler::~InputHandler() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// PUBLIC METHODS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

bool InputHandler::MouseDown() {
    return m_MouseDown;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

double InputHandler::MouseXPos() {
    return m_MouseXPos;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

double InputHandler::MouseYPos() {
    return m_MouseYPos;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void InputHandler::MouseDown(bool down) {
    m_MouseDown = down;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void InputHandler::MousePos(double xpos, double ypos) {
    m_MouseXPos = xpos;
    m_MouseYPos = ypos;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
