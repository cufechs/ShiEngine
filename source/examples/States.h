//
// Created by adham on 12/4/2020.
//

#ifndef GFX_LAB_STATES_H
#define GFX_LAB_STATES_H

//#include <Shader.hpp>
//#include <GameState.h>
//#include "GameObject.h"
//#include "MeshRenderer.h"
//#include "testComp.h"
//#include "Camera.h"
//#include "CameraController.h"
//#include <application.hpp>
//#include "Globals/Global_vars.h"
//#include "RenderState.h"
//#include "BoxCollider.h"
//#include "EnemyMovement.h"

#include "Level2.h"

ShiEngine::GameState* CreateState1(ShiEngine::Application* application){

    auto* state = new ShiEngine::GameState;
    state->Name = "Level1";
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
    ShiEngine::MeshRenderer* MRBox1;
    ShiEngine::MeshRenderer* MRBox2;
    ShiEngine::MeshRenderer* MRBox3;
    ShiEngine::MeshRenderer* MRBox4;
    ShiEngine::MeshRenderer* MRBox5;
    ShiEngine::MeshRenderer* MRBox6;
    ShiEngine::MeshRenderer* MRBox7;
    ShiEngine::MeshRenderer* MRBox8;
    ShiEngine::MeshRenderer* MRBox9;
    ShiEngine::MeshRenderer* MRBox10;

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
    auto* pointLightGameObjectS1 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* pointLightGameObjectS2 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* pointLightGameObjectS3 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* pointLightGameObjectS4 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* pointLightGameObjectS5 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* pointLightGameObjectS6 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* pointLightGameObjectS7 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* pointLightGameObjectS8 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* pointLightGameObjectS9 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* pointLightGameObjectS10 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* pointLightGameObject5 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* pointLightGameObject6 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
    auto* objSuzane = new ShiEngine::GameObject();
    auto* objSuzane2 = new ShiEngine::GameObject();
    auto* objSuzane3 = new ShiEngine::GameObject();
    auto* objSuzane4 = new ShiEngine::GameObject();
    auto* objSuzane5 = new ShiEngine::GameObject();
    auto* objSuzane6 = new ShiEngine::GameObject();
    auto* camController = new ShiEngine::GameObject();
    auto* Box1 = new ShiEngine::GameObject();
    auto* Box2 = new ShiEngine::GameObject();
    auto* Box3 = new ShiEngine::GameObject();
    auto* Box4 = new ShiEngine::GameObject();
    auto* Box5 = new ShiEngine::GameObject();
    auto* Box6 = new ShiEngine::GameObject();
    auto* Box7 = new ShiEngine::GameObject();
    auto* Box8 = new ShiEngine::GameObject();
    auto* Box9 = new ShiEngine::GameObject();
    auto* Box10 = new ShiEngine::GameObject();

    RenderState* renderState1;

    ShiEngine::Transform* transform1;
    ShiEngine::Transform* transform2;
    ShiEngine::Transform* transformCamera;
    ShiEngine::Transform* transformCube;

    ShiEngine::Transform* TBox1;
    ShiEngine::Transform* TBox2;
    ShiEngine::Transform* TBox3;
    ShiEngine::Transform* TBox4;
    ShiEngine::Transform* TBox5;
    ShiEngine::Transform* TBox6;
    ShiEngine::Transform* TBox7;
    ShiEngine::Transform* TBox8;
    ShiEngine::Transform* TBox9;
    ShiEngine::Transform* TBox10;

    ShiEngine::BoxCollider* BCBox1;
    ShiEngine::BoxCollider* BCBox2;
    ShiEngine::BoxCollider* BCBox3;
    ShiEngine::BoxCollider* BCBox4;
    ShiEngine::BoxCollider* BCBox5;
    ShiEngine::BoxCollider* BCBox6;
    ShiEngine::BoxCollider* BCBox7;
    ShiEngine::BoxCollider* BCBox8;
    ShiEngine::BoxCollider* BCBox9;
    ShiEngine::BoxCollider* BCBox10;

    ShiEngine::BoxCollider* boxColliderPlayer;
    ShiEngine::BoxCollider* boxColliderWallBehind;
    ShiEngine::BoxCollider* boxColliderWallFront;
    ShiEngine::BoxCollider* boxColliderWallRight;
    ShiEngine::BoxCollider* boxColliderWallLeft;

    ShiEngine::BoxCollider* pointLightBoxCollider1;
    ShiEngine::BoxCollider* pointLightBoxCollider2;
    ShiEngine::BoxCollider* pointLightBoxCollider3;
    ShiEngine::BoxCollider* pointLightBoxCollider4;
    ShiEngine::BoxCollider* pointLightBoxCollider5;
    ShiEngine::BoxCollider* pointLightBoxCollider6;
    ShiEngine::BoxCollider* BCWF;

    ShiEngine::Transform* transformPlane;
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

    ShiEngine::Transform* transformPointLightS1;
    ShiEngine::Transform* transformPointLightS2;
    ShiEngine::Transform* transformPointLightS3;
    ShiEngine::Transform* transformPointLightS4;
    ShiEngine::Transform* transformPointLightS5;
    ShiEngine::Transform* transformPointLightS6;
    ShiEngine::Transform* transformPointLightS7;
    ShiEngine::Transform* transformPointLightS8;
    ShiEngine::Transform* transformPointLightS9;
    ShiEngine::Transform* transformPointLightS10;
    ShiEngine::Transform* transformPointLight5;
    ShiEngine::Transform* transformPointLight6;

    ShiEngine::Camera* camera;
    ShiEngine::Light* pointLightS1;
    ShiEngine::Light* pointLightS2;
    ShiEngine::Light* pointLightS3;
    ShiEngine::Light* pointLightS4;
    ShiEngine::Light* pointLightS5;
    ShiEngine::Light* pointLightS6;
    ShiEngine::Light* pointLightS7;
    ShiEngine::Light* pointLightS8;
    ShiEngine::Light* pointLightS9;
    ShiEngine::Light* pointLightS10;
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
    ShiEngine::Material* MATBox;

    ShiEngine::Mesh* meshCube;
    ShiEngine::Mesh* meshPlane;
    ShiEngine::Mesh* meshSphere;
    ShiEngine::Mesh* meshPlane2;
    ShiEngine::Mesh* meshPlane3;
    ShiEngine::Mesh* meshPlane4;
    ShiEngine::Mesh* meshPlane5;
    ShiEngine::Mesh* meshPlane6;
    ShiEngine::Mesh* meshSuzane;
    ShiEngine::Mesh* meshKey;

    ShiEngine::Texture2D* texture1; //texture Earth
    ShiEngine::Texture2D* TextureM;
    ShiEngine::Sampler* sampler1;

    ShiEngine::Texture2D* texture2;
    ShiEngine::Texture2D* textureEarth;

    ShiEngine::EnemyMovement* moveEnemy1;
    ShiEngine::EnemyMovement* moveEnemy2;
    ShiEngine::EnemyMovement* moveEnemy3;
    ShiEngine::EnemyMovement* moveEnemy4;
    ShiEngine::EnemyMovement* moveEnemy5;
    ShiEngine::EnemyMovement* moveEnemy6;
    ShiEngine::EnemyMovement* moveEnemy7;
    ShiEngine::EnemyMovement* moveEnemy8;
    ShiEngine::EnemyMovement* moveEnemy9;
    ShiEngine::EnemyMovement* moveEnemy10;
    ShiEngine::EnemyMovement* moveEnemy11;
    ShiEngine::EnemyMovement* moveEnemy12;

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


    meshSphere = new ShiEngine::Mesh();
   // meshSphere->Model("../assets/models/Ghost/ghost.obj");

    meshSuzane = new ShiEngine::Mesh();
    meshSuzane->Model( "../assets/models/Suzanne/Suzanne.obj");

    meshKey = new ShiEngine::Mesh();
    meshKey->Model( "../assets/models/Suzanne/Suzanne.obj");

    //Transforms
    TBox1 = new ShiEngine::Transform();
    TBox1->position = glm::vec3({-150, 20, -54});
    TBox1->scale = glm::vec3({1,40,14});
    TBox1->rotation = glm::vec3({0,180,0});

    TBox2 = new ShiEngine::Transform();
    TBox2->position = glm::vec3({-150, 20, 54});
    TBox2->scale = glm::vec3({1,40,14});
    TBox2->rotation = glm::vec3({0,0,0});

    TBox3 = new ShiEngine::Transform();
    TBox3->position = glm::vec3({-103, 20, 0});
    TBox3->scale = glm::vec3({1,40,14});
    TBox3->rotation = glm::vec3({0,0,0});

    TBox4 = new ShiEngine::Transform();
    TBox4->position = glm::vec3({-72, 20, -54});
    TBox4->scale = glm::vec3({1,40,14});
    TBox4->rotation = glm::vec3({0,0,0});

    TBox5 = new ShiEngine::Transform();
    TBox5->position = glm::vec3({-72, 20, 54});
    TBox5->scale = glm::vec3({1,40,14});
    TBox5->rotation = glm::vec3({0,0,0});

    TBox6 = new ShiEngine::Transform();
    TBox6->position = glm::vec3({-200, 10, 0});
    TBox6->scale = glm::vec3({1,1,1});
    TBox6->rotation = glm::vec3({0,0,0});

    TBox7 = new ShiEngine::Transform();
    TBox7->position = glm::vec3({-200, 10, 0});
    TBox7->scale = glm::vec3({1,1,1});
    TBox7->rotation = glm::vec3({0,0,0});

    TBox8 = new ShiEngine::Transform();
    TBox8->position = glm::vec3({-200, 10, 0});
    TBox8->scale = glm::vec3({1,1,1});
    TBox8->rotation = glm::vec3({0,0,0});

    TBox9 = new ShiEngine::Transform();
    TBox9->position = glm::vec3({-200, 10, 0});
    TBox9->scale = glm::vec3({1,1,1});
    TBox9->rotation = glm::vec3({0,0,0});

    TBox10 = new ShiEngine::Transform();
    TBox10->position = glm::vec3({190, 2, -45});
    TBox10->scale = glm::vec3({1,1,1});
    TBox10->rotation = glm::vec3({0,0,0});

    transformCamera = new ShiEngine::Transform();
    transformCamera->position = glm::vec3({-210, 10, 0});
    transformCamera->scale = glm::vec3({10,25,4});
    transformCamera->rotation = glm::vec3({0,0,0});

    transformCube = new ShiEngine::Transform();
    transformCube->position = glm::vec3({-208, 0, 6});
    transformCube->scale = glm::vec3({0.1,0.1,0.1});
    transformCube->rotation = glm::vec3({5,0,0});

    // Wall left
    transformPlane2 = new ShiEngine::Transform();
    transformPlane2->position = glm::vec3({0, 1, -65});
    transformPlane2->scale = glm::vec3({-500,100,4});
    transformPlane2->rotation = glm::vec3({0,0,0});

    // Wall right
    transformPlane3 = new ShiEngine::Transform();
    transformPlane3->position = glm::vec3({0, 1, 65});
    transformPlane3->scale = glm::vec3({-500,100,4});
    transformPlane3->rotation = glm::vec3({0,0,0});

    // Wall behind
    transformPlane4 = new ShiEngine::Transform();
    transformPlane4->position = glm::vec3({-225, 1, 0});
    transformPlane4->scale = glm::vec3({4,30,200});
    transformPlane4->rotation = glm::vec3({0,0,0});

    // Wall front
    transformPlane5 = new ShiEngine::Transform();
    transformPlane5->position = glm::vec3({-18, 1, 0});
    transformPlane5->scale = glm::vec3({2,100,400});
    transformPlane5->rotation = glm::vec3({0,0,0});

    // Wall up
    transformPlane6 = new ShiEngine::Transform();
    transformPlane6->position = glm::vec3({0, 40, 0});
    transformPlane6->scale = glm::vec3({-500,1,200});
    transformPlane6->rotation = glm::vec3({0,0,0});

    // Wall down
    transformPlane = new ShiEngine::Transform();
    transformPlane->position = glm::vec3({0, -1, 0});
    transformPlane->scale = glm::vec3({-700,1,700});
    transformPlane->rotation = glm::vec3({0,0,0});

    //Loading Objects
    transformSuzane = new ShiEngine::Transform();
    //transformSuzane->position = glm::vec3({-30, 5, 0});//kairi
    transformSuzane->position = glm::vec3({3.5, -1, 2}); // note: position relative to parent (PointLight2)
    transformSuzane->scale = glm::vec3({4,4,4});
    transformSuzane->rotation = glm::vec3({0,-90,0});

    transformSuzane2 = new ShiEngine::Transform();
    transformSuzane2->position = glm::vec3({3.5, -1, 2});//kairi
    transformSuzane2->scale = glm::vec3({4,4,4});
    transformSuzane2->rotation = glm::vec3({0,-90,0});

    transformSuzane3 = new ShiEngine::Transform();
    transformSuzane3->position = glm::vec3({3.5, -1, 2});//kairi
    transformSuzane3->scale = glm::vec3({4,4,4});
    transformSuzane3->rotation = glm::vec3({0,-90,0});

    transformSuzane4 = new ShiEngine::Transform();
    transformSuzane4->position = glm::vec3({3.5, -1, 2});//kairi
    transformSuzane4->scale = glm::vec3({4,4,4});
    transformSuzane4->rotation = glm::vec3({0,-90,0});

    transformSuzane5 = new ShiEngine::Transform();
    transformSuzane5->position = glm::vec3({3.5, -1, 2});//kairi
    transformSuzane5->scale = glm::vec3({4,4,4});
    transformSuzane5->rotation = glm::vec3({0,-90,0});

    transformSuzane6 = new ShiEngine::Transform();
    transformSuzane6->position = glm::vec3({3.5, -1, 2});//kairi
    transformSuzane6->scale = glm::vec3({4,4,4});
    transformSuzane6->rotation = glm::vec3({0,-90,0});

    transform1 = new ShiEngine::Transform();
    transform1->position = glm::vec3({0, 0, 0});
    transform1->scale = glm::vec3({1,1,1});
    transform1->rotation = glm::vec3({0,0,0});

    transform2 = new ShiEngine::Transform();
    transform2->position = glm::vec3({2, 5, 0});
    transform2->scale = glm::vec3({2,2,2});
    transform2->rotation = glm::vec3({0,0,0});

    BCBox1 = new ShiEngine::BoxCollider();
    BCBox2 = new ShiEngine::BoxCollider();
    BCBox3 = new ShiEngine::BoxCollider();
    BCBox4 = new ShiEngine::BoxCollider();
    BCBox5 = new ShiEngine::BoxCollider();
    BCBox6 = new ShiEngine::BoxCollider();
    BCBox7 = new ShiEngine::BoxCollider();
    BCBox8 = new ShiEngine::BoxCollider();
    BCBox9 = new ShiEngine::BoxCollider();
    BCBox10 = new ShiEngine::BoxCollider();
    BCWF = new ShiEngine::BoxCollider();

    boxColliderPlayer = new ShiEngine::BoxCollider();
    boxColliderWallBehind = new ShiEngine::BoxCollider();
    boxColliderWallFront = new ShiEngine::BoxCollider();
    boxColliderWallFront->IsTrigger = true;
    boxColliderWallLeft = new ShiEngine::BoxCollider();
    boxColliderWallRight = new ShiEngine::BoxCollider();

    pointLightBoxCollider1 = new ShiEngine::BoxCollider();
    pointLightBoxCollider2 = new ShiEngine::BoxCollider();
    pointLightBoxCollider3 = new ShiEngine::BoxCollider();
    pointLightBoxCollider4 = new ShiEngine::BoxCollider();
    pointLightBoxCollider5 = new ShiEngine::BoxCollider();
    pointLightBoxCollider6 = new ShiEngine::BoxCollider();

    // Door
    transformCubeObj = new ShiEngine::Transform();
    transformCubeObj->position = glm::vec3({-20, 12, 0});
    transformCubeObj->scale = glm::vec3({2,30,18});
    transformCubeObj->rotation = glm::vec3({0,0,0});


    transformCube = new ShiEngine::Transform();
    transformCube->position = glm::vec3({0, 0, 0});
    transformCube->scale = glm::vec3({2,2,2});
    transformCube->rotation = glm::vec3({0,0,0});

    // Point Light Transfor Spot Light Transform
    transformPointLightS1 = new ShiEngine::Transform();
    transformPointLightS1->position = glm::vec3({-30, 5, 0});
    transformPointLightS1->scale = glm::vec3({1,1,1});
    transformPointLightS1->rotation = glm::vec3({0,0,0});
    transformPointLightS1->direction = glm::vec3({-1, -1, -1});

    transformPointLightS2 = new ShiEngine::Transform();
    transformPointLightS2->position = glm::vec3({-30, 5, 4});
    transformPointLightS2->scale = glm::vec3({1,1,1});
    transformPointLightS2->rotation = glm::vec3({0,0,0});
    transformPointLightS2->direction = glm::vec3({0, -2, 0});// Point Light Transform

    transformPointLightS3 = new ShiEngine::Transform();
    transformPointLightS3->position = glm::vec3({-50, 5, -20});
    transformPointLightS3->scale = glm::vec3({1,1,1});
    transformPointLightS3->rotation = glm::vec3({0,0,0});
    transformPointLightS3->direction = glm::vec3({-1, -1, -1});

    transformPointLightS4 = new ShiEngine::Transform();
    transformPointLightS4->position = glm::vec3({-50, 5, -16});
    transformPointLightS4->scale = glm::vec3({1,1,1});
    transformPointLightS4->rotation = glm::vec3({0,0,0});
    transformPointLightS4->direction = glm::vec3({0, -2, 0});// Point Light Transform

    transformPointLightS5 = new ShiEngine::Transform();
    transformPointLightS5->position = glm::vec3({-70, 5, 30});
    transformPointLightS5->scale = glm::vec3({1,1,1});
    transformPointLightS5->rotation = glm::vec3({0,0,0});
    transformPointLightS5->direction = glm::vec3({-1, -1, -1});

    transformPointLightS6 = new ShiEngine::Transform();
    transformPointLightS6->position = glm::vec3({-70, 5, 34});
    transformPointLightS6->scale = glm::vec3({1,1,1});
    transformPointLightS6->rotation = glm::vec3({0,0,0});
    transformPointLightS6->direction = glm::vec3({0, -2, 0});// Point Light Transform

    transformPointLightS7 = new ShiEngine::Transform();
    transformPointLightS7->position = glm::vec3({-90, 5, 10});
    transformPointLightS7->scale = glm::vec3({1,1,1});
    transformPointLightS7->rotation = glm::vec3({0,0,0});
    transformPointLightS7->direction = glm::vec3({-1, -1, -1});

    transformPointLightS8 = new ShiEngine::Transform();
    transformPointLightS8->position = glm::vec3({-90, 5, 14});
    transformPointLightS8->scale = glm::vec3({1,1,1});
    transformPointLightS8->rotation = glm::vec3({0,0,0});
    transformPointLightS8->direction = glm::vec3({0, -2, 0});// Point Light Transform

    transformPointLightS9 = new ShiEngine::Transform();
    transformPointLightS9->position = glm::vec3({-120, 5, -20});
    transformPointLightS9->scale = glm::vec3({1,1,1});
    transformPointLightS9->rotation = glm::vec3({0,0,0});
    transformPointLightS9->direction = glm::vec3({-1, -1, -1});

    transformPointLightS10 = new ShiEngine::Transform();
    transformPointLightS10->position = glm::vec3({-120, 5, -16});
    transformPointLightS10->scale = glm::vec3({1,1,1});
    transformPointLightS10->rotation = glm::vec3({0,0,0});
    transformPointLightS10->direction = glm::vec3({0, -2, 0});// Point Light Transform

    transformPointLight5 = new ShiEngine::Transform();
    transformPointLight5->position = glm::vec3({-154, 6, -2});
    transformPointLight5->scale = glm::vec3({1,1,1});
    transformPointLight5->rotation = glm::vec3({0,0,0});
    transformPointLight5->direction = glm::vec3({-1, -1, -1});

    transformPointLight6 = new ShiEngine::Transform();
    transformPointLight6->position = glm::vec3({-154, 6, 2});
    transformPointLight6->scale = glm::vec3({1,1,1});
    transformPointLight6->rotation = glm::vec3({0,0,0});
    transformPointLight6->direction = glm::vec3({0, -2, 0});// Point Light Transform

    moveEnemy1 = new ShiEngine::EnemyMovement(0.0f);
    moveEnemy1->setOscillateY(2.0, 0.1);
    moveEnemy1->setOscillateZ(20.0, 0.4);
    moveEnemy1->setFollow(transformCamera, false, true);

    moveEnemy2 = new ShiEngine::EnemyMovement(0.0f);
    moveEnemy2->setOscillateY(2.0, 0.1);
    moveEnemy2->setOscillateZ(20.0, 0.4);
    moveEnemy2->setFollow(transformCamera, false, true);

    moveEnemy3 = new ShiEngine::EnemyMovement(1);
    moveEnemy3->setOscillateY(2.0, 0.1);
    moveEnemy3->setOscillateZ(20.0, 0.4);
    moveEnemy3->setFollow(transformCamera, false, true);

    moveEnemy4 = new ShiEngine::EnemyMovement(1);
    moveEnemy4->setOscillateY(2.0, 0.1);
    moveEnemy4->setOscillateZ(20.0, 0.4);
    moveEnemy4->setFollow(transformCamera, false, true);

    moveEnemy5 = new ShiEngine::EnemyMovement(2);
    moveEnemy5->setOscillateY(2.0, 0.1);
    moveEnemy5->setOscillateZ(20.0, 0.4);
    moveEnemy5->setFollow(transformCamera, false, true);

    moveEnemy6 = new ShiEngine::EnemyMovement(2);
    moveEnemy6->setOscillateY(2.0, 0.1);
    moveEnemy6->setOscillateZ(20.0, 0.4);
    moveEnemy6->setFollow(transformCamera, false, true);

    moveEnemy7 = new ShiEngine::EnemyMovement(3);
    moveEnemy7->setOscillateY(2.0, 0.1);
    moveEnemy7->setOscillateZ(20.0, 0.4);
    moveEnemy7->setFollow(transformCamera, false, true);

    moveEnemy8 = new ShiEngine::EnemyMovement(3);
    moveEnemy8->setOscillateY(2.0, 0.1);
    moveEnemy8->setOscillateZ(20.0, 0.4);
    moveEnemy8->setFollow(transformCamera, false, true);

    moveEnemy9 = new ShiEngine::EnemyMovement(4);
    moveEnemy9->setOscillateY(2.0, 0.1);
    moveEnemy9->setOscillateZ(20.0, 0.4);
    moveEnemy9->setFollow(transformCamera, false, true);

    moveEnemy10 = new ShiEngine::EnemyMovement(4);
    moveEnemy10->setOscillateY(2.0, 0.1);
    moveEnemy10->setOscillateZ(20.0, 0.4);
    moveEnemy10->setFollow(transformCamera, false, true);

    moveEnemy11 = new ShiEngine::EnemyMovement(5);
    moveEnemy11->setOscillateY(2.0, 0.1);
    moveEnemy11->setOscillateZ(20.0, 0.4);
    moveEnemy11->setFollow(transformCamera, false, true);

    moveEnemy12 = new ShiEngine::EnemyMovement(5);
    moveEnemy12->setOscillateY(2.0, 0.1);
    moveEnemy12->setOscillateZ(20.0, 0.4);
    moveEnemy12->setFollow(transformCamera, false, true);

    camera = new ShiEngine::Camera();
    camera->setupPerspective(glm::pi<float>()/2, 1.7f, 0.1f, 1000.0f);
    //camera->setupOrthographic(2.f, 1.7, 0.1f, 100.0f);

    pointLightS1 = new ShiEngine::Light(ShiEngine::LightType::POINT);
    pointLightS1->setAttenuation(0,0,0.1);
    pointLightS1->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({0.1,0.1,0.1}), glm::vec3({0.1,0.1,0.1}));

    pointLightS2 = new ShiEngine::Light(ShiEngine::LightType::POINT);
    pointLightS2->setAttenuation(0,0,0.1);
    pointLightS2->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({1,1,1}), glm::vec3({0.1,0.1,0.1}));

    pointLightS3 = new ShiEngine::Light(ShiEngine::LightType::POINT);
    pointLightS3->setAttenuation(0,0,0.1);
    pointLightS3->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({0.1,0.1,0.1}), glm::vec3({0.1,0.1,0.1}));

    pointLightS4 = new ShiEngine::Light(ShiEngine::LightType::POINT);
    pointLightS4->setAttenuation(0,0,0.1);
    pointLightS4->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({1,1,1}), glm::vec3({0.1,0.1,0.1}));

    pointLightS5 = new ShiEngine::Light(ShiEngine::LightType::POINT);
    pointLightS5->setAttenuation(0,0,0.1);
    pointLightS5->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({0.1,0.1,0.1}), glm::vec3({0.1,0.1,0.1}));

    pointLightS6 = new ShiEngine::Light(ShiEngine::LightType::POINT);
    pointLightS6->setAttenuation(0,0,0.1);
    pointLightS6->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({1,1,1}), glm::vec3({0.1,0.1,0.1}));

    pointLightS7 = new ShiEngine::Light(ShiEngine::LightType::POINT);
    pointLightS7->setAttenuation(0,0,0.1);
    pointLightS7->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({0.1,0.1,0.1}), glm::vec3({0.1,0.1,0.1}));

    pointLightS8 = new ShiEngine::Light(ShiEngine::LightType::POINT);
    pointLightS8->setAttenuation(0,0,0.1);
    pointLightS8->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({1,1,1}), glm::vec3({0.1,0.1,0.1}));

    pointLightS9 = new ShiEngine::Light(ShiEngine::LightType::POINT);
    pointLightS9->setAttenuation(0,0,0.1);
    pointLightS9->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({0.1,0.1,0.1}), glm::vec3({0.1,0.1,0.1}));

    pointLightS10 = new ShiEngine::Light(ShiEngine::LightType::POINT);
    pointLightS10->setAttenuation(0,0,0.1);
    pointLightS10->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({1,1,1}), glm::vec3({0.1,0.1,0.1}));

    pointLight5 = new ShiEngine::Light(ShiEngine::LightType::POINT);
    pointLight5->setAttenuation(0,0,0.1);
    pointLight5->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({0.1,0.1,0.1}), glm::vec3({0.1,0.1,0.1}));

    pointLight6 = new ShiEngine::Light(ShiEngine::LightType::POINT);
    pointLight6->setAttenuation(0,0,0.1);
    pointLight6->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({1,1,1}), glm::vec3({0.1,0.1,0.1}));

    renderState1 = new RenderState(true,true,false);

    MRBox1 = new ShiEngine::MeshRenderer(program, meshCube);
    MRBox1->SetRenderState(renderState1);

    MRBox2 = new ShiEngine::MeshRenderer(program, meshCube);
    MRBox2->SetRenderState(renderState1);

    MRBox3 = new ShiEngine::MeshRenderer(program, meshCube);
    MRBox3->SetRenderState(renderState1);

    MRBox4 = new ShiEngine::MeshRenderer(program, meshCube);
    MRBox4->SetRenderState(renderState1);

    MRBox5 = new ShiEngine::MeshRenderer(program, meshCube);
    MRBox5->SetRenderState(renderState1);

    MRBox6 = new ShiEngine::MeshRenderer(program, meshCube);
    MRBox6->SetRenderState(renderState1);

    MRBox7 = new ShiEngine::MeshRenderer(program, meshCube);
    MRBox7->SetRenderState(renderState1);

    MRBox8 = new ShiEngine::MeshRenderer(program, meshCube);
    MRBox8->SetRenderState(renderState1);

    MRBox9 = new ShiEngine::MeshRenderer(program, meshCube);
    MRBox9->SetRenderState(renderState1);

    MRBox10 = new ShiEngine::MeshRenderer(program, meshCube);
    MRBox10->SetRenderState(renderState1);

    meshRenderer1 = new ShiEngine::MeshRenderer(program, meshSphere);
    meshRenderer1->SetRenderState(renderState1);

    meshRenderer2 = new ShiEngine::MeshRenderer(program, meshCube);
    meshRenderer2->SetRenderState(renderState1);

    meshRenderer3 = new ShiEngine::MeshRenderer(program, meshCube);
    meshRenderer3->SetRenderState(renderState1);

    meshRendererPlane = new ShiEngine::MeshRenderer(program, meshPlane);
    meshRendererPlane->SetRenderState(renderState1);

    meshRendererPlane2 = new ShiEngine::MeshRenderer(program, meshCube);
    meshRendererPlane2->SetRenderState(renderState1);

    meshRendererPlane3 = new ShiEngine::MeshRenderer(program, meshCube);
    meshRendererPlane3->SetRenderState(renderState1);

    meshRendererPlane4 = new ShiEngine::MeshRenderer(program, meshCube);
    meshRendererPlane4->SetRenderState(renderState1);

    meshRendererPlane5 = new ShiEngine::MeshRenderer(program, meshCube);
    meshRendererPlane5->SetRenderState(renderState1);

    meshRendererPlane6 = new ShiEngine::MeshRenderer(program, meshPlane);
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

    TextureM = new ShiEngine::Texture2D("../assets/Textures/bloodtexture.jpg", true);

    texture2 = new ShiEngine::Texture2D("../assets/Textures/doorTexture.jpg", true);
    textureEarth = new ShiEngine::Texture2D("../assets/Textures/2k_earth_daymap.jpg", true);

    material1 = new ShiEngine::Material();
    material1->shaderProgram = program;
    material1->albedo_tint = {1, 1, 1}; // The reflectance color
    material1->specular_tint = {1, 1, 1};
    material1->roughness_range = {0,1};
    material1->emissive_tint = {0.1,0.1,0.1};
    material1->setTexture(TextureM);
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

    MATBox = new ShiEngine::Material();
    MATBox->shaderProgram = program;
    MATBox->albedo_tint = {1, 1, 1}; // The reflectance color
    MATBox->specular_tint = {1, 1, 1};
    MATBox->roughness_range = {0,1};
    MATBox->emissive_tint = {1,1,1};
    MATBox->setTexture(texture1);
    MATBox->setSampler(sampler1);

    materialPlane = new ShiEngine::Material();
    materialPlane->albedo_tint = {0.93, 0.1019, 0.301}; // The reflectance color
    materialPlane->specular_tint = {1, 1, 1};
    materialPlane->roughness_range = {0,1};
    materialPlane->emissive_tint = {0.1,0.1,0.1};
    materialPlane->setTexture(texture1);
    materialPlane->setSampler(sampler1);
    materialPlane->shaderProgram = program;

    meshRendererPlane->SetMaterial(materialPlane);
    meshRenderer2->SetMaterial(materialCube); //cube will have same material as sphere
    meshRenderer3->SetMaterial(materialCube);

    MRBox1->SetMaterial(MATBox);
    MRBox2->SetMaterial(MATBox);
    MRBox3->SetMaterial(MATBox);
    MRBox4->SetMaterial(MATBox);
    MRBox5->SetMaterial(MATBox);
    MRBox6->SetMaterial(MATBox);
    MRBox7->SetMaterial(MATBox);
    MRBox8->SetMaterial(MATBox);
    MRBox9->SetMaterial(MATBox);
    MRBox10->SetMaterial(MATBox);

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

    Box1->AddComponent(TBox1);
    Box2->AddComponent(TBox2);
    Box3->AddComponent(TBox3);
    Box4->AddComponent(TBox4);
    Box5->AddComponent(TBox5);
    Box6->AddComponent(TBox6);
    Box7->AddComponent(TBox7);
    Box8->AddComponent(TBox8);
    Box9->AddComponent(TBox9);
    Box10->AddComponent(TBox10);

    Box1->AddComponent(MRBox1);
    Box2->AddComponent(MRBox2);
    Box3->AddComponent(MRBox3);
    Box4->AddComponent(MRBox4);
    Box5->AddComponent(MRBox5);
    Box6->AddComponent(MRBox6);
    Box7->AddComponent(MRBox7);
    Box8->AddComponent(MRBox8);
    Box9->AddComponent(MRBox9);
    Box10->AddComponent(MRBox10);

    Box1->AddComponent(BCBox1);
    Box2->AddComponent(BCBox2);
    Box3->AddComponent(BCBox3);
    Box4->AddComponent(BCBox4);
    Box5->AddComponent(BCBox5);
    Box6->AddComponent(BCBox6);
    Box7->AddComponent(BCBox7);
    Box8->AddComponent(BCBox8);
    Box9->AddComponent(BCBox9);
    Box10->AddComponent(BCBox10);

    objCamera->AddComponent(transformCamera);
    objCamera->AddComponent(camera);
    objCamera->AddComponent(boxColliderPlayer);
    objCamera->Name = "objCamera";

//    obj1->AddComponent(transform1);
//    obj1->AddComponent(meshRenderer1);
//    obj1->AddComponent(boxColliderWallRight);

    obj2->AddComponent(transform2);
    obj2->AddComponent(meshRenderer3);
    //obj2->AddComponent(boxColliderWallLeft);

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

//////-------//////
    objSuzane->AddComponent(transformSuzane);
    objSuzane->AddComponent(meshRendererSuzane);
    objSuzane->Name = "Suzane";

    // Plane
    planeGameObject6->AddComponent(transformPlane6);
    planeGameObject6->AddComponent(meshRendererPlane6);
    planeGameObject6->Name = "plane6 gameObject";

    planeGameObject2->AddComponent(transformPlane2);
    planeGameObject2->AddComponent(meshRendererPlane2);
    planeGameObject2->AddComponent(boxColliderWallLeft);
    planeGameObject2->Name = "plane2 gameObject";

    planeGameObject3->AddComponent(transformPlane3);
    planeGameObject3->AddComponent(meshRendererPlane3);
    planeGameObject3->AddComponent(boxColliderWallRight);
    planeGameObject3->Name = "plane3 gameObject";

    planeGameObject4->AddComponent(transformPlane4);
    planeGameObject4->AddComponent(meshRendererPlane4);
    planeGameObject4->AddComponent(boxColliderWallBehind); // TODO: at start, the player is very close to the wall, therefore crashes
    planeGameObject4->Name = "plane4 gameObject";

    planeGameObject5->AddComponent(transformPlane5);
    planeGameObject5->AddComponent(meshRendererPlane5);
    planeGameObject5->AddComponent(BCWF);

    planeGameObject5->Name = "plane5 gameObject";

    pointLightGameObjectS1->AddComponent(transformPointLightS1);
    pointLightBoxCollider1->IsTrigger = true;
    pointLightGameObjectS1->AddComponent(pointLightBoxCollider1);
    pointLightGameObjectS1->AddComponent(pointLightS1);

    pointLightGameObjectS2->AddComponent(transformPointLightS2);
    pointLightGameObjectS2->AddComponent(pointLightS2);

    pointLightGameObjectS3->AddComponent(transformPointLightS3);
    pointLightBoxCollider2->IsTrigger = true;
    pointLightGameObjectS3->AddComponent(pointLightBoxCollider2);
    pointLightGameObjectS3->AddComponent(pointLightS3);

    pointLightGameObjectS4->AddComponent(transformPointLightS4);
    pointLightGameObjectS4->AddComponent(pointLightS4);

    pointLightGameObjectS5->AddComponent(transformPointLightS5);
    pointLightBoxCollider3->IsTrigger = true;
    pointLightGameObjectS5->AddComponent(pointLightBoxCollider3);
    pointLightGameObjectS5->AddComponent(pointLightS5);

    pointLightGameObjectS6->AddComponent(transformPointLightS6);
    pointLightGameObjectS6->AddComponent(pointLightS6);

    pointLightGameObjectS7->AddComponent(transformPointLightS7);
    pointLightBoxCollider4->IsTrigger = true;
    pointLightGameObjectS7->AddComponent(pointLightBoxCollider4);
    pointLightGameObjectS7->AddComponent(pointLightS7);

    pointLightGameObjectS8->AddComponent(transformPointLightS8);
    pointLightGameObjectS8->AddComponent(pointLightS8);

    pointLightGameObjectS9->AddComponent(transformPointLightS9);
    pointLightBoxCollider5->IsTrigger = true;
    pointLightGameObjectS9->AddComponent(pointLightBoxCollider5);
    pointLightGameObjectS9->AddComponent(pointLightS9);

    pointLightGameObjectS10->AddComponent(transformPointLightS10);
    pointLightGameObjectS10->AddComponent(pointLightS10);

    pointLightGameObject5->AddComponent(transformPointLight5);
    pointLightBoxCollider6->IsTrigger = true;
    pointLightGameObject5->AddComponent(pointLightBoxCollider6);
    pointLightGameObject5->AddComponent(pointLight5);

    pointLightGameObject6->AddComponent(transformPointLight6);
    pointLightGameObject6->AddComponent(pointLight6);

    pointLightGameObjectS1->AddComponent(moveEnemy1);
    pointLightGameObjectS2->AddComponent(moveEnemy2);
    pointLightGameObjectS3->AddComponent(moveEnemy3);
    pointLightGameObjectS4->AddComponent(moveEnemy4);
    pointLightGameObjectS5->AddComponent(moveEnemy5);
    pointLightGameObjectS6->AddComponent(moveEnemy6);
    pointLightGameObjectS7->AddComponent(moveEnemy7);
    pointLightGameObjectS8->AddComponent(moveEnemy8);
    pointLightGameObjectS9->AddComponent(moveEnemy9);
    pointLightGameObjectS10->AddComponent(moveEnemy10);
    pointLightGameObject5->AddComponent(moveEnemy11);
    pointLightGameObject6->AddComponent(moveEnemy12);

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

    camController->AddComponent(controller);


    objCamera->Start();
    controller->initialize(application, camera);


    //state->addChildGameObject(objCamera, obj1);
    state->addGameObject(obj1);
    state->addGameObject(obj2);
    //state->addChildGameObject(obj1, cubeGameObj);
    state->addGameObject(cubeGameObj);

    //state->addGameObject(directionalLightGameObject);

    //state->addGameObject(spotLightGameObject);
    state->addGameObject(planeGameObject);
    state->addGameObject(planeGameObject2);
    state->addGameObject(planeGameObject3);
    state->addGameObject(planeGameObject4);
    state->addGameObject(planeGameObject5);
    state->addGameObject(planeGameObject6);

    state->addGameObject(Box1);
    state->addGameObject(Box2);
    state->addGameObject(Box3);
    state->addGameObject(Box4);
    state->addGameObject(Box5);
//    state->addGameObject(Box6);
//    state->addGameObject(Box7);
//    state->addGameObject(Box8);
//    state->addGameObject(Box9);
//    state->addGameObject(Box10);
    //state->addGameObject(spotLightGameObject);


    state->addGameObject(pointLightGameObjectS1);
    state->addGameObject(pointLightGameObjectS2);
    state->addGameObject(pointLightGameObjectS3);
    state->addGameObject(pointLightGameObjectS4);
    state->addGameObject(pointLightGameObjectS5);
    state->addGameObject(pointLightGameObjectS6);
    state->addGameObject(pointLightGameObjectS7);
    state->addGameObject(pointLightGameObjectS8);
    state->addGameObject(pointLightGameObjectS9);
    state->addGameObject(pointLightGameObjectS10);
    state->addGameObject(pointLightGameObject5);
    state->addGameObject(pointLightGameObject6);
    state->addChildGameObject(pointLightGameObjectS1, objSuzane);
    state->addChildGameObject(pointLightGameObjectS3, objSuzane2);
    state->addChildGameObject(pointLightGameObjectS5, objSuzane3);
    state->addChildGameObject(pointLightGameObjectS7, objSuzane4);
    state->addChildGameObject(pointLightGameObjectS9, objSuzane5);
    state->addChildGameObject(pointLightGameObject5, objSuzane6);

    //state->addGameObject(camController);
    state->addGameObject(objCamera);


    state->attachCameraController(controller);

    return state;
}









//ShiEngine::GameState* CreateState2(ShiEngine::Application* application){
//
//    auto* state = new ShiEngine::GameState;
//    state->Name = "Level2";
//    auto *program = new ShiEngine::ShaderProgram;
//    ShiEngine::Global::Global_ShaderProgram = program;
//
//    GLuint vertex_array = 0;
//    //ShiEngine::GameObject GO;
//    ShiEngine::MeshRenderer* meshRenderer1;
//    ShiEngine::MeshRenderer* meshRenderer2;
//    ShiEngine::MeshRenderer* meshRenderer3;
//    ShiEngine::MeshRenderer* meshRendererSuzane;
//    ShiEngine::MeshRenderer* meshRendererPlane2;//side walls
//    ShiEngine::MeshRenderer* meshRendererPlane3;//side walls
//    ShiEngine::MeshRenderer* meshRendererPlane4;//first end walls
//    ShiEngine::MeshRenderer* meshRendererPlane5;//last end walls
//    ShiEngine::MeshRenderer* meshRendererPlane6;//elsa2f end walls
//    ShiEngine::MeshRenderer* meshRendererPlane;
//    ShiEngine::MeshRenderer* meshRendererSuzanne2;
//    ShiEngine::MeshRenderer* meshRendererSuzanne3;
//    ShiEngine::MeshRenderer* meshRendererSuzanne4;
//    ShiEngine::MeshRenderer* meshRendererSuzanne5;
//    ShiEngine::MeshRenderer* meshRendererSuzanne6;
//    ShiEngine::MeshRenderer* MRBox1;
//    ShiEngine::MeshRenderer* MRBox2;
//    ShiEngine::MeshRenderer* MRBox3;
//    ShiEngine::MeshRenderer* MRBox4;
//    ShiEngine::MeshRenderer* MRBox5;
//    ShiEngine::MeshRenderer* MRBox6;
//    ShiEngine::MeshRenderer* MRBox7;
//    ShiEngine::MeshRenderer* MRBox8;
//    ShiEngine::MeshRenderer* MRBox9;
//    ShiEngine::MeshRenderer* MRBox10;
//
//    auto* obj1 = new ShiEngine::GameObject();
//    auto* obj2 = new ShiEngine::GameObject();
//    auto* cubeGameObj = new ShiEngine::GameObject();
//    auto* directionalLightGameObject = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
//    auto* objCamera = new ShiEngine::GameObject(ShiEngine::Tags::CAMERA);
//    auto* pointLightGameObject = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
//    auto* planeGameObject = new ShiEngine::GameObject;
//    auto* spotLightGameObject = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
//    auto* pointLightGameObject2 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
//    auto* planeGameObject2 = new ShiEngine::GameObject;
//    auto* planeGameObject3 = new ShiEngine::GameObject;
//    auto* planeGameObject4 = new ShiEngine::GameObject;
//    auto* planeGameObject5 = new ShiEngine::GameObject;
//    auto* planeGameObject6 = new ShiEngine::GameObject;
//    auto* pointLightGameObjectS1 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
//    auto* pointLightGameObjectS2 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
//    auto* pointLightGameObjectS3 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
//    auto* pointLightGameObjectS4 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
//    auto* pointLightGameObjectS5 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
//    auto* pointLightGameObjectS6 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
//    auto* pointLightGameObjectS7 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
//    auto* pointLightGameObjectS8 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
//    auto* pointLightGameObjectS9 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
//    auto* pointLightGameObjectS10 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
//    auto* pointLightGameObject5 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
//    auto* pointLightGameObject6 = new ShiEngine::GameObject(ShiEngine::Tags::LIGHT);
//    auto* objSuzane = new ShiEngine::GameObject();
//    auto* objSuzane2 = new ShiEngine::GameObject();
//    auto* objSuzane3 = new ShiEngine::GameObject();
//    auto* objSuzane4 = new ShiEngine::GameObject();
//    auto* objSuzane5 = new ShiEngine::GameObject();
//    auto* objSuzane6 = new ShiEngine::GameObject();
//    auto* camController = new ShiEngine::GameObject();
//    auto* Box1 = new ShiEngine::GameObject();
//    auto* Box2 = new ShiEngine::GameObject();
//    auto* Box3 = new ShiEngine::GameObject();
//    auto* Box4 = new ShiEngine::GameObject();
//    auto* Box5 = new ShiEngine::GameObject();
//    auto* Box6 = new ShiEngine::GameObject();
//    auto* Box7 = new ShiEngine::GameObject();
//    auto* Box8 = new ShiEngine::GameObject();
//    auto* Box9 = new ShiEngine::GameObject();
//    auto* Box10 = new ShiEngine::GameObject();
//
//    RenderState* renderState1;
//
//    ShiEngine::Transform* transform1;
//    ShiEngine::Transform* transform2;
//    ShiEngine::Transform* transformCamera;
//    ShiEngine::Transform* transformCube;
//
//    ShiEngine::Transform* TBox1;
//    ShiEngine::Transform* TBox2;
//    ShiEngine::Transform* TBox3;
//    ShiEngine::Transform* TBox4;
//    ShiEngine::Transform* TBox5;
//    ShiEngine::Transform* TBox6;
//    ShiEngine::Transform* TBox7;
//    ShiEngine::Transform* TBox8;
//    ShiEngine::Transform* TBox9;
//    ShiEngine::Transform* TBox10;
//
//    ShiEngine::BoxCollider* BCBox1;
//    ShiEngine::BoxCollider* BCBox2;
//    ShiEngine::BoxCollider* BCBox3;
//    ShiEngine::BoxCollider* BCBox4;
//    ShiEngine::BoxCollider* BCBox5;
//    ShiEngine::BoxCollider* BCBox6;
//    ShiEngine::BoxCollider* BCBox7;
//    ShiEngine::BoxCollider* BCBox8;
//    ShiEngine::BoxCollider* BCBox9;
//    ShiEngine::BoxCollider* BCBox10;
//
//    ShiEngine::BoxCollider* boxColliderPlayer;
//    ShiEngine::BoxCollider* boxColliderWallBehind;
//    ShiEngine::BoxCollider* boxColliderWallFront;
//    ShiEngine::BoxCollider* boxColliderWallRight;
//    ShiEngine::BoxCollider* boxColliderWallLeft;
//
//    ShiEngine::BoxCollider* pointLightBoxCollider1;
//    ShiEngine::BoxCollider* pointLightBoxCollider2;
//    ShiEngine::BoxCollider* pointLightBoxCollider3;
//    ShiEngine::BoxCollider* pointLightBoxCollider4;
//    ShiEngine::BoxCollider* pointLightBoxCollider5;
//    ShiEngine::BoxCollider* pointLightBoxCollider6;
//    ShiEngine::BoxCollider* BCWF;
//
//    ShiEngine::Transform* transformPlane;
//    ShiEngine::Transform* transformCubeObj;
//
//    ShiEngine::Transform* transformPlane2;
//    ShiEngine::Transform* transformPlane3;
//    ShiEngine::Transform* transformPlane4;
//    ShiEngine::Transform* transformPlane5;
//    ShiEngine::Transform* transformPlane6;
//    ShiEngine::Transform* transformSuzane;
//    ShiEngine::Transform* transformSuzane2;
//    ShiEngine::Transform* transformSuzane3;
//    ShiEngine::Transform* transformSuzane4;
//    ShiEngine::Transform* transformSuzane5;
//    ShiEngine::Transform* transformSuzane6;
//
//    ShiEngine::Transform* transformPointLightS1;
//    ShiEngine::Transform* transformPointLightS2;
//    ShiEngine::Transform* transformPointLightS3;
//    ShiEngine::Transform* transformPointLightS4;
//    ShiEngine::Transform* transformPointLightS5;
//    ShiEngine::Transform* transformPointLightS6;
//    ShiEngine::Transform* transformPointLightS7;
//    ShiEngine::Transform* transformPointLightS8;
//    ShiEngine::Transform* transformPointLightS9;
//    ShiEngine::Transform* transformPointLightS10;
//    ShiEngine::Transform* transformPointLight5;
//    ShiEngine::Transform* transformPointLight6;
//    ShiEngine::Transform* transformDirectionalLight;
//
//    ShiEngine::Camera* camera;
//    ShiEngine::Light* pointLightS1;
//    ShiEngine::Light* pointLightS2;
//    ShiEngine::Light* pointLightS3;
//    ShiEngine::Light* pointLightS4;
//    ShiEngine::Light* pointLightS5;
//    ShiEngine::Light* pointLightS6;
//    ShiEngine::Light* pointLightS7;
//    ShiEngine::Light* pointLightS8;
//    ShiEngine::Light* pointLightS9;
//    ShiEngine::Light* pointLightS10;
//    ShiEngine::Light* pointLight5;
//    ShiEngine::Light* pointLight6;
//
//    ShiEngine::Material* material1;
//    ShiEngine::Material* materialPlane;
//    ShiEngine::Material* materialCube;
//    ShiEngine::Material* materialSuzane;
//    ShiEngine::Material* materialPlane2;
//    ShiEngine::Material* materialPlane3;
//    ShiEngine::Material* materialPlane4;
//    ShiEngine::Material* materialPlane5;
//    ShiEngine::Material* materialPlane6;
//    ShiEngine::Material* MATBox;
//
//    ShiEngine::Mesh* meshCube;
//    ShiEngine::Mesh* meshPlane;
//    ShiEngine::Mesh* meshSphere;
//    ShiEngine::Mesh* meshPlane2;
//    ShiEngine::Mesh* meshPlane3;
//    ShiEngine::Mesh* meshPlane4;
//    ShiEngine::Mesh* meshPlane5;
//    ShiEngine::Mesh* meshPlane6;
//    ShiEngine::Mesh* meshSuzane;
//
//    ShiEngine::Texture2D* texture1; //texture Earth
//    ShiEngine::Texture2D* TextureM;
//    ShiEngine::Sampler* sampler1;
//
//    ShiEngine::Texture2D* texture2;
//    ShiEngine::Texture2D* textureEarth;
//
//    ShiEngine::EnemyMovement* moveEnemy1;
//    ShiEngine::EnemyMovement* moveEnemy2;
//    ShiEngine::EnemyMovement* moveEnemy3;
//    ShiEngine::EnemyMovement* moveEnemy4;
//    ShiEngine::EnemyMovement* moveEnemy5;
//    ShiEngine::EnemyMovement* moveEnemy6;
//    ShiEngine::EnemyMovement* moveEnemy7;
//    ShiEngine::EnemyMovement* moveEnemy8;
//    ShiEngine::EnemyMovement* moveEnemy9;
//    ShiEngine::EnemyMovement* moveEnemy10;
//    ShiEngine::EnemyMovement* moveEnemy11;
//    ShiEngine::EnemyMovement* moveEnemy12;
//
//    auto *controller = new ShiEngine::FlyCameraController;
//
//    program->create("../assets/Shaders/Phase3/light_transform.vert", GL_VERTEX_SHADER,
//                    "../assets/Shaders/Phase3/light_array2.frag", GL_FRAGMENT_SHADER);
//
//    // Resources
//    meshCube = new ShiEngine::Mesh();
//    meshCube->Cuboid(false);
//
//    meshSphere = new ShiEngine::Mesh();
//    meshSphere->Sphere(false);
//    ///
//
//    meshPlane = new ShiEngine::Mesh();
//    meshPlane->Plane(false);
//
//
//    meshSphere = new ShiEngine::Mesh();
//    // meshSphere->Model("../assets/models/Ghost/ghost.obj");
//
//    meshSuzane = new ShiEngine::Mesh();
//    meshSuzane->Model( "../assets/models/Suzanne/Suzanne.obj");
//
//    //Transforms
//    TBox1 = new ShiEngine::Transform();
//    TBox1->position = glm::vec3({-150, 20, -54});
//    TBox1->scale = glm::vec3({1,40,14});
//    TBox1->rotation = glm::vec3({0,180,0});
//
//    TBox2 = new ShiEngine::Transform();
//    TBox2->position = glm::vec3({-150, 20, 54});
//    TBox2->scale = glm::vec3({1,40,14});
//    TBox2->rotation = glm::vec3({0,0,0});
//
//    TBox3 = new ShiEngine::Transform();
//    TBox3->position = glm::vec3({-103, 20, 0});
//    TBox3->scale = glm::vec3({1,40,14});
//    TBox3->rotation = glm::vec3({0,0,0});
//
//    TBox4 = new ShiEngine::Transform();
//    TBox4->position = glm::vec3({-72, 20, -54});
//    TBox4->scale = glm::vec3({1,40,14});
//    TBox4->rotation = glm::vec3({0,0,0});
//
//    TBox5 = new ShiEngine::Transform();
//    TBox5->position = glm::vec3({-72, 20, 54});
//    TBox5->scale = glm::vec3({1,40,14});
//    TBox5->rotation = glm::vec3({0,0,0});
//
//    TBox6 = new ShiEngine::Transform();
//    TBox6->position = glm::vec3({-200, 10, 0});
//    TBox6->scale = glm::vec3({1,1,1});
//    TBox6->rotation = glm::vec3({0,0,0});
//
//    TBox7 = new ShiEngine::Transform();
//    TBox7->position = glm::vec3({-200, 10, 0});
//    TBox7->scale = glm::vec3({1,1,1});
//    TBox7->rotation = glm::vec3({0,0,0});
//
//    TBox8 = new ShiEngine::Transform();
//    TBox8->position = glm::vec3({-200, 10, 0});
//    TBox8->scale = glm::vec3({1,1,1});
//    TBox8->rotation = glm::vec3({0,0,0});
//
//    TBox9 = new ShiEngine::Transform();
//    TBox9->position = glm::vec3({-200, 10, 0});
//    TBox9->scale = glm::vec3({1,1,1});
//    TBox9->rotation = glm::vec3({0,0,0});
//
//    TBox10 = new ShiEngine::Transform();
//    TBox10->position = glm::vec3({-200, 10, 0});
//    TBox10->scale = glm::vec3({1,1,1});
//    TBox10->rotation = glm::vec3({0,0,0});
//
//    transformCamera = new ShiEngine::Transform();
//    transformCamera->position = glm::vec3({-210, 10, 0});
//    transformCamera->scale = glm::vec3({10,25,4});
//    transformCamera->rotation = glm::vec3({0,0,0});
//
//    transformCube = new ShiEngine::Transform();
//    transformCube->position = glm::vec3({-208, 0, 6});
//    transformCube->scale = glm::vec3({0.1,0.1,0.1});
//    transformCube->rotation = glm::vec3({5,0,0});
//
//    // Wall left
//    transformPlane2 = new ShiEngine::Transform();
//    transformPlane2->position = glm::vec3({0, 1, -65});
//    transformPlane2->scale = glm::vec3({-500,100,4});
//    transformPlane2->rotation = glm::vec3({0,0,0});
//
//    // Wall right
//    transformPlane3 = new ShiEngine::Transform();
//    transformPlane3->position = glm::vec3({0, 1, 65});
//    transformPlane3->scale = glm::vec3({-500,100,4});
//    transformPlane3->rotation = glm::vec3({0,0,0});
//
//    // Wall behind
//    transformPlane4 = new ShiEngine::Transform();
//    transformPlane4->position = glm::vec3({-225, 1, 0});
//    transformPlane4->scale = glm::vec3({4,30,200});
//    transformPlane4->rotation = glm::vec3({0,0,0});
//
//    // Wall front
//    transformPlane5 = new ShiEngine::Transform();
//    transformPlane5->position = glm::vec3({-18, 1, 0});
//    transformPlane5->scale = glm::vec3({2,100,400});
//    transformPlane5->rotation = glm::vec3({0,0,0});
//
//    // Wall up
//    transformPlane6 = new ShiEngine::Transform();
//    transformPlane6->position = glm::vec3({0, 40, 0});
//    transformPlane6->scale = glm::vec3({-500,1,100});
//    transformPlane6->rotation = glm::vec3({0,0,0});
//
//    // Wall down
//    transformPlane = new ShiEngine::Transform();
//    transformPlane->position = glm::vec3({0, -1, 0});
//    transformPlane->scale = glm::vec3({-700,1,700});
//    transformPlane->rotation = glm::vec3({0,0,0});
//
//    //Loading Objects
//    transformSuzane = new ShiEngine::Transform();
//    //transformSuzane->position = glm::vec3({-30, 5, 0});//kairi
//    transformSuzane->position = glm::vec3({3.5, -1, 2}); // note: position relative to parent (PointLight2)
//    transformSuzane->scale = glm::vec3({4,4,4});
//    transformSuzane->rotation = glm::vec3({0,-90,0});
//
//    transformSuzane2 = new ShiEngine::Transform();
//    transformSuzane2->position = glm::vec3({3.5, -1, 2});//kairi
//    transformSuzane2->scale = glm::vec3({4,4,4});
//    transformSuzane2->rotation = glm::vec3({0,-90,0});
//
//    transformSuzane3 = new ShiEngine::Transform();
//    transformSuzane3->position = glm::vec3({3.5, -1, 2});//kairi
//    transformSuzane3->scale = glm::vec3({4,4,4});
//    transformSuzane3->rotation = glm::vec3({0,-90,0});
//
//    transformSuzane4 = new ShiEngine::Transform();
//    transformSuzane4->position = glm::vec3({3.5, -1, 2});//kairi
//    transformSuzane4->scale = glm::vec3({4,4,4});
//    transformSuzane4->rotation = glm::vec3({0,-90,0});
//
//    transformSuzane5 = new ShiEngine::Transform();
//    transformSuzane5->position = glm::vec3({3.5, -1, 2});//kairi
//    transformSuzane5->scale = glm::vec3({4,4,4});
//    transformSuzane5->rotation = glm::vec3({0,-90,0});
//
//    transformSuzane6 = new ShiEngine::Transform();
//    transformSuzane6->position = glm::vec3({3.5, -1, 2});//kairi
//    transformSuzane6->scale = glm::vec3({4,4,4});
//    transformSuzane6->rotation = glm::vec3({0,-90,0});
//
//    transform1 = new ShiEngine::Transform();
//    transform1->position = glm::vec3({0, 0, 0});
//    transform1->scale = glm::vec3({1,1,1});
//    transform1->rotation = glm::vec3({0,0,0});
//
//    transform2 = new ShiEngine::Transform();
//    transform2->position = glm::vec3({2, 5, 0});
//    transform2->scale = glm::vec3({2,2,2});
//    transform2->rotation = glm::vec3({0,0,0});
//
//    BCBox1 = new ShiEngine::BoxCollider();
//    BCBox2 = new ShiEngine::BoxCollider();
//    BCBox3 = new ShiEngine::BoxCollider();
//    BCBox4 = new ShiEngine::BoxCollider();
//    BCBox5 = new ShiEngine::BoxCollider();
//    BCBox6 = new ShiEngine::BoxCollider();
//    BCBox7 = new ShiEngine::BoxCollider();
//    BCBox8 = new ShiEngine::BoxCollider();
//    BCBox9 = new ShiEngine::BoxCollider();
//    BCBox10 = new ShiEngine::BoxCollider();
//    BCWF = new ShiEngine::BoxCollider();
//
//    boxColliderPlayer = new ShiEngine::BoxCollider();
//    boxColliderWallBehind = new ShiEngine::BoxCollider();
//    boxColliderWallFront = new ShiEngine::BoxCollider();
//    boxColliderWallFront->IsTrigger = true;
//    boxColliderWallLeft = new ShiEngine::BoxCollider();
//    boxColliderWallRight = new ShiEngine::BoxCollider();
//
//    pointLightBoxCollider1 = new ShiEngine::BoxCollider();
//    pointLightBoxCollider2 = new ShiEngine::BoxCollider();
//    pointLightBoxCollider3 = new ShiEngine::BoxCollider();
//    pointLightBoxCollider4 = new ShiEngine::BoxCollider();
//    pointLightBoxCollider5 = new ShiEngine::BoxCollider();
//    pointLightBoxCollider6 = new ShiEngine::BoxCollider();
//
//    // Door
//    transformCubeObj = new ShiEngine::Transform();
//    transformCubeObj->position = glm::vec3({-20, 12, 0});
//    transformCubeObj->scale = glm::vec3({2,30,18});
//    transformCubeObj->rotation = glm::vec3({0,0,0});
//
//
//    transformCube = new ShiEngine::Transform();
//    transformCube->position = glm::vec3({0, 0, 0});
//    transformCube->scale = glm::vec3({2,2,2});
//    transformCube->rotation = glm::vec3({0,0,0});
//
//    // Point Light Transfor Spot Light Transform
//    transformPointLightS1 = new ShiEngine::Transform();
//    transformPointLightS1->position = glm::vec3({-30, 5, 0});
//    transformPointLightS1->scale = glm::vec3({1,1,1});
//    transformPointLightS1->rotation = glm::vec3({0,0,0});
//    transformPointLightS1->direction = glm::vec3({-1, -1, -1});
//
//    transformPointLightS2 = new ShiEngine::Transform();
//    transformPointLightS2->position = glm::vec3({-30, 5, 4});
//    transformPointLightS2->scale = glm::vec3({1,1,1});
//    transformPointLightS2->rotation = glm::vec3({0,0,0});
//    transformPointLightS2->direction = glm::vec3({0, -2, 0});// Point Light Transform
//
//    transformPointLightS3 = new ShiEngine::Transform();
//    transformPointLightS3->position = glm::vec3({-50, 5, -20});
//    transformPointLightS3->scale = glm::vec3({1,1,1});
//    transformPointLightS3->rotation = glm::vec3({0,0,0});
//    transformPointLightS3->direction = glm::vec3({-1, -1, -1});
//
//    transformPointLightS4 = new ShiEngine::Transform();
//    transformPointLightS4->position = glm::vec3({-50, 5, -16});
//    transformPointLightS4->scale = glm::vec3({1,1,1});
//    transformPointLightS4->rotation = glm::vec3({0,0,0});
//    transformPointLightS4->direction = glm::vec3({0, -2, 0});// Point Light Transform
//
//    transformPointLightS5 = new ShiEngine::Transform();
//    transformPointLightS5->position = glm::vec3({-70, 5, 30});
//    transformPointLightS5->scale = glm::vec3({1,1,1});
//    transformPointLightS5->rotation = glm::vec3({0,0,0});
//    transformPointLightS5->direction = glm::vec3({-1, -1, -1});
//
//    transformPointLightS6 = new ShiEngine::Transform();
//    transformPointLightS6->position = glm::vec3({-70, 5, 34});
//    transformPointLightS6->scale = glm::vec3({1,1,1});
//    transformPointLightS6->rotation = glm::vec3({0,0,0});
//    transformPointLightS6->direction = glm::vec3({0, -2, 0});// Point Light Transform
//
//    transformPointLightS7 = new ShiEngine::Transform();
//    transformPointLightS7->position = glm::vec3({-90, 5, 10});
//    transformPointLightS7->scale = glm::vec3({1,1,1});
//    transformPointLightS7->rotation = glm::vec3({0,0,0});
//    transformPointLightS7->direction = glm::vec3({-1, -1, -1});
//
//    transformPointLightS8 = new ShiEngine::Transform();
//    transformPointLightS8->position = glm::vec3({-90, 5, 14});
//    transformPointLightS8->scale = glm::vec3({1,1,1});
//    transformPointLightS8->rotation = glm::vec3({0,0,0});
//    transformPointLightS8->direction = glm::vec3({0, -2, 0});// Point Light Transform
//
//    transformPointLightS9 = new ShiEngine::Transform();
//    transformPointLightS9->position = glm::vec3({-120, 5, -20});
//    transformPointLightS9->scale = glm::vec3({1,1,1});
//    transformPointLightS9->rotation = glm::vec3({0,0,0});
//    transformPointLightS9->direction = glm::vec3({-1, -1, -1});
//
//    transformPointLightS10 = new ShiEngine::Transform();
//    transformPointLightS10->position = glm::vec3({-120, 5, -16});
//    transformPointLightS10->scale = glm::vec3({1,1,1});
//    transformPointLightS10->rotation = glm::vec3({0,0,0});
//    transformPointLightS10->direction = glm::vec3({0, -2, 0});// Point Light Transform
//
//    transformPointLight5 = new ShiEngine::Transform();
//    transformPointLight5->position = glm::vec3({-154, 6, -2});
//    transformPointLight5->scale = glm::vec3({1,1,1});
//    transformPointLight5->rotation = glm::vec3({0,0,0});
//    transformPointLight5->direction = glm::vec3({-1, -1, -1});
//
//    transformPointLight6 = new ShiEngine::Transform();
//    transformPointLight6->position = glm::vec3({-154, 6, 2});
//    transformPointLight6->scale = glm::vec3({1,1,1});
//    transformPointLight6->rotation = glm::vec3({0,0,0});
//    transformPointLight6->direction = glm::vec3({0, -2, 0});// Point Light Transform
//
//    transformDirectionalLight = new ShiEngine::Transform();
//    transformDirectionalLight->position = glm::vec3({0, 160, 2});
//    transformDirectionalLight->scale = glm::vec3({1,1,1});
//    transformDirectionalLight->rotation = glm::vec3({0,0,0});
//    transformDirectionalLight->direction = glm::vec3({-1, -1, -1});// Point Light Transform
//
//    moveEnemy1 = new ShiEngine::EnemyMovement(0.0f);
//    moveEnemy1->setOscillateY(2.0, 0.1);
//    moveEnemy1->setOscillateZ(20.0, 0.4);
//
//    moveEnemy2 = new ShiEngine::EnemyMovement(0.0f);
//    moveEnemy2->setOscillateY(2.0, 0.1);
//    moveEnemy2->setOscillateZ(20.0, 0.4);
//
//    moveEnemy3 = new ShiEngine::EnemyMovement(1);
//    moveEnemy3->setOscillateY(2.0, 0.1);
//    moveEnemy3->setOscillateZ(20.0, 0.4);
//
//    moveEnemy4 = new ShiEngine::EnemyMovement(1);
//    moveEnemy4->setOscillateY(2.0, 0.1);
//    moveEnemy4->setOscillateZ(20.0, 0.4);
//
//    moveEnemy5 = new ShiEngine::EnemyMovement(2);
//    moveEnemy5->setOscillateY(2.0, 0.1);
//    moveEnemy5->setOscillateZ(20.0, 0.4);
//
//    moveEnemy6 = new ShiEngine::EnemyMovement(2);
//    moveEnemy6->setOscillateY(2.0, 0.1);
//    moveEnemy6->setOscillateZ(20.0, 0.4);
//
//    moveEnemy7 = new ShiEngine::EnemyMovement(3);
//    moveEnemy7->setOscillateY(2.0, 0.1);
//    moveEnemy7->setOscillateZ(20.0, 0.4);
//
//    moveEnemy8 = new ShiEngine::EnemyMovement(3);
//    moveEnemy8->setOscillateY(2.0, 0.1);
//    moveEnemy8->setOscillateZ(20.0, 0.4);
//
//    moveEnemy9 = new ShiEngine::EnemyMovement(4);
//    moveEnemy9->setOscillateY(2.0, 0.1);
//    moveEnemy9->setOscillateZ(20.0, 0.4);
//
//    moveEnemy10 = new ShiEngine::EnemyMovement(4);
//    moveEnemy10->setOscillateY(2.0, 0.1);
//    moveEnemy10->setOscillateZ(20.0, 0.4);
//
//    moveEnemy11 = new ShiEngine::EnemyMovement(5);
//    moveEnemy11->setOscillateY(2.0, 0.1);
//    moveEnemy11->setOscillateZ(20.0, 0.4);
//
//    moveEnemy12 = new ShiEngine::EnemyMovement(5);
//    moveEnemy12->setOscillateY(2.0, 0.1);
//    moveEnemy12->setOscillateZ(20.0, 0.4);
//
//    camera = new ShiEngine::Camera();
//    camera->setupPerspective(glm::pi<float>()/2, 1.7f, 0.1f, 1000.0f);
//    //camera->setupOrthographic(2.f, 1.7, 0.1f, 100.0f);
//
//    pointLightS1 = new ShiEngine::Light(ShiEngine::LightType::POINT);
//    pointLightS1->setAttenuation(0,0,0.1);
//    pointLightS1->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({0.1,0.1,0.1}), glm::vec3({0.1,0.1,0.1}));
//
//    pointLightS2 = new ShiEngine::Light(ShiEngine::LightType::POINT);
//    pointLightS2->setAttenuation(0,0,0.1);
//    pointLightS2->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({1,1,1}), glm::vec3({0.1,0.1,0.1}));
//
//    pointLightS3 = new ShiEngine::Light(ShiEngine::LightType::POINT);
//    pointLightS3->setAttenuation(0,0,0.1);
//    pointLightS3->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({0.1,0.1,0.1}), glm::vec3({0.1,0.1,0.1}));
//
//    pointLightS4 = new ShiEngine::Light(ShiEngine::LightType::POINT);
//    pointLightS4->setAttenuation(0,0,0.1);
//    pointLightS4->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({1,1,1}), glm::vec3({0.1,0.1,0.1}));
//
//    pointLightS5 = new ShiEngine::Light(ShiEngine::LightType::POINT);
//    pointLightS5->setAttenuation(0,0,0.1);
//    pointLightS5->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({0.1,0.1,0.1}), glm::vec3({0.1,0.1,0.1}));
//
//    pointLightS6 = new ShiEngine::Light(ShiEngine::LightType::POINT);
//    pointLightS6->setAttenuation(0,0,0.1);
//    pointLightS6->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({1,1,1}), glm::vec3({0.1,0.1,0.1}));
//
//    pointLightS7 = new ShiEngine::Light(ShiEngine::LightType::POINT);
//    pointLightS7->setAttenuation(0,0,0.1);
//    pointLightS7->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({0.1,0.1,0.1}), glm::vec3({0.1,0.1,0.1}));
//
//    pointLightS8 = new ShiEngine::Light(ShiEngine::LightType::POINT);
//    pointLightS8->setAttenuation(0,0,0.1);
//    pointLightS8->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({1,1,1}), glm::vec3({0.1,0.1,0.1}));
//
//    pointLightS9 = new ShiEngine::Light(ShiEngine::LightType::POINT);
//    pointLightS9->setAttenuation(0,0,0.1);
//    pointLightS9->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({0.1,0.1,0.1}), glm::vec3({0.1,0.1,0.1}));
//
//    pointLightS10 = new ShiEngine::Light(ShiEngine::LightType::POINT);
//    pointLightS10->setAttenuation(0,0,0.1);
//    pointLightS10->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({1,1,1}), glm::vec3({0.1,0.1,0.1}));
//
//    pointLight5 = new ShiEngine::Light(ShiEngine::LightType::POINT);
//    pointLight5->setAttenuation(0,0,0.1);
//    pointLight5->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({0.1,0.1,0.1}), glm::vec3({0.1,0.1,0.1}));
//
//    pointLight6 = new ShiEngine::Light(ShiEngine::LightType::POINT);
//    pointLight6->setAttenuation(0,0,0.1);
//    pointLight6->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({1,1,1}), glm::vec3({0.1,0.1,0.1}));
//
//    renderState1 = new RenderState(true,true,false);
//
//    MRBox1 = new ShiEngine::MeshRenderer(program, meshCube);
//    MRBox1->SetRenderState(renderState1);
//
//    MRBox2 = new ShiEngine::MeshRenderer(program, meshCube);
//    MRBox2->SetRenderState(renderState1);
//
//    MRBox3 = new ShiEngine::MeshRenderer(program, meshCube);
//    MRBox3->SetRenderState(renderState1);
//
//    MRBox4 = new ShiEngine::MeshRenderer(program, meshCube);
//    MRBox4->SetRenderState(renderState1);
//
//    MRBox5 = new ShiEngine::MeshRenderer(program, meshCube);
//    MRBox5->SetRenderState(renderState1);
//
//    MRBox6 = new ShiEngine::MeshRenderer(program, meshCube);
//    MRBox6->SetRenderState(renderState1);
//
//    MRBox7 = new ShiEngine::MeshRenderer(program, meshCube);
//    MRBox7->SetRenderState(renderState1);
//
//    MRBox8 = new ShiEngine::MeshRenderer(program, meshCube);
//    MRBox8->SetRenderState(renderState1);
//
//    MRBox9 = new ShiEngine::MeshRenderer(program, meshCube);
//    MRBox9->SetRenderState(renderState1);
//
//    MRBox10 = new ShiEngine::MeshRenderer(program, meshCube);
//    MRBox10->SetRenderState(renderState1);
//
//    meshRenderer1 = new ShiEngine::MeshRenderer(program, meshSphere);
//    meshRenderer1->SetRenderState(renderState1);
//
//    meshRenderer2 = new ShiEngine::MeshRenderer(program, meshCube);
//    meshRenderer2->SetRenderState(renderState1);
//
//    meshRenderer3 = new ShiEngine::MeshRenderer(program, meshCube);
//    meshRenderer3->SetRenderState(renderState1);
//
//    meshRendererPlane = new ShiEngine::MeshRenderer(program, meshPlane);
//    meshRendererPlane->SetRenderState(renderState1);
//
//    meshRendererPlane2 = new ShiEngine::MeshRenderer(program, meshCube);
//    meshRendererPlane2->SetRenderState(renderState1);
//
//    meshRendererPlane3 = new ShiEngine::MeshRenderer(program, meshCube);
//    meshRendererPlane3->SetRenderState(renderState1);
//
//    meshRendererPlane4 = new ShiEngine::MeshRenderer(program, meshCube);
//    meshRendererPlane4->SetRenderState(renderState1);
//
//    meshRendererPlane5 = new ShiEngine::MeshRenderer(program, meshCube);
//    meshRendererPlane5->SetRenderState(renderState1);
//
//    meshRendererPlane6 = new ShiEngine::MeshRenderer(program, meshPlane);
//    meshRendererPlane6->SetRenderState(renderState1);
//
//    meshRendererSuzane = new ShiEngine::MeshRenderer(program, meshSuzane);
//    meshRendererSuzane->SetRenderState(renderState1);
//
//    meshRendererSuzanne2 = new ShiEngine::MeshRenderer(program, meshSuzane);
//    meshRendererSuzanne2->SetRenderState(renderState1);
//
//    meshRendererSuzanne3 = new ShiEngine::MeshRenderer(program, meshSuzane);
//    meshRendererSuzanne3->SetRenderState(renderState1);
//
//    meshRendererSuzanne4 = new ShiEngine::MeshRenderer(program, meshSuzane);
//    meshRendererSuzanne4->SetRenderState(renderState1);
//
//    meshRendererSuzanne5 = new ShiEngine::MeshRenderer(program, meshSuzane);
//    meshRendererSuzanne5->SetRenderState(renderState1);
//
//    meshRendererSuzanne6 = new ShiEngine::MeshRenderer(program, meshSuzane);
//    meshRendererSuzanne6->SetRenderState(renderState1);
//
//    texture1 = new ShiEngine::Texture2D("../assets/Textures/woodtexture.jpg", true);
//    sampler1 = new ShiEngine::Sampler();
//
//    TextureM = new ShiEngine::Texture2D("../assets/Textures/bloodtexture.jpg", true);
//
//    texture2 = new ShiEngine::Texture2D("../assets/Textures/doorTexture.jpg", true);
//    textureEarth = new ShiEngine::Texture2D("../assets/Textures/2k_earth_daymap.jpg", true);
//
//    material1 = new ShiEngine::Material();
//    material1->shaderProgram = program;
//    material1->albedo_tint = {1, 1, 1}; // The reflectance color
//    material1->specular_tint = {1, 1, 1};
//    material1->roughness_range = {0,1};
//    material1->emissive_tint = {0.6,0.6,0.6};
//    material1->setTexture(TextureM);
//    material1->setSampler(sampler1);
//    meshRenderer1->SetMaterial(material1);
//
//    materialCube = new ShiEngine::Material();
//    materialCube->shaderProgram = program;
//    materialCube->albedo_tint = {1, 1, 1}; // The reflectance color
//    materialCube->specular_tint = {1, 1, 1};
//    materialCube->roughness_range = {0,1};
//    materialCube->emissive_tint = {1,1,1};
//    materialCube->setTexture(texture2);
//    materialCube->setSampler(sampler1);
//
//    MATBox = new ShiEngine::Material();
//    MATBox->shaderProgram = program;
//    MATBox->albedo_tint = {1, 1, 1}; // The reflectance color
//    MATBox->specular_tint = {1, 1, 1};
//    MATBox->roughness_range = {0,1};
//    MATBox->emissive_tint = {1,1,1};
//    MATBox->setTexture(texture1);
//    MATBox->setSampler(sampler1);
//
//    materialPlane = new ShiEngine::Material();
//    materialPlane->albedo_tint = { 0.1019, 0.93, 0.301}; // The reflectance color
//    materialPlane->specular_tint = {1, 1, 1};
//    materialPlane->roughness_range = {0,1};
//    materialPlane->emissive_tint = {0.6,0.6,0.6};
//    materialPlane->setTexture(texture1);
//    materialPlane->setSampler(sampler1);
//    materialPlane->shaderProgram = program;
//
//    meshRendererPlane->SetMaterial(materialPlane);
//    meshRenderer2->SetMaterial(materialCube); //cube will have same material as sphere
//    meshRenderer3->SetMaterial(materialCube);
//
//    MRBox1->SetMaterial(MATBox);
//    MRBox2->SetMaterial(MATBox);
//    MRBox3->SetMaterial(MATBox);
//    MRBox4->SetMaterial(MATBox);
//    MRBox5->SetMaterial(MATBox);
//    MRBox6->SetMaterial(MATBox);
//    MRBox7->SetMaterial(MATBox);
//    MRBox8->SetMaterial(MATBox);
//    MRBox9->SetMaterial(MATBox);
//    MRBox10->SetMaterial(MATBox);
//
//    ///
//    meshRendererPlane2->SetMaterial(materialPlane);
//    meshRendererPlane3->SetMaterial(materialPlane);
//    meshRendererPlane4->SetMaterial(materialPlane);
//    meshRendererPlane5->SetMaterial(materialPlane);
//    meshRendererPlane6->SetMaterial(materialPlane);
//    meshRendererSuzane->SetMaterial(material1);
//    meshRendererSuzanne2->SetMaterial(material1);
//    meshRendererSuzanne3->SetMaterial(material1);
//    meshRendererSuzanne4->SetMaterial(material1);
//    meshRendererSuzanne5->SetMaterial(material1);
//    meshRendererSuzanne6->SetMaterial(material1);
//
//    Box1->AddComponent(TBox1);
//    Box2->AddComponent(TBox2);
//    Box3->AddComponent(TBox3);
//    Box4->AddComponent(TBox4);
//    Box5->AddComponent(TBox5);
//    Box6->AddComponent(TBox6);
//    Box7->AddComponent(TBox7);
//    Box8->AddComponent(TBox8);
//    Box9->AddComponent(TBox9);
//    Box10->AddComponent(TBox10);
//
//    Box1->AddComponent(MRBox1);
//    Box2->AddComponent(MRBox2);
//    Box3->AddComponent(MRBox3);
//    Box4->AddComponent(MRBox4);
//    Box5->AddComponent(MRBox5);
//    Box6->AddComponent(MRBox6);
//    Box7->AddComponent(MRBox7);
//    Box8->AddComponent(MRBox8);
//    Box9->AddComponent(MRBox9);
//    Box10->AddComponent(MRBox10);
//
//    Box1->AddComponent(BCBox1);
//    Box2->AddComponent(BCBox2);
//    Box3->AddComponent(BCBox3);
//    Box4->AddComponent(BCBox4);
//    Box5->AddComponent(BCBox5);
//    Box6->AddComponent(BCBox6);
//    Box7->AddComponent(BCBox7);
//    Box8->AddComponent(BCBox8);
//    Box9->AddComponent(BCBox9);
//    Box10->AddComponent(BCBox10);
//
//    objCamera->AddComponent(transformCamera);
//    objCamera->AddComponent(camera);
//    objCamera->AddComponent(boxColliderPlayer);
//    objCamera->Name = "objCamera";
//
////    obj1->AddComponent(transform1);
////    obj1->AddComponent(meshRenderer1);
////    obj1->AddComponent(boxColliderWallRight);
//
//    obj2->AddComponent(transform2);
//    obj2->AddComponent(meshRenderer3);
//    //obj2->AddComponent(boxColliderWallLeft);
//
//    // Door
//    cubeGameObj->AddComponent(transformCubeObj);
//    cubeGameObj->AddComponent(meshRenderer2);
//    cubeGameObj->AddComponent(boxColliderWallFront);
//
//
//    cubeGameObj->Name = "Door";
//    obj2->Name = "cube 2";
//
//    // Plane
//    planeGameObject->AddComponent(transformPlane);
//    planeGameObject->AddComponent(meshRendererPlane);
//    planeGameObject->Name = "plane gameObject";
//
////////-------//////
//    objSuzane->AddComponent(transformSuzane);
//    objSuzane->AddComponent(meshRendererSuzane);
//    objSuzane->Name = "Suzane";
//
//    // Plane
//    planeGameObject6->AddComponent(transformPlane6);
//    planeGameObject6->AddComponent(meshRendererPlane6);
//    planeGameObject6->Name = "plane6 gameObject";
//
//    planeGameObject2->AddComponent(transformPlane2);
//    planeGameObject2->AddComponent(meshRendererPlane2);
//    planeGameObject2->AddComponent(boxColliderWallLeft);
//    planeGameObject2->Name = "plane2 gameObject";
//
//    planeGameObject3->AddComponent(transformPlane3);
//    planeGameObject3->AddComponent(meshRendererPlane3);
//    planeGameObject3->AddComponent(boxColliderWallRight);
//    planeGameObject3->Name = "plane3 gameObject";
//
//    planeGameObject4->AddComponent(transformPlane4);
//    planeGameObject4->AddComponent(meshRendererPlane4);
//    planeGameObject4->AddComponent(boxColliderWallBehind); // TODO: at start, the player is very close to the wall, therefore crashes
//    planeGameObject4->Name = "plane4 gameObject";
//
//    planeGameObject5->AddComponent(transformPlane5);
//    planeGameObject5->AddComponent(meshRendererPlane5);
//    planeGameObject5->AddComponent(BCWF);
//
//    planeGameObject5->Name = "plane5 gameObject";
//
//    pointLightGameObjectS1->AddComponent(transformPointLightS1);
//    pointLightBoxCollider1->IsTrigger = true;
//    pointLightGameObjectS1->AddComponent(pointLightBoxCollider1);
//    pointLightGameObjectS1->AddComponent(pointLightS1);
//
//    pointLightGameObjectS2->AddComponent(transformPointLightS2);
//    pointLightGameObjectS2->AddComponent(pointLightS2);
//
//    pointLightGameObjectS3->AddComponent(transformPointLightS3);
//    pointLightBoxCollider2->IsTrigger = true;
//    pointLightGameObjectS3->AddComponent(pointLightBoxCollider2);
//    pointLightGameObjectS3->AddComponent(pointLightS3);
//
//    pointLightGameObjectS4->AddComponent(transformPointLightS4);
//    pointLightGameObjectS4->AddComponent(pointLightS4);
//
//    pointLightGameObjectS5->AddComponent(transformPointLightS5);
//    pointLightBoxCollider3->IsTrigger = true;
//    pointLightGameObjectS5->AddComponent(pointLightBoxCollider3);
//    pointLightGameObjectS5->AddComponent(pointLightS5);
//
//    pointLightGameObjectS6->AddComponent(transformPointLightS6);
//    pointLightGameObjectS6->AddComponent(pointLightS6);
//
//    pointLightGameObjectS7->AddComponent(transformPointLightS7);
//    pointLightBoxCollider4->IsTrigger = true;
//    pointLightGameObjectS7->AddComponent(pointLightBoxCollider4);
//    pointLightGameObjectS7->AddComponent(pointLightS7);
//
//    pointLightGameObjectS8->AddComponent(transformPointLightS8);
//    pointLightGameObjectS8->AddComponent(pointLightS8);
//
//    pointLightGameObjectS9->AddComponent(transformPointLightS9);
//    pointLightBoxCollider5->IsTrigger = true;
//    pointLightGameObjectS9->AddComponent(pointLightBoxCollider5);
//    pointLightGameObjectS9->AddComponent(pointLightS9);
//
//    pointLightGameObjectS10->AddComponent(transformPointLightS10);
//    pointLightGameObjectS10->AddComponent(pointLightS10);
//
//    pointLightGameObject5->AddComponent(transformPointLight5);
//    pointLightBoxCollider6->IsTrigger = true;
//    pointLightGameObject5->AddComponent(pointLightBoxCollider6);
//    pointLightGameObject5->AddComponent(pointLight5);
//
//    pointLightGameObject6->AddComponent(transformPointLight6);
//    pointLightGameObject6->AddComponent(pointLight6);
//
//    pointLightGameObjectS1->AddComponent(moveEnemy1);
//    pointLightGameObjectS2->AddComponent(moveEnemy2);
//    pointLightGameObjectS3->AddComponent(moveEnemy3);
//    pointLightGameObjectS4->AddComponent(moveEnemy4);
//    pointLightGameObjectS5->AddComponent(moveEnemy5);
//    pointLightGameObjectS6->AddComponent(moveEnemy6);
//    pointLightGameObjectS7->AddComponent(moveEnemy7);
//    pointLightGameObjectS8->AddComponent(moveEnemy8);
//    pointLightGameObjectS9->AddComponent(moveEnemy9);
//    pointLightGameObjectS10->AddComponent(moveEnemy10);
//    pointLightGameObject5->AddComponent(moveEnemy11);
//    pointLightGameObject6->AddComponent(moveEnemy12);
//
//    objSuzane2->AddComponent(transformSuzane2);
//    objSuzane2->AddComponent(meshRendererSuzanne2);
//    objSuzane2->Name = "Suzane2";
//
//    objSuzane3->AddComponent(transformSuzane3);
//    objSuzane3->AddComponent(meshRendererSuzanne3);
//    objSuzane3->Name = "Suzane3";
//
//    objSuzane4->AddComponent(transformSuzane4);
//    objSuzane4->AddComponent(meshRendererSuzanne4);
//    objSuzane4->Name = "Suzane4";
//
//    objSuzane5->AddComponent(transformSuzane5);
//    objSuzane5->AddComponent(meshRendererSuzanne5);
//    objSuzane5->Name = "Suzane5";
//
//    objSuzane6->AddComponent(transformSuzane6);
//    objSuzane6->AddComponent(meshRendererSuzanne6);
//    objSuzane6->Name = "Suzane6";
//
//    camController->AddComponent(controller);
//
//
//    objCamera->Start();
//    controller->initialize(application, camera);
//
//
//    //state->addChildGameObject(objCamera, obj1);
//    state->addGameObject(obj1);
//    state->addGameObject(obj2);
//    state->addGameObject(cubeGameObj);
//
//    state->addGameObject(directionalLightGameObject);
//
//    //state->addGameObject(spotLightGameObject);
//    state->addGameObject(planeGameObject);
//    state->addGameObject(planeGameObject2);
//    state->addGameObject(planeGameObject3);
//    state->addGameObject(planeGameObject4);
//    state->addGameObject(planeGameObject5);
//    //state->addGameObject(planeGameObject6);
//
//    state->addGameObject(Box1);
//    state->addGameObject(Box2);
//    state->addGameObject(Box3);
//    state->addGameObject(Box4);
//    state->addGameObject(Box5);
////    state->addGameObject(Box6);
////    state->addGameObject(Box7);
////    state->addGameObject(Box8);
////    state->addGameObject(Box9);
////    state->addGameObject(Box10);
//    //state->addGameObject(spotLightGameObject);
//
//
//    state->addGameObject(pointLightGameObjectS1);
//    state->addGameObject(pointLightGameObjectS2);
//    state->addGameObject(pointLightGameObjectS3);
//    state->addGameObject(pointLightGameObjectS4);
//    state->addGameObject(pointLightGameObjectS5);
//    state->addGameObject(pointLightGameObjectS6);
//    state->addGameObject(pointLightGameObjectS7);
//    state->addGameObject(pointLightGameObjectS8);
//    state->addGameObject(pointLightGameObjectS9);
//    state->addGameObject(pointLightGameObjectS10);
//    state->addGameObject(pointLightGameObject5);
//    state->addGameObject(pointLightGameObject6);
//    state->addChildGameObject(pointLightGameObjectS1, objSuzane);
//    state->addChildGameObject(pointLightGameObjectS3, objSuzane2);
//    state->addChildGameObject(pointLightGameObjectS5, objSuzane3);
//    state->addChildGameObject(pointLightGameObjectS7, objSuzane4);
//    state->addChildGameObject(pointLightGameObjectS9, objSuzane5);
//    state->addChildGameObject(pointLightGameObject5, objSuzane6);
//
//    //state->addGameObject(camController);
//    state->addGameObject(objCamera);
//
//
//    state->attachCameraController(controller);
//
//    return state;
//}
























ShiEngine::GameState* CreateState3(ShiEngine::Application* application){

    auto* state = new ShiEngine::GameState;
    state->Name = "MainMenu";
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
    ShiEngine::MeshRenderer* meshRendererWallMiddle1;
    ShiEngine::MeshRenderer* meshRendererHouse;
    ShiEngine::MeshRenderer* meshRendererTree1;
    ShiEngine::MeshRenderer* meshRendererTree2;
    ShiEngine::MeshRenderer* meshRendererKey;

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
    auto* camController = new ShiEngine::GameObject();
    auto* wallMiddle1 = new ShiEngine::GameObject;
    auto* houseGameObj = new ShiEngine::GameObject;
    auto* treeGameObj1 = new ShiEngine::GameObject;
    auto* treeGameObj2 = new ShiEngine::GameObject;
    auto* keyGameObj = new ShiEngine::GameObject;

    RenderState* renderState1;

    ShiEngine::Transform* transform1;
    ShiEngine::Transform* transform2;
    ShiEngine::Transform* transformCamera;
    ShiEngine::Transform* transformCube;
    ShiEngine::Transform* transformKey;

    ShiEngine::BoxCollider* boxColliderPlayer;
    ShiEngine::BoxCollider* boxColliderWallBehind;
    ShiEngine::BoxCollider* boxColliderWallFront;
    ShiEngine::BoxCollider* boxColliderWallRight;
    ShiEngine::BoxCollider* boxColliderWallLeft;
    ShiEngine::BoxCollider* boxColliderWallDoor;


    ShiEngine::Transform* transformDirectionalLight;
    ShiEngine::Transform* transformPointLight;
    ShiEngine::Transform* transformPlane;
    ShiEngine::Transform* transformSpotLight;
    ShiEngine::Transform* transformPointLight2;
    ShiEngine::Transform* transformCubeObj;

    ShiEngine::Transform* transformWallMiddle1;

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
    ShiEngine::Transform* transformHouse;

    ShiEngine::Transform* transformPointLight3;
    ShiEngine::Transform* transformPointLight4;
    ShiEngine::Transform* transformPointLight5;
    ShiEngine::Transform* transformPointLight6;
    ShiEngine::Transform* transformTree1;
    ShiEngine::Transform* transformTree2;

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
    ShiEngine::Material* materialHouse;
    ShiEngine::Material* materialWalls;
    ShiEngine::Material* materialwelcome;
    ShiEngine::Material* materialTree;
    ShiEngine::Material* materialKey;


    ShiEngine::Mesh* meshCube;
    ShiEngine::Mesh* meshPlane;
    ShiEngine::Mesh* meshSphere;
    ShiEngine::Mesh* meshPlane2;
    ShiEngine::Mesh* meshPlane3;
    ShiEngine::Mesh* meshPlane4;
    ShiEngine::Mesh* meshPlane5;
    ShiEngine::Mesh* meshPlane6;
    ShiEngine::Mesh* meshSuzane;
    ShiEngine::Mesh* meshHouse;
    ShiEngine::Mesh* meshTree;


    ShiEngine::Texture2D* texture1; //texture Earth
    ShiEngine::Sampler* sampler1;

    ShiEngine::Texture2D* texture2;
    ShiEngine::Texture2D* textureEarth;
    ShiEngine::Texture2D* textureHouse;
    ShiEngine::Texture2D* textureWalls;
    ShiEngine::Texture2D* texturewelcome;
    ShiEngine::Texture2D* textureKey;


    ShiEngine::EnemyMovement* moveEnemy1; // In front of the Door/Gate
    ShiEngine::EnemyMovement* moveEnemy2; // Follows the player
    ShiEngine::EnemyMovement* moveEnemy3;
    ShiEngine::EnemyMovement* moveEnemy4;
    ShiEngine::EnemyMovement* moveEnemy5;
    ShiEngine::EnemyMovement* moveEnemy6;

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


    meshSphere = new ShiEngine::Mesh();
    // meshSphere->Model("../assets/models/Ghost/ghost.obj");

    meshSuzane = new ShiEngine::Mesh();
    meshSuzane->Model( "../assets/models/Skeleton/skull.obj");
    //meshSuzane->Model("../assets/models/zombie/mediaeval_house.obj");

    meshHouse = new ShiEngine::Mesh();
    meshHouse->Model("../assets/models/zombie/mediaeval_house.obj");

    meshTree = new ShiEngine::Mesh();
    meshTree->Model("../assets/models/Trees/tree2.obj");


    //Transforms
    transformCamera = new ShiEngine::Transform();
    //transformCamera->position = glm::vec3({-210, 10, 0});
    transformCamera->position = glm::vec3({-500, 16, 0});
    transformCamera->scale = glm::vec3({1,1,1});
    transformCamera->rotation = glm::vec3({0,0,0});

    transformCube = new ShiEngine::Transform();
    transformCube->position = glm::vec3({-208, 0, 6});
    transformCube->scale = glm::vec3({0.1,0.1,0.1});
    transformCube->rotation = glm::vec3({5,0,0});

    // Wall left
    transformPlane2 = new ShiEngine::Transform();
    transformPlane2->position = glm::vec3({-300, 1, -140});
    transformPlane2->scale = glm::vec3({-500,100,4});
    transformPlane2->rotation = glm::vec3({0,0,0});

    // Wall right
    transformPlane3 = new ShiEngine::Transform();
    transformPlane3->position = glm::vec3({-300, 1, 140});
    transformPlane3->scale = glm::vec3({-500,100,4});
    transformPlane3->rotation = glm::vec3({0,0,0});

    // Wall behind
    transformPlane4 = new ShiEngine::Transform();
    transformPlane4->position = glm::vec3({-520, 20, 0});
    transformPlane4->scale = glm::vec3({4,30,500});
    transformPlane4->rotation = glm::vec3({0,0,0});

    // Wall front
    transformPlane5 = new ShiEngine::Transform();
    transformPlane5->position = glm::vec3({-200, 1, 0});
    transformPlane5->position = glm::vec3({-200, 1, 0});
    transformPlane5->scale = glm::vec3({2,100,400});
    transformPlane5->rotation = glm::vec3({0,0,0});

    // Wall up
    transformPlane6 = new ShiEngine::Transform();
    transformPlane6->position = glm::vec3({-250, 1500, 0});
    transformPlane6->scale = glm::vec3({1500,1,1500});
    transformPlane6->rotation = glm::vec3({0,0,0});

    // Wall down
    transformPlane = new ShiEngine::Transform();
    transformPlane->position = glm::vec3({-220, 0, 0});
    transformPlane->scale = glm::vec3({700,1,700});
    transformPlane->rotation = glm::vec3({0,0,0});

    // Wall middle
    transformWallMiddle1 = new ShiEngine::Transform();
    transformWallMiddle1->position = glm::vec3({-400, 40, 80});
    transformWallMiddle1->scale = glm::vec3({2,60,60});
    transformWallMiddle1->rotation = glm::vec3({0,0,0});

    transformHouse = new ShiEngine::Transform();
    transformHouse->position = glm::vec3({10, 0, 0});
    transformHouse->scale = glm::vec3({50,80,35});
    transformHouse->rotation = glm::vec3({270,0,270});


    // Suzane Transforms
    transformSuzane = new ShiEngine::Transform();
    transformSuzane->position = glm::vec3({-250, 5, 40}); // note: position relative to parent (PointLight2)
    transformSuzane->scale = glm::vec3({4,4,4});
    transformSuzane->rotation = glm::vec3({0,0,0});

    transformSuzane2 = new ShiEngine::Transform();
    transformSuzane2->position = glm::vec3({-250, 5, -40});//kairi
    transformSuzane2->scale = glm::vec3({4,4,4});
    transformSuzane2->rotation = glm::vec3({0,0,0});

    transformSuzane3 = new ShiEngine::Transform();
    transformSuzane3->position = glm::vec3({-260, 5, 50});//kairi
    transformSuzane3->scale = glm::vec3({4,4,4});
    transformSuzane3->rotation = glm::vec3({0,0,0});

    transformSuzane4 = new ShiEngine::Transform();
    transformSuzane4->position = glm::vec3({-260, 5, -50});//kairi
    transformSuzane4->scale = glm::vec3({4,4,4});
    transformSuzane4->rotation = glm::vec3({0,0,0});

    transformSuzane5 = new ShiEngine::Transform();
    transformSuzane5->position = glm::vec3({-270, 5, 60});//kairi
    transformSuzane5->scale = glm::vec3({4,4,4});
    transformSuzane5->rotation = glm::vec3({0,0,0});

    transformSuzane6 = new ShiEngine::Transform();
    transformSuzane6->position = glm::vec3({-270, 5, -60});//kairi
    transformSuzane6->scale = glm::vec3({4,4,4});
    transformSuzane6->rotation = glm::vec3({0,0,0});

    transformTree1 = new ShiEngine::Transform();
    transformTree1->position = glm::vec3({-200, 5, -150});
    transformTree1->scale = glm::vec3({30,30,30});
    transformTree1->rotation = glm::vec3({0,0,0});

    transformKey = new ShiEngine::Transform();
    transformKey->position = glm::vec3({-200, 5, -150});
    transformKey->scale = glm::vec3({30,30,30});
    transformKey->rotation = glm::vec3({0,0,0});

    transformTree2 = new ShiEngine::Transform();
    transformTree2->position = glm::vec3({-200, 5, 150});
    transformTree2->scale = glm::vec3({30,30,30});
    transformTree2->rotation = glm::vec3({0,0,0});

    transform1 = new ShiEngine::Transform();
    transform1->position = glm::vec3({0, 0, 0});
    transform1->scale = glm::vec3({1,1,1});
    transform1->rotation = glm::vec3({0,0,0});

    transform2 = new ShiEngine::Transform();
    transform2->position = glm::vec3({2, 5, 0});
    transform2->scale = glm::vec3({2,2,2});
    transform2->rotation = glm::vec3({0,0,0});

    boxColliderPlayer = new ShiEngine::BoxCollider();
    boxColliderWallBehind = new ShiEngine::BoxCollider();
    boxColliderWallFront = new ShiEngine::BoxCollider();
    boxColliderWallLeft = new ShiEngine::BoxCollider();
    boxColliderWallRight = new ShiEngine::BoxCollider();
    boxColliderWallDoor = new ShiEngine::BoxCollider();
    boxColliderWallDoor->IsTrigger = true;

    // Door
    transformCubeObj = new ShiEngine::Transform();
    transformCubeObj->position = glm::vec3({-210, 15, -16});
    transformCubeObj->scale = glm::vec3({2,40,25});
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
    transformDirectionalLight->direction = glm::vec3({-1, -1, -1});

    // Point Light Transfor Spot Light Transform
    transformSpotLight = new ShiEngine::Transform();
    transformSpotLight->position = glm::vec3({2, 0, 0});
    transformSpotLight->scale = glm::vec3({1,1,1});
    transformSpotLight->rotation = glm::vec3({0,0,0});
    transformSpotLight->direction = glm::vec3({0,0,1});

    transformPointLight = new ShiEngine::Transform();
    transformPointLight->position = glm::vec3({-168, 0, 1});
    transformPointLight->scale = glm::vec3({1,1,1});
    transformPointLight->rotation = glm::vec3({0,0,0});
    transformPointLight->direction = glm::vec3({0, -2, 0});

    transformPointLight2 = new ShiEngine::Transform();
    transformPointLight2->position = glm::vec3({-35, 10, 0});
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
    transformPointLight5->position = glm::vec3({-154, 6, -1});
    transformPointLight5->scale = glm::vec3({1,1,1});
    transformPointLight5->rotation = glm::vec3({0,0,0});
    transformPointLight5->direction = glm::vec3({-1, -1, -1});

    transformPointLight6 = new ShiEngine::Transform();
    transformPointLight6->position = glm::vec3({-154, 6, 2});
    transformPointLight6->scale = glm::vec3({1,1,1});
    transformPointLight6->rotation = glm::vec3({0,0,0});
    transformPointLight6->direction = glm::vec3({0, -2, 0});// Point Light Transform

    // Spot Light Transform
    transformSpotLight = new ShiEngine::Transform();
    transformSpotLight->position = glm::vec3({-120, 6, -10});
    transformSpotLight->scale = glm::vec3({1,1,1});
    transformSpotLight->rotation = glm::vec3({0,0,0});
    transformSpotLight->direction = glm::vec3({0,0,-1});


    moveEnemy1 = new ShiEngine::EnemyMovement(transformCamera, false, true);
    moveEnemy2 = new ShiEngine::EnemyMovement(transformCamera, false, true);
    moveEnemy3 = new ShiEngine::EnemyMovement(transformCamera,false,true);
    moveEnemy4 = new ShiEngine::EnemyMovement(transformCamera, false, true);
    moveEnemy5 = new ShiEngine::EnemyMovement(transformCamera, false, true);
    moveEnemy6 = new ShiEngine::EnemyMovement(transformCamera, false, true);

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
    pointLight2->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({0.1,0.1,0.1}), glm::vec3({1,1,1}));

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
    pointLight6->setPhong(glm::vec3({0.5,0.5,0.5}), glm::vec3({1,1,1}), glm::vec3({1,1,1}));


    spotLight = new ShiEngine::Light(ShiEngine::LightType::SPOT);
    spotLight->setAttenuation(3,0,0);
    spotLight->setPhong(glm::vec3({1,1,1}), glm::vec3({1,0.1,0.1}), glm::vec3({1,1,1}));
    spotLight->setSpotAngle(0.785, 0.786);

    renderState1 = new RenderState(true,true,false);

    meshRenderer1 = new ShiEngine::MeshRenderer(program, meshSphere);
    meshRenderer1->SetRenderState(renderState1);

    meshRenderer2 = new ShiEngine::MeshRenderer(program, meshCube);
    meshRenderer2->SetRenderState(renderState1);

    meshRenderer3 = new ShiEngine::MeshRenderer(program, meshCube);
    meshRenderer3->SetRenderState(renderState1);

    meshRendererPlane = new ShiEngine::MeshRenderer(program, meshPlane);
    meshRendererPlane->SetRenderState(renderState1);

    meshRendererPlane2 = new ShiEngine::MeshRenderer(program, meshCube);
    meshRendererPlane2->SetRenderState(renderState1);

    meshRendererPlane3 = new ShiEngine::MeshRenderer(program, meshCube);
    meshRendererPlane3->SetRenderState(renderState1);

    meshRendererPlane4 = new ShiEngine::MeshRenderer(program, meshCube);
    meshRendererPlane4->SetRenderState(renderState1);

    meshRendererPlane5 = new ShiEngine::MeshRenderer(program, meshCube);
    meshRendererPlane5->SetRenderState(renderState1);

    meshRendererPlane6 = new ShiEngine::MeshRenderer(program, meshPlane);
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

    meshRendererWallMiddle1 = new ShiEngine::MeshRenderer(program, meshCube);
    meshRendererWallMiddle1->SetRenderState(renderState1);

    meshRendererHouse = new ShiEngine::MeshRenderer(program, meshHouse);
    meshRendererHouse->SetRenderState(renderState1);

    meshRendererTree1 = new ShiEngine::MeshRenderer(program, meshTree);
    meshRendererTree1->SetRenderState(renderState1);

    meshRendererTree2 = new ShiEngine::MeshRenderer(program, meshTree);
    meshRendererTree2->SetRenderState(renderState1);

    texture1 = new ShiEngine::Texture2D("../assets/Textures/woodtexture.jpg", true);
    sampler1 = new ShiEngine::Sampler();


    texture2 = new ShiEngine::Texture2D("../assets/Textures/doorTexture.jpg", true);

    textureEarth = new ShiEngine::Texture2D("../assets/models/Skeleton/color.png", true);

    textureWalls = new ShiEngine::Texture2D("../assets/Textures/oldwall.jpg", true);
    texturewelcome = new ShiEngine::Texture2D("../assets/Textures/welcome.jpg", true);

    textureHouse = new ShiEngine::Texture2D("../assets/Textures/MittelH col DH.jpg", true);

    material1 = new ShiEngine::Material();
    material1->shaderProgram = program;
    material1->albedo_tint = {0.7, 0.7, 0.7}; // The reflectance color
    material1->specular_tint = {1, 1, 1};
    material1->roughness_range = {0,1};
    material1->emissive_tint = {0.6,0.6,0.6};
    material1->setTexture(textureEarth);
    material1->setSampler(sampler1);
    meshRenderer1->SetMaterial(material1);

    //

    materialwelcome = new ShiEngine::Material();
    materialwelcome->shaderProgram = program;
    materialwelcome->albedo_tint = {0.7, 0.7, 0.7};// The reflectance color
    materialwelcome->specular_tint = {1, 1, 1};
    materialwelcome->roughness_range = {0,1};
    materialwelcome->emissive_tint = {0.6,0.6,0.6};
    materialwelcome->setTexture(texturewelcome);
    materialwelcome->setSampler(sampler1);
    meshRendererWallMiddle1->SetMaterial(materialwelcome);
    //
    materialCube = new ShiEngine::Material();
    materialCube->shaderProgram = program;
    materialCube->albedo_tint = {0.7, 0.7, 0.7}; // The reflectance color
    materialCube->specular_tint = {1, 1, 1};
    materialCube->roughness_range = {0,1};
    materialCube->emissive_tint = {0.6,0.6,0.6};
    materialCube->setTexture(texture2);
    materialCube->setSampler(sampler1);

    materialPlane = new ShiEngine::Material();
    materialPlane->albedo_tint = {0.93, 0.1019, 0.301}; // The reflectance color
    materialPlane->specular_tint = {0.1, 0.1, 0.1};
    materialPlane->roughness_range = {0,1};
    materialPlane->emissive_tint = {0.1,0.1,0.1};
    materialPlane->setTexture(texture1);
    materialPlane->setSampler(sampler1);
    materialPlane->shaderProgram = program;


    materialHouse = new ShiEngine::Material();
    materialHouse->shaderProgram = program;
    materialHouse->albedo_tint = {1, 1, 1}; // The reflectance color
    materialHouse->specular_tint = {1, 1, 1};
    materialHouse->roughness_range = {0,1};
    materialHouse->emissive_tint = {1,1,1};
    materialHouse->setTexture(textureHouse);
    materialHouse->setSampler(sampler1);
    meshRendererHouse->SetMaterial(materialHouse);

    materialWalls = new ShiEngine::Material();
    materialWalls->shaderProgram = program;
    materialWalls->albedo_tint = {0.2, 0.1, 0.1}; // The reflectance color
    materialWalls->specular_tint = {1, 1, 1};
    materialWalls->roughness_range = {0,1};
    materialWalls->emissive_tint = {0.1,0.1,0.1};
    materialWalls->setTexture(textureWalls);
    materialWalls->setSampler(sampler1);

    materialTree = new ShiEngine::Material();
    materialTree->shaderProgram = program;
    materialTree->albedo_tint = {0.2, 0.1, 0.1}; // The reflectance color
    materialTree->specular_tint = {1, 1, 1};
    materialTree->roughness_range = {0,1};
    materialTree->emissive_tint = {0.1,0.1,0.1};
    materialTree->setTexture(textureEarth);
    materialTree->setSampler(sampler1);

    meshRendererPlane2->SetMaterial(materialWalls);
    meshRendererPlane3->SetMaterial(materialWalls);

    meshRendererPlane->SetMaterial(materialPlane);
    meshRenderer2->SetMaterial(materialCube); //cube will have same material as sphere
    meshRenderer3->SetMaterial(materialCube);

    ///
    meshRendererPlane4->SetMaterial(materialPlane);
    meshRendererPlane5->SetMaterial(materialPlane);
    meshRendererPlane6->SetMaterial(materialPlane);
    meshRendererSuzane->SetMaterial(material1);
    meshRendererSuzanne2->SetMaterial(material1);
    meshRendererSuzanne3->SetMaterial(material1);
    meshRendererSuzanne4->SetMaterial(material1);
    meshRendererSuzanne5->SetMaterial(material1);
    meshRendererSuzanne6->SetMaterial(material1);
    meshRendererTree1->SetMaterial(materialTree);
    meshRendererTree2->SetMaterial(materialTree);

    objCamera->AddComponent(transformCamera);
    objCamera->AddComponent(camera);
    objCamera->AddComponent(boxColliderPlayer);
    objCamera->Name = "objCamera";

    obj2->AddComponent(transform2);
    obj2->AddComponent(meshRenderer3);
    //obj2->AddComponent(boxColliderWallLeft);
    obj2->Name = "cube 2";

    // Door
    cubeGameObj->AddComponent(transformCubeObj);
    cubeGameObj->AddComponent(meshRenderer2);
    cubeGameObj->AddComponent(boxColliderWallDoor);
    cubeGameObj->Name = "Door";


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
    //pointLightGameObject2->AddComponent(moveEnemy1);

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
    planeGameObject2->AddComponent(boxColliderWallLeft);
    planeGameObject2->Name = "plane2 gameObject";

    planeGameObject3->AddComponent(transformPlane3);
    planeGameObject3->AddComponent(meshRendererPlane3);
    planeGameObject3->AddComponent(boxColliderWallRight);
    planeGameObject3->Name = "plane3 gameObject";

    planeGameObject4->AddComponent(transformPlane4);
    planeGameObject4->AddComponent(meshRendererPlane4);
    planeGameObject4->AddComponent(boxColliderWallFront); // TODO: at start, the player is very close to the wall, therefore crashes
    planeGameObject4->Name = "plane4 gameObject";

    planeGameObject5->AddComponent(transformPlane5);
    planeGameObject5->AddComponent(meshRendererPlane5);
    planeGameObject5->AddComponent(boxColliderWallBehind);
    planeGameObject5->Name = "plane5 gameObject";

    wallMiddle1->AddComponent(transformWallMiddle1);
    wallMiddle1->AddComponent(meshRendererWallMiddle1);

    houseGameObj->AddComponent(transformHouse);
    houseGameObj->AddComponent(meshRendererHouse);

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
    objSuzane2->AddComponent(moveEnemy2);
    objSuzane2->Name = "Suzane2";

    objSuzane3->AddComponent(transformSuzane3);
    objSuzane3->AddComponent(meshRendererSuzanne3);
    objSuzane3->AddComponent(moveEnemy3);
    objSuzane3->Name = "Suzane3";

    objSuzane4->AddComponent(transformSuzane4);
    objSuzane4->AddComponent(meshRendererSuzanne4);
    objSuzane4->AddComponent(moveEnemy4);
    objSuzane4->Name = "Suzane4";

    objSuzane5->AddComponent(transformSuzane5);
    objSuzane5->AddComponent(meshRendererSuzanne5);
    objSuzane5->AddComponent(moveEnemy5);
    objSuzane5->Name = "Suzane5";

    objSuzane6->AddComponent(transformSuzane6);
    objSuzane6->AddComponent(meshRendererSuzanne6);
    objSuzane6->AddComponent(moveEnemy6);
    objSuzane6->Name = "Suzane6";

    treeGameObj1->AddComponent(transformTree1);
    treeGameObj1->AddComponent(meshRendererTree1);
    treeGameObj1->Name = "tree1";

    treeGameObj2->AddComponent(transformTree2);
    treeGameObj2->AddComponent(meshRendererTree2);
    treeGameObj2->Name = "tree2";

    camController->AddComponent(controller);


    objCamera->Start();
    controller->initialize(application, camera);


    state->addGameObject(obj1);
    state->addGameObject(obj2);
    state->addGameObject(cubeGameObj);

    state->addGameObject(directionalLightGameObject);


    state->addGameObject(planeGameObject);
    state->addGameObject(planeGameObject2);
    state->addGameObject(planeGameObject3);
    state->addGameObject(planeGameObject4);
    state->addGameObject(planeGameObject5);
    state->addGameObject(planeGameObject6);
    state->addGameObject(wallMiddle1);
    state->addGameObject(houseGameObj);
    state->addGameObject(treeGameObj1);
    state->addGameObject(treeGameObj2);

    state->addGameObject(spotLightGameObject);
    state->addGameObject(pointLightGameObject2);
    state->addGameObject(pointLightGameObject5);
    state->addGameObject(pointLightGameObject6);
    state->addGameObject(objSuzane);
    state->addGameObject(objSuzane2);
    state->addGameObject(objSuzane3);
    state->addGameObject(objSuzane4);
    state->addGameObject(objSuzane5);
    state->addGameObject(objSuzane6);

    //state->addGameObject(camController);
    state->addGameObject(objCamera);


    state->attachCameraController(controller);

    return state;
}



#endif //GFX_LAB_STATES_H
