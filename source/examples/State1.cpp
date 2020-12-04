//
// Created by adham on 12/4/2020.
//

#include "State1.h"


ShiEngine::GameState* CreateState1(ShiEngine::Application* application){

    auto* state = new ShiEngine::GameState;

    ShiEngine::ShaderProgram program;
    GLuint vertex_array = 0;
    ShiEngine::GameObject GO;
    ShiEngine::MeshRenderer* meshRenderer1;
    ShiEngine::MeshRenderer* meshRenderer2;
    //ShiEngine:: comp_mesh;
    ShiEngine::GameObject obj1;
    ShiEngine::GameObject obj2;
    ShiEngine::GameObject objCamera;

    ShiEngine::Transform* transform1;
    ShiEngine::Transform* transform2;

    ShiEngine::Camera* camera;

    ShiEngine::Mesh* meshCube;
    ShiEngine::Mesh* meshPlane;

    ShiEngine::FlyCameraController controller;

    program.create("../assets/Shaders/Phase 1/transform.vert", GL_VERTEX_SHADER, "../assets/Shaders/Phase 1/tint.frag", GL_FRAGMENT_SHADER);

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


    transform2 = new ShiEngine::Transform();
    transform2->position = glm::vec3({-3, 0, 0});
    transform2->scale = glm::vec3({1,1,1});
    transform2->rotation = glm::vec3({0,0,0});


    int width = 1280, height = 720;
    camera = new ShiEngine::Camera();

    camera->setEyePosition({10.f, 10.f, 10.f});
    camera->setTarget({0.f, 0.f, 0.f});
    camera->setUp({0, 1, 0});
    camera->setupPerspective(glm::pi<float>()/2, 1.7f, 0.1f, 100.0f);
    //camera->setupOrthographic(2.f, 1.7, 0.1f, 100.0f);

    meshRenderer1 = new ShiEngine::MeshRenderer(&program, meshCube);
    meshRenderer1->Setcam(camera);
    controller.initialize(application, camera);


    meshRenderer2 = new ShiEngine::MeshRenderer(&program, meshCube);
    meshRenderer2->Setcam(camera);

    objCamera.AddComponent(transform1); // TODO: independent transform -> transformCamera
    objCamera.AddComponent(camera);

    obj1.AddComponent(transform1);
    obj1.AddComponent(meshRenderer1);
    obj1.Name = "obj 1";

    obj2.AddComponent(transform2);
    obj2.AddComponent(meshRenderer2);
    obj2.Name = "obj 2";

    state->addGameObject(&obj1);
    state->addGameObject(&obj2);
    state->attachCameraController(&controller);

    return state;
}