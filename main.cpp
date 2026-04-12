#include "DisplayManager.h"
#include "InputManager.h"
#include "MeshGroup.h"
#include "Material.h"
#include "Shader.h"
#include "Texture.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

int main()
{
    // Init
    auto& displayManager = DisplayManager::GetInstance();
    auto& inputManager = InputManager::GetInstance();

    displayManager.Init(800, 600);
    inputManager.Init(displayManager.GetWindow());

    Shader shader("res/shader/until.vs", "res/shader/until.fs");
    Texture texture("texture_diffuse", "res/backpack/diffuse.jpg", 0);

    Material material(&texture, &shader);
    MeshGroup packback("res/backpack/backpack.obj");

    // Loop
    while(!displayManager.ShouldClose()) {
        // Poll Event
        displayManager.PollEvents();

        // Process Input
        {
            if (inputManager.IsKeyPressed(GLFW_KEY_ESCAPE)) {
                displayManager.Close();
            }
        }

        displayManager.Clear();

        // Render
        {
            glm::mat4 projection = glm::perspective(glm::radians(45.0f), 
                (float)displayManager.GetFrameBufferWidth() / (float)displayManager.GetFrameBufferHeight(), 
                0.1f, 100.0f
            );
            glm::mat4 view = glm::mat4(1.0f);
            view = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));
            glm::mat4 model = glm::mat4(1.0f);

            glm::mat4 mvp = projection * view * model;

            material.SetMVP(mvp);
            packback.Draw();
        }

        displayManager.SwapBuffers();
    }

    // Quit
    displayManager.Destroy();
    return 0;
}