#include "GameObjectComponent.h"

namespace ShiEngine {
    ShiEngine::GameObjectComponent::GameObjectComponent()
    {
        Enabled = true;
        gameObject = nullptr;
    }

    ShiEngine::GameObjectComponent::~GameObjectComponent() = default;
}