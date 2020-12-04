#include "GameObject.h"
#include "GameObjectComponent.h"
namespace ShiEngine {

    ShiEngine::GameObject::GameObject()
    {
        Active = true;
        ComponentsCount = 0;
        Tag = Tags::Default;
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
            for(auto & Component : Components) {
                (*Component).Update(deltatime);
            }

    }

    void ShiEngine::GameObject::Draw()
    {
        if(Active)
            for(auto & Component : Components)
                (*Component).Draw();

    }

    void ShiEngine::GameObject::AddComponent(GameObjectComponent* component)
    //void ShiEngine::GameObject::AddComponent(GameObjectComponent* component)
    {
        component->gameObject = this;
        Components.push_back(component);
        ComponentsCount++;
    }

    GameObjectComponent* ShiEngine::GameObject::GetComponent(ComponentType type1) {
        for (auto &Component : Components)
            if (type1 == Component->Type)
                return Component;

        return nullptr;
    }

    //void ShiEngine::GameObject::RemoveComponent(GameObjectComponent& component)
    //{
//        for (auto ptr = Components.begin(); ptr < Components.end(); ptr++)
//            if((*ptr) == &component)
//                Components.erase(ptr);
    //}

    ShiEngine::GameObject::~GameObject() = default;
}