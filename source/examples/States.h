//
// Created by adham on 12/4/2020.
//

#ifndef GFX_LAB_STATES_H
#define GFX_LAB_STATES_H

#include <Shader.hpp>
#include <GameState.h>
#include "GameObject.h"
#include "MeshRenderer.h"
#include "testComp.h"
#include "Camera.h"
#include "CameraController.h"
#include <application.hpp>
//#include "Material.h"
#include <vector>

ShiEngine::GameState* CreateState1(ShiEngine::Application* application){

    auto* state = new ShiEngine::GameState;
    auto *program = new ShiEngine::ShaderProgram;
    GLuint vertex_array = 0;
    //ShiEngine::GameObject GO;
    ShiEngine::MeshRenderer* meshRenderer1;
    ShiEngine::MeshRenderer* meshRenderer2;
    ShiEngine::MeshRenderer* meshRendererPlane;
    //ShiEngine:: comp_mesh;
    auto* obj1 = new ShiEngine::GameObject;
    auto* directionalLightGameObject = new ShiEngine::GameObject;
    auto* objCamera = new ShiEngine::GameObject;
    auto* pointLightGameObject = new ShiEngine::GameObject;
    auto* planeGameObject = new ShiEngine::GameObject;
    auto* spotLightGameObject = new ShiEngine::GameObject;

    ShiEngine::Transform* transformCube;
    ShiEngine::Transform* transformCamera;
    ShiEngine::Transform* transformDirectionalLight;
    ShiEngine::Transform* transformPointLight;
    ShiEngine::Transform* transformPlane;
    ShiEngine::Transform* transformSpotLight;

    ShiEngine::Camera* camera;
    ShiEngine::Light* directionalLight;
    ShiEngine::Light* pointLight;
    ShiEngine::Light* spotLight;

    ShiEngine::Material* material1;
    ShiEngine::Material* materialPlane;

    ShiEngine::Mesh* meshCube;
    ShiEngine::Mesh* meshPlane;
    ShiEngine::Mesh* meshSphere;

    std::vector<ShiEngine::Light*> lights;
    std::vector<ShiEngine::MeshRenderer*> meshRenderers;
    std::vector<ShiEngine::Transform*> lightTransforms;

    auto *controller = new ShiEngine::FlyCameraController;

    program->create("../assets/Shaders/Phase3/light_transform.vert", GL_VERTEX_SHADER,
                    "../assets/Shaders/Phase3/light_array.frag", GL_FRAGMENT_SHADER);

    // Resources
    meshCube = new ShiEngine::Mesh();
    meshCube->Cuboid(false);

    meshPlane = new ShiEngine::Mesh();
    meshPlane->Plane(false);

    meshSphere = new ShiEngine::Mesh();
    meshSphere->Sphere(false);

    // Camera Transformer
    transformCamera = new ShiEngine::Transform();
    transformCamera->position = glm::vec3({10, 10, 10});
    transformCamera->scale = glm::vec3({1,1,1});
    transformCamera->rotation = glm::vec3({0,0,0});

    transformCube = new ShiEngine::Transform();
    transformCube->position = glm::vec3({0, 0, 0});
    transformCube->scale = glm::vec3({2,2,2});
    transformCube->rotation = glm::vec3({0,0,0});

    transformPlane = new ShiEngine::Transform();
    transformPlane->position = glm::vec3({0, -1, 0});
    transformPlane->scale = glm::vec3({50,1,50});
    transformPlane->rotation = glm::vec3({0,0,0});

    // Directional Light Transform
    transformDirectionalLight = new ShiEngine::Transform();
    transformDirectionalLight->position = glm::vec3({0, 10, 2});
    transformDirectionalLight->scale = glm::vec3({1,1,1});
    transformDirectionalLight->rotation = glm::vec3({0,0,0});
    transformDirectionalLight->direction = glm::vec3({-1, -1, -1});
    lightTransforms.push_back(transformDirectionalLight);

    // Point Light Transform
    transformPointLight = new ShiEngine::Transform();
    transformPointLight->position = glm::vec3({-2, -0.9, 0});
    transformPointLight->scale = glm::vec3({1,1,1});
    transformPointLight->rotation = glm::vec3({0,0,0});
    transformPointLight->direction = glm::vec3({-1, -1, -1});
    lightTransforms.push_back(transformPointLight);

    // Spot Light Transform
    transformSpotLight = new ShiEngine::Transform();
    transformSpotLight->position = glm::vec3({2, 0, 0});
    transformSpotLight->scale = glm::vec3({1,1,1});
    transformSpotLight->rotation = glm::vec3({0,0,0});
    transformSpotLight->direction = glm::vec3({0,0,1});
    lightTransforms.push_back(transformSpotLight);

    camera = new ShiEngine::Camera();

    camera->setupPerspective(glm::pi<float>()/2, 1.7f, 0.1f, 100.0f);
    //camera->setupOrthographic(2.f, 1.7, 0.1f, 100.0f);

    directionalLight = new ShiEngine::Light(ShiEngine::LightType::DIRECTIONAL);
    lights.push_back(directionalLight);

    pointLight = new ShiEngine::Light(ShiEngine::LightType::POINT);
    pointLight->setAttenuation(0,1,0);
    pointLight->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({0.1,0.1,0.1}), glm::vec3({0.1,0.1,0.1}));
    lights.push_back(pointLight);

    spotLight = new ShiEngine::Light(ShiEngine::LightType::SPOT);
    spotLight->setAttenuation(0,1,0);
    spotLight->setPhong(glm::vec3({1,1,1}), glm::vec3({1,1,1}), glm::vec3({0.101,0.101,0.101}));
    spotLight->setSpotAngle(0.785, 1.571);
    lights.push_back(spotLight);

    meshRenderer1 = new ShiEngine::MeshRenderer(program, meshSphere);
    meshRenderer1->Setcam(camera);
    meshRenderers.push_back(meshRenderer1);

    meshRenderer2 = new ShiEngine::MeshRenderer(program, meshCube);
    meshRenderer2->Setcam(camera);
    meshRenderers.push_back(meshRenderer2);

    meshRendererPlane = new ShiEngine::MeshRenderer(program, meshPlane);
    meshRendererPlane->Setcam(camera);
    meshRenderers.push_back(meshRendererPlane);


    // TODO: zabbat el shader program fel meshrenderer
    material1 = new ShiEngine::Material();
    material1->shaderProgram = program;
    material1->diffuse = {0.93, 0.1019, 0.301};
    material1->specular = {1, 1, 1};
    material1->ambient = {0.93, 0.1019, 0.301};
    material1->shininess = 100;

    materialPlane = new ShiEngine::Material();
    materialPlane->shaderProgram = program;
    materialPlane->diffuse = {0.93, 0.1019, 0.301};
    materialPlane->specular = {1, 1, 1};
    materialPlane->ambient = {0.93, 0.1019, 0.301};
    materialPlane->shininess = 1;

    objCamera->AddComponent(transformCamera);
    objCamera->AddComponent(camera);
    //objCamera.Name = "objCamera";

    // Cube, Sphere for now :(
    obj1->AddComponent(transformCube);
    obj1->AddComponent(meshRenderer1);
    obj1->AddComponent(material1);
    obj1->Name = "cube 1";

    // Plane
    planeGameObject->AddComponent(transformPlane);
    planeGameObject->AddComponent(meshRendererPlane);
    planeGameObject->AddComponent(materialPlane);
    planeGameObject->Name = "plane gameObject";

    pointLightGameObject->AddComponent(transformPointLight);
    pointLightGameObject->AddComponent(pointLight);

    spotLightGameObject->AddComponent(transformSpotLight);
    spotLightGameObject->AddComponent(spotLight);
    spotLightGameObject->Name = "spotLightGameObject";

    // Directional Light GameObject
    directionalLightGameObject->AddComponent(transformDirectionalLight);
    directionalLightGameObject->AddComponent(directionalLight);
    directionalLightGameObject->Name = "directional light";


    for (auto _meshRenderer : meshRenderers) {
        for (int i = 0;i < lights.size(); i++) {
            _meshRenderer->SetLight(lights[i], lightTransforms[i]);
        }
    }

    objCamera->Start();
    controller->initialize(application, camera);


    state->addGameObject(obj1);
    state->addGameObject(planeGameObject);
    state->addGameObject(directionalLightGameObject);
    state->addGameObject(pointLightGameObject);
    state->addGameObject(spotLightGameObject);

    state->attachCameraController(controller);


    return state;
}


ShiEngine::GameState* CreateState2(ShiEngine::Application* application){

    auto* state = new ShiEngine::GameState;
    auto *program = new ShiEngine::ShaderProgram;
    GLuint vertex_array = 0;
    //ShiEngine::GameObject GO;
    ShiEngine::MeshRenderer* meshRenderer1;
    ShiEngine::MeshRenderer* meshRenderer2;
    //ShiEngine:: comp_mesh;
    auto* obj1 = new ShiEngine::GameObject;
    auto* objCamera = new ShiEngine::GameObject;

    ShiEngine::Transform* transform1;

    ShiEngine::Camera* camera;

    ShiEngine::Mesh* meshCube;
    ShiEngine::Mesh* meshPlane;

    auto *controller = new ShiEngine::FlyCameraController;

    program->create("../assets/Shaders/Phase 1/transform.vert", GL_VERTEX_SHADER,
                    "../assets/Shaders/Phase 1/tint.frag", GL_FRAGMENT_SHADER);

    // Resources
    meshCube = new ShiEngine::Mesh();
    meshCube->Cuboid(true);

    meshPlane = new ShiEngine::Mesh();
    meshPlane->Plane(true);

    // Camera Transformer
    transform1 = new ShiEngine::Transform();
    transform1->position = glm::vec3({0, 0, 0});
    transform1->scale = glm::vec3({1,1,1});
    transform1->rotation = glm::vec3({0,0,0});

    camera = new ShiEngine::Camera();

    camera->setEyePosition({10.f, 10.f, 10.f});
    camera->setTarget({0.f, 0.f, 0.f});
    camera->setUp({0, 1, 0});
    camera->setupPerspective(glm::pi<float>()/2, 1.7f, 0.1f, 100.0f);
    //camera->setupOrthographic(2.f, 1.7, 0.1f, 100.0f);

    meshRenderer1 = new ShiEngine::MeshRenderer(program, meshCube);
    meshRenderer1->Setcam(camera);
    controller->initialize(application, camera);

    objCamera->AddComponent(transform1); // TODO: independent transform -> transformCamera
    objCamera->AddComponent(camera);
    objCamera->Name = "objCamera";

    obj1->AddComponent(transform1);
    obj1->AddComponent(meshRenderer1);
    obj1->Name = "obj 1";

    state->addGameObject(obj1);
    state->attachCameraController(controller);

    return state;
}

#endif //GFX_LAB_STATES_H
