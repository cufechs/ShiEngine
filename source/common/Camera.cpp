//
// Created by yuze on 11/26/2020.
//

#include "Camera.h"

using namespace std;
using namespace ShiEngine;
using namespace glm;


    void Camera :: Start(){

        trans_game_Object = gameObject->GetComponent<Transform>();

    }

    void Camera::To_cam(Transform game_Object) {

        glUseProgram(program);

        program.set("tint", glm::vec4(1,1,1,1));

        glm::mat4 camera_matrix = glm::inverse(trans_game_Object->to_mat4());

        program.set("transform", camera_matrix * game_Object.to_mat4());
    }

