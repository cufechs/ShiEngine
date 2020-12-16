//
// Created by Adham on 26-Nov-20.
//

#include "GameStateManger.h"

namespace ShiEngine {
    int GameStateManger::GSM_Controller = 0;

    GameStateManger::GameStateManger() {
        GSM_Controller++;
        if (GSM_Controller != 1) {
            std::cerr << "ERROR: Multiple game state manger is created!" << std::endl;
            std::exit(-1);
        }
        activeState = nullptr;
        Init();
    }

    GameStateManger::GameStateManger(Application* appPtr) {
        GSM_Controller++;
        if (GSM_Controller != 1) {
            std::cerr << "ERROR: Multiple game state manger is created!" << std::endl;
            std::exit(-1);
        }
        application_ptr = appPtr;
        activeState = nullptr;
        activeStateKey = -1;

        Init();
    }

    GameStateManger::GameStateManger(Application* appPtr, function_pointer fucPtr) {
        GSM_Controller++;
        if (GSM_Controller != 1) {
            std::cerr << "ERROR: Multiple game state manger is created!" << std::endl;
            std::exit(-1);
        }
        application_ptr = appPtr;
        activeState = fucPtr(appPtr);
        activeStateKey = -1;

        Init();
    }

    void GameStateManger::attachApplicationPtr(Application * appPtr) {
        application_ptr = appPtr;
    }

    GameState *GameStateManger::GetActiveState() const {
        return activeState;
    }

    void GameStateManger::Init() {

    }

    void GameStateManger::Cleanup() {
        if (activeState) {
            activeState->Exit();
            delete (activeState);
        }
    }

    void GameStateManger::AttachGameState(int gameStateKey, function_pointer fucPtr) {
        gameStates_UMap[gameStateKey] = fucPtr;
    }

    void GameStateManger::ChangeGameState(int gameStateKey) {
        if (activeState) {
            activeState->Exit();
            delete (activeState);
        }
        activeState = gameStates_UMap[gameStateKey](application_ptr);
        activeState->Enter();
        activeStateKey = gameStateKey;
    }

    void GameStateManger::ChangeGameState(GameState *gameState) {
        if (activeState) {
            activeState->Exit();
            delete (activeState);
        }
        activeState = gameState;
        activeState->Enter();
    }

    void GameStateManger::Update(double deltaTime) {
        activeState->Update(deltaTime);
    }

    void GameStateManger::Draw() {
        activeState->Draw();
    }
}