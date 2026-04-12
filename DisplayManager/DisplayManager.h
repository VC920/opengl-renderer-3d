#pragma once

struct GLFWwindow;
class DisplayManager
{
/* Meyers Instance */
public:
    static DisplayManager& GetInstance() {
        static DisplayManager instance;
        return instance;
    }
private:
    DisplayManager() = default;
    DisplayManager(const DisplayManager&) = delete;
    DisplayManager& operator=(const DisplayManager&) = delete;
    DisplayManager(DisplayManager&&) = delete;
    DisplayManager& operator=(DisplayManager&&) = delete;
/* ========== */

public:
    // 函数
    bool Init(int width, int height);
    void Destroy();

    bool ShouldClose();
    void PollEvents();
    void Clear();
    void SwapBuffers();
    void Close();

    void SetClearColor(float r, float g, float b, float a);
    int GetFrameBufferWidth();
    int GetFrameBufferHeight();
    GLFWwindow* GetWindow();

private:
    // 数据
    GLFWwindow* m_window;
};