#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <glad/glad.h>
#include <glm/glm.hpp>

class Shader
{
public:
    unsigned int ID;

    Shader(const char *vertexPath, const char *fragmentPath)
    {
        // 加载着色器源代码
        std::ifstream vShaderFile(vertexPath);
        std::ifstream fShaderFile(fragmentPath);

        std::string vShaderSource{std::istreambuf_iterator<char>(vShaderFile), std::istreambuf_iterator<char>()};
        std::string fShaderSource{std::istreambuf_iterator<char>(fShaderFile), std::istreambuf_iterator<char>()};

        unsigned int vertexShader, fragmentShader;

        vertexShader = CompileShader(GL_VERTEX_SHADER, vShaderSource.c_str());
        fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fShaderSource.c_str());

        this->ID = CreateProgram(vertexShader, fragmentShader);
    }

    void Use() 
    { 
        glUseProgram(ID); 
    }

    void SetBool(const std::string &name, bool value) const
    {         
        glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value); 
    }
    
    void SetInt(const std::string &name, int value) const
    { 
        glUniform1i(glGetUniformLocation(ID, name.c_str()), value); 
    }

    void SetFloat(const std::string &name, float value) const
    { 
        glUniform1f(glGetUniformLocation(ID, name.c_str()), value); 
    }

    void setMat4(const std::string &name, const glm::mat4 &mat) const
    {
        glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }

    void SetTexture(const std::string &name, int value) const
    { 
        glUniform1i(glGetUniformLocation(ID, name.c_str()), value); 
    }


private:
    unsigned int CompileShader(unsigned int shaderType, const char *shaderSource)
    {
        unsigned int shader;
        shader = glCreateShader(shaderType);
        glShaderSource(shader, 1, &shaderSource, nullptr);
        glCompileShader(shader);

        int success;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            char infoLog[512];
            glGetShaderInfoLog(shader, 512, nullptr, infoLog);
            if (shaderType == GL_VERTEX_SHADER)
                std::cout << "Error compile vertex shader: " << infoLog << std::endl;
            else if (shaderType == GL_FRAGMENT_SHADER)
                std::cout << "Error compile fragment shader: " << infoLog << std::endl;
            return 0;
        }

        return shader;
    }

    unsigned int CreateProgram(unsigned int vertexShader, unsigned int fragmentShader)
    {
        unsigned int program = glCreateProgram();
        glAttachShader(program, vertexShader);
        glAttachShader(program, fragmentShader);
        glLinkProgram(program);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        int success;
        glGetProgramiv(program, GL_LINK_STATUS, &success);
        if (!success) {
            char infoLog[512];
            glGetProgramInfoLog(program, 512, nullptr, infoLog);
            std::cout << "Error link shader program: " << infoLog << std::endl;
            return 0;
        }

        return program;
    }
};