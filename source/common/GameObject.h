#pragma once
#include <vector>
#include "GameObjectComponent.h"
#include <string>
#include <typeinfo>
using namespace std;

namespace ShiEngine {

    enum Tags {Default};

    class GameObject
    {
    public:
        int ComponentsCount;
        vector<GameObjectComponent*> Components;
        Tags Tag;
        string Name;
        bool Active;
        GameObject* Parent;

        GameObject();
        ~GameObject();

        void AddComponent(GameObjectComponent& component); //Should be Implemented as Template
        void RemoveComponent(GameObjectComponent& component); //Should be Implemented as Template
        template <class T>
        T& GetComponent();

        void Start();
        void Update(double deltatime);
        void Draw();
    private:

    };
}