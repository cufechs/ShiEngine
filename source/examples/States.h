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
#include "BoxCollider.h"
#include "EnemyMovement.h"

ShiEngine::GameState* CreateState1(ShiEngine::Application* application){

    auto* state = new ShiEngine::GameState;
    auto *program = new ShiEngine::ShaderProgram;
    ShiEngine::Global::Global_ShaderProgram = program;

    GLuint vertex_array = 0;
    //ShiEngine::GameObject GO;
    ShiEngine::MeshRenderer* meshRenderer1;
    ShiEngine::MeshRenderer* meshRenderer2;
    ShiEngine::MeshRenderer* meshRenderer3;
    ShiEngine::MeshRenderer* meshRendererSuzane;
    ShiEngine::MeshRenderer* meshRendererPlane2;//side walls
    ShiEngine::MeshRenderer* meshRendererPlane3;//side walls
    ShiEngine::MeshRenderer* meshRendererPlane4;//first end walls
    ShiEngine::MeshRenderer* meshRendererPlane5;//last end walls
    ShiEngine::MeshRenderer* meshRendererPlane6;//elsa2f end walls
    ShiEngine::MeshRenderer* meshRendererPlane;
    ShiEngine::MeshRenderer* meshRendererSuzanne2;
    ShiEngine::MeshRenderer* meshRendererSuzanne3;
    ShiEngine::MeshRenderer* meshRendererSuzanne4;
    ShiEngine::MeshRenderer* meshRendererSuzanne5;
    ShiEngine::MeshRenderer* meshRendererSuzanne6;

    auto* obj1 = new ShiEngine::GameObject();
    auto* obj2 = new ShiEngine::GameObject();
    auto* cubeGameObj = new ShiEngine::GameObject();
    auto* directionalLightGameObject = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* objCamera = new ShiEngine::GameObject(ShiEngine::Tags::CAMERA);
    auto* pointLightGameObject = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* planeGameObject = new ShiEngine::GameObject;
    auto* spotLightGameObject = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* pointLightGameObject2 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* planeGameObject2 = new ShiEngine::GameObject;
    auto* planeGameObject3 = new ShiEngine::GameObject;
    auto* planeGameObject4 = new ShiEngine::GameObject;
    auto* planeGameObject5 = new ShiEngine::GameObject;
    auto* planeGameObject6 = new ShiEngine::GameObject;
    auto* pointLightGameObject3 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* pointLightGameObject4 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* pointLightGameObject5 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* pointLightGameObject6 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* objSuzane = new ShiEngine::GameObject();
    auto* objSuzane2 = new ShiEngine::GameObject();
    auto* objSuzane3 = new ShiEngine::GameObject();
    auto* objSuzane4 = new ShiEngine::GameObject();
    auto* objSuzane5 = new ShiEngine::GameObject();
    auto* objSuzane6 = new ShiEngine::GameObject();

    RenderState* renderState1;

    ShiEngine::Transform* transform1;
    ShiEngine::Transform* transform2;
    ShiEngine::Transform* transformCamera;
    ShiEngine::Transform* transformCube;

    ShiEngine::BoxCollider* boxColliderPlayer;
    ShiEngine::BoxCollider* boxColliderWallBehind;
    ShiEngine::BoxCollider* boxColliderWallFront;
    ShiEngine::BoxCollider* boxColliderWallRight;
    ShiEngine::BoxCollider* boxColliderWallLeft;


    ShiEngine::Transform* transformDirectionalLight;
    ShiEngine::Transform* transformPointLight;
    ShiEngine::Transform* transformPlane;
    ShiEngine::Transform* transformSpotLight;
    ShiEngine::Transform* transformPointLight2;
    ShiEngine::Transform* transformCubeObj;

    ShiEngine::Transform* transformPlane2;
    ShiEngine::Transform* transformPlane3;
    ShiEngine::Transform* transformPlane4;
    ShiEngine::Transform* transformPlane5;
    ShiEngine::Transform* transformPlane6;
    ShiEngine::Transform* transformSuzane;
    ShiEngine::Transform* transformSuzane2;
    ShiEngine::Transform* transformSuzane3;
    ShiEngine::Transform* transformSuzane4;
    ShiEngine::Transform* transformSuzane5;
    ShiEngine::Transform* transformSuzane6;

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
    ShiEngine::Material* materialCube;
    ShiEngine::Material* materialSuzane;
    ShiEngine::Material* materialPlane2;
    ShiEngine::Material* materialPlane3;
    ShiEngine::Material* materialPlane4;
    ShiEngine::Material* materialPlane5;
    ShiEngine::Material* materialPlane6;

    ShiEngine::Mesh* meshCube;
    ShiEngine::Mesh* meshPlane;
    ShiEngine::Mesh* meshSphere;
    ShiEngine::Mesh* meshPlane2;
    ShiEngine::Mesh* meshPlane3;
    ShiEngine::Mesh* meshPlane4;
    ShiEngine::Mesh* meshPlane5;
    ShiEngine::Mesh* meshPlane6;
    ShiEngine::Mesh* meshSuzane;

    ShiEngine::Texture2D* texture1; //texture Earth
    ShiEngine::Sampler* sampler1;

    ShiEngine::Texture2D* texture2;
    ShiEngine::Texture2D* textureEarth;

    ShiEngine::EnemyMovement* moveEnemy1;


    auto *controller = new ShiEngine::FlyCameraController;

    program->create("../assets/Shaders/Phase3/light_transform.vert", GL_VERTEX_SHADER,
                    "../assets/Shaders/Phase3/light_array2.frag", GL_FRAGMENT_SHADER);

    // Resources
    meshCube = new ShiEngine::Mesh();
    meshCube->Cuboid(false);

    meshSphere = new ShiEngine::Mesh();
    meshSphere->Sphere(false);
    ///

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
   // meshSphere->Model("../assets/models/Ghost/ghost.obj");

    meshSuzane = new ShiEngine::Mesh();
    meshSuzane->Model( "../assets/models/Suzanne/Suzanne.obj");

    //Transforms
    transformCamera = new ShiEngine::Transform();
    transformCamera->position = glm::vec3({-215, 5, 0});
    transformCamera->scale = glm::vec3({1,1,1});
    transformCamera->rotation = glm::vec3({0,0,0});

    transformCube = new ShiEngine::Transform();
    transformCube->position = glm::vec3({-208, 0, 6});
    transformCube->scale = glm::vec3({0.1,0.1,0.1});
    transformCube->rotation = glm::vec3({5,0,0});

    // Wall left
    transformPlane2 = new ShiEngine::Transform();
    transformPlane2->position = glm::vec3({20, 10, -50});
    transformPlane2->scale = glm::vec3({-500,1,40});
    transformPlane2->rotation = glm::vec3({90,0,0});

    // Wall right
    transformPlane3 = new ShiEngine::Transform();
    transformPlane3->position = glm::vec3({20, 10, 50});
    transformPlane3->scale = glm::vec3({-500,1,40});
    transformPlane3->rotation = glm::vec3({90,0,0});

    // Wall behind
    transformPlane4 = new ShiEngine::Transform();
    transformPlane4->position = glm::vec3({-220, 10, 10});
    transformPlane4->scale = glm::vec3({40,1,200});
    transformPlane4->rotation = glm::vec3({0,0,90});

    // Wall front
    transformPlane5 = new ShiEngine::Transform();
    transformPlane5->position = glm::vec3({-20, 10, 10});
    transformPlane5->scale = glm::vec3({40,1,200});
    transformPlane5->rotation = glm::vec3({0,0,90});

    // Wall up
    transformPlane6 = new ShiEngine::Transform();
    transformPlane6->position = glm::vec3({0, 30, 0});
    transformPlane6->scale = glm::vec3({-500,1,100});
    transformPlane6->rotation = glm::vec3({0,0,0});

    // Wall down
    transformPlane = new ShiEngine::Transform();
    transformPlane->position = glm::vec3({0, -1, 0});
    transformPlane->scale = glm::vec3({-500,1,100});
    transformPlane->rotation = glm::vec3({0,0,0});

    //Loading Objects
    transformSuzane = new ShiEngine::Transform();
    transformSuzane->position = glm::vec3({-30, 5, 0});//kairi
    transformSuzane->scale = glm::vec3({4,4,4});
    transformSuzane->rotation = glm::vec3({0,-90,0});

    transformSuzane2 = new ShiEngine::Transform();
    transformSuzane2->position = glm::vec3({-50, 5, -20});//kairi
    transformSuzane2->scale = glm::vec3({4,4,4});
    transformSuzane2->rotation = glm::vec3({0,-90,0});

    transformSuzane3 = new ShiEngine::Transform();
    transformSuzane3->position = glm::vec3({-70, 5, 30});//kairi
    transformSuzane3->scale = glm::vec3({4,4,4});
    transformSuzane3->rotation = glm::vec3({0,-90,0});

    transformSuzane4 = new ShiEngine::Transform();
    transformSuzane4->position = glm::vec3({-90, 5, 10});//kairi
    transformSuzane4->scale = glm::vec3({4,4,4});
    transformSuzane4->rotation = glm::vec3({0,-90,0});

    transformSuzane5 = new ShiEngine::Transform();
    transformSuzane5->position = glm::vec3({-120, 5, -20});//kairi
    transformSuzane5->scale = glm::vec3({4,4,4});
    transformSuzane5->rotation = glm::vec3({0,-90,0});

    transformSuzane6 = new ShiEngine::Transform();
    transformSuzane6->position = glm::vec3({-150, 5, 1});//kairi
    transformSuzane6->scale = glm::vec3({4,4,4});
    transformSuzane6->rotation = glm::vec3({0,-90,0});

    transform1 = new ShiEngine::Transform();
    transform1->position = glm::vec3({0, 0, 0});
    transform1->scale = glm::vec3({1,1,1});
    transform1->rotation = glm::vec3({0,0,0});

    transform2 = new ShiEngine::Transform();
    transform2->position = glm::vec3({2, 0, 0});
    transform2->scale = glm::vec3({2,2,2});
    transform2->rotation = glm::vec3({0,0,0});

    boxColliderPlayer = new ShiEngine::BoxCollider();
    boxColliderWallBehind = new ShiEngine::BoxCollider();
    boxColliderWallFront = new ShiEngine::BoxCollider();
    boxColliderWallLeft = new ShiEngine::BoxCollider();
    boxColliderWallRight = new ShiEngine::BoxCollider();


    // Door
    transformCubeObj = new ShiEngine::Transform();
    transformCubeObj->position = glm::vec3({-20, 12, 0});
    transformCubeObj->scale = glm::vec3({2,30,18});
    transformCubeObj->rotation = glm::vec3({0,0,0});


    transformCube = new ShiEngine::Transform();
    transformCube->position = glm::vec3({0, 0, 0});
    transformCube->scale = glm::vec3({2,2,2});
    transformCube->rotation = glm::vec3({0,0,0});

    // Directional Light Transform
    transformDirectionalLight = new ShiEngine::Transform();
    transformDirectionalLight->position = glm::vec3({0, 0, 0});
    transformDirectionalLight->scale = glm::vec3({1,1,1});
    transformDirectionalLight->rotation = glm::vec3({0,0,0});
    transformDirectionalLight->direction = glm::vec3({1, -0.2, 1});

    // Point Light Transfor Spot Light Transform
    transformSpotLight = new ShiEngine::Transform();
    transformSpotLight->position = glm::vec3({2, 0, 0});
    transformSpotLight->scale = glm::vec3({1,1,1});
    transformSpotLight->rotation = glm::vec3({0,0,0});
    transformSpotLight->direction = glm::vec3({0,0,1});

    transformPointLight = new ShiEngine::Transform();
    transformPointLight->position = glm::vec3({-250, 0, 10});
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
    transformPointLight4->position = glm::vec3({-215, 3, -48});
    transformPointLight4->scale = glm::vec3({1,1,1});
    transformPointLight4->rotation = glm::vec3({0,0,0});
    transformPointLight4->direction = glm::vec3({0, -2, 0});

    transformPointLight5 = new ShiEngine::Transform();
    transformPointLight5->position = glm::vec3({-215, 3, 48});
    transformPointLight5->scale = glm::vec3({1,1,1});
    transformPointLight5->rotation = glm::vec3({0,0,0});
    transformPointLight5->direction = glm::vec3({-1, -1, -1});

    transformPointLight6 = new ShiEngine::Transform();
    transformPointLight6->position = glm::vec3({-200, 0, 10});
    transformPointLight6->scale = glm::vec3({1,1,1});
    transformPointLight6->rotation = glm::vec3({0,0,0});
    transformPointLight6->direction = glm::vec3({0, -2, 0});// Point Light Transform

    // Spot Light Transform
    transformSpotLight = new ShiEngine::Transform();
    transformSpotLight->position = glm::vec3({-200, 1, 0});
    transformSpotLight->scale = glm::vec3({1,1,1});
    transformSpotLight->rotation = glm::vec3({0,0,0});
    transformSpotLight->direction = glm::vec3({0,-1,0});


    moveEnemy1 = new ShiEngine::EnemyMovement();
    moveEnemy1->setOscillateY(2.0, 0.01);
    moveEnemy1->setOscillateZ(20.0, 0.05);

    camera = new ShiEngine::Camera();
    camera->setupPerspective(glm::pi<float>()/2, 1.7f, 0.1f, 1000.0f);
    //camera->setupOrthographic(2.f, 1.7, 0.1f, 100.0f);

    // Directional Light, Set attenuation and other stuff if needed
    directionalLight = new ShiEngine::Light(ShiEngine::LightType::DIRECTIONAL);
    directionalLight->color = {1,1,1};

    pointLight = new ShiEngine::Light(ShiEngine::LightType::POINT);
    pointLight->setAttenuation(0,0,1);
    pointLight->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({0.1,0.1,0.1}), glm::vec3({0.1,0.1,0.1}));

    pointLight2 = new ShiEngine::Light(ShiEngine::LightType::POINT);
    pointLight2->setAttenuation(0,0,1);
    pointLight2->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({0.1,0.1,0.1}), glm::vec3({0.1,0.1,0.1}));

    pointLight3 = new ShiEngine::Light(ShiEngine::LightType::POINT);
    pointLight3->setAttenuation(0,0,1);
    pointLight3->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({0.1,0.1,0.1}), glm::vec3({0.1,0.1,0.1}));

    pointLight4 = new ShiEngine::Light(ShiEngine::LightType::POINT);
    pointLight4->setAttenuation(0,0,1);
    pointLight4->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({0.1,0.1,0.1}), glm::vec3({0.1,0.1,0.1}));

    pointLight5 = new ShiEngine::Light(ShiEngine::LightType::POINT);
    pointLight5->setAttenuation(0,0,1);
    pointLight5->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({0.1,0.1,0.1}), glm::vec3({0.1,0.1,0.1}));

    pointLight6 = new ShiEngine::Light(ShiEngine::LightType::POINT);
    pointLight6->setAttenuation(0,0,1);
    pointLight6->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({0.1,0.1,0.1}), glm::vec3({0.1,0.1,0.1}));


    spotLight = new ShiEngine::Light(ShiEngine::LightType::SPOT);
    spotLight->setAttenuation(0,1,0);
    spotLight->setPhong(glm::vec3({1,1,1}), glm::vec3({1,1,1}), glm::vec3({1,1,1}));
    spotLight->setSpotAngle(0.785, 1.571);

    renderState1 = new RenderState(true,true,false);

    meshRenderer1 = new ShiEngine::MeshRenderer(program, meshSphere);
    meshRenderer1->SetRenderState(renderState1);

    meshRenderer2 = new ShiEngine::MeshRenderer(program, meshCube);
    meshRenderer2->SetRenderState(renderState1);

    meshRenderer3 = new ShiEngine::MeshRenderer(program, meshCube);
    meshRenderer3->SetRenderState(renderState1);

    meshRendererPlane = new ShiEngine::MeshRenderer(program, meshPlane);
    meshRendererPlane->SetRenderState(renderState1);

    meshRendererPlane2 = new ShiEngine::MeshRenderer(program, meshPlane2);
    meshRendererPlane2->SetRenderState(renderState1);

    meshRendererPlane3 = new ShiEngine::MeshRenderer(program, meshPlane3);
    meshRendererPlane3->SetRenderState(renderState1);

    meshRendererPlane4 = new ShiEngine::MeshRenderer(program, meshPlane4);
    meshRendererPlane4->SetRenderState(renderState1);

    meshRendererPlane5 = new ShiEngine::MeshRenderer(program, meshPlane5);
    meshRendererPlane5->SetRenderState(renderState1);

    meshRendererPlane6 = new ShiEngine::MeshRenderer(program, meshPlane6);
    meshRendererPlane6->SetRenderState(renderState1);

    meshRendererSuzane = new ShiEngine::MeshRenderer(program, meshSuzane);
    meshRendererSuzane->SetRenderState(renderState1);

    meshRendererSuzanne2 = new ShiEngine::MeshRenderer(program, meshSuzane);
    meshRendererSuzanne2->SetRenderState(renderState1);

    meshRendererSuzanne3 = new ShiEngine::MeshRenderer(program, meshSuzane);
    meshRendererSuzanne3->SetRenderState(renderState1);

    meshRendererSuzanne4 = new ShiEngine::MeshRenderer(program, meshSuzane);
    meshRendererSuzanne4->SetRenderState(renderState1);

    meshRendererSuzanne5 = new ShiEngine::MeshRenderer(program, meshSuzane);
    meshRendererSuzanne5->SetRenderState(renderState1);

    meshRendererSuzanne6 = new ShiEngine::MeshRenderer(program, meshSuzane);
    meshRendererSuzanne6->SetRenderState(renderState1);

    texture1 = new ShiEngine::Texture2D("../assets/Textures/woodtexture.jpg", true);
    sampler1 = new ShiEngine::Sampler();

    texture2 = new ShiEngine::Texture2D("../assets/Textures/doorTexture.jpg", true);
    textureEarth = new ShiEngine::Texture2D("../assets/Textures/2k_earth_daymap.jpg", true);

    material1 = new ShiEngine::Material();
    material1->shaderProgram = program;
    material1->albedo_tint = {1, 1, 1}; // The reflectance color
    material1->specular_tint = {1, 1, 1};
    material1->roughness_range = {0,1};
    material1->emissive_tint = {0.1,0.1,0.1};
    material1->setTexture(textureEarth);
    material1->setSampler(sampler1);
    meshRenderer1->SetMaterial(material1);

    materialCube = new ShiEngine::Material();
    materialCube->shaderProgram = program;
    materialCube->albedo_tint = {1, 1, 1}; // The reflectance color
    materialCube->specular_tint = {1, 1, 1};
    materialCube->roughness_range = {0,1};
    materialCube->emissive_tint = {1,1,1};
    materialCube->setTexture(texture2);
    materialCube->setSampler(sampler1);

    materialPlane = new ShiEngine::Material();
    materialPlane->albedo_tint = {0.93, 0.1019, 0.301}; // The reflectance color
    materialPlane->specular_tint = {1, 1, 1};
    materialPlane->roughness_range = {0,1};
    materialPlane->emissive_tint = {0.3,0.3,0.3};
    materialPlane->setTexture(texture1);
    materialPlane->setSampler(sampler1);
    materialPlane->shaderProgram = program;

    meshRendererPlane->SetMaterial(materialPlane);
    meshRenderer2->SetMaterial(materialCube); //cube will have same material as sphere
    meshRenderer3->SetMaterial(materialCube);






    ///
    meshRendererPlane2->SetMaterial(materialPlane);
    meshRendererPlane3->SetMaterial(materialPlane);
    meshRendererPlane4->SetMaterial(materialPlane);
    meshRendererPlane5->SetMaterial(materialPlane);
    meshRendererPlane6->SetMaterial(materialPlane);
    meshRendererSuzane->SetMaterial(material1);
    meshRendererSuzanne2->SetMaterial(material1);
    meshRendererSuzanne3->SetMaterial(material1);
    meshRendererSuzanne4->SetMaterial(material1);
    meshRendererSuzanne5->SetMaterial(material1);
    meshRendererSuzanne6->SetMaterial(material1);

    objCamera->AddComponent(transformCamera);
    objCamera->AddComponent(camera);
    objCamera->AddComponent(boxColliderPlayer);
    objCamera->Name = "objCamera";

//    obj1->AddComponent(transform1);
//    obj1->AddComponent(meshRenderer1);
//    obj1->AddComponent(boxColliderWallRight);

    obj2->AddComponent(transform2);
    obj2->AddComponent(meshRenderer3);
    obj2->AddComponent(boxColliderWallLeft);

    // Door
    cubeGameObj->AddComponent(transformCubeObj);
    cubeGameObj->AddComponent(meshRenderer2);
    cubeGameObj->AddComponent(boxColliderWallFront);


    //obj1->AddComponent(material1);
    //obj1->Name = "sphere 1";
    cubeGameObj->Name = "Door";
    obj2->Name = "cube 2";

    // Plane
    planeGameObject->AddComponent(transformPlane);
    planeGameObject->AddComponent(meshRendererPlane);
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
//////-------//////
    objSuzane->AddComponent(transformSuzane);
    objSuzane->AddComponent(meshRendererSuzane);
    objSuzane->AddComponent(moveEnemy1);
    objSuzane->Name = "Suzane";

    // Plane
    planeGameObject6->AddComponent(transformPlane6);
    planeGameObject6->AddComponent(meshRendererPlane6);
    planeGameObject6->Name = "plane6 gameObject";

    planeGameObject2->AddComponent(transformPlane2);
    planeGameObject2->AddComponent(meshRendererPlane2);
    //planeGameObject2->AddComponent(boxColliderWallRight);
    planeGameObject2->Name = "plane2 gameObject";

    planeGameObject3->AddComponent(transformPlane3);
    planeGameObject3->AddComponent(meshRendererPlane3);
    //planeGameObject3->AddComponent(boxColliderWallLeft);
    planeGameObject3->Name = "plane3 gameObject";

    planeGameObject4->AddComponent(transformPlane4);
    planeGameObject4->AddComponent(meshRendererPlane4);
    //planeGameObject4->AddComponent(boxColliderWallFront);
    planeGameObject4->Name = "plane4 gameObject";

    planeGameObject5->AddComponent(transformPlane5);
    planeGameObject5->AddComponent(meshRendererPlane5);
    //planeGameObject5->AddComponent(boxColliderWallBehind);
    planeGameObject5->Name = "plane4 gameObject";

    // Point Light 1
    pointLightGameObject3->AddComponent(transformPointLight3);
    pointLightGameObject3->AddComponent(pointLight3);

    pointLightGameObject4->AddComponent(transformPointLight4);
    pointLightGameObject4->AddComponent(pointLight4);

    pointLightGameObject5->AddComponent(transformPointLight5);
    pointLightGameObject5->AddComponent(pointLight5);

    pointLightGameObject6->AddComponent(transformPointLight6);
    pointLightGameObject6->AddComponent(pointLight6);


    objSuzane2->AddComponent(transformSuzane2);
    objSuzane2->AddComponent(meshRendererSuzanne2);
    objSuzane2->Name = "Suzane2";

    objSuzane3->AddComponent(transformSuzane3);
    objSuzane3->AddComponent(meshRendererSuzanne3);
    objSuzane3->Name = "Suzane3";

    objSuzane4->AddComponent(transformSuzane4);
    objSuzane4->AddComponent(meshRendererSuzanne4);
    objSuzane4->Name = "Suzane4";

    objSuzane5->AddComponent(transformSuzane5);
    objSuzane5->AddComponent(meshRendererSuzanne5);
    objSuzane5->Name = "Suzane5";

    objSuzane6->AddComponent(transformSuzane6);
    objSuzane6->AddComponent(meshRendererSuzanne6);
    objSuzane6->Name = "Suzane6";



    objCamera->Start();
    controller->initialize(application, camera);

    state->addGameObject(objCamera);
    //state->addChildGameObject(objCamera, obj1);
    state->addGameObject(obj1);
    state->addGameObject(obj2);
    //state->addChildGameObject(obj1, cubeGameObj);
    state->addGameObject(cubeGameObj);
    //state->addGameObject(planeGameObject);
    //state->addGameObject(directionalLightGameObject);
    state->addGameObject(pointLightGameObject);
    state->addGameObject(pointLightGameObject2);
    //state->addGameObject(spotLightGameObject);
    //state->addGameObject(planeGameObject2);
    //state->addGameObject(planeGameObject3);
    //state->addGameObject(planeGameObject4);
    //state->addGameObject(planeGameObject5);
    //state->addGameObject(planeGameObject6);
    state->addGameObject(spotLightGameObject);

    state->addGameObject(objSuzane);
    state->addGameObject(pointLightGameObject3);
    state->addGameObject(pointLightGameObject4);
    state->addGameObject(pointLightGameObject5);
    state->addGameObject(pointLightGameObject6);

    state->addGameObject(objSuzane2);
    state->addGameObject(objSuzane3);
    state->addGameObject(objSuzane4);
    state->addGameObject(objSuzane5);
    state->addGameObject(objSuzane6);


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

    ShiEngine::MeshRenderer* meshRendererPlane;

    auto* obj1 = new ShiEngine::GameObject();
    auto* obj2 = new ShiEngine::GameObject();
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

    // Resources
    meshCube = new ShiEngine::Mesh();
    meshCube->Sphere(false);

    meshSphere = new ShiEngine::Mesh();
    meshSphere->Cuboid(false);

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


    transformPlane = new ShiEngine::Transform();
    transformPlane->position = glm::vec3({0, -1, 0});
    transformPlane->scale = glm::vec3({100,1,100});
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
    transformPointLight2->position = glm::vec3({-2, 0, 0});
    transformPointLight2->scale = glm::vec3({1,1,1});
    transformPointLight2->rotation = glm::vec3({0,0,0});
    transformPointLight2->direction = glm::vec3({-1, -1, -1});

    // Spot Light Transform
    transformSpotLight = new ShiEngine::Transform();
    transformSpotLight->position = glm::vec3({-200, 5, 0});
    transformSpotLight->scale = glm::vec3({1,1,1});
    transformSpotLight->rotation = glm::vec3({0,0,0});
    transformSpotLight->direction = glm::vec3({0,-1,0});

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

    texture1 = new ShiEngine::Texture2D("../assets/Textures/monarch.png", true);
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
    //state->addGameObject(planeGameObject);
    //state->addGameObject(directionalLightGameObject);
    //state->addGameObject(pointLightGameObject);
    //state->addGameObject(pointLightGameObject2);
    state->addGameObject(spotLightGameObject);


    state->attachCameraController(controller);

    return state;
}


#endif //GFX_LAB_STATES_H
