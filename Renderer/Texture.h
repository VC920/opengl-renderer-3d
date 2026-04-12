#pragma once
#include <glad/glad.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <iostream>
#include <string>

class Texture
{
public:
    unsigned int ID;
    const char *m_name;
    int m_num;

    Texture(const char *name, const char *path, int num)
    {
        stbi_set_flip_vertically_on_load(true);
        this->m_name = name;
        this->m_num = num;
        this->ID = CreateTexture(path);
    }

    void Use()
    {
        glActiveTexture(GL_TEXTURE0 + m_num);
        glBindTexture(GL_TEXTURE_2D, this->ID);
    }

private:
    unsigned int CreateTexture(const char *path)
    {
        unsigned int texture;
        glGenTextures(1, &texture);

        int width, height, nrComponents;
        unsigned char *data = stbi_load(path, &width, &height, &nrComponents, 0);
        if (data) {
            GLenum format;
            if (nrComponents == 1) {
                format = GL_RED;
            } else if (nrComponents == 3) {
                format = GL_RGB;
            } else if (nrComponents == 4) {
                format = GL_RGBA;
            }

            glBindTexture(GL_TEXTURE_2D, texture);
            glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

            stbi_image_free(data);
        } else {
            std::cout << "Error load texture: " << path << std::endl;
            stbi_image_free(data);
        }

        return texture;
    }
};