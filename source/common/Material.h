
#include "GameObjectComponent.h"
#include <glm/glm.hpp>
#include "Shader.hpp"
#include "Texture2D.h"
#include "Sampler.h"

namespace ShiEngine {
    class Material {
    public:
        glm::vec3 diffuse, specular, ambient;
        float shininess;
        ShiEngine::ShaderProgram* shaderProgram;

        ShiEngine::Texture2D* texture;
        ShiEngine::Sampler* sampler;


        explicit Material(
                const glm::vec3& diffuse = {0,0,0},
                const glm::vec3& specular = {0,0,0},
                const glm::vec3& ambient = {0, 0, 0},
                float shininess = 1.0f
        ): diffuse(diffuse), specular(specular), ambient(ambient), shininess(shininess) {
            texture = NULL;
            sampler = NULL;
        }

        void setTexture(Texture2D* _texture) { texture = _texture; }
        void setSampler(Sampler* _sampler) { sampler = _sampler; }



    };
}