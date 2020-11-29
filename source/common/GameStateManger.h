//
// Created by Adham on 26-Nov-20.
//

#ifndef GAMESTATEMANGER_H
#define GAMESTATEMANGER_H

#include <iostream>
#include <GameState.h>
#include <unordered_map>

namespace ShiEngine {
    typedef GameState *(*function_pointer)(); // pointer to function type

    class GameStateManger {
    private:
        GameState *activeState;
        std::unordered_map<int, function_pointer> gameStates_UMap;
        static int GSM_Controller;
    public:
        explicit GameStateManger(function_pointer);

        void Init();

        void Cleanup();

        void AttachGameState(int gameStateKey, function_pointer fucPtr);

        void ChangeGameState(int gameStateKey);

        void Update(double deltaTime);

        void Draw();
    };
}

#endif //GAMESTATEMANGER_H
