#include <application.hpp>
#include "GameStateManger.h"
#include "States.h"

// This exercise Window Application that derives from "Application" parent
class Main : public ShiEngine::Application {

    enum States {State1,State2};

    // This overridden function sets the window configuration params struct (title, size, isFullscreen).
    ShiEngine::WindowConfiguration getWindowConfiguration() override {
        return { "Engine", {1280, 720}, false };
    }

    // onInitialize() function is called once before the application loop
    void onInitialize() override {

        gameStateManger = new ShiEngine::GameStateManger();
        gameStateManger->attachApplicationPtr(this);

        gameStateManger->AttachGameState(State1,&CreateState1);
        gameStateManger->AttachGameState(State2,&CreateState2);

        gameStateManger->ChangeGameState(State1);
    }

    //void onImmediateGui(ImGuiIO &io) override {
    //    // Shows a metric window just as an example of ImGui operations
    //    ImGui::ShowMetricsWindow();
    //}

    void onUpdate(double deltaTime) override {
        //Here you write all your game logic

        if(this->getKeyboard().justPressed(GLFW_KEY_1))
            gameStateManger->ChangeGameState(State1);
        if(this->getKeyboard().justPressed(GLFW_KEY_2))
            gameStateManger->ChangeGameState(State2);

        if(this->getKeyboard().isPressed(GLFW_KEY_X))
            gameStateManger->GetActiveState()->getGameObjects(ShiEngine::Tags::Default)[0]->transform->rotation.x++;
        if(this->getKeyboard().isPressed(GLFW_KEY_C))
            gameStateManger->GetActiveState()->getGameObjects(ShiEngine::Tags::Default)[0]->transform->rotation.y++;
        if(this->getKeyboard().isPressed(GLFW_KEY_Z))
            gameStateManger->GetActiveState()->getGameObjects(ShiEngine::Tags::Default)[0]->transform->rotation.z++;

        if(this->getKeyboard().justPressed(GLFW_KEY_K))
            gameStateManger->GetActiveState()->getGameObjects(ShiEngine::Tags::Default)[0]->DeleteMe();

        gameStateManger->Update(deltaTime);
    }

	void onDraw() override {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        gameStateManger->Draw();
	}


private:
    ShiEngine::GameStateManger* gameStateManger;
};

// Example Entry point
int main(int argc, char** argv) {
    
    // Creates an instance of EmptyWindowApplication and call run on this instance
    return Main().run();
}
