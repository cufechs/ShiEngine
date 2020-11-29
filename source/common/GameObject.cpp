#include <memory>
#include "GameObject.h"
#include "GameObjectComponent.h"
namespace ShiEngine {
    ShiEngine::GameObject::GameObject()
    {
        Active = true;
        ComponentsCount = 0;
        Tag = Default;
        Name = "GameObject";
        Parent = nullptr;
    }

    void ShiEngine::GameObject::Start()
    {
        if(Active)
            for(auto & Component : Components)
                (*Component).Start();


    }

    void ShiEngine::GameObject::Update(double deltatime)
    {
        if(Active)
            for(auto & Component : Components)
                (*Component).Update(deltatime);
    }

    void ShiEngine::GameObject::Draw()
    {
        if(Active)
            for(auto & Component : Components)
                (*Component).Draw();

    }

    void ShiEngine::GameObject::AddComponent(std::shared_ptr<GameObjectComponent> component)
    //void ShiEngine::GameObject::AddComponent(GameObjectComponent* component)
    {
        Components.push_back(component);
    }

    void ShiEngine::GameObject::RemoveComponent(GameObjectComponent& component)
    {
//        for (auto ptr = Components.begin(); ptr < Components.end(); ptr++)
//            if((*ptr) == &component)
//                Components.erase(ptr);
    }

    template <class T>
    T& ShiEngine::GameObject::GetComponent()
    {
        for(auto & Component : Components)
            if(typeid(Component) == typeid(T)) {
                std::cout << "yes"  << std::endl;
                return Component;
            } else {
                std::cout << "No\n";
            }


    }

    ShiEngine::GameObject::~GameObject() = default;
}