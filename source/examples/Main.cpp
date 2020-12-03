#include <application.hpp>
#include <Shader.hpp>
#include "GameObject.h"
#include "MeshRenderer.h"
#include "testComp.h"
#include "Camera.h"
#include "CameraController.h"

// This exercise Window Application that derives from "Application" parent
class Main : public ShiEngine::Application {

    ShiEngine::ShaderProgram program;
    GLuint vertex_array = 0;
    ShiEngine::GameObject GO;
    ShiEngine::MeshRenderer* meshRenderer1;
    ShiEngine::MeshRenderer* meshRenderer2;
    //ShiEngine:: comp_mesh;
    ShiEngine::GameObject obj1;
    ShiEngine::GameObject obj2;
    ShiEngine::GameObject objCamera;

    ShiEngine::Transform* transform1;
    ShiEngine::Transform* transform2;

    ShiEngine::Camera* camera;

    ShiEngine::Mesh* meshCube;
    ShiEngine::Mesh* meshPlane;

    ShiEngine::FlyCameraController controller;

    // This overriden function sets the window configuration params struct (title, size, isFullscreen).
    ShiEngine::WindowConfiguration getWindowConfiguration() override {
        return { "Engine", {1280, 720}, false };
    }



    // onInitialize() function is called once before the application loop
    void onInitialize() override {

        program.create("../assets/Shaders/Phase 1/transform.vert", GL_VERTEX_SHADER, "../assets/Shaders/Phase 1/tint.frag", GL_FRAGMENT_SHADER);


        // Resources
        meshCube = new ShiEngine::Mesh();
        meshCube->Cuboid(true);

        meshPlane = new ShiEngine::Mesh();
        meshPlane->Plane(true);

        // Camera Transfomr
        transform1 = new ShiEngine::Transform();
        transform1->position = glm::vec3({0, 0, 0});
        transform1->scale = glm::vec3({1,1,1});
        transform1->rotation = glm::vec3({0,0,0});


        transform2 = new ShiEngine::Transform();
        transform2->position = glm::vec3({-3, 0, 0});
        transform2->scale = glm::vec3({1,1,1});
        transform2->rotation = glm::vec3({0,0,0});


        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        camera = new ShiEngine::Camera();

        camera->setEyePosition({10.f, 10.f, 10.f});
        camera->setTarget({0.f, 0.f, 0.f});
        camera->setUp({0, 1, 0});
        camera->setupPerspective(glm::pi<float>()/2, 1.7f, 0.1f, 100.0f);
        //camera->setupOrthographic(2.f, 1.7, 0.1f, 100.0f);

        meshRenderer1 = new ShiEngine::MeshRenderer(&program, meshCube);
        meshRenderer1->Setcam(camera);
        controller.initialize(this, camera);


        meshRenderer2 = new ShiEngine::MeshRenderer(&program, meshCube);
        meshRenderer2->Setcam(camera);



        objCamera.AddComponent(transform1); // TODO: independent transform -> transformCamera
        objCamera.AddComponent(camera);

        obj1.AddComponent(transform1);
        obj1.AddComponent(meshRenderer1);


        obj2.AddComponent(transform2);
        obj2.AddComponent(meshRenderer2);





        obj1.Start();
        obj2.Start();

    }

    //void onImmediateGui(ImGuiIO &io) override {
    //    // Shows a metric window just as an example of ImGui operations
    //    ImGui::ShowMetricsWindow();
    //}

    void onUpdate(double deltaTime) override {
        //Here you write all your game logic
        controller.Update(deltaTime);
        obj1.Update(deltaTime);
        obj2.Update(deltaTime);

    }

	void onDraw() override {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        obj1.Draw();
        obj2.Draw();
	}

};

// Example Entry point
int main(int argc, char** argv) {
    
    // Creates an instance of EmptyWindowApplication and call run on this instance
    return Main().run();
}
