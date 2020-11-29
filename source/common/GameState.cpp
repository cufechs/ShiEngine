//
// Created by Adham on 26-Nov-20.
//

#include "GameState.h"

namespace ShiEngine {
    GameState::GameState() {
        timeScale = 1;
        Enter();
    }

    void GameState::Enter() {

    }

    void GameState::Exit() {
        // Deleting all game objects
        int vecSize = (int) GameObj_vector.size();
        for (int i = 0; i < vecSize; i++)
            if (GameObj_vector[i])
                delete (GameObj_vector[i]);

        GameObj_vector.clear();
    }

    void GameState::addGameObject(GameObject *gameObject) {
        GameObj_vector.push_back(gameObject);
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
        timeScale = userTimeScale > 0 ? (userTimeScale < 10 ? userTimeScale : 10) : 0;
    }

    void GameState::Update(double deltaTime) {
        int vecSize = (int) GameObj_vector.size();
        for (int i = 0; i < vecSize; i++)
            GameObj_vector[i]->Update(deltaTime * timeScale);
    }

    void GameState::Draw() {
        int vecSize = (int) GameObj_vector.size();
        for (int i = 0; i < vecSize; i++)
            GameObj_vector[i]->Draw();
    }
}