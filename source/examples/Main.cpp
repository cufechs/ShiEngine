#include <application.hpp>
#include "Sampler.h"
#include "GameStateManger.h"
#include "States.h"
#include "LoadState.h"
#include "Texture2D.h"
#include "Globals/Global_vars.h"

// This exercise Window Application that derives from "Application" parent
class Main : public ShiEngine::Application {

    enum States {State1,State2};
    ShiEngine::Texture2D* texture;
    ShiEngine::Sampler* sampler;

    // This overridden function sets the window configuration params struct (title, size, isFullscreen).
    ShiEngine::WindowConfiguration getWindowConfiguration() override {
        return { "Engine", {1280, 720}, false };
    }

    // onInitialize() function is called once before the application loop
    void onInitialize() override {

        ShiEngine::Global::Global_GameStateManger = new ShiEngine::GameStateManger();

        ShiEngine::Global::Global_GameStateManger->attachApplicationPtr(this);

        texture = new ShiEngine::Texture2D("../assets/Textures/moon.jpg", true);
        sampler = new ShiEngine::Sampler();

        //program
        ShiEngine::Global::Global_GameStateManger->AttachGameState(State1,&CreateState1);
        ShiEngine::Global::Global_GameStateManger->AttachGameState(State2,&CreateState2);

        ShiEngine::Global::Global_GameStateManger->ChangeGameState(State1);
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

        if(this->getKeyboard().justPressed(GLFW_KEY_1))
            ShiEngine::Global::Global_GameStateManger->ChangeGameState(State1);
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

        ShiEngine::Global::Global_GameStateManger->Update(deltaTime);
    }

	void onDraw() override {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        ShiEngine::Global::Global_ShaderProgram->use();

        sampler->use(ShiEngine::Global::Global_ShaderProgram); //ShaderProgram's"sampler" uniform is set inside this function

        texture->Draw();

        ShiEngine::Global::Global_ShaderProgram->unuse();

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
