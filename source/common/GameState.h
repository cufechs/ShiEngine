//
// Created by Adham on 26-Nov-20.
//

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>
#include <GameObject.h>


class GameState {
private:
    double timeScale;
    std::vector<GameObject*> GameObj_vector;
public:
    GameState();

    void Enter();
    void Exit();

    void addGameObject(GameObject* gameObject);
    static void enableGameObject(GameObject* gameObject);
    static void disableGameObject(GameObject* gameObject);

    void Pause();
    void Resume();
    void ScaleGameTime(double timeScale);

    void Update(double deltaTime);
    void Draw();
};


#endif //GAMESTATE_H
