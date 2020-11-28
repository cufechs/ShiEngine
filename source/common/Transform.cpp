//
// Created by yuze on 11/26/2020.
//

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


