cmake_minimum_required(VERSION 3.10)
project(renderer)

add_executable(${PROJECT_NAME} 
    thirdparty/glad/src/glad.c
    main.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
    thirdparty/glad/include
)