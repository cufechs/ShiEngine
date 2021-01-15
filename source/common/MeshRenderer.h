#ifndef MESHRENDERER_H
#define MESHRENDERER_H

#include <iostream>
#include "Mesh.h"

#include "GameObject.h"
//#include "GameObjectComponent.h"
#include "Shader.hpp"
//#include "Transform.h"
#include "Camera.h"
#include "Light.h"
#include "Material.h"

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
        //ShiEngine::Light * light;
        ShiEngine::Material* material;

        std::vector<ShiEngine::Light*> lights;
        std::vector<ShiEngine::Transform*> lightTransforms;


        bool transform_sent;
    public:
        MeshRenderer();

        MeshRenderer(ShaderProgram* program);
        MeshRenderer(ShaderProgram* program, Mesh* m);
        ~MeshRenderer();

        void Primitives(ShiEngine::Shapes3D shape, bool colored , const char* FilePath);
        void destroy();
        void Setcam(Camera *cam);
        void SetLight(Light *_light);
        void setMesh(ShiEngine::Mesh* m);
        void setShader(ShaderProgram* program);
        void setTransformationMatrix(glm::mat4 m);
        void SetLight(Light* _light, Transform* _transformLight);




        void Start() override;
        void Update(double deltaTime) override;
//        template<typename ...T>
//        void Update(double deltaTime, T&&... arguments);
        void Draw() override;

    };


}

#endif //MESHRENDERER_H