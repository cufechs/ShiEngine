//
// Created by yuze on 11/26/2020.
//

#ifndef GFX_LAB_CAMERA_H
#define GFX_LAB_CAMERA_H

#endif //GFX_LAB_CAMERA_H
//
// Created by yuze on 11/26/2020.
//

#include <application.hpp>
#include <shader.hpp>
#include <imgui-utils/utils.hpp>
#include "GameObjectComponent.h"
#include "GameObject.h"
#include <glm/gtx/euler_angles.hpp>
#include "Transform.h"


class Camera : public ShiEngine::GameObjectComponent {

private:

    Transform* trans_game_Object;

public:
    ShiEngine::ShaderProgram program;

    void Start() override;
    void To_cam(Transform game_Object);

};

