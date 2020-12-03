#include <iostream>
#include "Mesh.h"

#include "GameObject.h"
//#include "GameObjectComponent.h"
#include "Shader.hpp"
#include "Transform.h"
#include "Camera.h"

namespace ShiEngine {

    class MeshRenderer : public ShiEngine::GameObjectComponent {
    private:
        //std::shared_ptr<ShiEngine::Mesh> mesh;
        ShiEngine::Mesh* mesh;
        ShaderProgram* shaderProgram;
        glm::vec4 color_intensity;
        glm::mat4 transformationMatrix;
        ShiEngine::Transform* transform;
        ShiEngine:: Camera* cam_era;

        bool transform_sent;
    public:
        MeshRenderer();

        MeshRenderer(ShaderProgram* program);
        MeshRenderer(ShaderProgram* program, Mesh* m);
        ~MeshRenderer();

        void Primitives(ShiEngine::Shapes3D shape, bool colored = false);
        void destroy();
        void Setcam(Camera *cam);
        void setMesh(ShiEngine::Mesh* m);
        void setShader(ShaderProgram* program);
        void setTransformationMatrix(glm::mat4 m);
        void Start() override;
        void Update(double deltaTime) override;
//        template<typename ...T>
//        void Update(double deltaTime, T&&... arguments);
        void Draw() override;

    };


}