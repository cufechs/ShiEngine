#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include "Transform.h"
#include <string>
#include <memory>
#include <iostream>
#include "Global.h"


namespace ShiEngine {
    enum class Tags {Default};

    class GameObjectComponent;

    class GameObject {
    public:
        int ComponentsCount;
        //vector<GameObjectComponent*> Components;
        std::vector<GameObjectComponent *> Components;
        std::string Name;
        Tags Tag;
        bool Active;
        bool deleteMeFlag;
        GameObject* Parent;
        std::vector<GameObject*> Children;
        Transform* transform;

        GameObject();

        ~GameObject();

        void DeleteMe();
        void AddComponent(GameObjectComponent *component); //Should be Implemented as Template
        //void RemoveComponent(GameObjectComponent* component); //Should be Implemented as Template
        GameObjectComponent* GetComponent(ComponentType type1);

        void Start();
        void Update(double deltatime);
        void Draw();
    };
}

#endif //GAMEOBJECT_H