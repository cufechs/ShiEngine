#include "GameObjectComponent.h"

namespace ShiEngine {
    GameObjectComponent::GameObjectComponent()
    {
        Enabled = true;
        gameObject = nullptr;
    }

    GameObjectComponent::~GameObjectComponent() = default;
}