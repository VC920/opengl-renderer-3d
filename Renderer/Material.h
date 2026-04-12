#pragma once
#include "Texture.h"
#include "Shader.h"

class Material
{
public:
    Material(Texture *texture, Shader *shader) 
    {
        m_texture = texture;
        m_shader = shader;
    }

    void UseTexture(int num)
    {
        m_shader->Use();
        m_texture->Use();
        m_shader->SetTexture(m_texture->m_name, num);
    }

    void SetMVP(glm::mat4 mvp)
    {
        m_shader->Use();
        m_shader->setMat4("mvp", mvp);
    }

private:
    Texture* m_texture;
    Shader* m_shader;
};