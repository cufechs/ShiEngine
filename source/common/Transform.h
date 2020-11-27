//
// Created by yuze on 11/26/2020.
//

#ifndef GFX_LAB_TRANSFORM_H
#define GFX_LAB_TRANSFORM_H

#endif //GFX_LAB_TRANSFORM_H

//
// Created by yuze on 11/26/2020.
//

#include <application.hpp>
#include <shader.hpp>
#include <imgui-utils/utils.hpp>

#include <glm/gtx/euler_angles.hpp>


enum class TransformationType : int {
    Translation = 0,
    Rotation = 1,
    Scaling = 2
};

struct Transformation {
    TransformationType type;
    glm::vec3 value;
};


class Transform : public ShiEngine:: Application
{
    // to be edited
public:
    std::vector<Transformation> transformations;
    Transformation Trans,Rot,Scal;
    glm::mat4 trans_mat,rot_mat,scal_mat;



    //funcs
    Transform(glm::vec3 trans,glm::vec3 rot,glm::vec3 scal);

    glm:: mat4 to_mat4() const;
    void composed();
    glm::mat4 compose();

    //GUI part
    void onImmediateGui(ImGuiIO &io) override ;


};
