#include <application.hpp>
#include "Sampler.h"
#include "GameStateManger.h"
#include "States.h"
#include "LoadState.h"
#include "Texture2D.h"
#include "Globals/Global_vars.h"

// This exercise Window Application that derives from "Application" parent
class Main : public ShiEngine::Application {

    glm::vec3 PlayerDefaultPos;
    enum States {State1,State2,State3};
    ShiEngine::Texture2D* texture;
    ShiEngine::Sampler* sampler;
    std::vector<ShiEngine::BoxCollider*> boxColliders; //stores all box colliders in the scene except that of the Player/Camera
    bool keyFound = false;

    // This overridden function sets the window configuration params struct (title, size, isFullscreen).
    ShiEngine::WindowConfiguration getWindowConfiguration() override {
        return { "Engine", {1700, 980}, false };
    }

    // onInitialize() function is called once before the application loop
    void onInitialize() override {

        ShiEngine::Global::Global_GameStateManger = new ShiEngine::GameStateManger();

        ShiEngine::Global::Global_GameStateManger->attachApplicationPtr(this);

        //program
        ShiEngine::Global::Global_GameStateManger->AttachGameState(State1,&CreateState1);
        ShiEngine::Global::Global_GameStateManger->AttachGameState(State2,&CreateState2);
        ShiEngine::Global::Global_GameStateManger->AttachGameState(State3,&CreateState3);// MainMenu

        ShiEngine::Global::Global_GameStateManger->ChangeGameState(State3);


        for (auto x: ShiEngine::Global::Global_GameStateManger->GetActiveState()->getAllGameObjects()) {
            if (x->Tag != ShiEngine::Tags::CAMERA) { //if not Player
                ShiEngine::BoxCollider* box = dynamic_cast<ShiEngine::BoxCollider*>(x->GetComponent(ShiEngine::ComponentType::BoxCollider));
                if (box != nullptr)
                    boxColliders.push_back( box );
            }
            else
                PlayerDefaultPos = x->transform->position;
        }

    }

    //void onImmediateGui(ImGuiIO &io) override {
    //    // Shows a metric window just as an example of ImGui operations
    //    ImGui::ShowMetricsWindow();
    //}

    void onUpdate(double deltaTime) override {
        //Here you write all your game logic
        //Close window on pressing ESC key
        if(this->getKeyboard().justReleased(GLFW_KEY_ESCAPE))
            glfwSetWindowShouldClose(window, 1);

        if(this->getKeyboard().justPressed(GLFW_KEY_1)) {
            ShiEngine::Global::Global_GameStateManger->ChangeGameState(State2);

            boxColliders.clear();
            for (auto x: ShiEngine::Global::Global_GameStateManger->GetActiveState()->getAllGameObjects()) {
                if (x->Tag != ShiEngine::Tags::CAMERA) { //if not Player
                    ShiEngine::BoxCollider* box = dynamic_cast<ShiEngine::BoxCollider*>(x->GetComponent(ShiEngine::ComponentType::BoxCollider));
                    if (box != nullptr)
                        boxColliders.push_back( box );
                }
                else
                    PlayerDefaultPos = x->transform->position;
            }
        }
        if(this->getKeyboard().justPressed(GLFW_KEY_2))
            ShiEngine::Global::Global_GameStateManger->ChangeGameState(State2);
        if(this->getKeyboard().justPressed(GLFW_KEY_0))
            ShiEngine::Global::Global_GameStateManger->ChangeGameState(
                    DeserializeState("../assets/simple.json", this));


        if(this->getKeyboard().isPressed(GLFW_KEY_X))
            ShiEngine::Global::Global_GameStateManger->GetActiveState()->getGameObjects(ShiEngine::Tags::Default)[0]->transform->rotation.x++;
        if(this->getKeyboard().isPressed(GLFW_KEY_C))
            ShiEngine::Global::Global_GameStateManger->GetActiveState()->getGameObjects(ShiEngine::Tags::Default)[0]->transform->rotation.y++;
        if(this->getKeyboard().isPressed(GLFW_KEY_Z))
            ShiEngine::Global::Global_GameStateManger->GetActiveState()->getGameObjects(ShiEngine::Tags::Default)[0]->transform->rotation.z++;

        if(this->getKeyboard().justPressed(GLFW_KEY_K))
            ShiEngine::Global::Global_GameStateManger->GetActiveState()->getGameObjects(ShiEngine::Tags::Default)[0]->DeleteMe();

        ///
        if(this->getKeyboard().isPressed(GLFW_KEY_L))
            ShiEngine::Global::Global_GameStateManger->GetActiveState()->getGameObject("cube 2")->transform->position.x = ShiEngine::Global::Global_GameStateManger->GetActiveState()->getGameObject("cube 2")->transform->position.x + 0.1f;
        if(this->getKeyboard().isPressed(GLFW_KEY_J))
            ShiEngine::Global::Global_GameStateManger->GetActiveState()->getGameObject("cube 2")->transform->position.x = ShiEngine::Global::Global_GameStateManger->GetActiveState()->getGameObject("cube 2")->transform->position.x - 0.1f;
        if(this->getKeyboard().isPressed(GLFW_KEY_I))
            ShiEngine::Global::Global_GameStateManger->GetActiveState()->getGameObject("cube 2")->transform->position.y = ShiEngine::Global::Global_GameStateManger->GetActiveState()->getGameObject("cube 2")->transform->position.y + 0.1f;
        if(this->getKeyboard().isPressed(GLFW_KEY_M))
            ShiEngine::Global::Global_GameStateManger->GetActiveState()->getGameObject("cube 2")->transform->position.y = ShiEngine::Global::Global_GameStateManger->GetActiveState()->getGameObject("cube 2")->transform->position.y - 0.1f;

        ShiEngine::Global::Global_GameStateManger->Update(deltaTime);

//        if (ShiEngine::Global::Global_GameStateManger->GetActiveState()->Name == "Level1" ||
//                ShiEngine::Global::Global_GameStateManger->GetActiveState()->Name == "Level2") {
            ShiEngine::BoxCollider *B1 = dynamic_cast<ShiEngine::BoxCollider *>(ShiEngine::Global::Global_GameStateManger->GetActiveState()->getGameObject(
                    "objCamera")->GetComponent(ShiEngine::ComponentType::BoxCollider));
            ShiEngine::BoxCollider *B2 = dynamic_cast<ShiEngine::BoxCollider *>(ShiEngine::Global::Global_GameStateManger->GetActiveState()->getGameObject(
                    "plane5 gameObject")->GetComponent(ShiEngine::ComponentType::BoxCollider));

            for (auto x: boxColliders) {
                if (B1->CollidesWith(x)) {
                    if (x->IsTrigger) {
                        if (x->gameObject->Name == "key") {
                            std::cout << "got the keyyyyyyyyyyyyy\n";
                            keyFound = true;
                        }
                        else if (x->gameObject->Name == "Door" && (
                                ShiEngine::Global::Global_GameStateManger->GetActiveState()->Name == "MainMenu" ||
                                ShiEngine::Global::Global_GameStateManger->GetActiveState()->Name == "Level1") ) //Door
                        {
                            boxColliders.clear();
                            if (ShiEngine::Global::Global_GameStateManger->GetActiveState()->Name == "MainMenu")
                                ShiEngine::Global::Global_GameStateManger->ChangeGameState(State1);
                            else if (ShiEngine::Global::Global_GameStateManger->GetActiveState()->Name == "Level1")
                                ShiEngine::Global::Global_GameStateManger->ChangeGameState(State2);
                            else if (ShiEngine::Global::Global_GameStateManger->GetActiveState()->Name == "Level2")
                                ShiEngine::Global::Global_GameStateManger->ChangeGameState(State3);

                            for (auto x: ShiEngine::Global::Global_GameStateManger->GetActiveState()->getAllGameObjects()) {
                                if (x->Tag != ShiEngine::Tags::CAMERA) { //if not Player

                                    ShiEngine::BoxCollider* box = dynamic_cast<ShiEngine::BoxCollider*>(x->GetComponent(ShiEngine::ComponentType::BoxCollider));
                                    if (box != nullptr)
                                        boxColliders.push_back( box );
                                }
                                else
                                    PlayerDefaultPos = x->transform->position;
                            }
                            //std::cout << "I am TRIGGERED!!!!\n";
                            return;
                        }
                        else if (keyFound && x->gameObject->Name == "Door") {
                            boxColliders.clear();
                            if (ShiEngine::Global::Global_GameStateManger->GetActiveState()->Name == "MainMenu")
                                ShiEngine::Global::Global_GameStateManger->ChangeGameState(State1);
                            else if (ShiEngine::Global::Global_GameStateManger->GetActiveState()->Name == "Level1")
                                ShiEngine::Global::Global_GameStateManger->ChangeGameState(State2);
                            else if (ShiEngine::Global::Global_GameStateManger->GetActiveState()->Name == "Level2")
                                ShiEngine::Global::Global_GameStateManger->ChangeGameState(State3);

                            for (auto x: ShiEngine::Global::Global_GameStateManger->GetActiveState()->getAllGameObjects()) {
                                if (x->Tag != ShiEngine::Tags::CAMERA) { //if not Player

                                    ShiEngine::BoxCollider *box = dynamic_cast<ShiEngine::BoxCollider *>(x->GetComponent(
                                            ShiEngine::ComponentType::BoxCollider));
                                    if (box != nullptr)
                                        boxColliders.push_back(box);
                                } else
                                    PlayerDefaultPos = x->transform->position;
                            }
                            keyFound = false;
                            return;
                        }
                        else {//Ghost
                            //B1->gameObject->transform->position = PlayerDefaultPos;
                            // Reload the same state if hit the ghosts
                            boxColliders.clear();
                            if (ShiEngine::Global::Global_GameStateManger->GetActiveState()->Name == "MainMenu")
                                ShiEngine::Global::Global_GameStateManger->ChangeGameState(State3);
                            else if (ShiEngine::Global::Global_GameStateManger->GetActiveState()->Name == "Level1")
                                ShiEngine::Global::Global_GameStateManger->ChangeGameState(State1);
                            else if (ShiEngine::Global::Global_GameStateManger->GetActiveState()->Name == "Level2")
                                ShiEngine::Global::Global_GameStateManger->ChangeGameState(State2);
                            for (auto x: ShiEngine::Global::Global_GameStateManger->GetActiveState()->getAllGameObjects()) {
                                if (x->Tag != ShiEngine::Tags::CAMERA) { //if not Player

                                    ShiEngine::BoxCollider* box = dynamic_cast<ShiEngine::BoxCollider*>(x->GetComponent(ShiEngine::ComponentType::BoxCollider));
                                    if (box != nullptr)
                                        boxColliders.push_back( box );
                                }
                                else
                                    PlayerDefaultPos = x->transform->position;
                            }
                            return;
                        }





                    }

                    //std::cout << "I am TRIGGERED!!!!\n";
                }
            }


        //}
        //ShiEngine::Global::Global_GameStateManger->Update(deltaTime);
        ShiEngine::Global::Global_GameStateManger->LateUpdate(deltaTime);
    }

	void onDraw() override {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        ShiEngine::Global::Global_GameStateManger->Draw();
	}


private:
    //ShiEngine::GameStateManger* gameStateManger;
};

// Example Entry point
int main(int argc, char** argv) {
    
    // Creates an instance of EmptyWindowApplication and call run on this instance
    return Main().run();
}
