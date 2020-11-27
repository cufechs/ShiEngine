//
// Created by Adham on 26-Nov-20.
//

#include "GameStateManger.h"

namespace ShiEngine {
    int GameStateManger::GSM_Controller = 0;

    GameStateManger::GameStateManger(function_pointer fucPtr) {
        GSM_Controller++;
        if (GSM_Controller != 1) {
            std::cerr << "ERROR: Multiple game state manger is created!" << std::endl;
            std::exit(-1);
        }

        activeState = fucPtr();

        Init();
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
        activeState = gameStates_UMap[gameStateKey]();
    }

    void GameStateManger::Update(double deltaTime) {
        activeState->Update(deltaTime);
    }

    void GameStateManger::Draw() {
        activeState->Draw();
    }
}