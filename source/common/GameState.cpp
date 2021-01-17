//
// Created by Adham on 26-Nov-20.
//

#include "GameState.h"

namespace ShiEngine {
    
    GameState::GameState() {
        timeScale = 1;
        cameraController = nullptr;
    }

    void GameState::Enter() {
        for(auto & gameObj : GameObj_vector)
            if(gameObj)
                gameObj->Start();
    }

    void GameState::Exit() {
        // Deleting all game objects
        for(auto & gameObj : GameObj_vector)
            if (gameObj)
                delete (gameObj);

        GameObj_vector.clear();
    }

    void GameState::addGameObject(GameObject *gameObject) {
        GameObj_vector.push_back(gameObject);
    }

    void GameState::addChildGameObject(GameObject *Parent, GameObject *Child) {
        GameObj_vector.push_back(Child);
        if(Parent) {
            Parent->Children.push_back(Child);
            Child->Parent = Parent;
        }
    }

    void GameState::attachChildGameObject(GameObject *Parent, GameObject *Child) {
        if(Parent) {
            Parent->Children.push_back(Child);
            Child->Parent = Parent;
        }
    }

    void GameState::deleteGameObject() {
        for( auto iter = GameObj_vector.begin(); iter != GameObj_vector.end(); ++iter ) {
            GameObject* GO = *iter;
            if (GO->deleteMeFlag) {
                GameObj_vector.erase(iter--);
                delete(GO);
            }
        }
    }

    void GameState::deleteGameObject(Tags tag) {
        std::vector<GameObject *> vec = getGameObjects(tag);
        for(auto & gameObj : vec)
            gameObj->DeleteMe();
    }

    void GameState::attachCameraController(FlyCameraController * camCont) {
        cameraController = camCont;
    }

    GameObject *GameState::getGameObject(Tags tag) {

        for(auto & gameObj : GameObj_vector)
            if(gameObj->Tag == tag)
                return gameObj;

        return nullptr;
    }

    GameObject *GameState::getGameObject(std::string Name) {

        for(auto & gameObj : GameObj_vector)
            if(gameObj->Name == Name)
                return gameObj;

        return nullptr;
    }

    std::vector<GameObject *> GameState::getAllGameObjects() {
        return GameObj_vector;
    }

    std::vector<GameObject *> GameState::getGameObjects(Tags tag) {

        std::vector<GameObject *> vec;

        for(auto & gameObj : GameObj_vector)
            if(gameObj->Tag == tag)
                vec.push_back(gameObj);

        return vec;
    }

    void GameState::enableGameObject(GameObject *gameObject) {
        gameObject->Active = true;
    }

    void GameState::disableGameObject(GameObject *gameObject) {
        gameObject->Active = false;
    }

    void GameState::Pause() {
        timeScale = 0;
    }

    void GameState::Resume() {
        timeScale = 1;
    }

    void GameState::ScaleGameTime(double userTimeScale) {
        // TimeScale Constraints: (0) <= timeScale <= (10)
        timeScale = userTimeScale>0? (userTimeScale<10? userTimeScale : 10) : 0;
    }

    void GameState::Update(double deltaTime) {

        deleteGameObject();

        if(cameraController) {
            cameraController->Update(deltaTime * timeScale);
        }

        for(auto & gameObj : GameObj_vector)
            gameObj->Update(deltaTime * timeScale);


    }

    void GameState::LateUpdate(double deltaTime) {

        for(auto & gameObj : GameObj_vector)
            gameObj->LateUpdate(deltaTime * timeScale);
    }

    void GameState::Draw() {
        for(auto & gameObj : GameObj_vector)
            gameObj->Draw();
    }

     std::vector<GameObject *> GameState::getGameObjects() {
        return GameObj_vector;
    }
}