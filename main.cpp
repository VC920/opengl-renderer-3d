#include "DisplayManager.h"
#include "InputManager.h"
#include <GLFW/glfw3.h>

int main()
{
    // Init
    auto& displayManager = DisplayManager::GetInstance();
    auto& inputManager = InputManager::GetInstance();

    displayManager.Init(800, 600);
    inputManager.Init(displayManager.GetWindow());
    displayManager.SetClearColor(204, 153, 255, 1);

    // Loop
    while(!displayManager.ShouldClose()) {
        // Poll Event
        displayManager.PollEvents();
        // Process Input
        if (inputManager.IsKeyPressed(GLFW_KEY_ESCAPE)) {
            displayManager.Close();
        }

        displayManager.Clear();
        // Render
        displayManager.SwapBuffers();
    }

    // Quit
    displayManager.Destroy();
    return 0;
}