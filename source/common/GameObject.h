#pragma once
#include <vector>
//#include "GameObjectComponent.h"
#include <string>
#include <typeinfo>
#include <memory>
#include <iostream>
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
        vector<GameObjectComponent*> Components;
        Tags Tag;
        string Name;
        bool Active;
        GameObject* Parent;

        GameObject();
        ~GameObject();

        void AddComponent(GameObjectComponent* component); //Should be Implemented as Template
        //void RemoveComponent(GameObjectComponent* component); //Should be Implemented as Template
        template <typename T>
        T* GetComponent()
        {

            for(auto & Component : Components) {
                std::cout << "name Comp: " << typeid(Component).name() << ", name T: " << typeid(T).name() << "\n";
                if (typeid((T*)Component) == typeid(T*)) {
                    std::cout << "in get comp\n";
                    return (T *) Component;
                } else {
                    std::cout << "not found\n";
                }
            }

            return nullptr;
        }

        void Start();
        void Update(double deltatime);
        void Draw();
    private:

    };
}