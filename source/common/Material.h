
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

        glm::vec3 albedo_tint{}, specular_tint{}, emissive_tint{};
        glm::vec2 roughness_range{};


        explicit Material(
                const glm::vec3& diffuse = {0,0,0},
                const glm::vec3& specular = {0,0,0},
                const glm::vec3& ambient = {0, 0, 0},
                float shininess = 1.0f
        ): diffuse(diffuse), specular(specular), ambient(ambient), shininess(shininess) {
            texture = NULL;
            sampler = NULL;
            albedo_tint = glm::vec3(1,1,1);
            specular_tint = glm::vec3(1,1,1);
            emissive_tint = glm::vec3(1,1,1);
            roughness_range = glm::vec2(0,1);
        }

        void setTexture(Texture2D* _texture) { texture = _texture; }
        void setSampler(Sampler* _sampler) { sampler = _sampler; }



    };
}