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
#include "Globals/Global_vars.h"
#include "RenderState.h"


//ShiEngine::GameState* CreateState1(ShiEngine::Application* application){
//
//    auto* state = new ShiEngine::GameState;
//    auto *program = new ShiEngine::ShaderProgram;
//    GLuint vertex_array = 0;
//    //ShiEngine::GameObject GO;
//    ShiEngine::MeshRenderer* meshRenderer1;
//    ShiEngine::MeshRenderer* meshRenderer2;
//    ShiEngine::MeshRenderer* meshRendererPlane;
//
//    auto* obj1 = new ShiEngine::GameObject();
//    auto* directionalLightGameObject = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
//    auto* objCamera = new ShiEngine::GameObject(ShiEngine::Tags::CAMERA);
//    auto* pointLightGameObject = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
//    auto* planeGameObject = new ShiEngine::GameObject;
//    auto* spotLightGameObject = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
//    auto* pointLightGameObject2 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
//
//    ShiEngine::Transform* transformCube;
//    ShiEngine::Transform* transformCamera;
//    ShiEngine::Transform* transformDirectionalLight;
//    ShiEngine::Transform* transformPointLight;
//    ShiEngine::Transform* transformPlane;
//    ShiEngine::Transform* transformSpotLight;
//    ShiEngine::Transform* transformPointLight2;
//
//    ShiEngine::Camera* camera;
//    ShiEngine::Light* directionalLight;
//    ShiEngine::Light* pointLight;
//    ShiEngine::Light* spotLight;
//    ShiEngine::Light* pointLight2;
//
//    ShiEngine::Material* material1;
//    ShiEngine::Material* materialPlane;
//
//    ShiEngine::Mesh* meshCube;
//    ShiEngine::Mesh* meshPlane;
//    ShiEngine::Mesh* meshSphere;
//
//
//    auto *controller = new ShiEngine::FlyCameraController;
//
//    program->create("../assets/Shaders/Phase3/light_transform.vert", GL_VERTEX_SHADER,
//                    "../assets/Shaders/Phase3/light_array.frag", GL_FRAGMENT_SHADER);
//
//    // Resources
//    meshCube = new ShiEngine::Mesh();
//    meshCube->Cuboid(false);
//
//    meshPlane = new ShiEngine::Mesh();
//    meshPlane->Plane(false);
//
//    meshSphere = new ShiEngine::Mesh();
//    meshSphere->Sphere(false);
//
//    // Camera Transformer
//    transformCamera = new ShiEngine::Transform();
//    transformCamera->position = glm::vec3({10, 10, 10});
//    transformCamera->scale = glm::vec3({1,1,1});
//    transformCamera->rotation = glm::vec3({0,0,0});
//
//    transformCube = new ShiEngine::Transform();
//    transformCube->position = glm::vec3({0, 0, 0});
//    transformCube->scale = glm::vec3({2,2,2});
//    transformCube->rotation = glm::vec3({0,0,0});
//
//    transformPlane = new ShiEngine::Transform();
//    transformPlane->position = glm::vec3({0, -1, 0});
//    transformPlane->scale = glm::vec3({50,1,50});
//    transformPlane->rotation = glm::vec3({0,0,0});
//
//    // Directional Light Transform
//    transformDirectionalLight = new ShiEngine::Transform();
//    transformDirectionalLight->position = glm::vec3({0, 0, 0});
//    transformDirectionalLight->scale = glm::vec3({1,1,1});
//    transformDirectionalLight->rotation = glm::vec3({0,0,0});
//    transformDirectionalLight->direction = glm::vec3({1, 10, 1});
//
//    // Point Light Transform
//    transformPointLight = new ShiEngine::Transform();
//    transformPointLight->position = glm::vec3({-2, 0, 0});
//    transformPointLight->scale = glm::vec3({1,1,1});
//    transformPointLight->rotation = glm::vec3({0,0,0});
//    transformPointLight->direction = glm::vec3({-1, -1, -1});
//
//    // Point Light Transform
//    transformPointLight2 = new ShiEngine::Transform();
//    transformPointLight2->position = glm::vec3({2, 0, 0});
//    transformPointLight2->scale = glm::vec3({1,1,1});
//    transformPointLight2->rotation = glm::vec3({0,0,0});
//    transformPointLight2->direction = glm::vec3({-1, -1, -1});
//
//    // Spot Light Transform
//    transformSpotLight = new ShiEngine::Transform();
//    transformSpotLight->position = glm::vec3({2, 0, 0});
//    transformSpotLight->scale = glm::vec3({1,1,1});
//    transformSpotLight->rotation = glm::vec3({0,0,0});
//    transformSpotLight->direction = glm::vec3({0,0,1});
//
//    camera = new ShiEngine::Camera();
//    camera->setupPerspective(glm::pi<float>()/2, 1.7f, 0.1f, 100.0f);
//    //camera->setupOrthographic(2.f, 1.7, 0.1f, 100.0f);
//
//    // Directional Light, Set attenuation and other stuff if needed
//    directionalLight = new ShiEngine::Light(ShiEngine::LightType::DIRECTIONAL);
//
//    pointLight = new ShiEngine::Light(ShiEngine::LightType::POINT);
//    pointLight->setAttenuation(0,0,1);
//    pointLight->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({0.1,0.1,0.1}), glm::vec3({0.1,0.1,0.1}));
//
//    pointLight2 = new ShiEngine::Light(ShiEngine::LightType::POINT);
//    pointLight2->setAttenuation(0,0,1);
//    pointLight2->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({0.1,0.1,0.1}), glm::vec3({0.1,0.1,0.1}));
//
//
//    spotLight = new ShiEngine::Light(ShiEngine::LightType::SPOT);
//    spotLight->setAttenuation(0,1,0);
//    spotLight->setPhong(glm::vec3({1,1,1}), glm::vec3({1,1,1}), glm::vec3({0.101,0.101,0.101}));
//    spotLight->setSpotAngle(0.785, 1.571);
//
//    meshRenderer1 = new ShiEngine::MeshRenderer(program, meshSphere);
//
//    meshRenderer2 = new ShiEngine::MeshRenderer(program, meshCube);
//
//    meshRendererPlane = new ShiEngine::MeshRenderer(program, meshPlane);
//
//    material1 = new ShiEngine::Material();
//    material1->shaderProgram = program;
//    material1->diffuse = {0.93, 0.1019, 0.301};
//    material1->specular = {1, 1, 1};
//    material1->ambient = {0.93, 0.1019, 0.301};
//    material1->shininess = 100;
//
//    materialPlane = new ShiEngine::Material();
//    materialPlane->shaderProgram = program;
//    materialPlane->diffuse = {0.93, 0.1019, 0.301};
//    materialPlane->specular = {1, 1, 1};
//    materialPlane->ambient = {0.93, 0.1019, 0.301};
//    materialPlane->shininess = 1;
//
//    objCamera->AddComponent(transformCamera);
//    objCamera->AddComponent(camera);
//    //objCamera.Name = "objCamera";
//
//    // Cube, Sphere for now :(
//    obj1->AddComponent(transformCube);
//    obj1->AddComponent(meshRenderer1);
//    obj1->AddComponent(material1);
//    obj1->Name = "cube 1";
//
//    // Plane
//    planeGameObject->AddComponent(transformPlane);
//    planeGameObject->AddComponent(meshRendererPlane);
//    planeGameObject->AddComponent(materialPlane);
//    planeGameObject->Name = "plane gameObject";
//
//    // Point Light 1
//    pointLightGameObject->AddComponent(transformPointLight);
//    pointLightGameObject->AddComponent(pointLight);
//
//    // Point light 2
//    pointLightGameObject2->AddComponent(transformPointLight2);
//    pointLightGameObject2->AddComponent(pointLight2);
//
//    spotLightGameObject->AddComponent(transformSpotLight);
//    spotLightGameObject->AddComponent(spotLight);
//    spotLightGameObject->Name = "spotLightGameObject";
//
//    // Directional Light GameObject
//    directionalLightGameObject->AddComponent(transformDirectionalLight);
//    directionalLightGameObject->AddComponent(directionalLight);
//    directionalLightGameObject->Name = "directional light";
//
//
//    objCamera->Start();
//    controller->initialize(application, camera);
//
//    state->addGameObject(objCamera);
//    //state->addChildGameObject(objCamera, obj1);
//    state->addGameObject(obj1);
//    state->addGameObject(planeGameObject);
//    state->addGameObject(directionalLightGameObject);
//    state->addGameObject(pointLightGameObject);
//    state->addGameObject(pointLightGameObject2);
//    //state->addGameObject(spotLightGameObject);
//
//    state->attachCameraController(controller);
//
//
//    return state;
//}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

ShiEngine::GameState* CreateState1(ShiEngine::Application* application){

    auto* state = new ShiEngine::GameState;
    auto *program = new ShiEngine::ShaderProgram;
    ShiEngine::Global::Global_ShaderProgram = program;

    GLuint vertex_array = 0;
    //ShiEngine::GameObject GO;
    ShiEngine::MeshRenderer* meshRenderer1;
    ShiEngine::MeshRenderer* meshRenderer2;

    ShiEngine::MeshRenderer* meshRendererPlane;

    auto* obj1 = new ShiEngine::GameObject();
    auto* directionalLightGameObject = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* objCamera = new ShiEngine::GameObject(ShiEngine::Tags::CAMERA);
    auto* pointLightGameObject = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* planeGameObject = new ShiEngine::GameObject;
    auto* spotLightGameObject = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* pointLightGameObject2 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);

    RenderState* renderState1;

    ShiEngine::Transform* transform1;
    ShiEngine::Transform* transform2;
    ShiEngine::Transform* transformCamera;
    ShiEngine::Transform* transformCube;

    ShiEngine::Transform* transformDirectionalLight;
    ShiEngine::Transform* transformPointLight;
    ShiEngine::Transform* transformPlane;
    ShiEngine::Transform* transformSpotLight;
    ShiEngine::Transform* transformPointLight2;

    ShiEngine::Camera* camera;
    ShiEngine::Light* directionalLight;
    ShiEngine::Light* pointLight;
    ShiEngine::Light* spotLight;
    ShiEngine::Light* pointLight2;

    ShiEngine::Material* material1;
    ShiEngine::Material* materialPlane;

    ShiEngine::Mesh* meshCube;
    ShiEngine::Mesh* meshPlane;
    ShiEngine::Mesh* meshSphere;

    ShiEngine::Texture2D* texture1;
    ShiEngine::Sampler* sampler1;



    auto *controller = new ShiEngine::FlyCameraController;





    program->create("../assets/Shaders/Phase3/light_transform.vert", GL_VERTEX_SHADER,
                    "../assets/Shaders/Phase3/light_array2.frag", GL_FRAGMENT_SHADER);


//    program->create("../assets/Shaders/Phase 1/transform.vert", GL_VERTEX_SHADER,
//                    "../assets/Shaders/Phase 1/tint.frag", GL_FRAGMENT_SHADER);


    // Resources
    meshCube = new ShiEngine::Mesh();
    meshCube->Sphere(false);

    meshSphere = new ShiEngine::Mesh();
    meshSphere->Sphere(false);

    meshPlane = new ShiEngine::Mesh();
    meshPlane->Plane(false);

    transform1 = new ShiEngine::Transform();
    transform1->position = glm::vec3({0, 0, 0});
    transform1->scale = glm::vec3({1,1,1});
    transform1->rotation = glm::vec3({0,0,0});

    // Camera Transform
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
    transformDirectionalLight->position = glm::vec3({0, 0, 0});
    transformDirectionalLight->scale = glm::vec3({1,1,1});
    transformDirectionalLight->rotation = glm::vec3({0,0,0});
    transformDirectionalLight->direction = glm::vec3({1, 60, 1});

    // Point Light Transform
    transformPointLight = new ShiEngine::Transform();
    transformPointLight->position = glm::vec3({-2, 0, 0});
    transformPointLight->scale = glm::vec3({1,1,1});
    transformPointLight->rotation = glm::vec3({0,0,0});
    transformPointLight->direction = glm::vec3({-1, -1, -1});

    // Point Light Transform
    transformPointLight2 = new ShiEngine::Transform();
    transformPointLight2->position = glm::vec3({2, 0, 0});
    transformPointLight2->scale = glm::vec3({1,1,1});
    transformPointLight2->rotation = glm::vec3({0,0,0});
    transformPointLight2->direction = glm::vec3({-1, -1, -1});

    // Spot Light Transform
    transformSpotLight = new ShiEngine::Transform();
    transformSpotLight->position = glm::vec3({2, 0, 0});
    transformSpotLight->scale = glm::vec3({1,1,1});
    transformSpotLight->rotation = glm::vec3({0,0,0});
    transformSpotLight->direction = glm::vec3({0,0,1});

    camera = new ShiEngine::Camera();
    camera->setupPerspective(glm::pi<float>()/2, 1.7f, 0.1f, 100.0f);
    //camera->setupOrthographic(2.f, 1.7, 0.1f, 100.0f);

    // Directional Light, Set attenuation and other stuff if needed
    directionalLight = new ShiEngine::Light(ShiEngine::LightType::DIRECTIONAL);

    pointLight = new ShiEngine::Light(ShiEngine::LightType::POINT);
    pointLight->setAttenuation(0,0,1);
    pointLight->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({0.1,0.1,0.1}), glm::vec3({0.1,0.1,0.1}));

    pointLight2 = new ShiEngine::Light(ShiEngine::LightType::POINT);
    pointLight2->setAttenuation(0,0,1);
    pointLight2->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({0.1,0.1,0.1}), glm::vec3({0.1,0.1,0.1}));


    spotLight = new ShiEngine::Light(ShiEngine::LightType::SPOT);
    spotLight->setAttenuation(0,1,0);
    spotLight->setPhong(glm::vec3({1,1,1}), glm::vec3({1,1,1}), glm::vec3({0.101,0.101,0.101}));
    spotLight->setSpotAngle(0.785, 1.571);

    renderState1 = new RenderState(true,true,true);
    meshRenderer1 = new ShiEngine::MeshRenderer(program, meshSphere);
    meshRenderer1->SetRenderState(renderState1);

    meshRenderer2 = new ShiEngine::MeshRenderer(program, meshCube);

    meshRendererPlane = new ShiEngine::MeshRenderer(program, meshPlane);

    texture1 = new ShiEngine::Texture2D("../assets/Textures/moon.jpg", true);
    sampler1 = new ShiEngine::Sampler();


    material1 = new ShiEngine::Material();
    material1->shaderProgram = program;
    material1->diffuse = {0.93, 0.1019, 0.301};
    material1->specular = {1, 1, 1};
    material1->ambient = {0.93, 0.1019, 0.301};
    material1->shininess = 100;
    material1->setTexture(texture1);
    material1->setSampler(sampler1);
    meshRenderer1->SetMaterial(material1);

    materialPlane = new ShiEngine::Material();
    materialPlane->shaderProgram = program;
    materialPlane->diffuse = {0.93, 0.1019, 0.301};
    materialPlane->specular = {1, 1, 1};
    materialPlane->ambient = {0.93, 0.1019, 0.301};
    materialPlane->shininess = 1;

    meshRendererPlane->SetMaterial(materialPlane);


    //objCamera->AddComponent(transform1); // TODO: independent transform -> transformCamera
    objCamera->AddComponent(transformCamera);
    objCamera->AddComponent(camera);
    //objCamera.Name = "objCamera";

    obj1->AddComponent(transform1);
    obj1->AddComponent(meshRenderer1);

    //obj1->AddComponent(material1);
    obj1->Name = "cube 1";

    // Plane
    planeGameObject->AddComponent(transformPlane);
    planeGameObject->AddComponent(meshRendererPlane);
    //planeGameObject->AddComponent(materialPlane);
    planeGameObject->Name = "plane gameObject";

    // Point Light 1
    pointLightGameObject->AddComponent(transformPointLight);
    pointLightGameObject->AddComponent(pointLight);

    // Point light 2
    pointLightGameObject2->AddComponent(transformPointLight2);
    pointLightGameObject2->AddComponent(pointLight2);

    spotLightGameObject->AddComponent(transformSpotLight);
    spotLightGameObject->AddComponent(spotLight);
    spotLightGameObject->Name = "spotLightGameObject";

    // Directional Light GameObject
    directionalLightGameObject->AddComponent(transformDirectionalLight);
    directionalLightGameObject->AddComponent(directionalLight);
    directionalLightGameObject->Name = "directional light";


    objCamera->Start();
    controller->initialize(application, camera);

    state->addGameObject(objCamera);
    //state->addChildGameObject(objCamera, obj1);
    state->addGameObject(obj1);
    state->addGameObject(planeGameObject);
    state->addGameObject(directionalLightGameObject);
    state->addGameObject(pointLightGameObject);
    state->addGameObject(pointLightGameObject2);
    //state->addGameObject(spotLightGameObject);


    state->attachCameraController(controller);

    return state;
}




ShiEngine::GameState* CreateState2(ShiEngine::Application* application){

    auto* state = new ShiEngine::GameState;
    auto *program = new ShiEngine::ShaderProgram;
    ShiEngine::Global::Global_ShaderProgram = program;
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
