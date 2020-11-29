#pragma once
#include <vector>
//#include "GameObjectComponent.h"
#include <string>
#include <typeinfo>
#include <memory>
using namespace std;

//class GameObjectComponent;
namespace ShiEngine {

    enum Tags {Default};
    class GameObjectComponent;
    class GameObject
    {
    public:
        int ComponentsCount;
        //vector<GameObjectComponent*> Components;
        vector<std::shared_ptr<GameObjectComponent> > Components;
        Tags Tag;
        string Name;
        bool Active;
        GameObject* Parent;

        GameObject();
        ~GameObject();

        void AddComponent(std::shared_ptr<GameObjectComponent> component); //Should be Implemented as Template
        void RemoveComponent(GameObjectComponent& component); //Should be Implemented as Template
        template <class T>
        T& GetComponent();

        void Start();
        void Update(double deltatime);
        void Draw();
    private:

    };
}