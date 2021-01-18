#include "GameObject.h"

namespace ShiEngine {

    ShiEngine::GameObject::GameObject()
    {
        Active = true;
        deleteMeFlag = false;
        ComponentsCount = 0;
        Tag = Tags::Default;
        Name = "GameObject";
        Parent = nullptr;
        transform = nullptr;
    }

    ShiEngine::GameObject::GameObject(Tags tag)
    {
        Active = true;
        deleteMeFlag = false;
        ComponentsCount = 0;
        Tag = tag;
        Name = "GameObject";
        Parent = nullptr;
        transform = nullptr;
    }

    void ShiEngine::GameObject::Start()
    {
        if(Active)
            for(auto & Component : Components)
                Component->Start();

        transform = (Transform*)this->GetComponent(ComponentType::Transform);
        if(Parent)
            transform->parent = (Transform*)Parent->GetComponent(ComponentType::Transform);
    }

    void ShiEngine::GameObject::Update(double deltatime)
    {
        if(Active)
            for(auto & Component : Components)
                Component->Update(deltatime);
    }

    void ShiEngine::GameObject::LateUpdate(double deltatime)
    {
        if(Active)
            for(auto & Component : Components)
                Component->LateUpdate(deltatime);
    }

    void ShiEngine::GameObject::Draw()
    {
        if(Active)
            for(auto & Component : Components)
                Component->Draw();
    }

    void ShiEngine::GameObject::DeleteMe(){
        deleteMeFlag = true;
        for(auto & gameObject : Children)
            gameObject->DeleteMe();
    }

    void ShiEngine::GameObject::AddComponent(GameObjectComponent* component)
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

    ShiEngine::GameObject::~GameObject() {
        for(auto & Component : Components)
            if (Component)
                delete(Component);
    }
}