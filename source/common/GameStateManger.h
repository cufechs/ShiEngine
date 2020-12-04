//
// Created by Adham on 26-Nov-20.
//

#ifndef GAMESTATEMANGER_H
#define GAMESTATEMANGER_H

#include <iostream>
#include <GameState.h>
#include <unordered_map>
#include "application.hpp"

namespace ShiEngine {
    typedef GameState* (*function_pointer)(Application* application); // pointer to function type

    class GameStateManger {
    private:
        Application* application_ptr;
        GameState *activeState;
        std::unordered_map<int, function_pointer> gameStates_UMap;
        static int GSM_Controller;
    public:
        GameStateManger();
        GameStateManger(Application *pApplication);
        explicit GameStateManger(Application*, function_pointer);

        void attachApplicationPtr(Application* );

        void Init();
        void Cleanup();

        void AttachGameState(int gameStateKey, function_pointer fucPtr);
        void ChangeGameState(int gameStateKey);

        void Update(double deltaTime);
        void Draw();
    };
}

#endif //GAMESTATEMANGER_H
