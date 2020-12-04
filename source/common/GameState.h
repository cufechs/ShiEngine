//
// Created by Adham on 26-Nov-20.
//

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>
#include <GameObject.h>
#include <CameraController.h>

namespace ShiEngine {
    class GameState {
    private:
        double timeScale;
        std::vector<GameObject *> GameObj_vector;
        FlyCameraController *cameraController;
    public:
        GameState();

        void Enter();
        void Exit();

        void addGameObject(GameObject *gameObject);
        bool deleteGameObject(GameObject *gameObject);

        void attachCameraController(FlyCameraController *cameraController);

        GameObject* getGameObject(Tags tag);
        vector<GameObject*> getGameObjects(Tags tag);

        static void enableGameObject(GameObject *gameObject);
        static void disableGameObject(GameObject *gameObject);

        void Pause();
        void Resume();
        void ScaleGameTime(double timeScale);

        void Update(double deltaTime);
        void Draw();
    };
}


#endif //GAMESTATE_H
