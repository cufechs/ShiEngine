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
    ShiEngine::MeshRenderer* meshRendererSuzane;
    ShiEngine::MeshRenderer* meshRendererPlane2;//side walls
    ShiEngine::MeshRenderer* meshRendererPlane3;//side walls
    ShiEngine::MeshRenderer* meshRendererPlane4;//first end walls
    ShiEngine::MeshRenderer* meshRendererPlane5;//last end walls
    ShiEngine::MeshRenderer* meshRendererPlane6;//elsa2f end walls



    auto* obj1 = new ShiEngine::GameObject();
    auto* directionalLightGameObject = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* objCamera = new ShiEngine::GameObject(ShiEngine::Tags::CAMERA);
    auto* pointLightGameObject = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* planeGameObject = new ShiEngine::GameObject;
    auto* planeGameObject2 = new ShiEngine::GameObject;
    auto* planeGameObject3 = new ShiEngine::GameObject;
    auto* planeGameObject4 = new ShiEngine::GameObject;
    auto* planeGameObject5 = new ShiEngine::GameObject;
    auto* planeGameObject6 = new ShiEngine::GameObject;
    auto* spotLightGameObject = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* pointLightGameObject2 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* pointLightGameObject3 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* pointLightGameObject4 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* pointLightGameObject5 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* pointLightGameObject6 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* objSuzane = new ShiEngine::GameObject();

    ShiEngine::Transform* transformCube;
    ShiEngine::Transform* transformCamera;
    ShiEngine::Transform* transformDirectionalLight;
    ShiEngine::Transform* transformPlane;
    ShiEngine::Transform* transformPlane2;
    ShiEngine::Transform* transformPlane3;
    ShiEngine::Transform* transformPlane4;
    ShiEngine::Transform* transformPlane5;
    ShiEngine::Transform* transformPlane6;
    ShiEngine::Transform* transformSpotLight;
    ShiEngine::Transform* transformPointLight2;
    ShiEngine::Transform* transformSuzane;
    ShiEngine::Transform* transformPointLight;
    ShiEngine::Transform* transformPointLight3;
    ShiEngine::Transform* transformPointLight4;
    ShiEngine::Transform* transformPointLight5;
    ShiEngine::Transform* transformPointLight6;

    ShiEngine::Camera* camera;
    ShiEngine::Light* directionalLight;
    ShiEngine::Light* pointLight;
    ShiEngine::Light* spotLight;
    ShiEngine::Light* pointLight2;
    ShiEngine::Light* pointLight3;
    ShiEngine::Light* pointLight4;
    ShiEngine::Light* pointLight5;
    ShiEngine::Light* pointLight6;

    ShiEngine::Material* material1;
    ShiEngine::Material* materialPlane;
    ShiEngine::Material* materialSuzane;
    ShiEngine::Material* materialPlane2;
    ShiEngine::Material* materialPlane3;
    ShiEngine::Material* materialPlane4;
    ShiEngine::Material* materialPlane5;
    ShiEngine::Material* materialPlane6;

    ShiEngine::Mesh* meshCube;
    ShiEngine::Mesh* meshPlane;
    ShiEngine::Mesh* meshPlane2;
    ShiEngine::Mesh* meshPlane3;
    ShiEngine::Mesh* meshPlane4;
    ShiEngine::Mesh* meshPlane5;
    ShiEngine::Mesh* meshPlane6;
    ShiEngine::Mesh* meshSphere;
    ShiEngine::Mesh* meshSuzane;


    auto *controller = new ShiEngine::FlyCameraController;

    program->create("../assets/Shaders/Phase3/light_transform.vert", GL_VERTEX_SHADER,
                    "../assets/Shaders/Phase3/light_array.frag", GL_FRAGMENT_SHADER);



    // Resources
    meshCube = new ShiEngine::Mesh();
    meshCube->Cuboid(false);

    meshPlane = new ShiEngine::Mesh();
    meshPlane->Plane(false);

    meshPlane2 = new ShiEngine::Mesh();
    meshPlane2->Plane(false);

    meshPlane3 = new ShiEngine::Mesh();
    meshPlane3->Plane(false);

    meshPlane4 = new ShiEngine::Mesh();
    meshPlane4->Plane(false);

    meshPlane5 = new ShiEngine::Mesh();
    meshPlane5->Plane(false);

    meshPlane6 = new ShiEngine::Mesh();
    meshPlane6->Plane(false);

    meshSphere = new ShiEngine::Mesh();
    meshSphere->Model("../assets/models/Ghost/ghost.obj");

    meshSuzane = new ShiEngine::Mesh();
    meshSuzane->Model( "../assets/models/kairi/kairi.obj");

    // Camera Transformer
    transformCamera = new ShiEngine::Transform();
    transformCamera->position = glm::vec3({-215, 5, 10});
    transformCamera->scale = glm::vec3({1,1,1});
    transformCamera->rotation = glm::vec3({0,0,0});

    transformCube = new ShiEngine::Transform();
    transformCube->position = glm::vec3({-208, 0, 6});
    transformCube->scale = glm::vec3({0.1,0.1,0.1});
    transformCube->rotation = glm::vec3({5,0,0});

    transformPlane2 = new ShiEngine::Transform();
    transformPlane2->position = glm::vec3({20, 0, 0});
    transformPlane2->scale = glm::vec3({-500,1,40});
    transformPlane2->rotation = glm::vec3({90,0,0});

    transformPlane3 = new ShiEngine::Transform();
    transformPlane3->position = glm::vec3({20, 0, 20});
    transformPlane3->scale = glm::vec3({-500,1,40});
    transformPlane3->rotation = glm::vec3({90,0,0});

    transformPlane4 = new ShiEngine::Transform();
    transformPlane4->position = glm::vec3({-220, 0, 10});
    transformPlane4->scale = glm::vec3({40,1,40});
    transformPlane4->rotation = glm::vec3({0,0,90});

    transformPlane5 = new ShiEngine::Transform();
    transformPlane5->position = glm::vec3({-119, 0, 10});
    transformPlane5->scale = glm::vec3({40,1,40});
    transformPlane5->rotation = glm::vec3({0,0,90});

    transformPlane6 = new ShiEngine::Transform();
    transformPlane6->position = glm::vec3({0, 20, 0});
    transformPlane6->scale = glm::vec3({-500,1,40});
    transformPlane6->rotation = glm::vec3({0,0,0});

    transformPlane = new ShiEngine::Transform();
    transformPlane->position = glm::vec3({0, -1, 0});
    transformPlane->scale = glm::vec3({-500,1,40});
    transformPlane->rotation = glm::vec3({0,0,0});

    //Loading Objects
    transformSuzane = new ShiEngine::Transform();
    transformSuzane->position = glm::vec3({-208, 0, 10});//kairi
    transformSuzane->scale = glm::vec3({4,4,4});
    transformSuzane->rotation = glm::vec3({0,-90,0});

    // Directional Light Transform
    transformDirectionalLight = new ShiEngine::Transform();
    transformDirectionalLight->position = glm::vec3({0, 0, 0});
    transformDirectionalLight->scale = glm::vec3({1,1,1});
    transformDirectionalLight->rotation = glm::vec3({0,0,0});
    transformDirectionalLight->direction = glm::vec3({1, 10, 1});

    // Point Light Transform
    transformPointLight = new ShiEngine::Transform();
    transformPointLight->position = glm::vec3({-210, 6, 10});
    transformPointLight->scale = glm::vec3({1,1,1});
    transformPointLight->rotation = glm::vec3({0,0,0});
    transformPointLight->direction = glm::vec3({0, -2, 0});

    transformPointLight2 = new ShiEngine::Transform();
    transformPointLight2->position = glm::vec3({-50, 0, 10});
    transformPointLight2->scale = glm::vec3({1,1,1});
    transformPointLight2->rotation = glm::vec3({0,0,0});
    transformPointLight2->direction = glm::vec3({0, -2, 0});

    transformPointLight3 = new ShiEngine::Transform();
    transformPointLight3->position = glm::vec3({-100, 0, 10});
    transformPointLight3->scale = glm::vec3({1,1,1});
    transformPointLight3->rotation = glm::vec3({0,0,0});
    transformPointLight3->direction = glm::vec3({0, -2, 0});

    transformPointLight4 = new ShiEngine::Transform();
    transformPointLight4->position = glm::vec3({-150, 0, 10});
    transformPointLight4->scale = glm::vec3({1,1,1});
    transformPointLight4->rotation = glm::vec3({0,0,0});
    transformPointLight4->direction = glm::vec3({0, -2, 0});

    transformPointLight5 = new ShiEngine::Transform();
    transformPointLight5->position = glm::vec3({-200, 0, 10});
    transformPointLight5->scale = glm::vec3({1,1,1});
    transformPointLight5->rotation = glm::vec3({0,0,0});
    transformPointLight5->direction = glm::vec3({-1, -1, -1});

    transformPointLight6 = new ShiEngine::Transform();
    transformPointLight6->position = glm::vec3({-250, 0, 10});
    transformPointLight6->scale = glm::vec3({1,1,1});
    transformPointLight6->rotation = glm::vec3({0,0,0});
    transformPointLight6->direction = glm::vec3({0, -2, 0});// Point Light Transform

    // Spot Light Transform
    transformSpotLight = new ShiEngine::Transform();
    transformSpotLight->position = glm::vec3({3, 5, 4});
    transformSpotLight->scale = glm::vec3({1,1,1});
    transformSpotLight->rotation = glm::vec3({0,0,0});
    transformSpotLight->direction = glm::vec3({0,-1,0});

    camera = new ShiEngine::Camera();
    camera->setupPerspective(glm::pi<float>()/2, 1.7f, 0.1f, 100.0f);
    //camera->setupOrthographic(2.f, 1.7, 0.1f, 100.0f);

    // Directional Light, Set attenuation and other stuff if needed
    directionalLight = new ShiEngine::Light(ShiEngine::LightType::DIRECTIONAL);

    pointLight = new ShiEngine::Light(ShiEngine::LightType::POINT);
    pointLight->setAttenuation(0,1,0);
    pointLight->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({0.1,0.1,0.1}), glm::vec3({0.1,0.1,0.1}));

    pointLight2 = new ShiEngine::Light(ShiEngine::LightType::POINT);
    pointLight2->setAttenuation(0,1,0);
    pointLight2->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({0.1,0.1,0.1}), glm::vec3({0.1,0.1,0.1}));

    pointLight3 = new ShiEngine::Light(ShiEngine::LightType::POINT);
    pointLight3->setAttenuation(0,1,0);
    pointLight3->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({0.1,0.1,0.1}), glm::vec3({0.1,0.1,0.1}));

    pointLight4 = new ShiEngine::Light(ShiEngine::LightType::POINT);
    pointLight4->setAttenuation(0,1,0);
    pointLight4->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({0.1,0.1,0.1}), glm::vec3({0.1,0.1,0.1}));

    pointLight5 = new ShiEngine::Light(ShiEngine::LightType::POINT);
    pointLight5->setAttenuation(0,1,0);
    pointLight5->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({0.1,0.1,0.1}), glm::vec3({0.1,0.1,0.1}));

    pointLight6 = new ShiEngine::Light(ShiEngine::LightType::POINT);
    pointLight6->setAttenuation(0,1,0);
    pointLight6->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({0.1,0.1,0.1}), glm::vec3({0.1,0.1,0.1}));

    spotLight = new ShiEngine::Light(ShiEngine::LightType::SPOT);
    spotLight->setAttenuation(0,1,0);
    spotLight->setPhong(glm::vec3({1,1,1}), glm::vec3({1,1,1}), glm::vec3({0.101,0.101,0.101}));
    spotLight->setSpotAngle(glm::pi<float>()/4, glm::pi<float>()/2 +0.5);

    meshRenderer1 = new ShiEngine::MeshRenderer(program, meshSphere);

    meshRenderer2 = new ShiEngine::MeshRenderer(program, meshCube);

    meshRendererPlane = new ShiEngine::MeshRenderer(program, meshPlane);

    meshRendererPlane2 = new ShiEngine::MeshRenderer(program, meshPlane2);

    meshRendererPlane3 = new ShiEngine::MeshRenderer(program, meshPlane3);

    meshRendererPlane4 = new ShiEngine::MeshRenderer(program, meshPlane4);

    meshRendererPlane5 = new ShiEngine::MeshRenderer(program, meshPlane5);

    meshRendererPlane6 = new ShiEngine::MeshRenderer(program, meshPlane6);

    meshRendererSuzane = new ShiEngine::MeshRenderer(program, meshSuzane);

    material1 = new ShiEngine::Material();
    material1->shaderProgram = program;
    material1->diffuse = {0.93, 0.1019, 0.301};
    material1->specular = {1, 1, 1};
    material1->ambient = {0.93, 0.1019, 0.301};
    material1->shininess = 100;

    materialSuzane = new ShiEngine::Material();
    materialSuzane->shaderProgram = program;
    materialSuzane->diffuse = {0.5, 0.4, 0.301};
    materialSuzane->specular = {0.7, 0.7, 0.7};
    materialSuzane->ambient = {0.5, 0.3, 0.2};
    materialSuzane->shininess = 10;

    materialPlane = new ShiEngine::Material();
    materialPlane->shaderProgram = program;
    materialPlane->diffuse = {0.2, 0.2, 0.2};
    materialPlane->specular = {0.3, 0.3, 0.3}; // This is how bright
    materialPlane->ambient = {0.1, 0.1, 0.1};
    materialPlane->shininess = 1;

    materialPlane6 = new ShiEngine::Material();
    materialPlane6->shaderProgram = program;
    materialPlane6->diffuse = {0.2, 0.2, 0.2};
    materialPlane6->specular = {0.3, 0.3, 0.3}; // This is how bright
    materialPlane6->ambient = {0.1, 0.1, 0.1};
    materialPlane6->shininess = 1;

    materialPlane4 = new ShiEngine::Material();
    materialPlane4->shaderProgram = program;
    materialPlane4->diffuse = {0.2, 0.2, 0.2};
    materialPlane4->specular = {0.3, 0.3, 0.3}; // This is how bright
    materialPlane4->ambient = {0.1, 0.2, 0.1};
    materialPlane4->shininess = 1;

    materialPlane5 = new ShiEngine::Material();
    materialPlane5->shaderProgram = program;
    materialPlane5->diffuse = {0.2, 0.2, 0.2};
    materialPlane5->specular = {0.3, 0.3, 0.3}; // This is how bright
    materialPlane5->ambient = {0.1, 0.2, 0.1};
    materialPlane5->shininess = 1;


    materialPlane2 = new ShiEngine::Material();
    materialPlane2->shaderProgram = program;
    materialPlane2->diffuse = {0.3, 0.3, 0.3};
    materialPlane2->specular = {0.4, 0.4, 0.4};
    materialPlane2->ambient = {0.1, 0.05, 0.05};
    materialPlane2->shininess = 1;

    materialPlane3 = new ShiEngine::Material();
    materialPlane3->shaderProgram = program;
    materialPlane3->diffuse = {0.3, 0.3, 0.3};
    materialPlane3->specular = {0.1, 0.1, 0.1};
    materialPlane3->ambient = {0.1, 0.05, 0.05};
    materialPlane3->shininess = 1;

    objCamera->AddComponent(transformCamera);
    objCamera->AddComponent(camera);
    //objCamera.Name = "objCamera";

    // Cube, Sphere for now :(
    obj1->AddComponent(transformCube);
    obj1->AddComponent(meshRenderer1);
    obj1->AddComponent(material1);
    obj1->Name = "cube 1";

    //Loading Objects
    objSuzane->AddComponent(transformSuzane);
    objSuzane->AddComponent(meshRendererSuzane);
    objSuzane->AddComponent(materialSuzane);
    objSuzane->Name = "Suzane";

    // Plane
    planeGameObject->AddComponent(transformPlane);
    planeGameObject->AddComponent(meshRendererPlane);
    planeGameObject->AddComponent(materialPlane);
    planeGameObject->Name = "plane gameObject";

    planeGameObject6->AddComponent(transformPlane6);
    planeGameObject6->AddComponent(meshRendererPlane6);
    planeGameObject6->AddComponent(materialPlane6);
    planeGameObject6->Name = "plane6 gameObject";

    planeGameObject2->AddComponent(transformPlane2);
    planeGameObject2->AddComponent(meshRendererPlane2);
    planeGameObject2->AddComponent(materialPlane2);
    planeGameObject2->Name = "plane2 gameObject";

    planeGameObject3->AddComponent(transformPlane3);
    planeGameObject3->AddComponent(meshRendererPlane3);
    planeGameObject3->AddComponent(materialPlane3);
    planeGameObject3->Name = "plane3 gameObject";

    planeGameObject4->AddComponent(transformPlane4);
    planeGameObject4->AddComponent(meshRendererPlane4);
    planeGameObject4->AddComponent(materialPlane4);
    planeGameObject4->Name = "plane4 gameObject";

    planeGameObject5->AddComponent(transformPlane5);
    planeGameObject5->AddComponent(meshRendererPlane5);
    planeGameObject5->AddComponent(materialPlane5);
    planeGameObject5->Name = "plane4 gameObject";

    // Point Light 1
    pointLightGameObject->AddComponent(transformPointLight);
    pointLightGameObject->AddComponent(pointLight);

    // Point light 2
    pointLightGameObject2->AddComponent(transformPointLight2);
    pointLightGameObject2->AddComponent(pointLight2);

    pointLightGameObject3->AddComponent(transformPointLight3);
    pointLightGameObject3->AddComponent(pointLight3);

    pointLightGameObject4->AddComponent(transformPointLight4);
    pointLightGameObject4->AddComponent(pointLight4);

    pointLightGameObject5->AddComponent(transformPointLight5);
    pointLightGameObject5->AddComponent(pointLight5);

    pointLightGameObject6->AddComponent(transformPointLight6);
    pointLightGameObject6->AddComponent(pointLight6);

    spotLightGameObject->AddComponent(transformSpotLight);
    spotLightGameObject->AddComponent(spotLight);
    spotLightGameObject->Name = "spotLightGameObject";

    // Directional Light GameObject
    directionalLightGameObject->AddComponent(transformDirectionalLight);
    directionalLightGameObject->AddComponent(directionalLight);
    directionalLightGameObject->Name = "directional light";


    objCamera->Start();
    controller->initialize(application, camera);


    //setting parenting
    transformPointLight->parent = transformSuzane;

    //obj1->transform->parent = transformCamera;
    state->addGameObject(objCamera);
    state->addGameObject(objSuzane);
    state->addGameObject(obj1);
    state->addGameObject(planeGameObject);
    state->addGameObject(planeGameObject2);
    state->addGameObject(planeGameObject3);
    state->addGameObject(planeGameObject4);
    state->addGameObject(planeGameObject5);
    state->addGameObject(planeGameObject6);
 //   state->addGameObject(directionalLightGameObject);
    state->addGameObject(pointLightGameObject);
    state->addGameObject(pointLightGameObject2);
    state->addGameObject(spotLightGameObject);
    //state->addGameObject(pointLightGameObject3);
    //state->addGameObject(pointLightGameObject4);
    //state->addGameObject(pointLightGameObject5);
  //  state->addGameObject(pointLightGameObject6);




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
