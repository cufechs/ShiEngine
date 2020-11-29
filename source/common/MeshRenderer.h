#include <iostream>
#include "Mesh.h"

#include "GameObject.h"
//#include "GameObjectComponent.h"
#include "Shader.hpp"
#include "Transform.h"

namespace ShiEngine {

    class MeshRenderer : public ShiEngine::GameObjectComponent {
    private:
        std::shared_ptr<ShiEngine::Mesh> mesh;
        ShaderProgram* shaderProgram;
        glm::vec4 color_intensity;
        glm::mat4 transformationMatrix;
        ShiEngine::Transform transform;

        bool transform_sent;
    public:
        MeshRenderer();
        MeshRenderer(ShaderProgram* program);
        MeshRenderer(ShaderProgram* program, Mesh* m);
        MeshRenderer(ShaderProgram* program, glm::mat4 m);
        ~MeshRenderer();

        void Primitives(ShiEngine::Shapes3D shape, bool colored = false);
        void destroy();

        void setMesh(std::shared_ptr<Mesh> m);
        void setShader(ShaderProgram* program);
        void setTransformationMatrix(glm::mat4 m);
        void Start() override;
        void Update(double deltaTime) override;
//        template<typename ...T>
//        void Update(double deltaTime, T&&... arguments);
        void Draw() override;

    };


}