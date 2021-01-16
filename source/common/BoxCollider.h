//
// Created by ossya on 1/16/2021.
//

#ifndef GFX_LAB_BOXCOLLIDER_H
#define GFX_LAB_BOXCOLLIDER_H

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Transform.h"
#include "GameObject.h"

namespace ShiEngine {
    class BoxCollider: public ShiEngine::GameObjectComponent
    {
    private:
        glm::vec3 StartVector;
        glm::vec3 EndVector;
    public:
        bool IsTrigger;

        BoxCollider();
        BoxCollider(glm::vec3 Start, glm::vec3 End);
        glm::vec3 GetStartVector();
        glm::vec3 GetEndVector();
        bool CollidesWith(glm::vec3 Start, glm::vec3 End);
    };
}


#endif //GFX_LAB_BOXCOLLIDER_H
