#include "GameObject.h"


GameObject::GameObject() {
    isEnabled = true;
}

void GameObject::Enable() {
    isEnabled = true;
}

void GameObject::Disable() {
    isEnabled = false;
}

void GameObject::Update(double deltaTime) {

}

void GameObject::Draw() {

}