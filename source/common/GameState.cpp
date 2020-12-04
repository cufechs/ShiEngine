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

    bool GameState::deleteGameObject(GameObject *gameObject) {

        for( auto iter = GameObj_vector.begin(); iter != GameObj_vector.end(); ++iter ) {
            if (*iter == gameObject) {
                GameObj_vector.erase(iter);
                delete gameObject;
                return true;
            }
        }
        return false;
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

    vector<GameObject *> GameState::getGameObjects(Tags tag) {

        vector<GameObject *> vec;

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

        for(auto & gameObj : GameObj_vector)
            gameObj->Update(deltaTime);

        if(cameraController)
            cameraController->Update(deltaTime);
    }

    void GameState::Draw() {
        for(auto & gameObj : GameObj_vector)
            gameObj->Draw();
    }
}