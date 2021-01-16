//
// Created by Adham on 26-Nov-20.
//

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>
#include <GameObject.h>
#include <CameraController.h>

namespace ShiEngine {

    static std::vector<GameObject *> GameObj_vector;
    class GameState {
    private:
        double timeScale;

        FlyCameraController *cameraController;
    public:

        GameState();

        void Enter();
        void Exit();

        void addGameObject(GameObject *gameObject);
        void addChildGameObject(GameObject *Parent, GameObject *Child);
        static void attachChildGameObject(GameObject *Parent, GameObject *Child);

        void deleteGameObject();
        void deleteGameObject(Tags tag);

        void attachCameraController(FlyCameraController *cameraController);

        std::vector<GameObject*> getAllGameObjects();
        GameObject* getGameObject(Tags tag);
        GameObject *getGameObject(std::string Name);
        std::vector<GameObject*> getGameObjects(Tags tag);

        static std::vector<GameObject*> getGameObjects();

        static void enableGameObject(GameObject *gameObject);
        static void disableGameObject(GameObject *gameObject);

        void Pause();
        void Resume();
        void ScaleGameTime(double timeScale);

        void Update(double deltaTime);
        void LateUpdate(double deltaTime);
        void Draw();
    };
}


#endif //GAMESTATE_H
