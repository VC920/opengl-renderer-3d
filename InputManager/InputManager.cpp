#include "InputManager.h"
#include <GLFW/glfw3.h>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    auto& inputManager = InputManager::GetInstance();

    if (action == GLFW_PRESS) {
        inputManager.SetKeyPressed(key, true);
    } else if (action == GLFW_RELEASE){
        inputManager.SetKeyPressed(key, false);
    }
}

void InputManager::Init(GLFWwindow *window)
{
    glfwSetKeyCallback(window, key_callback);
}

void InputManager::SetKeyPressed(int key, bool pressed)
{
    if (key < 0 || key >= static_cast<int>(m_keys.size())) {
        return;
    }
    m_keys[key] = pressed;
}

bool InputManager::IsKeyPressed(int key)
{
    if (key < 0 || key >= static_cast<int>(m_keys.size())) {
        return false;
    }

    return m_keys[key];
}