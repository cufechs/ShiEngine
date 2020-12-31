//
// Created by adham on 31-Dec-20.
//

#ifndef SHIENGINE_GLOBAL_VARS_H
#define SHIENGINE_GLOBAL_VARS_H

#include "GameStateManger.h"

namespace ShiEngine {

    class Global{
    public:
        inline static GameStateManger* Global_GameStateManger = nullptr;
        inline static ShaderProgram* Global_ShaderProgram = nullptr;
    };

}

#endif //SHIENGINE_GLOBAL_VARS_H