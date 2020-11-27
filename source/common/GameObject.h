
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <list>

class GameObject
{
private:
    bool isEnabled;
public:
    GameObject();

    void Enable();
    void Disable();

    void Update(double deltaTime);
    void Draw();
};

#endif //GAMEOBJECT_H
