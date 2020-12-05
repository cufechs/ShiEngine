
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <string>
#include <memory>
#include "GameObjectComponent.h"

namespace ShiEngine {
    class Transform : public ShiEngine::GameObjectComponent {
    public:
        glm::vec4 tint;
        glm::vec3 position, rotation, scale;
        Transform* parent;

        Transform(
                const glm::vec3 &position = {0, 0, 0},
                const glm::vec3 &rotation = {0, 0, 0},
                const glm::vec3 &scale = {1, 1, 1},
                const glm::vec4 &tint = {1, 1, 1, 1}
        ) : position(position), rotation(rotation), scale(scale), tint(tint) {
            Type = ComponentType::Transform;
        }

        glm::mat4 to_mat4() const {

            glm::mat4 m = glm::translate(glm::mat4(1.0f), position);
            m = glm::rotate(m, glm::radians(rotation.x), glm::vec3(1, 0, 0));
            m = glm::rotate(m, glm::radians(rotation.y), glm::vec3(0, 1, 0));
            m = glm::rotate(m, glm::radians(rotation.z), glm::vec3(0, 0, 1));
            m = glm::scale(m, scale);
            return m;

        }

        void Start() override {}

        void Update(double deltaTime) override {}

        void Draw() override {}
    };
}