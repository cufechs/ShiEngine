//
// Created by yuze on 11/26/2020.
//

#include <application.hpp>
#include <shader.hpp>
#include <imgui-utils/utils.hpp>

#include <glm/gtx/euler_angles.hpp>
#include "Transform.h"
using namespace ShiEngine;
using namespace glm;
using namespace std;




    Transform :: Transform(vec3 trans,vec3 rot,vec3 scal){

        Trans.type = TransformationType::Translation;
        Trans.value = trans;

        Rot.type = TransformationType::Rotation;
        Rot.value = rot;

        Scal.type = TransformationType::Scaling;
        Scal.value = scal;

    }

    mat4 Transform::to_mat4() const {
    return translate(glm::mat4(1.0f), Trans.value) *
           glm::yawPitchRoll(Rot.value.y, Rot.value.x, Rot.value.z) *
           glm::scale(glm::mat4(1.0f), Scal.value);
}

    void Transform::composed()
    {
        trans_mat = mat4 (1.0f);
        rot_mat = mat4(1.0f);
        scal_mat = mat4(1.0f);

        trans_mat = translate(mat4(1.0f), Trans.value) * trans_mat;

        rot_mat = yawPitchRoll(Rot.value.y, Rot.value.x, Rot.value.z) * rot_mat;

        scal_mat = scale(mat4(1.0f), Scal.value) * scal_mat;

    }
    mat4 Transform::compose(){
        mat4 transf_mat(1.0f);

        for(const auto& transformation : transformations)
        {
            switch (transformation.type) {
                case TransformationType::Translation:
                    transf_mat = translate(mat4(1.0f), transformation.value) * transf_mat;

                    break;
                case TransformationType::Rotation:
                    transf_mat = yawPitchRoll(transformation.value.y, transformation.value.x, transformation.value.z) *
                                 transf_mat;
                    break;
                case TransformationType::Scaling:
                    transf_mat = scale(mat4(1.0f), transformation.value) * transf_mat;
                    break;

            }
        }
        return transf_mat;

    }

    //GUI part
    void Transform :: onImmediateGui(ImGuiIO &io) {

        ImGui::Begin("Controls");

        ImGui::Text("Transformations");

        const char* transformation_names[] = {
                "Translation",
                "Rotation",
                "Scaling"
        };

        NotEngine::ReorderableList(transformations.begin(), transformations.end(),
                             [transformation_names](size_t index, Transformation& transform){
                                 auto selected = static_cast<int>(transform.type);
                                 if(ImGui::BeginCombo("Type", transformation_names[selected])){
                                     for(int selectable = 0; selectable < 3; ++selectable){
                                         bool is_selected = selected == selectable;
                                         if(ImGui::Selectable(transformation_names[selectable], is_selected))
                                             selected = selectable;
                                         if(is_selected)
                                             ImGui::SetItemDefaultFocus();
                                     }
                                     ImGui::EndCombo();
                                     transform.type = static_cast<TransformationType>(selected);
                                 }
                                 ImGui::DragFloat3("Value", glm::value_ptr(transform.value), 0.1f);
                             }, [this](size_t index){
                    transformations.insert(transformations.begin() + index, { TransformationType::Translation, glm::vec3() });
                }, [this](size_t index){
                    transformations.erase(transformations.begin() + index);
                });

        if(ImGui::Button("Clear")){
            transformations.clear();
        }

        ImGui::Separator();

        ImGui::Text("Result:");
        auto matrix = compose();
        for(int row = 0; row < 4; ++row)
            ImGui::Text("%f\t%f\t%f\t%f", matrix[0][row], matrix[1][row], matrix[2][row], matrix[3][row]);

        ImGui::End();
    }
