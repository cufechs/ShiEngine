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

#include <glm/gtx/euler_angles.hpp>
#include "Transform.h"
class Camera : public ShiEngine::Application {

    ShiEngine::ShaderProgram program;
    ShiEngine::Mesh quad;

    std::vector<Transform> objects;
    Transform camera;

    ShiEngine::WindowConfiguration getWindowConfiguration() override;

    void onInitialize() override;

    void onDraw(double deltaTime) override;

    void onDestroy() override;

};

