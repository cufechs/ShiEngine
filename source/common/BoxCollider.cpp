//
// Created by ossya on 1/16/2021.
//

#include "BoxCollider.h"
#include <glm/gtx/io.hpp>

ShiEngine::BoxCollider::BoxCollider()
{
    StartVector = glm::vec3(0, 0, 0);
    EndVector = glm::vec3(1, 1, 1);
    Type = ComponentType::BoxCollider;
    IsTrigger = false;
}

ShiEngine::BoxCollider::BoxCollider(glm::vec3 Start, glm::vec3 End)
{
    StartVector = Start;
    EndVector = End;
    Type = ComponentType::BoxCollider;
    IsTrigger = false;
}

glm::vec3 ShiEngine::BoxCollider::GetStartVector()
{
    return gameObject->transform->position + StartVector - gameObject->transform->scale/2.0f;
}

glm::vec3 ShiEngine::BoxCollider::GetEndVector()
{
    return gameObject->transform->position + EndVector * (gameObject->transform->scale*0.5f);
}

bool ShiEngine::BoxCollider::CollidesWith(glm::vec3 Start, glm::vec3 End) //Pass start and end vectors
{
    glm::vec3 SV = GetStartVector();
    glm::vec3 EV = GetEndVector();
    glm::vec3 Center1 = (Start + End)/2.0f;
    glm::vec3 Center2 = (SV + EV)/2.0f;

    if(abs(Center1.x - Center2.x) > (abs(Center1.x - Start.x) + abs(Center2.x - SV.x)))
        return false;
    if(abs(Center1.y - Center2.y) > (abs(Center1.y - Start.y) + abs(Center2.y - SV.y)))
        return false;
    if(abs(Center1.z - Center2.z) > (abs(Center1.z - Start.z) + abs(Center2.z - SV.z)))
        return false;

    if(!IsTrigger) {
        std::cout << gameObject->transform->position << ",  " << gameObject->transform->PreviousPosition << "\n";
        gameObject->transform->position = gameObject->transform->PreviousPosition;
    }


    std::cout << "Triggered\n";
    return true;
}

