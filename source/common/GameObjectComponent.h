#ifndef GAMEOBJECTCOMPONENT_H
#define GAMEOBJECTCOMPONENT_H

#include "Globals/Global.h"

//class GameObject;
namespace ShiEngine {

    class GameObject;

    class GameObjectComponent
    {
    protected:

    public:
        ShiEngine::ComponentType Type;
        bool Enabled;
        GameObject* gameObject;
        GameObjectComponent();

        virtual void Start() {};

        //Called once per component
        virtual void Update(double deltaTime) {};  //Called every frame

        virtual void Draw() {};  //Called every frame after "Update()" execution

        ~GameObjectComponent();

        /*virtual GameObjectComponent DeepCopy(GameObject Clone)
        {
            return this() as GameObjectComponent;
        }*/
    };
}

#endif //GAMEOBJECTCOMPONENT_H