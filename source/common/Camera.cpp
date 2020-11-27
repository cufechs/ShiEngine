//
// Created by yuze on 11/26/2020.
//

#include <application.hpp>
#include <shader.hpp>
#include <imgui-utils/utils.hpp>

#include <glm/gtx/euler_angles.hpp>
#include "Camera.h"
using namespace std;
using namespace ShiEngine;
using namespace glm;

    WindowConfiguration Camera:: getWindowConfiguration() {
        return { "Camera (Simple)", {1280, 720}, false };
    }

    void Camera:: onInitialize() {
        program.create();
        program.attach("../assets/shaders/ex11_transformation/transform.vert", GL_VERTEX_SHADER);
        program.attach("../assets/shaders/ex11_transformation/tint.frag", GL_FRAGMENT_SHADER);
        program.link();

        objects.push_back({ {0,-100,0}, {0,0,0}, {500,20,1} });
        objects.push_back({ {-200,100,0}, {0,0,0}, {30,30,1} });
        objects.push_back({ {0,100,0}, {0,0,glm::pi<float>()/4}, {30,30,1} });
        objects.push_back({ {200,100,0}, {0,0,0}, {30,30,1} });

        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        camera = Transform({0,0,0},{0, 0, 0},{width, height, 1});

        glClearColor(0, 0, 0, 0);
    }

    void Camera::onDraw(double deltaTime) {
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(program);

        program.set("tint", glm::vec4(1,1,1,1));

        glm::mat4 camera_matrix = glm::inverse(camera.to_mat4());

        for(const auto& object : objects) {
            program.set("transform", camera_matrix * object.to_mat4());
        }
    }

    void Camera::onDestroy() {
        program.destroy();
    }