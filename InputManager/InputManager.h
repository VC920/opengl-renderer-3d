#pragma once
#include <array>

struct GLFWwindow;
class InputManager
{
/* Meyers Instance */
public:
    static InputManager& GetInstance() {
        static InputManager instance;
        return instance;
    }
private:
    InputManager() = default;
    InputManager(const InputManager&) = delete;
    InputManager& operator=(const InputManager&) = delete;
    InputManager(InputManager&&) = delete;
    InputManager& operator=(InputManager&&) = delete;
/* ========== */

private:
    std::array<bool, 349> m_keys;

public:
    void Init(GLFWwindow *window);

    void SetKeyPressed(int key, bool pressed);
    bool IsKeyPressed(int key);
};