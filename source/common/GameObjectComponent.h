#pragma once
//#include "GameObject.h"

class GameObject;
namespace ShiEngine {
    class GameObjectComponent
    {
    protected:

    public:
        bool Enabled;
        GameObject * gameObject;
        GameObjectComponent();

        virtual void Start() = 0;

        //Called once per component
        virtual void Update(double deltaTime) = 0;  //Called every frame

        virtual void Draw() = 0;  //Called every frame after "Update()" execution

        ~GameObjectComponent();

        /*virtual GameObjectComponent DeepCopy(GameObject Clone)
        {
            return this() as GameObjectComponent;
        }*/
    };
}