
#include "GameObjectComponent.h"
#include <glm/glm.hpp>
#include "Shader.hpp"


namespace ShiEngine {
    class Material : public ShiEngine::GameObjectComponent {
    public:
        glm::vec3 diffuse, specular, ambient;
        float shininess;
        ShiEngine::ShaderProgram* shaderProgram;

        explicit Material(
                const glm::vec3& diffuse = {0,0,0},
                const glm::vec3& specular = {0,0,0},
                const glm::vec3& ambient = {0, 0, 0},
                float shininess = 1.0f
        ): diffuse(diffuse), specular(specular), ambient(ambient), shininess(shininess) {
            Type = ShiEngine::ComponentType::Material;
        }
    };
}