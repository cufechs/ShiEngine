//
// Created by adham on 16-Dec-20.
//

#ifndef LOADSTATE_H
#define LOADSTATE_H

#include <glm/gtx/euler_angles.hpp>
#include <fstream>
#include <json/json.hpp>
#include "application.hpp"
#include "GameState.h"
#include "GameObject.h"
#include "Transform.h"
#include "MeshRenderer.h"

namespace glm {
    template<length_t L, typename T, qualifier Q>
    void from_json(const nlohmann::json& j, vec<L, T, Q>& v){
        for(length_t index = 0; index < L; ++index)
            v[index] = j[index].get<T>();
    }
}
namespace ShiEngine {

    GameObject* LoadGameObject(const nlohmann::json&,GameState*,ShaderProgram*,Camera*);
    void loadState(const nlohmann::json&,GameState*,ShaderProgram*,Camera*,GameObject*);

    GameState* DeserializeState(const std::string& fileName, Application* app ){
        std::ifstream file_in(fileName);
        nlohmann::json json;
        file_in >> json;
        file_in.close();

        auto GS = new GameState;

        auto GO = new GameObject;
        GO->AddComponent(new Transform());

        auto *program = new ShiEngine::ShaderProgram;
        program->create("../assets/Shaders/Phase 1/transform.vert", GL_VERTEX_SHADER,
                        "../assets/Shaders/Phase 1/tint.frag", GL_FRAGMENT_SHADER);

        auto camera = new ShiEngine::Camera();
        camera->setupPerspective(glm::pi<float>()/2, 1.7f, 0.1f, 100.0f);

        auto transformCamera = new ShiEngine::Transform();
        transformCamera->position = glm::vec3({10, 10, 10});
        transformCamera->scale = glm::vec3({1,1,1});
        transformCamera->rotation = glm::vec3({0,0,0});

        auto* objCamera = new ShiEngine::GameObject;

        objCamera->AddComponent(transformCamera);
        objCamera->AddComponent(camera);

        auto controller = new ShiEngine::FlyCameraController;

        controller->initialize(app, camera);
        GS->attachCameraController(controller);

        loadState(json, GS, program, camera, GO);

        return GS;
    }

    void loadState(const nlohmann::json& json, GameState* gs, ShaderProgram* prg, Camera* cam, GameObject* root){

        auto gameObj = LoadGameObject(json,gs,prg,cam);
        gs->addChildGameObject(root, gameObj);
    }

    GameObject* LoadGameObject(const nlohmann::json& json, GameState* gs, ShaderProgram* prg, Camera* cam){

        auto GO = new GameObject;

        auto trans = new Transform(
            json.value<glm::vec3>("position", {0, 0, 0}),
            json.value<glm::vec3>("rotation", {0, 0, 0}),
            json.value<glm::vec3>("scale", {1, 1, 1}),
            json.value<glm::vec4>("tint", {1,1,1,1})
        );

        GO->AddComponent(trans);

        // If it contains mesh name set it.
        MeshRenderer* MR;
        if(json.contains("mesh")){
            MR = new MeshRenderer(prg, new ShiEngine::Mesh(json.value<std::string>("mesh", "cube"), true));
            MR->Setcam(cam);

            GO->AddComponent(MR);
        }

        gs->addGameObject(GO);

        if(json.contains("children"))
            for(auto& [name, child]: json["children"].items())
                gs->attachChildGameObject(GO, LoadGameObject(child,gs,prg,cam));


        return GO;
    }
}



#endif //LOADSTATE_H