#pragma once
#include "Texture.h"
#include "Shader.h"

class Material
{
public:
    Material() {}

    void Use()
    {
        m_shader.Use();
        for (int i = 0; i < m_textures.size(); i++) {
            m_textures[i].Use();
            m_shader.SetTexture(m_textures[i].m_name, m_textures[i].m_num);
        }
    }

    void SetMVP(glm::mat4 &mvp)
    {
        m_shader.setMat4("mvp", mvp);
    }

    void PushTexture(Texture &texture)
    {
        m_textures.push_back(texture);
    }

    void UseShader(Shader &shader)
    {
        m_shader = shader;
    }

private:
    std::vector<Texture> m_textures;
    Shader m_shader;
};