#include "DisplayManager.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0,0, width, height);
}

bool DisplayManager::Init(int width, int height)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(width, height, "renderer", nullptr, nullptr);
    if (m_window == nullptr) {
        std::cout << "Error create window" << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(m_window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Error init glad" << std::endl;
        glfwTerminate();
        return false;
    }

    glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
    glfwSwapInterval(1);

    int framebufferWidth, framebufferHeight;
    glfwGetFramebufferSize(m_window, &framebufferWidth, &framebufferHeight);
    glViewport(0, 0, framebufferWidth, framebufferHeight);

    glEnable(GL_DEPTH_TEST);

    return true;
}

void DisplayManager::Destroy()
{
    glfwTerminate();
}

bool DisplayManager::ShouldClose()
{
    return glfwWindowShouldClose(m_window);
}

void DisplayManager::PollEvents()
{
    glfwPollEvents();
}

void DisplayManager::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void DisplayManager::SwapBuffers()
{
    glfwSwapBuffers(m_window);
}

void DisplayManager::Close()
{
    glfwSetWindowShouldClose(m_window, true);
}

void DisplayManager::SetClearColor(float r, float g, float b, float a)
{
    glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, a);
}

int DisplayManager::GetFrameBufferWidth()
{
    int framebufferWidth, framebufferHeight;
    glfwGetFramebufferSize(m_window, &framebufferWidth, &framebufferHeight);
    return framebufferWidth;
}

int DisplayManager::GetFrameBufferHeight()
{
    int framebufferWidth, framebufferHeight;
    glfwGetFramebufferSize(m_window, &framebufferWidth, &framebufferHeight);
    return framebufferHeight;
}

GLFWwindow* DisplayManager::GetWindow()
{
    return m_window;
}