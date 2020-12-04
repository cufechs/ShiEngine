#pragma once
#include <vector>
//#include "GameObjectComponent.h"
#include <string>
#include <memory>
#include <iostream>
//using namespace std;

//class GameObjectComponent;
namespace ShiEngine {
    enum class ComponentType {Transform, MeshRenderer, Camera};
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
        GameObject* Parent;

        GameObject();

        ~GameObject();

        void AddComponent(GameObjectComponent *component); //Should be Implemented as Template
        //void RemoveComponent(GameObjectComponent* component); //Should be Implemented as Template
        GameObjectComponent* GetComponent(ComponentType type1);

        void Start();
        void Update(double deltatime);
        void Draw();
    };
}