cmake_minimum_required(VERSION 3.10)
project(renderer)

add_executable(${PROJECT_NAME} 
    thirdparty/glad/src/glad.c
    DisplayManager/DisplayManager.cpp
    InputManager/InputManager.cpp
    main.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
    thirdparty/glad/include
    DisplayManager
    InputManager
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw
)